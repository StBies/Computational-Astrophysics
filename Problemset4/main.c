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
	double x = 0;
	double y = 0;

	srand(1337);

	int N = 1e6;
	int counter = 0;
	for(int i = 0; i < N; i++)
	{
		x = rand() / (double)RAND_MAX;
		y = rand() / (double)RAND_MAX;

		if(isUnder(x,y))
		{
			counter++;
		}
	}

	printf("Real integral is about: 0.78540, this calculation: %f\n", (double)counter/N);

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

