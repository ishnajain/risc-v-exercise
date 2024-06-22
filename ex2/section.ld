MEMORY
{
  rom (irx!wa): ORIGIN = 0x1000, LENGTH = 1K
  ram (arwx!i): ORIGIN = 0x80000000, LENGTH = 1K
}

SECTIONS
{
  .text : ALIGN(4)
  {
    KEEP(*(.text.*))
    . = ALIGN(8);
  } > rom AT > rom

  .rodata : ALIGN(4)
  {
  } > rom AT > rom

  .data : ALIGN(4)
  {
  } > ram
}
