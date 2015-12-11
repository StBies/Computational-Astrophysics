/*
 * main.c
 *
 *  Created on: Dec 9, 2015
 *      Author: Stefan
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUnder(double x, double y);

int main(void)
{
	//seed the random number generator
	srand(1337);

	//number of random number pairs, if much bigger, heap memory must be allocated -> slower
	int n = 1e4;

	//arrays to store random numbers for pairs x,y. z array is to store result for parallel computation
	double x[n];
	double y[n];
	short z[n];

	//feed the arrays with random numbers. Fed to arrays in order to get the same results with parallel computation
	for(int i = 0; i < n; i++)
	{
		x[i] = rand() / (double)RAND_MAX;
		y[i] = rand() / (double)RAND_MAX;
	}

	int counter = 0;

	//check, how many of the points are contributing to the integral
	#pragma omp parallel for
	for(int i = 0; i < n; i++)
	{
		z[i] = isUnder(x[i],y[i]) ? 1 : 0;
	}

	for(int i = 0; i < n; i++)
	{
		counter += z[i];
	}

	printf("Real integral is about: 0.78540, this calculation: %f\n", (double)counter/n);

	return 0;

}

/**
 * Checks, if the value y is smaller than the value of the function sqrt(1-x**2) at point x
 *
 * @author Stefan
 * @date Dec. 10, 2015
 * @version 0.1
 *
 * @param x point, at which the function is to be evaluated
 * @param y value that is to be checked if smaller than the value of the function
 *
 * @return true if y is smaller or equal to sqrt(1-x**2), else false
 */
bool isUnder(double x, double y)
{
	return y <= sqrt(1.0 - pow(x,2.0));
}

