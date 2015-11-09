#Set variables: compiler, compilerflags, linkerflags, objectcodenames
#Author: Stefan, Date: Nov. 9, 2015
CC=g++
CFLAGS=-O3 -fopenmp -std=c++11
LDFLAGS = -fopenmp

OBJ=main.o Matrix.o
SRC=$(OBJ:%.o=%.cpp)

all: $(OBJ)
	$(CC) $(OBJ) -o optPar.out $(LDFLAGS)	

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm *.out
