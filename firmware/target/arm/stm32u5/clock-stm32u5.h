/*
 * STM32U5 Clock Support Header
 * Defines clock structures and initialization functions
 */

#ifndef __CLOCK_STM32U5_H__
#define __CLOCK_STM32U5_H__

#include <stdint.h>

/* Clock structure for managing peripheral clocks */
struct stm32_clock {
    uint32_t frequency;
    uint32_t en_reg;
    uint32_t en_bit;
    uint32_t lpen_reg;
    uint32_t lpen_bit;
};

/* Clock source definitions */
#define STM32_CLKSRC_HSI    0   /* Internal 16 MHz */
#define STM32_CLKSRC_LSI    1   /* Internal 32 kHz */
#define STM32_CLKSRC_HSE    2   /* External (typically 16 MHz) */
#define STM32_CLKSRC_LSE    3   /* External 32.768 kHz RTC */
#define STM32_CLKSRC_PLL1   4   /* PLL1 output */
#define STM32_CLKSRC_PLL2   5   /* PLL2 output */
#define STM32_CLKSRC_PLL3   6   /* PLL3 output */
#define STM32_CLKSRC_MSIK   7   /* Multispeed internal kernel clock */

#endif /* __CLOCK_STM32U5_H__ */
