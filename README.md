# Adamantium OS Kernel
Adamantium is a microkernel being developed for Psionix Softworks LLC. If you wish to be a part of the development process I
have good news for you! It's open source for a reason. Use of this operating system kernel for commercial gain is prohibited,
but you may use it as long as you follow the guidelines. 

- You may use this kernel to build your own OS as long as it is running on YOUR machine. 
- You may NOT distribute copies of any binaries.
- You may NOT sell copies of it.
- You may NOT claim it as your own.
- If you distribute any of the source code, it must contain the copyright and license attached with a link to the original repo.

# TODO List
- With the GDT setup, the next thing is the IDT or Interrupt Descriptor Table. We may include an LDT (Local Descriptor Table), but
that may be optional. Basically, we need interrupt support and to setup the TSS as soon as possible so we can get to user mode.
- Setup the TSS (Task State Segment). As mentioned, it's required for getting to user mode. If the LDT is used, the TSS will most
likely use it in its setup. 
- A basic driver system to work from user mode. It has to be a robust system. We'll need a base driver that all others will be
the children of. Utilizing inheritance to build drivers and a server system for them to run from. This will require a lot of setup
to get working properly.

# Contributers
All contributers names will be listed here as a way of thanking you for your support. If you do not wish to be listed, but wish to
contribute, then just let me know. My email is gamemaker80@gmail.com.
- Vincent C. - gamemaker80@gmail.com
