#ifndef PARTICIPACAO_HPP_
#define PARTICIPACAO_HPP_

#include "Sessao.hpp"
#include "utils.hpp"

/**
 * \class Participacao
 * Classe que representa uma participacao numa sessao
 */
class Participacao {
private:

	///sessao a que diz respeito a participacao
	Sessao const * sessao; //participacoes sao guardadas nos candidatos

	/// Array com as pontuacoes atribuidas e com a estrutura: {pontuacao final, pontuacao jurado principal, pontuacao segundo jurado, pontuacao terceiro jurado}
	int pontuacao[4]; // pontuacao "0" é a pontuacao final, "1" jurado principal , "2" e "3" os outros jurados

	///Posicao em que as pontuacoes colocam o candidato na sessao
	int posicao;

	///Fase da sessao a que diz respeito a participacao
	int fase;
public:

	/**
	 * Construtor para criar uma participacao, fazendo o calculo da pontuacao final
	 * @param sessao sessao a que diz respeito a participacao
	 * @param pontuacao pontuacoes atribuidas pelos jurados
	 * @param posicao posicao em que o candidato fica colocado nesta fase da sessao
	 * @param fase fase da sessao a que dizem respeito as pontuacoes e a posicao
	 */
	Participacao(Sessao * sessao, int pontuacao[3], int posicao, int fase);

	//Metodos Get

	/**
	 * Metodo que permite obter um apontador para a sessao desta participacao
	 * @return um apontador para a sessao a que diz respeito a participacao
	 */
	const Sessao * getSessao() const;

	/**
	 * Metodo que permite obter a pontuacao final
	 * @return inteiro copia do primeiro elemento do array pontuacoes
	 */
	int getPontuacaoFinal();

	/**
	 * Metodo que permite obter a posicao do candidato na fase da sessao
	 * @return inteiro copia do membro dado posicao
	 */
	int getPosicao();

	/**
	 * Metodo que retorna a pontuacao completa
	 * @return apontador para o primeiro elemento do array pontuacao
	 */
	int* getPontuacao();

	/**
	 * Metodo que permite obter a fase
	 * @return inteiro copia do membro dado fase
	 */
	int getFase();

	//Metodos Set

	/**
	 * Metodo que permite definir todas as pontuacoes nesta participacao
	 * @param pontuacao array de tamanho 4 com as pontuacoes a atribuir, no formato do membro dado pontuacao
	 */
	void setPontuacao(int pontuacao[4]);

	/**
	 * Metodo que permite definir a posicao do candidato na sessao, apos ser gerada a fase atual
	 * @param posicao inteiro representando a posicao do candidato na sessao
	 */
	void setPosicao(int posicao);

	/**
	 * Operador que compara a participacao atual com a participacao passada em parametro
	 * @param p participacao a comparar com a participacao atual
	 * @return true se as participacoes corresponderem a mesma fase da mesma sessao, false em caso contrario
	 */
	bool operator == (const Participacao &p) const;
	friend ostream& operator <<(ostream &os, const Participacao *p);
};

/**
 * Operador para facilitar a escrita dos dados no ecra
 * @param os stream onde sao guardados os dados a imprimir
 * @param p apontador para a participacao da qual se quer imprimir as informacoes
 * @return ostream os passada como parametro
 */
ostream& operator <<(ostream &os, const Participacao *p);

#endif /* PARTICIPACAO_HPP_ */
