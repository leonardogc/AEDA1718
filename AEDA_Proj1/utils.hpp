#ifndef UTILS_HPP_
#define UTILS_HPP_


#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;


extern const string default_files[4];

int readMenuInput();

void clear_scrn();

int numbr_size(int numbr);

bool lowerThan(string d1, string d2);


class InvalidFileNameException
{
	string filename;
public:
	InvalidFileNameException(string filename) {this->filename = filename;}
	string getFilename() {return filename;}
};

#endif /* UTILS_HPP_ */
