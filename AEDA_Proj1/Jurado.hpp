#ifndef JURADO_HPP_
#define JURADO_HPP_

#include "Pessoa.hpp"
#include "utils.hpp"

/**
 *\class Jurado
 * Classe filha da classe pessoa, representando um jurado
 */
class Jurado: public Pessoa {
private:
	///telemovel do jurado, usado como identificador unico
	int telemovel; //must be 9 digits long
public:
	//construtores
	/**
	 * Construtor usado na criacao de um novo jurado atribuindo o valor de validade (na classe Pessoa) de forma automatica
	 * @param nome nome do jurado a criar
	 * @param morada local de residencia do jurado
	 * @param generoArte arte performativa que o jurado avalia
	 * @param telemovel numero de telemovel a atribuir ao novo jurado
	 */
	Jurado(string nome, string  morada, string  generoArte, int telemovel);

	/**
	 * Construtor usado na criacao de um jurado com base nos registos em ficheiros, permite definir todos os membros dado da classe
	 * @param nome nome do jurado a criar
	 * @param morada local de residencia do jurado
	 * @param generoArte arte performativa que o jurado avalia
	 * @param telemovel numero de telemovel a atribuir ao novo jurado
	 * @param validade define a validade do jurado na classe mae
	 */
	Jurado(string nome, string  morada, string  generoArte, int telemovel, bool validade);
	//métodos get
	/**
	 * Metodo que retorna o numero de telemovel do jurado
	 * @return inteiro com nove digitos, copia do membro dado telemovel
	 */
	int getTelemovel() const;

	//metodos set

	/**
	 *  Metodo que permite definir o telemovel
	 * @param telemovel numero de telemovel a atribuir ao jurado
	 */
	void setTelemovel(int telemovel);

	/**
	 * Metodo que permite escolher e atribuir um novo numero de telemovel ao jurado
	 */
	void alterarTelemovel();

	/**
	 * Metodo que permite escolher e atribuir uma nova moreda ao jurado
	 */
	void alterarMorada();

	/**
	 * Metodo que permite escolher e atribuir um novo nome ao jurado
	 */
	void alterarNome();

	//operadores
	/**
	 * Operador que compara o jurado atual com o jurado passado em parametro
	 * @param jurado jurado a comparar com o jurado atual
	 * @return true se os jurados tiverem o mesmo nome, morada e numero de telemovel, false em caso contrario
	 */
	bool operator== (Jurado jurado);
	friend ostream& operator <<(ostream & os, const Jurado *j);
};


/**
 * Operador para facilitar a escrita dos dados no ecra
 * @param os stream onde sao guardados os dados a imprimir
 * @param j jurado do qual se quer imprimir as informacoes
 * @return ostream os passada como parametro
 */
ostream& operator <<(ostream & os, const Jurado *j);


#endif /* JURADO_HPP_ */
