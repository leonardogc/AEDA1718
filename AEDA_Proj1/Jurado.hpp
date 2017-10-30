#ifndef JURADO_HPP_
#define JURADO_HPP_

#include "Pessoa.hpp"
#include "utils.hpp"


class Jurado: public Pessoa {
private:
	int telemovel; //must be 9 digits long
public:
	//construtor
	Jurado(string nome, string  morada, string  generoArte, int telemovel);

	//m�todos get
	int getTelemovel() const;

	//metodos set
	void setTelemovel(int telemovel);

	//operadores
	bool operator== (Jurado jurado);
};


#endif /* JURADO_HPP_ */
