#!/bin/bash

for i in {0..9999}
do
	./nonOpt >> nonOpt.dat
	./opt1 >> opt1.dat
	./opt2 >> opt2.dat
	./opt3 >> opt3.dat
	./nonOptPar >> nonOptPar.dat
	./opt1par >> opt1par.dat
	./opt2par >> opt2par.dat
	./opt3par >> opt3par.dat
done
