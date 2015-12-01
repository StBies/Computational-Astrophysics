/*
 * Star.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#include "Star.h"
#include "constants.h"

Star::Star(double mass, double x, double y, double velocityX, double velocityY)
: CelBody(mass,x,y,velocityX,velocityY)
{
	// TODO edit superconstructor call
	// TODO Auto-generated constructor stub
}

Star::~Star()
{
	// TODO Auto-generated destructor stub
}

/**
 * Check, if the object is movable. For simplification, stars (for now) are not movable, so velocity is fixed to zero.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @return True if object can change coordinates, false if not.
 */
bool Star::isMovable()
{
	return false;
}
