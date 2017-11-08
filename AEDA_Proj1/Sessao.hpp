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
	//construtor
	Sessao(vector<Jurado *> jurados, int indiceResponsavel,string artePerformativa, string data);

	//métodos get
	vector<Jurado *> getJurados() const;
	int getIndiceResponsavel() const;
	string getArtePerformativa() const;
	string getData() const;

	//metodos set
	void setJurados(vector <Jurado *> jur);
	void setIndiceResponsavel(int indiceResponsavel);
	void setArtePerformativa(string artePerformativa);
	void setData(string data);

	//operadores
	bool operator== (Sessao sessao) const;
	bool operator< (Sessao sessao) const;
	friend ostream& operator <<(ostream & os, const Sessao *s);
};

ostream& operator <<(ostream &os, const Sessao *s);

#endif /* SESSAO_HPP_ */
