/*
 * CelBody.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Stefan
 */

#include "CelBody.h"
#include <vector>

using namespace std;

CelBody::CelBody(double mass, double x, double y, double velocityX, double velocityY)
{
	_mass = mass;
	_coords = *new vector<double>;
	_velocity = *new vector<double>;
	_coords.resize(2);
	_velocity.resize(2);
	_coords[0] = x;
	_coords[1] = y;
	_velocity[0] = velocityX;
	_velocity[1] = velocityY;
}

CelBody::~CelBody()
{
	delete [] &_velocity;
	delete [] &_coords;
}

/**
 * Simple getter-method for the mass of the celestial body. Will return the mass in kg as a double precision
 * floating point number
 *
 * @brief getter for the mass
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @return Body's mass in kg
 */
double CelBody::getMass()
{
	return _mass;
}

/**
 * Getter-method for the celestial body's velocity in x-direction. Will return the velocity in km/s as a double precision
 * floating point number
 *
 * @brief getter for the velocity in x-direction
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @return velocity in x-direction [km/s]
 */
double CelBody::getVelocityX()
{
	return _velocity[0];
}

/**
 * Getter-method for the celestial body's velocity in y-direction. Will return the velocity in km/s as a double precision
 * floating point number
 *
 * @brief getter for the velocity in y-direction
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @return velocity in y-direction [km/s]
 */
double CelBody::getVelocityY()
{
	return _velocity[1];
}

/**
 * Getter-method for the celestial body's velocity in x and y direction. Will return the velocity in km/s as a double precision
 * vector.
 *
 * @brief getter for the velocityvector
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @return velocityvector in x and y direction [km/s]
 */
vector<double>* CelBody::getVeclocity()
{
	return &_velocity;
}


/**
 * Getter-method for the celestial body's x coordinate. Will return the coordinate in km as a double precision number.
 *
 * @brief Getter for the x coordinate
 *
 * @author Stefan
 * @date Nov 27, 2015
 * @version 0.1
 *
 * @return x coordinate of the celestial body
 */
double CelBody::getX()
{
	return _coords[0];
}

/**
 * Getter-method for the celestial body's y coordinate. Will return the coordinate in km as a double precision number.
 *
 * @brief Getter for the y coordinate
 *
 * @author Stefan
 * @date Nov 27, 2015
 * @version 0.1
 *
 * @return y coordinate of the celestial body
 */
double CelBody::getY()
{
	return _coords[1];
}

/**
 * Getter-method for the celestial body's coordinatevector. Will return the coordinatevector in km as a double precision
 * vector.
 *
 * @brief Getter for the coordinatevector
 *
 * @author Stefan
 * @date Nov 27, 2015
 * @version 0.1
 *
 * @return coordinatevector of the celestial body
 */
vector<double>* CelBody::getCoords()
{
	return &_coords;
}

/**
 * Setter-method for the celestial body's velocity. The set velocityvector will be the body's new velocity.
 *
 * @brief Setter for the velocityvector
 *
 * @author Stefan
 * @date Nov 27, 2015
 * @version 0.1
 *
 * @param velocity The new velocityvector containing two double precision elements (x,y). Must be a reference to an object
 * 		           on the heap
 *
 * @require velocity != nullptr
 * @require velocity->size() == this->getVeclocity()->size()
 *
 * @ensure this->getVeclocity() == &velocity
 */
void CelBody::setVelocity(vector<double>& velocity)
{
	_velocity = velocity;
}



