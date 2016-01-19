/*
 * Processor.h
 *
 *  Created on: 19.01.2016
 *      Author: stefan
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <gsl/gsl_fft.h>
#include <cmath>
#include <vector>
#include "Data.h"

class Processor
{
public:
	Processor();
	virtual ~Processor();
	void process();
};

#endif /* PROCESSOR_H_ */
