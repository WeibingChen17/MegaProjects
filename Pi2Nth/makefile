CC=g++
CFLAGS=-lgmp -lgmpxx
DEBUG=

main: main.o pi2nth.o
	$(CC) $^ $(CFLAGS) -o main

debug: main.o pi2nth.o
	$(CC) $^ $(CFLAGS) -o main

%.o: %.cc
	$(CC) $(DEBUG) -c $< -o $@ 

.PHONY: clean
clean: 
	rm -rf *.o
	rm main
