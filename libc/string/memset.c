#include <string.h>
#include <stdint.h>

void *
memset(void *_dest, int c, size_t n)
{
    uint8_t *ptr = _dest;
    while (n-- > 0)
    {
        *ptr++ = c;
    }
    return (_dest);
}
