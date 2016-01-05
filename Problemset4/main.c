/*
 * main.c
 *
 *  Created on: Dec 9, 2015
 *      Author: Stefan
 */

#include <stdio.h>
#include "mc-integrator.h"
#include <stdlib.h>
#include "randomtest.h"

int main(int argc, char** argv)
{
	//number of random numbers
	int n = 3e7;

	//arrays to store random numbers for pairs x,y. z array is to store result for parallel computation
	double* x = (double*) malloc(n * sizeof(double));
//	double* y = (double*) malloc(n * sizeof(double));

	generateNumbers(x, n);

	printf("Real integral is about: 0.78540, this calculation: %f\n",integrateSimple(n, 42)->value);

	//if program is called from commandline with argument ./*.out -r or ./*.out r results will be printed to files
	if (argc > 1 && (argv[1][0] == 'r' || argv[1][1] == 'r'))
	{
		FILE* saveFile = fopen("./convergenceSimple.dat", "w+");
		for (int i = 0; i < 1e6; i += 1000)
		{
			Solution* s = integrateSimpleOMP(x, i);
			fprintf(saveFile, "%d\t%f\t%f\n", i, s->value,s->error);
			free(s);
		}
		fclose(saveFile);
		testAnsiRand();
	}
	free(x);
//	free(y);

	return 0;
}
