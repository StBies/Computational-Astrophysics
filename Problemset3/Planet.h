/*
 * Planet.h
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#ifndef PLANET_H_
#define PLANET_H_

#include "CelBody.h"

/**
 * Representation of a planet. Planet is simplified to be a pointlike mass. It can either be set to units of
 * jupiter's quantities, earth's quantities or SI units. For detailed class information consult CelBody documentation.
 *
 * @brief Representation of a planet.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 */
class Planet: public CelBody
{
public:
	Planet(double mass, double x, double y, double velocityX, double velocityY);
	virtual ~Planet();

	bool isMovable();
};

#endif /* PLANET_H_ */
