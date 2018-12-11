OS := $(shell uname -s)
ifeq ($(OS), Linux)
	CC=g++
endif
ifeq ($(OS), Darwin) 
	CC=clang++
endif

CFLAGS=-Wall -std=c++11

main: Point2D.o main.o
	$(CC) $(CFLAGS) $^ -o main

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean: 
	rm -rf *.o
	rm -rf main
