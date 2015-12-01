#include <iostream>
#include "CelBody.h"
#include "constants.h"
#include "Planet.h"

using namespace std;

int main()
{
//	CelBody C(10000,10,9,5,4);
//	vector<double> v = *C.getVeclocity();

//	cout << v[1] << endl;
	CelBody* C = new Planet();
	cout <<"Adress from main.cpp: "<< &GRAV_CONST << endl;
	return 0;
}
