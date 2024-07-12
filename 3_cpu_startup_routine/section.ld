MEMORY
{
  /*rom (irx!wa): ORIGIN = 0x1000, LENGTH = 1K
  ram (arwx!i): ORIGIN = 0x80000000, LENGTH = 1K*/
	lma_mem(r!ixwa)  : ORIGIN = 0x1000,	  LENGTH = 1K  
	vma_imem(rxa!wi) : ORIGIN = 0x1000,	  LENGTH = 1K
	vma_dmem(wai!xr) : ORIGIN = 0x80000000, LENGTH = 4K

}
ENTRY(start)
SECTIONS
{
	.text : ALIGN(4)
	{
		*(.text.start)
		*(.text)
		*(.text.*)
		 . = ALIGN(8);
	} > vma_imem AT > lma_mem

	.rodata : ALIGN(4)
	{
		*(.rodata)
		*(.rodata.*)
	} > vma_imem AT > lma_mem

	.data : ALIGN(4)
	{  
		*(.data)
		*(.data.*)
		*(.sdata)
		. = ALIGN(8);
	} > vma_dmem AT > lma_mem

	.bss : ALIGN(4)
	{  
		*(.sbss)
		*(.sbss.*)
		*(.bss)
		*(.bss.*)
	} >vma_dmem

	.stack : ALIGN(16)
	{
		*(.stack)
		. = . + 0xc00;
	} >vma_dmem


	PROVIDE(_data_start = LOADADDR(.data));
	PROVIDE(_data_size  = SIZEOF(.data));
	PROVIDE(_data_end   = _data_start + _data_size -1);

	PROVIDE(_vdata_start = ADDR(.data));
	PROVIDE(_vdata_end   = _vdata_start + _data_size -1);

	PROVIDE(_bss_start =  ADDR(.bss));
	PROVIDE(_bss_size = SIZEOF(.bss));
	PROVIDE(_bss_end = _bss_start + _bss_size - 1);

	PROVIDE(_stack_start = ADDR(.stack) + SIZEOF(.stack));
	PROVIDE(_global_start = ADDR(.bss));


}


