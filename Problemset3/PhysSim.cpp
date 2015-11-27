/*
 * PhysSim.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#include "PhysSim.h"

/**
 * Initializes a simulator object.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 */
PhysSim::PhysSim()
{
	// TODO Auto-generated constructor stub

}

PhysSim::~PhysSim()
{
	// TODO maybe delete all contained objects as well?
	delete [] &_bodies;
}

/**
 * Adds a celestial body to the list of objects the simulation object is needed to calculate updates for.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @param body The celestial body, that is to be added.
 *
 * @require body != nullptr
 */
void PhysSim::addBody(CelBody* body)
{
	// TODO Sort: Stars in the beginning, then planets etc
	_bodies.push_back(body);
}

/**
 * Calculates new coordinates and velocities for all celestial bodies, this object holds.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 */
void PhysSim::update()
{
	// TODO implement
}

