#include "Sessao.hpp"

vector<Jurado *> Sessao::getJurados() const{
	return this->jurados;
}

string Sessao::getArtePerformativa() const{
	return this->artePerformativa;
}

string Sessao::getData() const{
	return this->data;
}

void Sessao::setJurados(vector <Jurado *> jur){

}

void Sessao::setArtePerformativa(string artePerformativa){
	this->artePerformativa = artePerformativa;
}

void Sessao::setData(string data){
	this->data = data;
}

Sessao::Sessao(vector<Jurado *> jurados,string artePerformativa, string data){
	this->jurados = jurados;
	this->artePerformativa = artePerformativa;
	this->data = data;
}

bool Sessao::operator== (Sessao sessao) const{
	bool variable = false;

	if(this->artePerformativa == sessao.getArtePerformativa() ){
		if (this->data == sessao.getData()){
			variable = true;
		}
	}

	return variable;
}

bool Sessao::operator< (Sessao sessao) const{
	bool variable = false;

	if(this->artePerformativa < sessao.getArtePerformativa() ){
		if (this->data < sessao.getData()){
			variable = true;
		}
	}

	return variable;
}

ostream& operator <<(ostream &os, const Sessao *s){
	os << setw(30) << left << s->artePerformativa;
	os << setw(20) << left << s->data;
	os << "\n";

	return os;
}
