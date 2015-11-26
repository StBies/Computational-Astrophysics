/*
 * CelBody.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Stefan
 */

#ifndef CELBODY_H_
#define CELBODY_H_

#pragma once
#include <vector>

/**
 * A class representing a celestial body. The body is considered a pointlike mass.
 *
 * @brief Representation of a celestial body.
 * @author Stefan
 * @date Nov. 26, 2015
 * @version 0.1
 */
class CelBody
{
public:
	CelBody();
	virtual ~CelBody();

private:
	double _mass;
	std::vector<double> _coords;
	std::vector<double> _velocity;

};

#endif /* CELBODY_H_ */
