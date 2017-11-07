#include "Candidato.hpp"

unsigned int Candidato::numCandidato = 1;

Candidato::Candidato(string nome, string  morada, string  generoArte, string dataNascimento):
		Pessoa(nome, morada, generoArte), numInscricao(numCandidato++)
{
	this->dataNascimento = dataNascimento;
}

Candidato::Candidato(int nInscricao, string nome, string  morada, string  generoArte, string dataNascimento):
		Pessoa(nome, morada, generoArte), numInscricao(nInscricao)
{
	this->dataNascimento = dataNascimento;
}

string Candidato::getDataNasc() const{
	return this->dataNascimento;
}

int Candidato::getNumInscricao() const{
	return this->numInscricao;
}

vector <Participacao *> Candidato::getParticipacoes() const
{
	return this->participacoes;
}
bool Candidato::addParticipacao(Participacao * participacao)
{
	for (unsigned i = 0; i < this->participacoes.size(); ++i)
	{
		if((*participacao) == (*this->participacoes[i]))
		{
			return false;
		}
	}
	this->participacoes.push_back(participacao);
	return true;
}

/*
 * TODO DELETE \/
 */
Participacao * Candidato::getParticipacao(Sessao * sessao) const
{
	for (unsigned i = 0; i < this->participacoes.size(); ++i)
	{
		if((*this->participacoes[i]->getSessao()) == (* sessao))
		{
			return participacoes[i];
		}
	}
	return NULL;
}
/*
 * TODO DELETE /\
 */

Participacao * Candidato::getParticipacao(string const &dataSessao) const
{
	for (unsigned i = 0; i < this->participacoes.size(); ++i)
	{
		if(((*this->participacoes[i]->getSessao()->getData()) == dataSessao) &&
				((*this->participacoes[i]->getSessao()->getArtePerformativa())) == this->generoArte)
		{
			return participacoes[i];
		}
	}
	return NULL;
}
bool Candidato::operator == (const Candidato &c) const {
	return this->numInscricao == c.numInscricao;
}
