#ifndef _CPU_STM32U5A5_H_
#define _CPU_STM32U5A5_H_

#include <stdint.h>

/* CPU identification */
#define CPU_STM32U5A5
#define CPU_ARM
#define CPU_ARM_CM33
#define MEMORYSIZE 2  /* 2 MB SRAM */

/* Memory Base Addresses for STM32U5A5/U575 */
#define FLASH_BASE        0x08000000  /* 256 KB Flash */
#define ITCM_BASE         0x00000000  /* 64 KB Instruction TCM */
#define DTCM_BASE         0x20000000  /* 64 KB Data TCM */
#define SRAM1_BASE        0x20010000  /* 1.5 MB SRAM1 */
#define SRAM2_BASE        0x20040000  /* 256 KB SRAM2 */
#define SRAM3_BASE        0x200B0000  /* 512 KB SRAM3 */
#define SRAM4_BASE        0x28000000  /* 64 KB SRAM4 (non-volatile) */

/* Peripheral Base Addresses */
#define APB1_BASE         0x40000000
#define APB2_BASE         0x44000000
#define AHB1_BASE         0x42000000
#define AHB2_BASE         0x42020000
#define AHB3_BASE         0x46000000

/* GPIO Peripherals */
#define GPIOA_BASE        (AHB2_BASE + 0x0000)
#define GPIOB_BASE        (AHB2_BASE + 0x0400)
#define GPIOC_BASE        (AHB2_BASE + 0x0800)
#define GPIOD_BASE        (AHB2_BASE + 0x0C00)
#define GPIOE_BASE        (AHB2_BASE + 0x1000)
#define GPIOF_BASE        (AHB2_BASE + 0x1400)
#define GPIOG_BASE        (AHB2_BASE + 0x1800)
#define GPIOH_BASE        (AHB2_BASE + 0x1C00)
#define GPIOI_BASE        (AHB2_BASE + 0x2000)

/* Core Peripherals */
#define RCC_BASE          (AHB3_BASE + 0x0C00)    /* Reset and Clock Control */
#define PWR_BASE          (AHB3_BASE + 0x0800)    /* Power Control */
#define SYSCFG_BASE       (APB2_BASE + 0x0000)    /* System Configuration */
#define RTC_BASE          (APB1_BASE + 0x2800)    /* Real-Time Clock */

/* I2C Peripherals */
#define I2C1_BASE         (APB1_BASE + 0x5400)
#define I2C2_BASE         (APB1_BASE + 0x5800)
#define I2C3_BASE         (APB1_BASE + 0x5C00)

/* SPI Peripherals */
#define SPI1_BASE         (APB2_BASE + 0x3000)
#define SPI2_BASE         (APB1_BASE + 0x3800)
#define SPI3_BASE         (APB1_BASE + 0x3C00)

/* USART Peripherals */
#define USART1_BASE       (APB2_BASE + 0x3800)
#define USART2_BASE       (APB1_BASE + 0x4400)
#define USART3_BASE       (APB1_BASE + 0x4800)

/* USB OTG Peripherals */
#define OTG_FS_BASE       (AHB3_BASE + 0x0000)    /* USB OTG Full-Speed */
#define OTG_HS_BASE       (AHB3_BASE + 0x100000)  /* USB OTG High-Speed */

/* SD/MMC */
#define SDMMC1_BASE       (AHB1_BASE + 0x4C00)
#define SDMMC2_BASE       (AHB1_BASE + 0x5000)

/* Display Controller */
#define LTDC_BASE         (AHB3_BASE + 0x1000)    /* LTDC (LCD interface) */

/* Audio SAI */
#define SAI1_BASE         (APB2_BASE + 0x4400)

/* DMA */
#define DMA1_BASE         (AHB1_BASE + 0x0000)
#define DMA2_BASE         (AHB1_BASE + 0x0400)
#define DMAMUX1_BASE      (AHB1_BASE + 0x0800)

/* Clock frequencies */
#define STM32_HSI_FREQ    16000000  /* 16 MHz internal oscillator */
#define STM32_LSI_FREQ    32000     /* 32 kHz low-speed oscillator */

#endif /* _CPU_STM32U5A5_H_ */