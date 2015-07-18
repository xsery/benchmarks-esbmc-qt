# Directories
QStack := QStack
QList := QList
QLinkedList := QLinkedList
qt := qt
QQueue := QQueue
QMap := QMap

# Clean
ifneq ($(filter clean,$(MAKECMDGOALS)),)
        TARGET := clean
endif
clean: all

# Make them all
all: $(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue) $(QMap)

$(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue) $(QMap):
	$(MAKE) --directory=$@ $(TARGET)

#Make only STL directories
stl: $(QStack) $(QList) $(QLinkedList) $(QQueue) $(QMap)

# Make each directory
algorithm: $(algorithm)
QStack := $(QStack)
QList := $(QList)
QLinkedList := $(QLinkedList)
qt := $(qt)
QQueue := $(QQueue)
QMap := $(QMap)

# Allow parallel make

.PHONY: all $(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue) $(QMap)
