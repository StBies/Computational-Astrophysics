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
 * @date Dec. 7, 2015
 * @version 0.2
 */
PhysSim::PhysSim()
{
	_bodies = *new std::vector<CelBody*>;
}

/**
 * Deletes the PhysSim object, including all celestial bodies, it may contain.
 *
 * @author Stefan
 * @date Dec. 7, 2015
 * @version 0.2
 */
PhysSim::~PhysSim()
{
	for(CelBody* body : _bodies)
	{
		delete body;
	}
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
 * Solving Newton's equation of motion with the explicit Euler method.
 *
 * @author Stefan
 * @date Dec. 07, 2015
 * @version 0.8
 *
 * @param timestep The step forward in time to update for
 */
void PhysSim::update(double timestep)
{
	//calculate net acceleration for each CelBody
	for (unsigned int i = 0; i < _bodies.size(); i++)
	{
		double ePot = 0.0;
		std::vector<double> acceleration = { 0, 0 };

		for (unsigned int j = 0; j < _bodies.size(); j++)
		{
			double distanceComponent = 0.0;

			double distance = std::sqrt(std::pow(_bodies[i]->getX() - _bodies[j]->getX(),2)
							+ std::pow(_bodies[i]->getY() - _bodies[j]->getY(),2));


			if (i != j)
			{

				distanceComponent = _bodies[i]->getX() - _bodies[j]->getX();
				acceleration[0] += -GRAV_CONST
						* (_bodies[j]->getMass() * distanceComponent)
						/ std::pow(distance, 3.0);
				distanceComponent = _bodies[i]->getY() - _bodies[j]->getY();
				acceleration[1] += -GRAV_CONST
						* (_bodies[j]->getMass() * distanceComponent)
						/ std::pow(distance, 3.0);
				ePot += -GRAV_CONST * _bodies[i]->getMass() * _bodies[j]->getMass() / distance;

			}
		}

		//update position and velocity
		if (_bodies[i]->isMovable())
		{
			std::vector<double>* coords;
			std::vector<double>* velocity;
			CelBody* body = _bodies[i];

			coords = body->getCoords();
			velocity = body->getVelocity();

			double* energy = body->getEnergy();

			for (unsigned int k = 0; k < 2; k++)
			{
				(*coords)[k] += timestep * (*velocity)[k];
				(*velocity)[k] += timestep * acceleration[k];
			}
			*energy = ePot
					+ body->getMass() / 2
					* (std::pow((*velocity)[0],2.0) + std::pow((*velocity)[1],2.0));
		}
	}
}

/**
 * Calculates new coordinates and velocities for all celestial bodies, this object holds.
 * Solving Newton's equation of motion with the second order Runge-Kutta method.
 *
 * @author Stefan
 * @date Dec. 08, 2015
 * @version 0.1
 *
 * @param timestep The step forward in time to update for
 */
void PhysSim::updateRK(double timestep)
{
	//calculate net acceleration for each CelBody
	for (unsigned int i = 0; i < _bodies.size(); i++)
	{
		double ePot = 0.0;
		std::vector<double> eulerAcceleration = { 0, 0 };
		std::vector<double> acceleration = { 0, 0 };

		for (unsigned int j = 0; j < _bodies.size(); j++)
		{
			double distanceComponent = 0.0;

			double distance = std::sqrt(std::pow(_bodies[i]->getX() - _bodies[j]->getX(),2)
							+ std::pow(_bodies[i]->getY() - _bodies[j]->getY(),2));


			if (i != j)
			{

				distanceComponent = _bodies[i]->getX() - _bodies[j]->getX();
				eulerAcceleration[0] += -GRAV_CONST
						* (_bodies[j]->getMass() * distanceComponent)
						/ std::pow(distance, 3.0);
				acceleration[0] += -GRAV_CONST
						* (_bodies[j]->getMass() * (distanceComponent + (timestep *eulerAcceleration[0]) / 2))
						/ std::pow(distance, 3.0);
				distanceComponent = _bodies[i]->getY() - _bodies[j]->getY();
				eulerAcceleration[1] += -GRAV_CONST
						* (_bodies[j]->getMass() * distanceComponent)
						/ std::pow(distance, 3.0);
				acceleration[1] += -GRAV_CONST
										* (_bodies[j]->getMass() * (distanceComponent + (timestep * eulerAcceleration[0]) / 2))
										/ std::pow(distance, 3.0);
				ePot += -GRAV_CONST * _bodies[i]->getMass() * _bodies[j]->getMass() / distance;
			}
		}
		ePot *= 1e6;

		//update position and velocity
		if (_bodies[i]->isMovable())
		{
			std::vector<double>* coords;
			std::vector<double>* velocity;
			CelBody* body = _bodies[i];

			coords = body->getCoords();
			velocity = body->getVelocity();

			double* energy = body->getEnergy();

			for (unsigned int k = 0; k < 2; k++)
			{
				(*coords)[k] += timestep * (*velocity)[k];
				(*velocity)[k] += timestep * eulerAcceleration[k];
			}
			*energy = ePot
					+ body->getMass() / 2
					* (std::pow((*velocity)[0],2.0) + std::pow((*velocity)[1],2.0));
		}
	}
}
