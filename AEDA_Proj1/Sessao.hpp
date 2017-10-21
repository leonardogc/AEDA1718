#ifndef SESSAO_HPP_
#define SESSAO_HPP_

#include <vector>
#include <string>

#include "Jurado.hpp"
#include "utils.hpp"


class Sessao {
private:
	vector<Jurado *> jurados; // maximo de 3 jurados
	int indiceResponsavel; //indice do jurado responsável no vetor de jurados
	string artePerformativa;
	string data; //simple string dd/mm/aaaa
public:
};

#endif /* SESSAO_HPP_ */
