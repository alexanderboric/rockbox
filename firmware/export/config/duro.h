/*
 * This config file is for the Duro (STM32U5A5)
 */

/* Pull in SoC-specific defines - You will need to create this file later */
#include "stm32u5-config.h"
/* RoLo-related defines */
#define MODEL_NAME      "Duro"
#define MODEL_NUMBER    271
#define BOOTFILE_EXT    "duro"
#define BOOTFILE        "rockbox." BOOTFILE_EXT
#define BOOTDIR         "/.rockbox"

/* CPU defines */
#define CPU_STM32U5A5
#define CONFIG_CPU STM32U5A5
#define STM32_HSE_FREQ      16000000  /* Common for U5 dev boards; check your crystal! */
#define CPU_FREQ            160000000 /* U5 max is 160MHz */

#ifndef SIMULATOR
#define TIMER_FREQ          STM32_HSE_FREQ
#endif

/* Kernel defines */
#define INCLUDE_TIMEOUT_API
#define HAVE_SEMAPHORE_OBJECTS

/* * Buffer for plugins and codecs. 
 * STM32U5A5 has ~2.5MB SRAM. We use 1MB for plugins to leave 
 * plenty for the system and audio buffers.
 */
#define PLUGIN_BUFFER_SIZE  0x100000 /* 1 MiB */
#define CODEC_SIZE          0x80000  /* 512 KiB */
#define AUDIOBUFFERSIZE     (8 * 1024 * 1024 - PLUGIN_BUFFER_SIZE - CODEC_SIZE) /* Rest of PSRAM */

/* LCD defines */
#define CONFIG_LCD          LCD_DURO
#define LCD_WIDTH           480
#define LCD_HEIGHT          360
#define LCD_DEPTH           16
#define LCD_PIXELFORMAT     RGB565
#define HAVE_LCD_COLOR
#define HAVE_LCD_BITMAP
#define HAVE_LCD_ENABLE
#define HAVE_LCD_SHUTDOWN
/* U5 has internal SRAM that can be used for the framebuffer */
#define IRAM_LCDFRAMEBUFFER __attribute__((section(".framebuffer")))

/* Backlight defines */
#define HAVE_BACKLIGHT
#define HAVE_BACKLIGHT_BRIGHTNESS
#define MIN_BRIGHTNESS_SETTING      1
#define MAX_BRIGHTNESS_SETTING      100
#define BRIGHTNESS_STEP             5
#define DEFAULT_BRIGHTNESS_SETTING  70
#define CONFIG_BACKLIGHT_FADING     BACKLIGHT_FADING_SW_SETTING

/* Codec / audio hardware defines */
#define HW_SAMPR_CAPS   SAMPR_CAP_44
#define HAVE_SW_TONE_CONTROLS
#define HAVE_SW_VOLUME_CONTROL

#ifndef SIMULATOR
/* U5 usually uses 16-bit or 24-bit PCM; starting with 16 for stability */
#define PCM_NATIVE_BITDEPTH 16
#endif

/* Button defines */
#define CONFIG_KEYPAD DURO_PAD

/* Storage defines */
#define CONFIG_STORAGE  STORAGE_SD
#define HAVE_HOTSWAP
#define HAVE_MULTIVOLUME
#define STORAGE_WANTS_ALIGN

/* RTC settings */
#define CONFIG_RTC      RTC_STM32U5
#define HAVE_RTC_ALARM

/* Power management */
#define CONFIG_BATTERY_MEASURE VOLTAGE_MEASURE
#define CONFIG_CHARGING        CHARGING_MONITOR
#define HAVE_SW_POWEROFF

/* Battery specs - Adjust these to your physical battery */
#define BATTERY_CAPACITY_DEFAULT 1000
#define BATTERY_CAPACITY_MIN     500
#define BATTERY_CAPACITY_MAX     2000
#define BATTERY_CAPACITY_INC     50

/* USB support - U5 uses a different OTG core than H7 */
#ifndef SIMULATOR
#define CONFIG_USBOTG USBOTG_STM32U5
#define HAVE_USBSTACK
#define USB_NUM_ENDPOINTS   6
#define USB_VENDOR_ID  0x6666 
#define USB_PRODUCT_ID 0xD050 /* Unique PID for Duro */
#define USB_DEVBSS_ATTR __attribute__((aligned(32)))
#define HAVE_USB_POWER
#define HAVE_USB_CHARGING_ENABLE
#endif

/* Rockbox capabilities */
#define HAVE_FAT16SUPPORT
#define HAVE_ALBUMART
#define HAVE_TAGCACHE
#define HAVE_VOLUME_IN_LIST
#define HAVE_QUICKSCREEN
#define HAVE_HOTKEY
#define HAVE_ELF

#define STM32U5_USBOTG_INSTANCE   STM32U5_USBOTG_INSTANCE_HS
#define STM32U5_USBOTG_PHY        STM32U5_USBOTG_PHY_INTERNAL_HS
#define STM32U5_USBOTG_CLKSEL     STM32U5_USBOTG_CLKSEL_HSI48

/* This manually injects VOLUME into the sound settings enum */
/* Audio: Dummy codec stub until real driver is ready */
#define CONFIG_CODEC    SWCODEC
#define HAVE_DUMMY_CODEC
#define AUDIOHW_CAPS    0