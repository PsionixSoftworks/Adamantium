#include <multiboot.h>
#include <vga.h>
#include <kernel/tty.h>
#include <kernel/ioportctrl.h>
#include <kernel/cursor.h>
#include <stdio.h>

// Check bit flags:
#define CHECK_FLAG(flags, bit)				((flags) & (1 << (bit)))

// Initialize the errno var:
int errno = 0;
struct tty_handler tty;

// Entry point of the operating system kernel:
int main(unsigned long magic, unsigned long addr)
{
	// Setup multiboot:
	multiboot_info_t* mbi;
	
	cursor_enable(0x0, 0xF);

	tty_init(&tty);
	tty_set_background_color(&tty, SYSTEM_COLOR_BLACK);
	tty_set_foreground_color(&tty, SYSTEM_COLOR_LT_GRAY);
	tty_clear_screen(&tty);
	
	// Get the address of the Multiboot info:
	mbi = (multiboot_info_t*)addr;

	// Print out flags (as per the Multiboot specification):
	printf("Flags: 0x%x\n", (unsigned)mbi->flags);

	// Check if the "mem_*" members are valid:
	if (CHECK_FLAG(mbi->flags, 0))
	{
		printf("mem_lower: %uKB, mum_upper: %uKB\n", (unsigned)mbi->mem_lower, (unsigned)mbi->mem_upper);
	}

	// Next, check if the boot device is valid:
	if (CHECK_FLAG(mbi->flags, 1))
	{
		printf("Boot Device: 0x%x\n", mbi->boot_device);
	}

	// And then the command line:
	if (CHECK_FLAG(mbi->flags, 2))
	{
		printf ("cmdline = %d\n", mbi->cmdline);
	}

	// Now check if "mods_*" members are valid:
	if (CHECK_FLAG(mbi->flags, 3))
	{
		multiboot_module_t* mod;
		int i;

		printf("Mods Count: %d, Mods Address: 0x%x\n", (int)mbi->mods_count, (int)mbi->mods_addr);
		for (i = 0, mod = (multiboot_module_t*)mbi->mods_addr; i < mbi->mods_count; i++, mod++)
		{
			printf (" mod_start = 0x%x, mod_end = 0x%x, cmdline = %s\n",
                (unsigned) mod->mod_start,
                (unsigned) mod->mod_end,
                (char *) mod->cmdline
			);
		}
	}

	// Check bits 4 & 5:
	if (CHECK_FLAG(mbi->flags, 4) && CHECK_FLAG(mbi->flags, 5))
	{
		printf("Bits 4 & 5 are set.\n");
		return;
	}

	// Check if a.out is valid:
	if (CHECK_FLAG (mbi->flags, 4))
    {
    	multiboot_aout_symbol_table_t *multiboot_aout_sym = &(mbi->u.aout_sym);
      
      	printf ("multiboot_aout_symbol_table: tabsize = 0x%0x, "
            "strsize = 0x%x, addr = 0x%x\n",
            (unsigned) multiboot_aout_sym->tabsize,
            (unsigned) multiboot_aout_sym->strsize,
            (unsigned) multiboot_aout_sym->addr
		);
    }

	// Check if ELF header is valid:
	if (CHECK_FLAG (mbi->flags, 5))
    {
      	multiboot_elf_section_header_table_t *multiboot_elf_sec = &(mbi->u.elf_sec);

      	printf ("multiboot_elf_sec: num = %u, size = 0x%x,"
            " addr = 0x%x, shndx = 0x%x\n",
            (unsigned) multiboot_elf_sec->num, (unsigned) multiboot_elf_sec->size,
            (unsigned) multiboot_elf_sec->addr, (unsigned) multiboot_elf_sec->shndx
		);
    }

	// Check if "mmap_*" members are valid:
	if (CHECK_FLAG (mbi->flags, 6))
    {
      	multiboot_memory_map_t *mmap;
      
      	printf ("mmap_addr = 0x%x, mmap_length = 0x%x\n",
            (unsigned) mbi->mmap_addr, (unsigned) mbi->mmap_length);
      	for (mmap = (multiboot_memory_map_t *) mbi->mmap_addr;
           	(unsigned long) mmap < mbi->mmap_addr + mbi->mmap_length;
           	mmap = (multiboot_memory_map_t *) ((unsigned long) mmap + mmap->size + sizeof (mmap->size)))
        printf (" size = 0x%x, base_addr = 0x%x,"
                " length = 0x%x, type = 0x%x\n",
                (unsigned) mmap->size,
                (unsigned) (mmap->addr >> 32),
                (unsigned) (mmap->addr & 0xffffffff),
                (unsigned) (mmap->len >> 32),
                (unsigned) (mmap->len & 0xffffffff),
                (unsigned) mmap->type);
    }

	// Return as usual:
	return 0;
}
