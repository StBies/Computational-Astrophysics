#include <iostream>
#include "CelBody.h"
#include "Planet.h"
#include "Star.h"
#include "PhysSim.h"

using namespace std;

int main()
{
	CelBody* star = new Star();
	CelBody* planet = new Planet();
	PhysSim* sim = new PhysSim();
	sim->addBody(star);
	sim->addBody(planet);

	sim->update();
	cout << star->getX() << endl;
	cout << planet->getX() << endl;
	cout << planet->getY() << endl;

	return 0;
}
