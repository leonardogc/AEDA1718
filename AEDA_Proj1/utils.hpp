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

namespace castingspace
{
	/**
	 * Enum type used in the sorting methods
	 */

	enum sort_t // all sorts are for Ascending order
	{
		//name is sorted from a to z
		by_name,			//used for jurados, candidatos

		//name and art are sorted from a to z | elements are grouped by art and ordered alphabetically in the same art
		by_name_and_art,	//used for jurados, candidatos

		//age is sorted from younger to older; art is sorted from a to z | elements are grouped by art and ordered by age in the same art
		by_age_and_art,		//used for candidatos

		//date is sorted chronologically; art is sorted from a to z | elements are grouped by art and ordered chronologically in the same art
		by_date_and_art,	//used for sessoes

		//
		by_phase_and_position //used for participacoes
	};
}


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
