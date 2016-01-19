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
Data::Data(const string file)
{
	_rawData = new vector<string>;
	_data = new vector<vector<double>*>;

	ifstream datafile;
	datafile.open(file.c_str());

	cout << "Reading data from file: " << file << endl;

	while (!datafile.eof())
	{
		string s;
		getline(datafile, s);
		parseLine(s);
		_rawData->push_back(s);
	}
	datafile.close();
	cout << "Done reading " << file << endl;

	_data->shrink_to_fit();
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
	delete[] _rawData;
}

/**
 * Getter-method for the data, the object holds. Will return a pointer to a vector containing
 * pointers to double-vectors.
 *
 * @author Stefan
 * @date Jan. 19, 2016
 * @version 0.1
 *
 * @return Pointer to a vector of pointers to vectors of doubles
 */
vector<vector<double>*>* Data::getData()
{
	return _data;
}

/**
 * A parser, that gets real Data out of the textfile containing it.
 *
 * @author Stefan
 * @date Jan. 18, 2016
 * @version 0.1
 *
 * @param line A String containing the line to be parsed
 */
void Data::parseLine(const string line)
{
	stringstream inStream;
	inStream << line;
	double a = 0;
	double b = 0;

	vector<double>* content = new vector<double>;
	content->resize(2);

	inStream >> a >> b;
	content->push_back(a);
	content->push_back(b);
	_data->push_back(content);
}

