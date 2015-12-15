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
double integrate(double a[], double b[], int n);
void generateNumbers(double a[], double b[], int n);
double integrate2(double a[], int n);

#endif /* MC_INTEGRATOR_H_ */
