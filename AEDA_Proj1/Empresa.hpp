#ifndef EMPRESA_HPP_
#define EMPRESA_HPP_

#include "Candidato.hpp"
#include "Jurado.hpp"
#include "Participacao.hpp"
#include "Pessoa.hpp"
#include "Sessao.hpp"
#include "utils.hpp"

namespace castingspace //TO DO get a better name
{
	/**
	 * Enum type used in the sorting methods
	 */

	enum sort_t
	{
		by_name,
		by_name_and_art,
    by_age_and_art,
    by_date_and_art
	};
}

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
	void sortJurados(castingspace::sort_t const & by):
	void sortSessoes(castingspace::sort_t const & by);
	void sortCandidatos(castingspace::sort_t const & by);
};

void sortBy_points_in_session(vector<Candidato> &candidatos, string const &dataSessao);

void parse_line(string &line, stringstream &ss);

#endif /* EMPRESA_HPP_ */
