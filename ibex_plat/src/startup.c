#include <lib_string.h>
extern uintptr_t _bss_start, _bss_size;

int bss_clear()
{
	memset(&_bss_start, 0,(size_t)&_bss_size);
	return 1;
}

int bootstrap()
{
	bss_clear();
	return 0;
}

