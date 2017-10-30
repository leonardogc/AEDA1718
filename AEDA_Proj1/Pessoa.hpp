#ifndef PESSOA_HPP_
#define PESSOA_HPP_

#include "utils.hpp"


class Pessoa {
protected:
	string nome;
	string morada;
	string generoArte;
public:
	//construtor
	Pessoa(string nome, string  morada, string  generoArte);

	//métodos get
	string getNome() const;
	string getMorada() const;
	string getGeneroArte() const;

	//métodos set
	void setNome(string nome);
	void setMorada(string morada);
	void setGeneroArte(string generoArte);


};


#endif /* PESSOA_HPP_ */
