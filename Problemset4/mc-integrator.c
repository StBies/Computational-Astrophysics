#include "mc-integrator.h"
#include <math.h>
#include <stdlib.h>

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
	return y <= sqrt(1.0 - pow(x, 2.0));
}

/**
 * Monte-Carlo-integration of \f$\int_{0}^{1}\sqrt(1-x^{2})dx\f$ using the rejection method.
 *
 * @author Stefan
 * @date Dec. 15, 2015
 * @version 0.2
 *
 * @note If compilerflag for openMP parallel computation is set, this will use it.
 *
 * @param a array of double precision random numbers of size n
 * @param b array of double precision random numbers of size n
 * @param n number of random numbers, array sizes a and b must be n
 *
 * @return Result of the integration as double precision floating point number
 */
double integrateRain(double a[], double b[], int n)
{
	char z[n];
	int counter = 0;

	//check, how many of the points are contributing to the integral
	#pragma omp parallel for
	for (int i = 0; i < n; i++)
	{
		z[i] = isUnder(a[i], b[i]) ? 1 : 0;
	}

	for (int i = 0; i < n; i++)
	{
		counter += z[i];
	}

	return (double) counter / n;
}

/**
 * Generates pairs of random numbers and stores them to the arrays a and b, each of size n.
 *
 * @author Stefan
 * @date Dec. 15, 2015
 * @version 0.2
 *
 * @param a array of double precision random numbers of size n
 * @param b array of double precision random numbers of size n
 * @param n number of random numbers, array sizes a and b must be n
 */
void generateNumberPairs(double a[], double b[], int n)
{
	//seed the random number generator
	srand(1337);

	//feed the arrays with random numbers. Fed to arrays in order to get the same results with parallel computation
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() / (double) RAND_MAX;
		b[i] = rand() / (double) RAND_MAX;
	}
}

void generateNumbers(double a[], int n)
{
	srand(1337);

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() / (double) RAND_MAX;
	}
}

/**
 * Monte Carlo Integration of the function \f$ \sqrt(1-x^{2}) \f$ in the interval [0,1).
 *
 * @author Stefan
 * @date Jan. 04, 2016
 * @version 0.1
 *
 * @return pointer of Solution type containing double precision value and error of the integration.
 *
 * @warn Can be executed with openMP parallelization, but is memory-expensive.
 */
Solution* integrateSimpleOMP(double a[], int n)
{
	double* functionValue = (double*)malloc(n * sizeof(double));
	double* squaredValue = (double*)malloc(n * sizeof(double));
	double functionAverage = 0.0;
	double error = 0;

	#pragma omp parallel for
	for (int i = 0; i < n; i++)
	{
		functionValue[i] = sqrt(1.0 - pow(a[i], 2.0));
		squaredValue[i] = 1.0 - pow(a[i],2);
	}

	for (int i = 0; i < n; i++)
	{
		functionAverage += functionValue[i];
		error += squaredValue[i];
	}
	free(functionValue);
	free(squaredValue);

	functionAverage /= n;
	error /= n;
	error = sqrt((error - pow(functionAverage,2.0))/n);

	//allocating dynamic memory for s
	Solution* s = (Solution*)malloc(sizeof(Solution));
	s->value = functionAverage;
	s->error = error;
	return s;
}

/**
 * Monte Carlo Integration of the function \f$ \sqrt(1-x^{2}) \f$ in the interval [0,1).
 *
 * @author Stefan
 * @date Jan. 04, 2016
 * @version 0.1
 *
 * @return pointer of Solution type containing double precision value and error of the integration.
 *
 * @warn Cannot be run in parallel.
 */
Solution* integrateSimple(int n, int seed)
{
	srand(seed);
	double functionAverage = 0.0;
	double error = 0;

	for (int i = 0; i < n; i++)
	{
		double value = rand()/(double)RAND_MAX;
		functionAverage += sqrt(1.0 - pow(value, 2.0));
		error += 1.0 - pow(value,2);
	}


	functionAverage /= n;
	error /= n;
	error = sqrt((error - pow(functionAverage,2.0))/n);

	//allocating dynamic memory for s
	Solution* s = (Solution*)malloc(sizeof(Solution));
	s->value = functionAverage;
	s->error = error;
	return s;
}
