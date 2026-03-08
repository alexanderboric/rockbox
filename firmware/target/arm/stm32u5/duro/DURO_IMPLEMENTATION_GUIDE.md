# Rockbox STM32U5A5 Duro Port - Implementation Guide

## Quick Start

This document provides step-by-step instructions to continue the Duro port implementation from the framework created.

## Current Status: Framework Complete ✓

The following are complete and ready to use:
- ✓ Build system integration
- ✓ Hardware configuration files  
- ✓ Memory layout and CPU definitions
- ✓ Device driver structure and headers
- ✓ Bootloader framework

## What Needs Implementation (Hardware Integration)

### Phase 1: Essential System Initialization (CRITICAL)

**1. Clock Initialization - START HERE**

File: `firmware/target/arm/stm32u5/duro/clock-duro.c`

Tasks:
```c
void duro_clock_init(void)
{
    // 1. Configure HSI (16 MHz) or HSE (external crystal)
    //    - Check your hardware schematic for crystal frequency
    //    - Default in duro.h: STM32_HSE_FREQ 16000000
    
    // 2. Initialize PLL1 for main system clock (target: 160 MHz)
    //    Formula: FVCO = (HSE/M) * N
    //    PLL1 Output = FVCO / P
    
    // 3. Configure PLL3 for peripherals
    //    Use for: LTDC (40 MHz), audio clocks (12.288 MHz)
    
    // 4. Set clock distribution to peripherals
    //    - SDMMC1, I2C, SAI1, LTDC clock sources
    
    // 5. Configure voltage scaling for 160 MHz operation
    //    - STM32U5 requires proper VOS setting
    
    // Reference: STM32U5 Reference Manual, Clock tree section
}
```

**2. GPIO Configuration**

File: `firmware/target/arm/stm32u5/duro/button-duro.c`

Tasks:
```c
void button_init_duro(void)
{
    // 1. Identify all GPIO pins from your hardware schematic
    //    Edit button-duro.h with actual port/pin assignments
    
    // 2. Configure pin modes:
    //    - Input with pull-up for buttons
    //    - Output for power/backlight control
    //    - Alternate function for peripheral pins
    
    // 3. Set appropriate speeds and drive strengths
    
    // Example pin mapping (ADJUST FOR YOUR HARDWARE):
    // GPIO_BUTTON_POWER   = GPIOF[0]
    // GPIO_BUTTON_HOLD    = GPIOF[1]
    // etc.
}
```

### Phase 2: Core Peripherals (HIGH PRIORITY)

**3. I2C Bus Implementation**

File: `firmware/target/arm/stm32u5/duro/i2c-duro.c`

Purpose: Communicate with audio codec and power management IC

Tasks:
```c
void i2c_init_duro(void)
{
    // 1. Configure I2C1 GPIO pins (SDA/SCL typically on PB6/PB7)
    // 2. Initialize I2C controller:
    //    - Clock speed: 400 kHz typical
    //    - Enable interrupt handling
    // 3. Test with codec detection (address 0x18)
    
    // Reference: Echo Player i2c-echoplayer.c
}

// Implement basic I2C functions:
int i2c_write_byte(uint8_t address, uint8_t reg, uint8_t data);
int i2c_read_byte(uint8_t address, uint8_t reg);
```

**4. Display (LTDC) Initialization**

File: `firmware/target/arm/stm32u5/duro/lcd-duro.c`

Tasks:
```c
void lcd_init_duro(void)
{
    // 1. Configure GPIO pins for LTDC interface
    //    - Data pins D0-D15 (parallel interface)
    //    - Control signals: HSYNC, VSYNC, DE, CLK
    
    // 2. Calculate timing parameters:
    //    - Display resolution: 480x360
    //    - Pixel clock: typically 40 MHz from PLL3
    //    - HSYNC, VSYNC timing from LCD datasheet
    
    // 3. Initialize LTDC peripheral:
    //    - Set resolution
    //    - Configure pixel format (RGB565)
    //    - Set framebuffer address
    
    // 4. Enable display output
}
```

**5. Audio Codec Interface**

Files: `firmware/target/arm/stm32u5/duro/audiohw-duro.c` and `.../pcm-duro.c`

Tasks:
```c
void audiohw_init_duro(void)
{
    // 1. Initialize codec via I2C (AIC34xx example)
    //    - Codec address typically 0x18
    //    - Power up codec
    //    - Configure audio routing
    
    // 2. Initialize SAI1 for audio data:
    //    - Configure as I2S or similar format
    //    - Set sample rate (44.1 kHz)
    //    - Configure DMA for PCM transfer
    
    // 3. Set initial volume levels
}

void pcm_init_duro(void)
{
    // 1. Set up DMA channels for SAI1
    // 2. Configure circular buffers for audio
    // 3. Enable interrupts for PCM callbacks
}
```

### Phase 3: Storage (MEDIUM PRIORITY)

**6. SD/MMC Card Support**

File: `firmware/target/arm/stm32u5/duro/sdmmc-duro.c`

Tasks:
```c
void sdmmc_init_duro(void)
{
    // 1. Configure GPIO pins for SDMMC1:
    //    - CMD, CLK, DAT0-3 pins
    //    - Check datasheet for pin assignments
    
    // 2. Initialize SDMMC controller:
    //    - Set clock divider for 400 kHz initialization
    //    - Configure data bus width
    
    // 3. Implement card detection and initialization
    
    // 4. Set up for faster operation (up to 50 MHz)
}
```

### Phase 4: USB (LOW PRIORITY)

**7. USB Device Implementation**

File: `firmware/target/arm/stm32u5/duro/usb-duro.c`

Note: Can be implemented after basic device functionality works

## Testing Strategy

### Level 1: Hardware Verification (No Software)
```bash
# Use oscilloscope/logic analyzer to verify:
- CPU clock frequency (check with oscilloscope)
- GPIO outputs toggle (LED blink test)
- I2C bus signals (measure SDA/SCL waveforms)
```

### Level 2: Minimal Bootloader Test
```c
// In bootloader duro.c, before feature additions:
int main(void)
{
    duro_clock_init();      // Test clock setup
    system_init();          // Test basic system
    
    // Blink LED to prove code is running
    while(1) {
        toggle_led();
        delay(100000);
    }
}
```

### Level 3: Peripheral Testing
```bash
# Test each subsystem individually:
1. Clock generation ✓
2. GPIO/LED blink ✓
3. I2C codec detection
4. Display initialization and pixel output
5. Audio codec operation
6. SD card detection
7. Full integration
```

## Important Files to Modify

### For Clock Configuration
- `firmware/target/arm/stm32u5/duro/clock-duro.c` - Clock initialization
- `firmware/export/config/duro.h` - Adjust STM32_HSE_FREQ if needed

### For GPIO Mapping
- `firmware/target/arm/stm32u5/duro/button-duro.h` - Button GPIO assignments
- `firmware/target/arm/stm32u5/duro/lcd-duro.c` - LTDC pin configuration
- `firmware/target/arm/stm32u5/duro/sdmmc-duro.c` - SDMMC pin configuration

### For I2C Devices
- `firmware/target/arm/stm32u5/duro/i2c-duro.h` - Device addresses
- Adjust addresses based on your hardware

## Resources Needed

1. **Hardware Documentation:**
   - STM32U5A5 Reference Manual
   - Your Duro hardware schematic
   - LCD datasheet (for timing parameters)
   - Audio codec datasheet (for register setup)

2. **Reference Code:**
   - Echo Player implementation: `firmware/target/arm/stm32/echoplayer/`
   - STM32H7 drivers: `firmware/target/arm/stm32/`
   - CubeMX or STM32 HAL examples

3. **Tools:**
   - ARM Cortex-M debugger (J-Link, ST-Link, etc.)
   - Oscilloscope for clock verification
   - Logic analyzer for I2C/SPI debugging

## Build & Test Commands

```bash
# Configure for Duro (select option 271)
./tools/configure

# Build bootloader
make bootloader

# Build firmware
make

# Clean build if issues arise
make distclean
./tools/configure    # Select 271 again
make

# Verify compilation
arm-none-eabi-nm build/duro/rockbox.elf | grep clock_init
```

## Common Pitfalls

1. **Clock Configuration**
   - Wrong PLL divisors will cause system to crash
   - Always verify with oscilloscope
   - Check RCC clock enable registers

2. **GPIO Configuration**
   - Forgetting to enable GPIO clock in RCC
   - Wrong alternate function numbers
   - Missing pullup/pulldown configuration

3. **I2C Issues**
   - SDA/SCL pullup resistors may be missing
   - Bus clock too fast for long traces
   - Codec address wrong (check schematic)

4. **Display Issues**
   - LTDC timing must match LCD datasheet exactly
   - Framebuffer address alignment critical
   - Check pixel clock frequency

## Additional Notes

- **Memory layout:** Easily adjustable in `cpu-stm32u5a5.h`
- **Device IDs:** Configured in `config/duro.h` (USB VID/PID)
- **Default settings:** Audio sample rate, LCD resolution, etc. in `config/duro.h`
- **Debug support:** Can be enabled once clocks are working

## Next Steps

1. Review your hardware schematic
2. Gather datasheets (STM32U5, LCD, codec, PMIC)
3. Start with `clock_duro_init()` - most critical
4. Test clock with oscilloscope before moving on
5. Implement GPIO configuration based on your schematic
6. Test each peripheral individually
7. Integrate into complete system

## Support & Questions

When implementing, refer to:
- STM32U5 Reference Manual (most detailed technical info)
- Echo Player reference: Shows how STM32H743 implementation works
- Rockbox IRC/forums: Community can help troubleshoot

Good luck with the implementation! Start with clocks - that's the foundation everything else depends on.
