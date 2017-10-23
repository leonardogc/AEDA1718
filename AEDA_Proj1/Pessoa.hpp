#ifndef PESSOA_HPP_
#define PESSOA_HPP_

#include "utils.hpp"


class Pessoa {
protected:
	string nome;
	string morada;
	string generoArte;
public:
	Pessoa(string nome, string  morada, string  generoArte);
};


#endif /* PESSOA_HPP_ */
