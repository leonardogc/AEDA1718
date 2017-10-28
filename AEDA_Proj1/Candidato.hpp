#ifndef CANDIDATO_HPP_
#define CANDIDATO_HPP_

#include "Participacao.hpp"
#include "Pessoa.hpp"
#include "utils.hpp"

class Candidato: protected Pessoa {
private:
	string dataNascimento;
	int numInscricao;
	vector <Participacao *> participacoes;

	/*
	 * se cada pessoa guardar as suas participa��es o vetor � mais pequeno do que se fosse guardado nas sessoes
	 * e para sabem quem participou em cada sess�o pode-se evitar percorrer todos os candidatos saltando os que n�o sejam da arte da sessao
	 */
public:
	static unsigned int numCandidato;
	Candidato();
	string getData();
	int getId();
	vector <Participacao *> getParticipacao();

};

#endif /* CANDIDATO_HPP_ */
