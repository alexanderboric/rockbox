#include "cpu.h"

ENTRY(crt0_start)
OUTPUT_FORMAT(elf32-littlearm)
OUTPUT_ARCH(arm)
STARTUP(target/arm/stm32u5/crt0-stm32u5.o)

MEMORY
{
    DTCM     (rw)  : ORIGIN = STM32_DTCM_BASE,     LENGTH = STM32_DTCM_SIZE
    ITCM     (rx)  : ORIGIN = STM32_ITCM_BASE,     LENGTH = STM32_ITCM_SIZE
    SRAM     (rw)  : ORIGIN = STM32_SRAM_BASE,     LENGTH = STM32_SRAM_SIZE
    PSRAM    (rwx) : ORIGIN = STM32_PSRAM_BASE,    LENGTH = STM32_PSRAM_SIZE
}

PHDRS
{
    itcm PT_LOAD;
    sdram PT_LOAD;
}

SECTIONS
{
    .itext :
    {
        KEEP(*(.vectors.arm));
        KEEP(*(.vectors.platform));
        *(.icode*);
    } > ITCM :itcm

    .stack (NOLOAD) : ALIGN(8)
    {
        irqstackbegin = .;
        . += 0x400;
        irqstackend = .;

        stackbegin = .;
        . += 0x2000;
        stackend = .;
    } > DTCM :NONE

    .framebuffer (NOLOAD) :
    {
        *(.framebuffer);
    } > SRAM :NONE

    .text :
    {
        loadaddress = .; /* only needed to keep ROLO happy */
        *(.text*);
        *(.rodata*);
    } > SRAM :sdram

    .data :
    {
        *(.data*);
        *(.sdata*);
    } > SRAM :sdram

    .bss ADDR(.data) + SIZEOF(.data) :
    {
        *(.bss*);
        *(.sbss*);
        *(COMMON);
    } > SRAM :NONE

    /* extra sections */
    .idata :
    {
        *(.irodata);
        *(.idata);
    } > ITCM :itcm

    .ibss (NOLOAD) :
    {
        *(.ibss);
    } > ITCM :NONE

    /* Buffer allocations in PSRAM */
    .audiobuffer (NOLOAD) :
    {
        audiobuffer = .;
        . += (8 * 1024 * 1024 - 0x100000 - 0x80000);  /* PSRAM size - plugin - codec buffers */
        audiobufend = .;
    } > PSRAM :NONE

    .codecbuf (NOLOAD) :
    {
        codecbuf = .;
        . += 0x80000;  /* CODEC_SIZE */
    } > PSRAM :NONE

    .pluginbuf (NOLOAD) :
    {
        pluginbuf = .;
        . += 0x100000;  /* PLUGIN_BUFFER_SIZE */
    } > PSRAM :NONE
}
