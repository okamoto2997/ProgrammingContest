CXXFLAGS=-std=gnu++17 -Wall -Wextra -O2

ALL ?= ${foreach dir,${shell find -mindepth 1 -maxdepth 1 -type d},${dir}/Main}

all: ${ALL}
clean:
	rm -rf ${ALL} *.o
	