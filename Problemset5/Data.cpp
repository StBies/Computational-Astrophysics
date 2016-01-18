/*
 * Data.cpp
 *
 *  Created on: 18.01.2016
 *      Author: stefan
 */

#include "Data.h"

using namespace std;

Data::Data(string file)
{
	_rawData = new vector<string>;
	_wavelength = new vector<double>;
	_fluxLog = new vector<double>;

	ifstream datafile;
	datafile.open(file.c_str());

	while(!datafile.eof())
	{
		string s;
		getline(datafile,s);
		_rawData->push_back(s);
	}

	datafile.close();

	for(string s: *_rawData)
	{
		cout << s << endl;
	}
}

Data::~Data()
{
	// TODO Auto-generated destructor stub
}

void Data::parseLine()
{
	regex number("(\\d)+\\.(?\\d*)");
	smatch submatch;
	for(string line: *_rawData)
	{
		regex_match matcher(line.c_str(),submatch,number);
	}
}

