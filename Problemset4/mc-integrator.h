/*
 * mc-integrator.h
 *
 *  Created on: 15.12.2015
 *      Author: Stefan
 */

#ifndef MC_INTEGRATOR_H_
#define MC_INTEGRATOR_H_

#include <stdbool.h>

bool isUnder(double x, double y);
double integrateRain(double a[], double b[], int n);
void generateNumbers(double a[], int n);
void generateNumberPairs(double a[], double b[], int n);
double integrateAvg(double a[], int n);

typedef struct
{
	double value;
	double error;
} Solution;

#endif /* MC_INTEGRATOR_H_ */
