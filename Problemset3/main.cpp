#include <iostream>
#include "CelBody.h"

using namespace std;

int main()
{

	CelBody C(10000,10,9,5,4);
	vector<double> v = *C.getVeclocity();

	cout << v[1] << endl;
	return 0;
}
