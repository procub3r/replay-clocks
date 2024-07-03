CC := g++
FLAGS := -Irepcl/ -Isim/ -std=c++17 -ggdb

SOURCE := sim/main.cc repcl/replay-clock.cc
INCLUDE := $(shell find sim/ repcl/ -type f -name "*.h")
TARGET := bin/sim

$(TARGET): $(INCLUDE) $(SOURCE)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(SOURCE) -o $@

.PHONY: clean
clean:
	rm $(TARGET)
