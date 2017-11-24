#ifndef JURADO_HPP_
#define JURADO_HPP_

#include "Pessoa.hpp"
#include "utils.hpp"

/**
 *
 */
class Jurado: public Pessoa {
private:
	int telemovel; //must be 9 digits long
public:
	//construtor
	/**
	 *
	 * @param nome
	 * @param morada
	 * @param generoArte
	 * @param telemovel
	 */
	Jurado(string nome, string  morada, string  generoArte, int telemovel);
	Jurado(string nome, string  morada, string  generoArte, int telemovel, bool validade);
	//m�todos get
	int getTelemovel() const;

	//metodos set
	void setTelemovel(int telemovel);
	void alterarTelemovel();
	void alterarMorada();
	void alterarNome();

	//operadores
	bool operator== (Jurado jurado);
	friend ostream& operator <<(ostream & os, const Jurado *j);
};

ostream& operator <<(ostream & os, const Jurado *j);


#endif /* JURADO_HPP_ */
