#ifndef SESSAO_HPP_
#define SESSAO_HPP_

#include <vector>
#include <string>

#include "Jurado.hpp"
#include "utils.hpp"


class Sessao {
private:
	vector<Jurado *> jurados; // maximo de 3 jurados
	string artePerformativa;
	string data; //simple string dd/mm/aaaa
	bool changeable; //cangeable sessions can be changed because no phase has been generated
	bool primeira_fase_gerada;
	bool segunda_fase_gerada;
public:
	//construtor e destrutor
	Sessao(vector<Jurado *> jurados,string artePerformativa, string data, bool changeable);
	//~Sessao();
	//métodos get
	vector<Jurado *> getJurados() const;
	string getArtePerformativa() const;
	string getData() const;
	bool getStatus() const;
	bool get_primeira_fase_gerada();
	bool get_segunda_fase_gerada();


	//metodos set
	void setJurados(vector <Jurado *> jur);
	void setArtePerformativa(string artePerformativa);
	void setData(string data);
	void setStatus(bool status);
	void set_primeira_fase_gerada(bool status);
	void set_segunda_fase_gerada(bool status);

	//operadores
	bool operator== (Sessao sessao) const;
	bool operator< (Sessao sessao) const;
	friend ostream& operator <<(ostream & os, const Sessao *s);

	//outros
	void alterarData();
};

ostream& operator <<(ostream &os, const Sessao *s);

#endif /* SESSAO_HPP_ */
