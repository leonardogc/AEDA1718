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
public:
	Empresa(string (&nomes)[4]);
	static int numCandidato;
	int save_files();
};



#endif /* EMPRESA_HPP_ */
