#include "Candidato.hpp"

unsigned int Candidato::numCandidato = 1;

Candidato::Candidato(string nome, string  morada, string  generoArte, string dataNascimento):
		Pessoa(nome, morada, generoArte), numInscricao(numCandidato++)
{
	this->dataNascimento = dataNascimento;
}

