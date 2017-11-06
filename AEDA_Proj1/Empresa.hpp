#ifndef EMPRESA_HPP_
#define EMPRESA_HPP_

#include "Candidato.hpp"
#include "Jurado.hpp"
#include "Participacao.hpp"
#include "Pessoa.hpp"
#include "Sessao.hpp"
#include "utils.hpp"


class Empresa {
private:
	vector<Jurado *> jurados;
	vector<Candidato *> candidatos;
	vector<Sessao *> sessoes;
	void load_files(string (&nomes)[4]);
	void load_jurados(string &s);
	void load_sessoes(string &s);
	void load_candidatos(string &s);
	void load_participacao(string &s);
public:
	Empresa(string (&nomes)[4]);
	vector<Jurado *> getJurados();
	vector<Candidato *> getCandidatos();
	vector<Sessao *> getSessoes();
	Candidato * remove_candidato(int id);
	int save_files();
};


void parse_line(string &line, stringstream &ss);

#endif /* EMPRESA_HPP_ */
