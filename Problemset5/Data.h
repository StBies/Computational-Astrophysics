/*
 * Data.h
 *
 *  Created on: 18.01.2016
 *      Author: stefan
 */

#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Class containing data of a solar spectrum, especially wavelength and a corresponding
 * flux for each wavelength
 *
 * @author Stefan
 * @date Jan. 19, 2016
 * @version 0.3
 */
class Data
{
public:
	Data(const string file);
	virtual ~Data();
	vector<vector<double>*>* getData();


private:
	void parseLine(const string line);
	vector<vector<double>*>* _data;
	vector<string>* _rawData;
};

#endif /* DATA_H_ */
