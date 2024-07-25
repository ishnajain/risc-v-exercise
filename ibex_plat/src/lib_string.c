#include <lib_string.h>
void *memcpy(void *dst, void *src, size_t n)
{       char *i = dst;
	char *j = src;
	while(n--)
	{
		*i++=*j++;
	}
	return i;


}

void *memset(void *str, int a, size_t n)
{
	char *i = str;
	while(n--)
	{
		*i++=a;
	}
	return i;
}


