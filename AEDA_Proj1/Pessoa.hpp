#ifndef PESSOA_HPP_
#define PESSOA_HPP_

#include "utils.hpp"

/**
 * \class Pessoa
 * Super classe de Candidato e Jurado, reunindo os membros dados e funcoes comuns
 */
class Pessoa {
protected:

	/// Nome da pessoa
	string nome;

	/// Local de resindencia
	string morada;

	/// Arte praticada pela pessoa
	string generoArte;

	/// Validade da pessoa (marca-se uma pessoa como nao valida quando a intencao e eliminar a pessoa, passando a ser apenas possivel consultar os registos dessa pessoa)
	bool validade;
public:
	//construtor

	/**
	 * Construtor usado na criacao de uma nova pessoa, inicializando validade, por defeito como true
	 * @param nome nome a atribuir a nova pessoa
	 * @param morada local de residencia da nova pessoa
	 * @param generoArte genero de arte praticada pela pessoa a criar
	 */
	Pessoa(string nome, string  morada, string  generoArte);

	/**
	 * Construtor usado na criacao de uma pessoa com base em dados guardados num ficheiro
	 * @param nome nomes da pessoa a criar
	 * @param morada local de residencia da nova pessoa
	 * @param generoArte genero de arte praticada pela pessoa a criar
	 * @param validade booleano que indica dado o registo, se a pessoa a adicionar esta valida ou nao
	 */
	Pessoa(string nome, string  morada, string  generoArte, bool validade);

	//métodos get

	/**
	 * Metodo que permite obter o nome da pessoa
	 * @return copia da string com o nome da pessoa atual
	 */
	string getNome() const;

	/**
	 * Metodo que permite obter o local de residencia da pessoa
	 * @return copia da string com a morada da pessoa atual
	 */
	string getMorada() const;

	/**
	 * Metodo que permite obter o nome da arte performativa praticada
	 * @return copia da string com o genero de arte da pessoa atual
	 */
	string getGeneroArte() const;

	/**
	 * Metodo que permite obter a validade
	 * @return booleano com o valor de validade true ou false
	 */
	bool getValidade() const;

	//métodos set

	/**
	 * Metodo que permite definir o nome
	 * @param nome string com um nome a atribuir a pessoa
	 */
	void setNome(string nome);

	/**
	 * Metodo que permite definir a morada
	 * @param morada string com uma morada a atribuir a pessoa
	 */
	void setMorada(string morada);

	/**
	 * Metodo que permite definir a arte performativa
	 * @param generoArte string com um genero de arte performativa a atribuir a pessoa
	 */
	void setGeneroArte(string generoArte);

	/**
	 * Metodo que permite definir a validade da pessoa
	 * @param state booleano com o valor a atribuir a validade
	 */
	void setValid(bool state);
};


#endif /* PESSOA_HPP_ */
