#include "utils.hpp"


bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int read_number_Input() {
	string input;
	int option;
	getline(cin, input);

	if (!is_number(input) || 0 == (option = atoi(input.c_str())) ) { throw invalid_argument(input);}
	return option;
}

void clear_scrn() {	cout << string(20, '\n'); }

int numbr_size(int numbr) {
	stringstream ss; ss.clear();
	string auxiliar = "";
	ss<<numbr;
	ss>>auxiliar;
	return auxiliar.size();
}

bool lowerThan(string d1, string d2){
	stringstream ss;
	int data1;
	int data2;

	ss<<d1[6];
	ss<<d1[7];
	ss<<d1[8];
	ss<<d1[9];

	ss<<d1[3];
	ss<<d1[4];

	ss<<d1[0];
	ss<<d1[1];

	ss >> data1;

	ss.str(string());
	ss.clear();

	ss<<d2[6];
	ss<<d2[7];
	ss<<d2[8];
	ss<<d2[9];

	ss<<d2[3];
	ss<<d2[4];

	ss<<d2[0];
	ss<<d2[1];


	ss >> data2;

	ss.str(string());
	ss.clear();

	if(data1<data2){
		return true;
	}
	else
	{
		return false;
	}
}


bool isValidDate(string date){
	stringstream ss, auxiliar;
	string line; int day, month, year;
	bool leapYear;
	ss << date;

	//Parse date to integers
	getline(ss, line, '/');
	auxiliar << line;
	auxiliar >> day;
	auxiliar.clear();

	getline(ss, line, '/');
	auxiliar << line;
	auxiliar >> month;
	auxiliar.clear();

	getline(ss, line, '/');
	auxiliar << line;
	auxiliar >> year;


	//Check validity

	if(day <= 0 || month <= 0 || year <= 0) return false;
	if(year%4 == 0)
	{
		if( year%100 == 0)
		{
			// year is divisible by 400, hence the year is a leap year
			if ( year%400 == 0)
				leapYear = true;
			else
				leapYear = false;
		}
		else
			leapYear = true;
	}
	else
		leapYear = false;

	switch(month){
	case 2:
		if(leapYear) return day < 29;
		else return day < 28;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return day < 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return day < 30;
	default:
		return false;
	}
}

