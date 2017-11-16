#ifndef CANDIDATO_HPP_
#define CANDIDATO_HPP_

#include "Participacao.hpp"
#include "Pessoa.hpp"
#include "utils.hpp"



class Candidato: public Pessoa {
private:
	string dataNascimento;
	const int numInscricao;
	vector <Participacao *> participacoes;
	/*
	 * se cada pessoa guardar as suas participa��es o vetor � mais pequeno do que se fosse guardado nas sessoes
	 * e para sabem quem participou em cada sess�o pode-se evitar percorrer todos os candidatos saltando os que n�o sejam da arte da sessao
	 */
public:
	static unsigned int numCandidato;
	Candidato(string nome, string  morada, string  generoArte, string dataNascimento);
	Candidato(int nInscricao, string nome, string  morada, string  generoArte, string dataNascimento, bool validade);
	string getDataNasc() const;
	int getNumInscricao() const;
	vector <Participacao *> getParticipacoes() const;
	bool addParticipacao(Participacao * participacao);

	Participacao * getParticipacao(string const &dataSessao) const;
	bool operator == (const Candidato &c) const;

	void printParticipacoes();

	void alterarMorada();
	void alterarNome();

	friend ostream& operator <<(ostream & os,const Candidato *c);
};

ostream& operator <<(ostream & os, const Candidato *c);


#endif /* CANDIDATO_HPP_ */
