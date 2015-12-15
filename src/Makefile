CC=g++
CFLAGS=-c

all: stegProject

stegProject: stegDriver.o steg.o text.o bitmap.o bits.o fileUtil.o sha_256.o deSteg.o
	$(CC) stegDriver.o steg.o text.o bitmap.o bits.o fileUtil.o sha_256.o deSteg.o -o steg  

stegDriver.o: stegDriver.cpp
	$(CC) $(CFLAGS) stegDriver.cpp

steg.o: steg.cpp
	$(CC) $(CFLAGS) steg.cpp

text.o: text.cpp
	$(CC) $(CFLAGS) text.cpp

bitmap.o: bitmap.cpp
	$(CC) $(CFLAGS) bitmap.cpp 

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
