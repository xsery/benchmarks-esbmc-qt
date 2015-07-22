# Directories
QStack := QStack
QList := QList
QLinkedList := QLinkedList
qt := qt
QQueue := QQueue
QMap := QMap
QSet := QSet

# Clean
ifneq ($(filter clean,$(MAKECMDGOALS)),)
        TARGET := clean
endif
clean: all

# Make them all
all: $(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue) $(QMap) $(QSet)

$(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue) $(QMap) $(QSet):
	$(MAKE) --directory=$@ $(TARGET)

#Make only STL directories
stl: $(QStack) $(QList) $(QLinkedList) $(QQueue) $(QMap) $(QSet)

# Make each directory
algorithm: $(algorithm)
QStack := $(QStack)
QList := $(QList)
QLinkedList := $(QLinkedList)
qt := $(qt)
QQueue := $(QQueue)
QMap := $(QMap)
QSet := $(QSet)

# Allow parallel make

.PHONY: all $(QStack) $(QList) $(QLinkedList) $(qt) $(QQueue) $(QMap) $(QSet)
