/*
 * PhysSim.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#include "PhysSim.h"
#include "constants.h"
#include <cmath>

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
	delete[] &_bodies;
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
 * @date Dec. 01, 2015
 * @version 0.6
 */
void PhysSim::update()
{
	double timestep = 1.337;
	//calculate net force for each CelBody
	for (unsigned int i = 0; i < _bodies.size(); i++)
	{
		std::vector<double> force = {0,0};

		for (unsigned int j = 0; j < _bodies.size(); j++)
		{
			double r = 0.0;

			if (i != j)
			{
				r = _bodies[i]->getX() - _bodies[j]->getX();
				force[0] += -GRAV_CONST * (_bodies[j]->getMass() * r)/ std::pow(r,3);
				r = _bodies[i]->getY() - _bodies[j]->getY();
				force[1] += -GRAV_CONST * (_bodies[j]->getMass() * r)/ std::pow(r,3);
			}
		}

		//update position and velocity
		if (_bodies[i]->isMovable())
		{
			std::vector<double>* coords;
			std::vector<double>* velocity;

			coords = _bodies[i]->getCoords();
			velocity = _bodies[i]->getVelocity();

			for(unsigned int k = 0; k < 2; k++)
			{
				(*coords)[k] += timestep * (*velocity)[k];
				(*velocity)[k] += timestep * force[k];
			}
		}
	}

}

