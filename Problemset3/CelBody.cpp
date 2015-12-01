/*
 * CelBody.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Stefan
 */

#include "CelBody.h"
#include <vector>

using namespace std;

/**
 * Initializes a celestial body with the passed values.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @param mass the body's mass in kg
 * @param x the x coordinate in km
 * @param y the y coordinate in km
 * @param velocityX the velocity in x direction in km/s
 * @param velocityY the velocity in y direction in km/s
 */
CelBody::CelBody(double mass, double x, double y, double velocityX,
		double velocityY)
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
	delete[] &_velocity;
	delete[] &_coords;
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
vector<double>* CelBody::getVelocity()
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
 * Setter-method for the body's mass. Will set the mass of the object to be the passed mass in kg
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @param mass New mass of the celestial body in kg
 * @require mass >= 0.0
 */
void CelBody::setMass(double mass)
{
	_mass = mass;
}

/**
 * Setter-method for the body's velocity in x-direction. Will set the x velocity of the object to be the passed
 * velocity in km/s.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @param velocity New velocity in the x-direction in km/s
 *
 * @ensure this->getVelocityX() == velocity
 */
void CelBody::setVelocityX(double velocity)
{
	_velocity[0] = velocity;
}

/**
 * Setter-method for the body's velocity in y-direction. Will set the y velocity of the object to be the passed
 * velocity in km/s.
 *
 * @author Stefan
 * @date Nov. 27, 2015
 * @version 0.1
 *
 * @param velocity New velocity in the y-direction in km/s
 *
 * @ensure this->getVelocityY() == velocity
 */
void CelBody::setVelocityY(double velocity)
{
	_velocity[1] = velocity;
}

/**
 * Setter-method for the celestial body's velocity. The set velocityvector will be the body's new velocity.
 *
 * @brief Setter for the velocityvector
 *
 * @author Stefan
 * @date Dec. 1, 2015
 * @version 0.6
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
	vector<double>* buffer = &_velocity;
	delete[] buffer;
	_velocity = velocity;
}

/**
 * Setter for the x-coordinate. Will set the body's x-coordinate to the passed value (in km).
 *
 * @author Stefan
 * @date Nov 27, 2015
 * @version 0.1
 *
 * @param x The new x coordinate.
 *
 * @ensure this->getX() == x
 */
void CelBody::setX(double x)
{
	_velocity[0] = x;
}

/**
 * Setter for the y-coordinate. Will set the body's y-coordinate to the passed value (in km).
 *
 * @author Stefan
 * @date Nov 27, 2015
 * @version 0.1
 *
 * @param y The new y coordinate.
 *
 * @ensure this->getY() == y
 */
void CelBody::setY(double y)
{
	_velocity[1] = y;
}

/**
 * Setter for the coordinatevector. Will set the body's coordinates to the passed coordinatevector containing double precision
 * floating point coordinates in km.
 *
 * @author Stefan
 * @date Dec. 1, 2015
 * @version 0.6
 *
 * @param coords the new coordinatevector as a reference.
 *
 * @require &coords != nullptr
 * @require coords.size() == this->getCoords()->size()
 *
 * @ensure this->getCoords() == &coords
 */
void CelBody::setCoords(vector<double>& coords)
{
	vector<double>* buffer = &_coords;
	delete[] buffer;
	_coords = coords;
}
