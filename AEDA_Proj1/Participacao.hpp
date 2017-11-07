#ifndef PARTICIPACAO_HPP_
#define PARTICIPACAO_HPP_

#include "Sessao.hpp"
#include "utils.hpp"

class Participacao {
private:
	Sessao const * sessao; //assumindo que participacoes sao guardadas nos concorrentes
	int pontuacao[4]; // pontuacao "0" é a pontuacao final, "1" jurado principal , "2" e "3" os outros jurados
	int posicao;
	int fase;
public:
	Participacao(Sessao * sessao, int pontuacao[3], int posicao, int fase);
	const Sessao * getSessao() const;
	void setPontuacao(int pontuacao[4]);
	void setPosicao(int posicao);
	int getPontuacaoFinal();
	bool operator == (const Participacao &p) const;
};

#endif /* PARTICIPACAO_HPP_ */
