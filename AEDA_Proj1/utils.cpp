#include "utils.hpp"


bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int readMenuInput() {
	string input;
	int option;
	getline(cin, input);

	if (!is_number(input) || 0 == (option = atoi(input.c_str())) ) { throw invalid_argument(input);}
	return option;
}

void clear_scrn() {	cout << string(20, '\n'); }


