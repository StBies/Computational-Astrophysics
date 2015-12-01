/*
 * Star.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#include "Star.h"
#include "constants.h"

/**
 * Initializes a Star object with the given parameters.
 *
 * @brief constructor
 *
 * @author Stefan
 * @date Dec. 01, 2015
 * @version 0.8
 *
 * @param mass Star's mass [kg]
 * @param x Star's initial x coordinate [km]
 * @param y Star's initial y coordinate [km]
 * @param velocityX initial velocity in x direction [km/s]
 * @param velocityY initial velocity in y direction [km/s]
 */
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
