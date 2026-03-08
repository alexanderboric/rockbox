/*
 * To be included by config/duro.h
 * Specific to the STM32U5 series architecture
 */

/* STM32U5_USBOTG_INSTANCE */
/* The U5 generally has one High-Speed OTG core and one Full-Speed only core */
#define STM32U5_USBOTG_INSTANCE_HS    0 /* OTG_HS (High Speed) */
#define STM32U5_USBOTG_INSTANCE_FS    1 /* OTG_FS (Full Speed) */

/* STM32U5_USBOTG_PHY */
/* The U5A5 is unique because it often includes an internal High-Speed PHY 
   which saves space on the board compared to the H7's external ULPI requirement. */
#define STM32U5_USBOTG_PHY_INTERNAL_HS  0 /* Internal HS PHY (Embedded) */
#define STM32U5_USBOTG_PHY_EXTERNAL_ULPI 1 /* External ULPI PHY */
#define STM32U5_USBOTG_PHY_INTERNAL_FS  2 /* Internal FS PHY */

/* STM32U5_USBOTG_CLKSEL */
/* The U5 clock tree is very flexible but prefers the 48MHz clock from 
   either the HSI48 or a specific PLL output for USB stability. */
#define STM32U5_USBOTG_CLKSEL_PLL1Q     1 /* PLL1 Q-output */
#define STM32U5_USBOTG_CLKSEL_PLL2Q     2 /* PLL2 Q-output */
#define STM32U5_USBOTG_CLKSEL_HSI48     3 /* Internal 48MHz Oscillator */
#define STM32U5_USBOTG_CLKSEL_MSIK      4 /* Multispeed Internal (Kernel) clock */

/* Power Scaling (Specific to U5) */
/* Because the U5 is ultra-low power, it uses "Voltage Scaling" to 
   reach its 160MHz max clock. */
#define STM32_PWR_REGULATOR_VOS1        1 /* Max performance (up to 160MHz) */
#define STM32_PWR_REGULATOR_VOS2        2 /* Medium performance (up to 110MHz) */
#define STM32_PWR_REGULATOR_VOS3        3 /* Low power (up to 25MHz) */