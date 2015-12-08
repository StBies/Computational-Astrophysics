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
	CelBody* planet2 = new Planet(JUPITER_MASS,5.203*AU,0,0,-JUPITER_ORBIT_VELOCITY);
	PhysSim* sim = new PhysSim();
	sim->addBody(star);
	sim->addBody(planet);
	sim->addBody(planet2);

	double stepsize = YEAR / 365;
	//simulate orbit
	//print table formatted as:
	//x_1, y_1, x_2, y_2, t, E_1, E_2, L_1, L_2
	for(int i = 0; i < 10000 * 365; i++)
	{
		sim->updateRK(stepsize);
		cout << planet->getX() / AU << "\t"
			 << planet->getY() / AU << "\t"
			 << planet2->getX() / AU << "\t"
			 << planet2->getY() / AU << "\t"
			 << (double)(i * stepsize) / YEAR << "\t"
			 << *(planet->getEnergy()) << "\t"
			 << *(planet2->getEnergy()) << "\t"
			 << planet->getAngularMomentum() << "\t"
			 << planet2->getAngularMomentum()
			 << endl;
	}

	delete sim;
	return 0;
}
