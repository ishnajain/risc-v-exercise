MEMORY
{
  /*rom (irx!wa): ORIGIN = 0x1000, LENGTH = 1K
  ram (arwx!i): ORIGIN = 0x80000000, LENGTH = 1K*/
	ram  : ORIGIN = 0x100000,LENGTH = 1M  

}
ENTRY(start)
SECTIONS
{
	.text : ALIGN(4)
	{
		*(.text.expnhndlr)
		*(.text.start)
		*(.text)
		*(.text.*)
		 . = ALIGN(8);
	} > ram

	.rodata : ALIGN(4)
	{
		*(.rodata)
		*(.rodata.*)
	} > ram

	.data : ALIGN(4)
	{  
		*(.data)
		*(.data.*)
		*(.sdata)
		. = ALIGN(8);
	} > ram

	.bss : ALIGN(4)
	{  
		*(.sbss)
		*(.sbss.*)
		*(.bss)
		*(.bss.*)
	} > ram

	.stack : ALIGN(16)
	{
		*(.stack)
		. = . + 0xc00;
	} > ram



	PROVIDE(_bss_start =  ADDR(.bss));
	PROVIDE(_bss_size = SIZEOF(.bss));
	PROVIDE(_bss_end = _bss_start + _bss_size - 1);

	PROVIDE(_stack_start = ADDR(.stack) + SIZEOF(.stack));
	PROVIDE(_global_start = ADDR(.bss));


}


