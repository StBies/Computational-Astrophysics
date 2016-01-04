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
#include <gsl/gsl_rng.h>

int main(void)
{
	//number of random numbers, if much bigger, heap memory must be allocated -> slower
	int n = 3e7;

	//arrays to store random numbers for pairs x,y. z array is to store result for parallel computation
	double* x = (double*)malloc(n * sizeof(double));
//	double y[n];

	generateNumbers(x,n);

	printf("Real integral is about: 0.78540, this calculation: %f\n", integrateSimpleOMP(x,n)->value);

	free(x);
	testAnsiRand();
	return 0;
}
