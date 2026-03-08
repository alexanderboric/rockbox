/*
 * STM32U5A5 Interrupt Vector Table
 *
 * This file is intentionally minimal as a placeholder.
 * The full vector table will define exception handlers for:
 * - NMI, HardFault, MemManage, BusFault, UsageFault
 * - SVC, DebugMon, PendSV, SysTick
 * - All peripheral interrupts specific to STM32U5A5
 *
 * TODO: Implement full vector table for STM32U5A5
 */

extern void __main(void);

/* Minimal interrupt vector table */
__attribute__((section(".vectors"))) int (*vector_table[])(void) = {
    0,  /* Stack pointer - will be set by loader */
    __main  /* Reset vector */
    /* Additional vectors would go here */
};
