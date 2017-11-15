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

	void save_jurados(string &s);
	void save_sessoes(string &s);
	void save_candidatos(string &s);
	void save_participacao(string &s);
public:
	Empresa(string (&nomes)[4]);
	vector<Jurado *> getJurados();
	vector<Candidato *> getCandidatos();
	vector<Sessao *> getSessoes();

	void printJurados();
	void printCandidatos();
	void printSessoes();

	void remove_candidato(int id);
	void adicionar_candidato(Candidato *c);
	void adicionar_jurado(Jurado *j);

	void save_files(string (&nomes)[4]);

	void sortJurados(castingspace::sort_t const & by);
	void sortSessoes(castingspace::sort_t const & by);
	void sortCandidatos(castingspace::sort_t const & by);

	Candidato* escolher_candidato();
	Jurado*  escolher_jurado();
	string adicionar_candidato();
	string adicionar_jurado();
	string adicionar_sessao();
	string remover_jurado();
	string remover_candidato();
};

void sortBy_points_in_session(vector<Candidato> &candidatos, string const &dataSessao);

void parse_line(string &line, stringstream &ss);

#endif /* EMPRESA_HPP_ */
