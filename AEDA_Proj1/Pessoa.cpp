#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, string morada, string generoArte){
	this->nome=nome;
	this->morada=morada;
	this->generoArte=generoArte;
}

string Pessoa::getNome() const{
	return this->nome;
}

string Pessoa::getMorada() const{
	return this->morada;
}

string Pessoa::getGeneroArte() const{
	return this->generoArte;
}


void Pessoa::setNome(string nome){
	this->nome = nome;
}


void Pessoa::setMorada(string morada){
	this->morada = morada;
}

void Pessoa::setGeneroArte(string generoArte){
	this->generoArte = generoArte;
}

