/*
 * STM32U5A5 Register Definitions for Rockbox
 * This file provides base definitions for the STM32U5 series processor
 */

#ifndef __STM32U5A5_H__
#define __STM32U5A5_H__

#include <stdint.h>

/* Memory layout for STM32U5A5 */
#define STM32_ITCM_BASE      0x00000000  /* Instruction TCM */
#define STM32_ITCM_SIZE      (64 * 1024) /* 64 KB */

#define STM32_DTCM_BASE      0x20000000  /* Data TCM */
#define STM32_DTCM_SIZE      (64 * 1024) /* 64 KB */

#define STM32_SRAM_BASE      0x20010000  /* Main SRAM */
#define STM32_SRAM_SIZE      (2 * 1024 * 1024) /* 2  MB */

#define STM32_PSRAM_BASE     0x90000000  /* External PSRAM */
#define STM32_PSRAM_SIZE     (8 * 1024 * 1024) /* 8 MB - Duro external memory */

#define STM32_SRAM4_BASE     0x28000000  /* SRAM4 (Backup) */
#define STM32_SRAM4_SIZE     (64 * 1024) /* 64 KB */

#define STM32_PERIPH_BASE    0x40000000  /* Peripheral base */

/* Peripheral addresses */
#define STM32_GPIOA_BASE     (STM32_PERIPH_BASE + 0x02000000)
#define STM32_GPIOB_BASE     (STM32_PERIPH_BASE + 0x02000400)
#define STM32_GPIOC_BASE     (STM32_PERIPH_BASE + 0x02000800)
#define STM32_GPIOD_BASE     (STM32_PERIPH_BASE + 0x02000C00)
#define STM32_GPIOE_BASE     (STM32_PERIPH_BASE + 0x02001000)
#define STM32_GPIOF_BASE     (STM32_PERIPH_BASE + 0x02001400)
#define STM32_GPIOG_BASE     (STM32_PERIPH_BASE + 0x02001800)
#define STM32_GPIOH_BASE     (STM32_PERIPH_BASE + 0x02001C00)
#define STM32_GPIOI_BASE     (STM32_PERIPH_BASE + 0x02002000)

#define STM32_SYSCFG_BASE    (STM32_PERIPH_BASE + 0x01000000)
#define STM32_RCC_BASE       (STM32_PERIPH_BASE + 0x02000800)
#define STM32_PWR_BASE       (STM32_PERIPH_BASE + 0x02004800)
#define STM32_RTC_BASE       (STM32_PERIPH_BASE + 0x02004400)

#define STM32_I2C1_BASE      (STM32_PERIPH_BASE + 0x01005400)
#define STM32_I2C2_BASE      (STM32_PERIPH_BASE + 0x01005800)
#define STM32_I2C3_BASE      (STM32_PERIPH_BASE + 0x01005C00)

#define STM32_SDMMC1_BASE    (STM32_PERIPH_BASE + 0x01104C00)

#define STM32_SAI1_BASE      (STM32_PERIPH_BASE + 0x01004400)

#define STM32_LTDC_BASE      (STM32_PERIPH_BASE + 0x03001000)

#define STM32_OTG_FS_BASE    (STM32_PERIPH_BASE + 0x03000000)
#define STM32_OTG_HS_BASE    (STM32_PERIPH_BASE + 0x03100000)

/* Clock frequencies */
#define STM32_HSI_FREQ       16000000  /* 16 MHz internal oscillator */
#define STM32_LSI_FREQ       32000     /* 32 kHz low-speed oscillator */

/* USB OTG Instance Selection */
#define STM32U5_USBOTG_INSTANCE_FS     0   /* Full-Speed (FS) instance */
#define STM32U5_USBOTG_INSTANCE_HS     1   /* High-Speed (HS) instance (primary) */

/* USB PHY Type Selection */
#define STM32U5_USBOTG_PHY_INTERNAL_FS 0   /* Internal Full-Speed PHY */
#define STM32U5_USBOTG_PHY_INTERNAL_HS 1   /* Internal High-Speed PHY (primary) */
#define STM32U5_USBOTG_PHY_EXTERNAL    2   /* External PHY */

/* USB Clock Source Selection */
#define STM32U5_USBOTG_CLKSEL_HSI48    0   /* HSI48 oscillator (primary for FS) */
#define STM32U5_USBOTG_CLKSEL_PLL3Q    1   /* PLL3Q output (for HS operation) */
#define STM32U5_USBOTG_CLKSEL_EXTERNAL 2   /* External clock source */

#endif /* __STM32U5A5_H__ */
