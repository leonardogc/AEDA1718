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

bool Sessao::getStatus() const{
	return this->changeable;
}

void Sessao::setJurados(vector <Jurado *> jur){

}

void Sessao::setArtePerformativa(string artePerformativa){
	this->artePerformativa = artePerformativa;
}

void Sessao::setData(string data){
	this->data = data;
}

void Sessao::setStatus(bool status){
	this->changeable = status;
}

Sessao::Sessao(vector<Jurado *> jurados,string artePerformativa, string data, bool changeable){
	this->jurados = jurados;
	this->artePerformativa = artePerformativa;
	this->data = data;
	this->changeable = changeable;
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

void Sessao::alterarData(){

	bool verifica = false;

	//ter em atencao se so altera se for changeable
	do{
	string data;
	cout << "Insira a nova data da sessao no formato dd/mm/aaaa: ";
	getline(cin, data);

	//verificacao se a data e valida e esta no formato certo, se nao, pedir para reintroduzir
	if(isValidDate(data) == true){
		this->setData(data);
		verifica = true;
	}
	else{
		cout << "A data que introduziu nao esta correta! Tente novamente: ";
		verifica = false;
	}
	}while(verifica == false);
}

ostream& operator <<(ostream &os, const Sessao *s){
	os << setw(30) << left << s->artePerformativa;
	os << setw(20) << left << s->data;
	os << "\n";

	return os;
}
