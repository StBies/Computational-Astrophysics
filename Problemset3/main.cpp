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
	CelBody* planet = new Planet(EARTH_MASS,AU,0,0,-EARTH_ORBIT_VELOCITY);
	CelBody* planet2 = new Planet(JUPITER_MASS,13.6*AU,0,0,-JUPITER_ORBIT_VELOCITY);
	PhysSim* sim = new PhysSim();
	sim->addBody(star);
	sim->addBody(planet);
	sim->addBody(planet2);

	//simulate orbit for 2 years, one day step
	for(int i = 0; i < 2 * 365; i++)
	{
		sim->update(YEAR / 365);
		cout << planet->getX() / AU << "\t"
			 << planet->getY() / AU << "\t"
			 << planet2->getX() / AU << "\t"
			 << planet2->getY() / AU
			 << endl;
	}

	delete sim;
	return 0;
}
