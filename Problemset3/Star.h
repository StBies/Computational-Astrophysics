/*
 * Star.h
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#ifndef STAR_H_
#define STAR_H_

#pragma once
#include "CelBody.h"

/**
 * Representation of a star. Star is simplified to be a pointlike mass. It can either be set to units of solar quantities
 * or SI units. For detailed class information consult CelBody documentation.
 *
 * @brief Representation of a star.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.2
 */
class Star: public CelBody
{
public:
	Star(double mass, double x, double y, double velocityX, double velocityY);
	virtual ~Star();

	bool isMovable();
};

#endif /* STAR_H_ */
