CC=clang++
CFLAGS=-Wall -std=c++11 -g

main: Point2D.o main.o
	$(CC) $(CFLAGS) $^ -o main

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean: 
	rm -rf *.o
	rm -rf main
