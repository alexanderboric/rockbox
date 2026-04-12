#include "cpu.h"

ENTRY(crt0_start)
OUTPUT_FORMAT(elf32-littlearm)
OUTPUT_ARCH(arm)

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

        *(.init*);
        *(.text*);
        *(.rodata*);
    } > SRAM :sdram

    .data :
    {
        _databegin = .;
        *(.data*);
        *(.sdata*);
        _dataend = .;
    } > SRAM :sdram

    _datacopy = LOADADDR(.data);

    .bss ADDR(.data) + SIZEOF(.data) :
    {
        _bssbegin = .;
        *(.bss*);
        *(.sbss*);
        *(COMMON);
        _bssend = .;
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
    /*
     * Audio, codec, and plugin buffers in external PSRAM (OctoSPI at 0x90000000).
     * The total PSRAM available is STM32_PSRAM_SIZE (8 MB).
     * Layout: [audio buffer][codec buffer][plugin buffer]
     * Sizes are from config: CODEC_SIZE=0x80000, PLUGIN_BUFFER_SIZE=0x100000
     */
    audiobuffer = ORIGIN(PSRAM);
    audiobufend = ORIGIN(PSRAM) + LENGTH(PSRAM) - CODEC_SIZE - PLUGIN_BUFFER_SIZE;
    codecbuf    = audiobufend;
    pluginbuf   = codecbuf + CODEC_SIZE;
}

EXTERN(__vectors_arm);
EXTERN(__vectors_platform);
ASSERT(DEFINED(__vectors_arm), "ARM exception vectors are not defined.");
ASSERT(DEFINED(__vectors_platform), "Platform exception vectors are not defined.");
