#!/bin/bash

g++ -O0 -std=c++11 -o nonOpt.o -c main.cpp
g++ -o nonOpt nonOpt.o -s -fopenmp
g++ -O -std=c++11 -o opt0.o -c main.cpp
g++ -o opt0 opt0.o -s -fopenmp
g++ -O1 -std=c++11 -o opt1.o -c main.cpp
g++ -o opt1 opt1.o -s -fopenmp
g++ -O2 -std=c++11 -o opt2.o -c main.cpp
g++ -o opt2 opt2.o -s -fopenmp
g++ -O3 -std=c++11 -o opt3.o -c main.cpp
g++ -o opt3 opt3.o -s -fopenmp
g++ -O0 -std=c++11 -fopenmp -o nonOptPar.o -c main.cpp
g++ -o nonOptPar nonOptPar.o -s -fopenmp
g++ -O -std=c++11 -fopenmp -o opt0par.o -c main.cpp
g++ -o opt0par opt0par.o -s -fopenmp
g++ -O1 -std=c++11 -fopenmp -o opt1par.o -c main.cpp
g++ -o opt1par opt1par.o -s -fopenmp
g++ -O2 -std=c++11 -fopenmp -o opt2par.o -c main.cpp
g++ -o opt2par opt2par.o -s -fopenmp
g++ -O3 -std=c++11 -fopenmp -o opt3par.o -c main.cpp
g++ -o opt3par opt3par.o -s -fopenmp
rm *.o
