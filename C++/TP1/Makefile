CC=g++
CPPFLAGS=-I ./Include
C++FLAGS=-Wall -W -pedantic --std=c++11
DEBUG=-g
SRC=magasin.cpp main.cpp

.PHONY=all clean

all:main

main:$(SRC)
	$(CC) $(C++FLAGS) $(CPPFLAGS)  $^ -o$@

debug:$(SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEBUG)  $^ -o$@

clean:debug main
	$(RM) $^
