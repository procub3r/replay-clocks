CC=g++
FLAGS= -std=c++17 -g

SRC_DIR=src/
SRC_FILES= process.cc replay-clock.cc simulator.cc
SRC_FILES_FULL=$(addprefix $(SRC_DIR), $(SRC_FILES))
HDR_FILES= process.h  replay-clock.h  simulator.h  message.h  replay-config.h
HDR_FILES_FULL=$(addprefix $(SRC_DIR), $(HDR_FILES))

all: rc_run

rc_run: $(HDR_FILES_FULL) $(SRC_FILES_FULL)
	$(CC) $(FLAGS) $(SRC_FILES_FULL) -o rc_run

clean:
	rm rc_run