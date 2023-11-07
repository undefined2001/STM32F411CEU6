ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx): ORIGIN =0x08000000, LENGTH = 512K
	SRAM(rwx): ORIGIN =0x20000000, LENGTH = 128K
}

SECTIONS
{
	.text :
	{
		*(.vector)
		*(.text)
		*(.init)
		*(.fini)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		__END_OF_TEXT = .;
	}>FLASH

	__START_FLASH_DATA = LOADADDR(.data);

	.data :
	{
		__START_SRAM_DATA = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		__END_SRAM_DATA = .;
	}>SRAM AT>FLASH

	.bss :
	{
		_sbss = .;
		__START_BSS = _sbss;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
		__END_BSS = _ebss;
	}>SRAM


}