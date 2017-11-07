#ifndef PESSOA_HPP_
#define PESSOA_HPP_

#include "utils.hpp"


class Pessoa {
protected:
	string nome;
	string morada;
	string generoArte;
	bool validade;
public:
	//construtor
	Pessoa(string nome, string  morada, string  generoArte);
	Pessoa(string nome, string  morada, string  generoArte, bool validade);

	//métodos get
	string getNome() const;
	string getMorada() const;
	string getGeneroArte() const;
	bool getValidade() const;

	//métodos set
	void setNome(string nome);
	void setMorada(string morada);
	void setGeneroArte(string generoArte);
	void setValid(bool state);
};


#endif /* PESSOA_HPP_ */
