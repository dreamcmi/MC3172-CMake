

OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv",
	      "elf32-littleriscv")
OUTPUT_ARCH(riscv)
ENTRY(thread_start)

MEMORY
{
    CODE_SPACE (x)  : ORIGIN = 0x00000010, LENGTH =  65520
    DATA_SPACE (rw) : ORIGIN = 0x20000010, LENGTH =  61248
}


SECTIONS
{
  . = 0x00000010;
  .text           :
  {
    *(.text.thread_start)
    *(.text)
    *(.text.unlikely .text.*_unlikely .text.unlikely.*)
    *(.text.exit .text.exit.*)
    *(.text.startup .text.startup.*)
    *(.text.hot .text.hot.*)
  }
  
  
  
  
  . = 0x20000010;
  .rodata         : { *(.rodata .rodata.* .gnu.linkonce.r.*) } > DATA_SPACE
  .rodata1        : { *(.rodata1) } > DATA_SPACE
  .srodata          :
  {
    *(.srodata.cst16) *(.srodata.cst8) *(.srodata.cst4) *(.srodata.cst2) *(.srodata .srodata.*)
  } > DATA_SPACE
  .data           :
  {
    *(.data .data.* .gnu.linkonce.d.*)
    SORT(CONSTRUCTORS)
  } > DATA_SPACE
  .data1          : { *(.data1) } > DATA_SPACE
  .sdata          :
  {
    *(.sdata .sdata.* .gnu.linkonce.s.*)
  } > DATA_SPACE
  .sdata2         :
  {
    *(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
  } > DATA_SPACE
  
    .bss            :
  {
   *(.dynbss)
   *(.bss .bss.* .gnu.linkonce.b.*)
  } > DATA_SPACE
  .sbss           :
  {
    *(.dynsbss)
    *(.sbss .sbss.* .gnu.linkonce.sb.*)
    *(.scommon)
  } > DATA_SPACE
  .sbss2          : { *(.sbss2 .sbss2.* .gnu.linkonce.sb2.*) } > DATA_SPACE
  
  
  
 }
 

  
