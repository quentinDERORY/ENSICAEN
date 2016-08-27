.PHONY: clean, mrproper

CC = g++
CFLAGS = -w -Wall -pedantic --std=c++11

all: essai main

main: main.cpp
	$(CC) $(CFLAGS) $^ -o $@

essai: essai_ensemble.cc
	$(CC) $(CFLAGS) $^ -o $@

debug: main.cpp
	$(CC) $(CFLAGS) -g $^ -o $@

Mrproper: 
	rm -f main
