# Duro (STM32U5A5) Device-Specific Build Rules
#
# This file handles build configuration specific to the Duro device.

# Compile the STM32U5 startup code and add to object list
STARTUP_OBJ := $(BUILDDIR)/target/arm/stm32u5/crt0-stm32u5.o
OBJ += $(STARTUP_OBJ)

$(STARTUP_OBJ): $(FIRMDIR)/target/arm/stm32u5/crt0-stm32u5.S
	$(SILENT)mkdir -p $(dir $@)
	$(call PRINTS,AS $<)$(AS) $(ASFLAGS) $< -o $@

# Duro uses button-target.h which exists in the source tree, not the build tree.
# Tell Make where to find it and that it doesn't need to be generated.
$(BUILDDIR)/button-target.h: $(FIRMDIR)/target/$(CPU)/$(MANUFACTURER)/$(MODEL)/button-target.h
	@true

$(BUILDDIR)/button-target.h: $(FIRMDIR)/target/$(CPU)/$(MANUFACTURER)/button-target.h
	@true
