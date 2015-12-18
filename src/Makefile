CC=g++
CFLAGS=-Wall -c

all: stegProject

stegProject: stegDriver.o steg.o file.o format.o bits.o fileUtil.o sha_256.o deSteg.o
	$(CC) stegDriver.o steg.o file.o format.o bits.o fileUtil.o sha_256.o deSteg.o -o steg  

stegDriver.o: stegDriver.cpp
	$(CC) $(CFLAGS) stegDriver.cpp

steg.o: steg.cpp
	$(CC) $(CFLAGS) steg.cpp

format.o: format.cpp
	$(CC) $(CFLAGS) format.cpp

file.o: file.cpp
	$(CC) $(CFLAGS) file.cpp 

bits.o: bits.cpp
	$(CC) $(CFLAGS) bits.cpp

fileUtil.o: fileUtil.cpp
	$(CC) $(CFLAGS) fileUtil.cpp

sha_256.o: sha_256.c
	$(CC) $(CFLAGS) sha_256.c

deSteg.o: deSteg.cpp
	$(CC) $(CFLAGS) deSteg.cpp

clean: 
	rm *.o steg
