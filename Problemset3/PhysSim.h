/*
 * PhysSim.h
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#ifndef PHYSSIM_H_
#define PHYSSIM_H_

#pragma once
#include "CelBody.h"

class PhysSim
{
public:
	PhysSim();
	virtual ~PhysSim();

	void addBody(CelBody& body);
	void update();

private:
	std::vector<CelBody> _bodies;
};

#endif /* PHYSSIM_H_ */
