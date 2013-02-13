#P = program_name
OBJECTS =
CFLAGS = -g -Wall -O3 -std=gnu11
CXXFLAGS= -g -Wall -O3 -std=gnu++11
LDLIBS = -lm
CC = gcc
CXX = g++

all: test
	
test: algorithmns.o

clean:
	rm -f test

$(P): $(OBJECTS)
