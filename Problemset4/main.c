/*
 * main.c
 *
 *  Created on: Dec 9, 2015
 *      Author: Stefan
 */

#include <stdio.h>
#include "mc-integrator.h"

int main(void)
{
	//number of random number pairs, if much bigger, heap memory must be allocated -> slower
	int n = 5e5;

	//arrays to store random numbers for pairs x,y. z array is to store result for parallel computation
	double x[n];
//	double y[n];

	generateNumbers(x,n);

	printf("Real integral is about: 0.78540, this calculation: %f\n", integrateAvg(x,n));

	return 0;
}
