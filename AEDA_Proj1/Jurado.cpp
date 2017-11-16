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

void Jurado::alterarTelemovel(){

		int telemovel;

		while(true)
		{
			clear_scrn();
			cout << "Introduza o numero de telemovel: ";
			try{
				telemovel = read_number_Input();
			}
			catch(invalid_argument &e){
				cout << "Introduziu um numero de telemovel invalido!";
				cout << "\n\nPressione alguma tecla para continuar...\n";

				cin.ignore();
				continue;
			}

			if(numbr_size(telemovel) != 9){
				cout << "Introduziu um numero de telemovel invalido!";

				cout << "\n\nPressione alguma tecla para continuar...\n";

				cin.ignore();
				continue;
			}
			break;
		}

		this->telemovel = telemovel;
		cout << "O numero de telemovel foi alterado com sucesso!";

		cout << "\n\nPressione alguma tecla para continuar...\n";

		cin.ignore();
}

void Jurado::alterarMorada(){

		string morada;

		while(true)
		{
			clear_scrn();
			cout << "Introduza uma nova morada: ";

			getline(cin, morada);

			if(morada.size() > 0){
				break;
			}
			else{
				cout << "Introduziu uma morada invalida!";

				cout << "\n\nPressione alguma tecla para continuar...\n";

				cin.ignore();
				continue;
			}
		}

		this->morada = morada;
		cout << "A morada foi alterada com sucesso!";

		cout << "\n\nPressione alguma tecla para continuar...\n";

		cin.ignore();
}


ostream& operator <<(ostream & os, const Jurado *j){
	string validade= j->validade ? "valido" : "invalido";

	os << setw(30) << left << j->nome;
	os << setw(30) << left << j->generoArte;
	os << setw(20) << left << j->telemovel;
	os << setw(20) << left << j->morada;
	os << setw(20) << left << validade;
	os << "\n";
	return os;
}
