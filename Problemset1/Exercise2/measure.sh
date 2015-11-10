#!/bin/bash

for i in {0..199}
do
	./nonOpt.out >> nonOpt.dat
	./Opt3.out >> opt3.dat
	./nonOptPar.out >> nonOptPar.dat
	./Opt3Par.out >> Opt3Par.dat
done



