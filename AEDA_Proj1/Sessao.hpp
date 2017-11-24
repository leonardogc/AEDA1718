#ifndef SESSAO_HPP_
#define SESSAO_HPP_

#include <vector>
#include <string>

#include "Jurado.hpp"
#include "utils.hpp"


/**
 * \class Sessao
 *
 * Classe utilizada para representar uma sessao
 */
class Sessao {
private:
	/// Vetor contendo os jurados da sessão, com um maximo de 3 jurados por sessão
	vector<Jurado *> jurados; // maximo de 3 jurados
	/// Arte da sessão, condiciona os jurados e candidatos que podem participar nesta. E tambem usada para identificar a sessão, juntamente com a data.
	string artePerformativa;
	/// Data da sessão no formato dd/mm/aaaa (dia/mes/ano), usada para identificar a sessão juntamente com a arte performativa
	string data; //simple string dd/mm/aaaa
	///booleano auxiliar que impede uma sessão de ser alterada apos serem geradas primeira e segunda fases
	bool changeable; //cangeable sessions can be changed because no phase has been generated
public:
	//construtor e destrutor
	/**
	 * Construtor da classe
	 * @param jurados vetor com os jurados previamente atribuidos a sessao
	 * @param artePerformativa arte performativa da sessao
	 * @param data data da sessão
	 * @param changeable valor booleano enviado como verdadeiro caso se adicione uma nova sessão mas podendo variar o valor na leitura de sessoes dos ficheiros
	 */
	Sessao(vector<Jurado *> jurados,string artePerformativa, string data, bool changeable);

	//métodos get

	/**
	 * Metodo que devolve uma copia do vetor de jurados
	 * @return vector com os jurados da sessao
	 */
	vector<Jurado *> getJurados() const;

	/**
	 * Metodo que devolve uma copia da string com a arte performativa da sessao
	 * @return string com o nome da arte performativa da sessao
	 */
	string getArtePerformativa() const;

	/**
	 * Metodo que retorna a data em que decorre a sessao
	 * @return string com a data no formato dd/mm/aaaa (dia/mes/ano)
	 */
	string getData() const;

	/**
	 * Metodo que retorna o estado da sessao (booleano changeable)
	 * @return true se ainda nao tiverem sido geradas primeira e segunda fases para a sessao, false em caso contrario
	 */
	bool getStatus() const;

	//metodos set

	/**
	 * Define os jurados da sessao para que fiquem de acordo com o vetor passado como parametro
	 * @param jur vetor com tres apontadores para jurados
	 */
	void setJurados(vector <Jurado *> jur);


	/**
	 * Define a data da sessao de acordo com o parametro dado
	 * @param data string com a data no formato dd/mm/aaaa (dia/mes/ano)
	 */
	void setData(string data);

	/**
	 * Define o estado da sessão de acordo com o parametro dado
	 * @param status booleano com o novo valor de changeable
	 */
	void setStatus(bool status);

	//operadores

	/**
	 * Operador que compara duas sessoes pela sua arte performativa e data (nao ha duas sessoes da mesma arte na mesma data)
	 * @param sessao sessao a ser comparada com a sessao atual
	 * @return true se ambas as sessoes tiverem a mesma arte performativa e a mesma arte
	 */
	bool operator== (Sessao sessao) const;

	//friend functions
	friend ostream& operator <<(ostream & os, const Sessao *s);


};

/**
 * Operador para facilitar a escrita dos dados no ecra
 * @param os stream onde são guardados os dados a imprimir
 * @param s sessao da qual se quer imprimir as informacoes
 * @return ostream os passada como parametro
 */
ostream& operator <<(ostream &os, const Sessao *s);

#endif /* SESSAO_HPP_ */
