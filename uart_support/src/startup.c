#include <lib_string.h>
extern uintptr_t _bss_start, _bss_size, _data_start, _data_size,
		  _vdata_start;

int bss_clear()
{
	memset(&_bss_start, 0,(size_t)&_bss_size);
	return 1;
}

int copy_data()
{
	memcpy(&_vdata_start,&_data_start,(size_t) &_data_size);
	return 1;
}


int bootstrap()
{
   bss_clear();
   copy_data();
   return 0;


}

