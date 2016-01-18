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
#include <regex>

class Data
{
public:
	Data(std::string file);
	virtual ~Data();

private:
	void parseLine();
	std::vector<std::string>* _rawData;
	std::vector<double>* _wavelength;
	std::vector<double>* _fluxLog;
};

#endif /* DATA_H_ */
