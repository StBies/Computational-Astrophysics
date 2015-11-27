/*
 * CelBody.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Stefan
 */

#ifndef CELBODY_H_
#define CELBODY_H_

#pragma once
#include <vector>

/**
 * A class representing a celestial body. The body is considered a pointlike mass.
 *
 * @brief Representation of a celestial body.
 * @author Stefan
 * @date Nov. 26, 2015
 * @version 0.1
 */
class CelBody
{
public:
	CelBody(double mass, double x, double y, double velocityX, double velocityY);
	virtual ~CelBody();

	double getMass();
	double getVelocityX();
	double getVelocityY();
	std::vector<double>* getVeclocity();
	double getX();
	double getY();
	std::vector<double>* getCoords();

	void setMass(double mass);

	void setVelocity(std::vector<double>& velocity);
	void setVelocityX(double velocity);
	void setVelocityY(double velocity);

	void setX(double x);
	void setY(double y);
	void setCoords(std::vector<double>& coords);

protected:
	double _mass;
	std::vector<double> _coords;
	std::vector<double> _velocity;

};

#endif /* CELBODY_H_ */
