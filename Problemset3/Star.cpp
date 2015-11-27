/*
 * Star.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#include "Star.h"

Star::Star() : CelBody(10,10,10,10,10)
{
	// TODO Auto-generated constructor stub

}

Star::~Star()
{
	// TODO Auto-generated destructor stub
}

/**
 * Check, if the object is movable. For simplification, stars (for now) are not movable, so velocity is fixed to zero.
 * @return True if object can change coordinates, false if not.
 */
bool Star::isMovable()
{
	return false;
}
