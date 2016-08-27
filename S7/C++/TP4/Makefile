CC=g++
CPPFLAGS=-I ./Include
CFLAGS= --std=c++11 -I ./Include
DEBUG=-g
SRC=Clou.cpp Compteur.cpp Obstacle.cpp Lanceur.cpp Planche.cpp  main.cpp
OBJDIR=./obj

.PHONY=all clean

all:main

main:main.cpp $(OBJDIR)/Clou.o $(OBJDIR)/Compteur.o $(OBJDIR)/Obstacle.o $(OBJDIR)/Lanceur.o $(OBJDIR)/Planche.o
	$(CC) $(CFLAGS)  $^ -o$@ -lm

$(OBJDIR)/%.o: %.cpp
	$(CC) -c $^  $(CFLAGS)  -o $@ -lm

debug:$(SRC)
	$(CC) $(CFLAGS) $(DEBUG)   $^ -o$@ -lm

clean:debug main $(OBJDIR)/*.o
	$(RM) $^
