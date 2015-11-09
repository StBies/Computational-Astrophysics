#!/bin/bash

echo "Building without parallelization and vectorization"
g++ -std=c++11 -c main.cpp Matrix.cpp
g++ -o nonOpt.out main.o Matrix.o -fopenmp

echo "Building with parallelization, without vectorization"
g++ -std=c++11 -fopenmp -c main.cpp Matrix.cpp
g++ -o nonOptPar.out main.o Matrix.o -fopenmp

echo "Building with parallelization and vectorization"
g++ -std=c++11 -O3 -fopenmp -c main.cpp Matrix.cpp
g++ -o Opt3Par.out main.o Matrix.o -fopenmp

echo "Building without parallelization, with vectorization"
g++ -std=c++11 -O3 -c main.cpp Matrix.cpp
g++ -o Opt3.out main.o Matrix.o -fopenmp

echo "cleaning"
rm *.o



