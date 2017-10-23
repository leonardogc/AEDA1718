#ifndef JURADO_HPP_
#define JURADO_HPP_

#include "Pessoa.hpp"
#include "utils.hpp"


class Jurado: protected Pessoa {
private:
	int telemovel; //must be 9 digits long
public:
	Jurado(string nome, string  morada, string  generoArte, int telemovel);
};


#endif /* JURADO_HPP_ */
