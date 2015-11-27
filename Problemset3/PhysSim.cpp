/*
 * PhysSim.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: Stefan
 */

#include "PhysSim.h"

PhysSim::PhysSim()
{
	// TODO Auto-generated constructor stub

}

PhysSim::~PhysSim()
{
	// TODO Auto-generated destructor stub
}

void PhysSim::addBody(CelBody& body)
{
	// TODO Sort: Stars in the beginning, then planets etc
	_bodies.push_back(body);
}

void PhysSim::update()
{
	// TODO implement
	//ZORK
}

