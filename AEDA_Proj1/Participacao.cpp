#include "Participacao.hpp"


Participacao::Participacao(Sessao * sessao, int pontuacao[3], int posicao, int fase): sessao(sessao)
{
	int pontuacao_final=0;

	if(fase == 1){
		pontuacao_final+= (int)(((double)(1/3))*pontuacao[0]);
		pontuacao_final+= (int)(((double)(1/3))*pontuacao[1]);
		pontuacao_final+= (int)(((double)(1/3))*pontuacao[2]);
	}
	else if (fase == 2){
		pontuacao_final+= (int)(((double)(2/4))*pontuacao[0]);
		pontuacao_final+= (int)(((double)(1/4))*pontuacao[1]);
		pontuacao_final+= (int)(((double)(1/4))*pontuacao[2]);
	}

	this->pontuacao[0]=pontuacao_final;
	this->pontuacao[1]=pontuacao[0];
	this->pontuacao[2]=pontuacao[1];
	this->pontuacao[3]=pontuacao[2];

	this->posicao = posicao;
	this->fase = fase;
}
const Sessao * Participacao::getSessao() const
{
	return this->sessao;
}
bool Participacao::operator== (const Participacao &p) const
{
	return ((* (this->sessao)) == (*(p.sessao)) && (this->fase == p.fase));
}

void Participacao::setPontuacao(int pontuacao[4])
{
	this->pontuacao[0] = pontuacao[0];
	this->pontuacao[1] = pontuacao[1];
	this->pontuacao[2] = pontuacao[2];
	this->pontuacao[3] = pontuacao[3];
}
void Participacao::setPosicao(int posicao)
{
	this->posicao=posicao;
}

int Participacao::getPontuacaoFinal(){
	return this->pontuacao[0];
}

int Participacao::getFase(){
	return this->fase;
}
