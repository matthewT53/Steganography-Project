CC=g++
CFLAGS=-c

all: stegProject

stegProject: main.o steg.o file.o format.o bits.o sha_256.o deSteg.o lodepng.o
	$(CC) main.o steg.o file.o format.o bits.o sha_256.o deSteg.o lodepng.o -o steg

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

steg.o: steg.cpp
	$(CC) $(CFLAGS) steg.cpp

format.o: format.cpp
	$(CC) $(CFLAGS) format.cpp

file.o: file.cpp
	$(CC) $(CFLAGS) file.cpp

bits.o: bits.cpp
	$(CC) $(CFLAGS) bits.cpp

sha_256.o: sha_256.c
	$(CC) $(CFLAGS) sha_256.c

deSteg.o: deSteg.cpp
	$(CC) $(CFLAGS) deSteg.cpp

lodepng.o: lodepng.cpp
	$(CC) $(CFLAGS) lodepng.cpp

clean:
	rm *.o steg
