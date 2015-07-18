# Directories
QStack := QStack
QList := QList
QLinkedList := QLinkedList
qt := qt
QQueue := QQueue


# Clean
ifneq ($(filter clean,$(MAKECMDGOALS)),)
        TARGET := clean
endif
clean: all

# Make them all
all: $(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue)

$(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue):
	$(MAKE) --directory=$@ $(TARGET)

#Make only STL directories
stl: $(QStack) $(QList) $(QLinkedList) $(QQueue)

# Make each directory
algorithm: $(algorithm)
QStack := $(QStack)
QList := $(QList)
QLinkedList := $(QLinkedList)
qt := $(qt)
QQueue := $(QQueue)

# Allow parallel make

.PHONY: all $(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue)
