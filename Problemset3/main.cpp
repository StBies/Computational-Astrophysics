#include <iostream>
#include "CelBody.h"
#include "Planet.h"
#include "Star.h"
#include "PhysSim.h"
#include "constants.h"

using namespace std;

int main()
{
	CelBody* star = new Star();
	CelBody* planet = new Planet(EARTH_MASS,AU,0,0,-1.0);
	PhysSim* sim = new PhysSim();
	sim->addBody(star);
	sim->addBody(planet);

	sim->update();
	cout << star->getX() << endl;
	cout << planet->getX() << endl;
	cout << planet->getY() << endl;
	cout << planet->getVelocityY() << endl;

	sim->update();
	cout << star->getX() << endl;
	cout << planet->getX() << endl;
	cout << planet->getY() << endl;
	return 0;
}
