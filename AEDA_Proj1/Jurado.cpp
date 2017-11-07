#include "Jurado.hpp"


Jurado::Jurado(string nome, string  morada, string  generoArte, int telemovel):
Pessoa(nome, morada, generoArte)
{
	this->telemovel = telemovel;
}

Jurado::Jurado(string nome, string  morada, string  generoArte, int telemovel, bool validade):
Pessoa(nome, morada, generoArte, validade)
{
	this->telemovel = telemovel;
}

int Jurado::getTelemovel() const{
	return this->telemovel;
}

void Jurado::setTelemovel(int telemovel){
	this->telemovel = telemovel;
}

bool Jurado::operator ==(Jurado jurado){
	bool variable = false;
	if(this->nome == jurado.nome && this->morada == jurado.morada && this->telemovel == jurado.telemovel)
		variable = true;
	return variable;
}
