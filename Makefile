CC := g++
FLAGS := -Isrc/ -std=c++17 -ggdb

SOURCE := $(shell find src/ -type f -name "*.cc")
INCLUDE := $(shell find src/ -type f -name "*.h")
TARGET := rc_run

$(TARGET): $(INCLUDE) $(SOURCE)
	$(CC) $(FLAGS) $(SOURCE) -o $@

.PHONY: clean
clean:
	rm $(TARGET)
