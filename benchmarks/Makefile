# Directories
QStack := QStack
QList := QList
QLinkedList := QLinkedList
qt := qt


# Clean
ifneq ($(filter clean,$(MAKECMDGOALS)),)
        TARGET := clean
endif
clean: all

# Make them all
all: $(QStack) $(QList) $(QLinkedList) $(qt)

$(QStack) $(QList) $(QLinkedList) $(qt):
	$(MAKE) --directory=$@ $(TARGET)

#Make only STL directories
stl: $(QStack) $(QList) $(QLinkedList)

# Make each directory
algorithm: $(algorithm)
QStack := $(QStack)
QList := $(QList)
QLinkedList := $(QLinkedList)
qt := $(qt)

# Allow parallel make

.PHONY: all $(QStack) $(QList) $(QLinkedList) $(qt)
