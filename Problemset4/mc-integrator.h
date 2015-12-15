/*
 * mc-integrator.h
 *
 *  Created on: 15.12.2015
 *      Author: sbieschk
 */

#ifndef MC_INTEGRATOR_H_
#define MC_INTEGRATOR_H_


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

double integrate(double a[], double b[], int n)
{
	char z[n];
	int counter = 0;

	//check, how many of the points are contributing to the integral
	#pragma omp parallel for
	for(int i = 0; i < n; i++)
	{
		z[i] = isUnder(a[i],b[i]) ? 1 : 0;
	}

	for(int i = 0; i < n; i++)
	{
		counter += z[i];
	}

	return (double)counter/n;
}

void generateNumbers(double a[], double b[], int n)
{
	//seed the random number generator
	srand(1337);

	//feed the arrays with random numbers. Fed to arrays in order to get the same results with parallel computation
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() / (double)RAND_MAX;
		b[i] = rand() / (double)RAND_MAX;
	}
}

#endif /* MC_INTEGRATOR_H_ */
