#include <iostream>
#include "CelBody.h"
#include "Planet.h"
#include "Star.h"
#include "PhysSim.h"
#include "constants.h"

using namespace std;

int main()
{
	CelBody* star = new Star(SOLAR_MASS,0,0,0,0);
	CelBody* planet = new Planet(EARTH_MASS,AU,0,0,-1.0);
	PhysSim* sim = new PhysSim();
	sim->addBody(star);
	sim->addBody(planet);

	sim->update();
	cout << planet->getX() << endl;
	cout << planet->getY() << endl;

	sim->update();
	cout << planet->getX() << endl;
	cout << planet->getY() << endl;
	return 0;
}
