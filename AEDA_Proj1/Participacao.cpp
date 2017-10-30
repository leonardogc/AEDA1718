#include "Participacao.hpp"


Participacao::Participacao(Sessao * sessao, int pontuacao, int posicao): sessao(sessao)
{
	this->pontuacao=pontuacao;
	this->posicao = posicao;
}
const Sessao * Participacao::getSessao() const
{
	return this->sessao;
}
bool Participacao::operator== (const Participacao &p) const
{
	return (* this->sessao) == (*p.sessao);
}

void Participacao::setPontuacao(int pontuacao)
{
	this->pontuacao = pontuacao;
}
void Participacao::setPosicao(int posicao)
{
	this->posicao=posicao;
}
