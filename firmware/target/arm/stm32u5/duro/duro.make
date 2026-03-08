# Duro (STM32U5A5) Device-Specific Build Rules
#
# This file handles build configuration specific to the Duro device.

# Duro uses button-target.h which exists in the source tree, not the build tree.
# Tell Make where to find it and that it doesn't need to be generated.
$(BUILDDIR)/button-target.h: $(FIRMDIR)/target/$(CPU)/$(MANUFACTURER)/$(MODEL)/button-target.h
	@true

$(BUILDDIR)/button-target.h: $(FIRMDIR)/target/$(CPU)/$(MANUFACTURER)/button-target.h
	@true
