#ifndef PARTICIPACAO_HPP_
#define PARTICIPACAO_HPP_

#include "Sessao.hpp"
#include "utils.hpp"

class Participacao {
private:
	Sessao const * sessao; //assumindo que participacoes sao guardadas nos concorrentes
	int pontuacao;
	int pontucao_2_fase;
	int posicao;
public:
	Participacao(Sessao * sessao, int pontuacao, int posicao);
	const Sessao * getSessao() const;
	void setPontuacao(int pontuacao);
	void setPosicao(int posicao);
	bool operator == (const Participacao &p) const;
};

#endif /* PARTICIPACAO_HPP_ */
