CC=g++
CFLAGS=-c

all: stegProject

stegProject: main.o de_steg.o steg.o bmp_file.o bin_file.o png_file.o steg_file.o steg_helper.o bits.o lodepng.o
	$(CC) main.o de_steg.o steg.o bmp_file.o bin_file.o png_file.o steg_file.o steg_helper.o bits.o lodepng.o -o run

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

steg.o: steg.cpp
	$(CC) $(CFLAGS) steg.cpp

de_steg.o: de_steg.cpp
	$(CC) $(CFLAGS) de_steg.cpp

bmp_file.o: bmp_file.cpp
	$(CC) $(CFLAGS) bmp_file.cpp

bin_file.o: bin_file.cpp
	$(CC) $(CFLAGS) bin_file.cpp

png_file.o: png_file.cpp
	$(CC) $(CFLAGS) png_file.cpp

steg_file.o: steg_file.cpp
	$(CC) $(CFLAGS) steg_file.cpp

steg_helper.o: steg_helper.cpp
	$(CC) $(CFLAGS) steg_helper.cpp

bits.o: bits.cpp
	$(CC) $(CFLAGS) bits.cpp

lodepng.o: lodepng.cpp
	$(CC) $(CFLAGS) lodepng.cpp

clean:
	rm *.o run
