/*
 * Data.cpp
 *
 *  Created on: 18.01.2016
 *      Author: stefan
 */

#include "Data.h"

using namespace std;

/**
 * Constructor, that reads a datafile and stores it in real data.
 *
 * @author Stefan
 * @date Jan. 18, 2016
 * @version 0.1
 *
 * @param file A string giving the filename with path if needed to the datafile
 */
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

/**
 * Destructor, cleaning memory.
 *
 * @author Stefan
 * @date Jan. 18, 2016
 * @version 0.1
 */
Data::~Data()
{
	delete [] _fluxLog;
	delete [] _wavelength;
	delete [] _rawData;
}

/**
 * A parser, that gets real Data out of the textfile containing it using regular expressions.
 *
 * @author Stefan
 * @date Jan. 18, 2016
 * @version 0.1
 */
void Data::parseLine()
{
	//regular expression for more than one digit, maybe a dot and maybe some more digits
	regex number("(\\d+)\\.(?\\d*)");
	smatch submatch;

	for(string line: *_rawData)
	{
		//TODO compilationtime error here, fix it
		regex_match matcher(line.c_str(),submatch,number);
	}
}

