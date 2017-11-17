#include "Candidato.hpp"

unsigned int Candidato::numCandidato = 1;


Candidato::Candidato(string nome, string  morada, string  generoArte, string dataNascimento):
				Pessoa(nome, morada, generoArte), numInscricao(numCandidato++)
{
	this->dataNascimento = dataNascimento;
}

Candidato::Candidato(int nInscricao, string nome, string  morada, string  generoArte, string dataNascimento, bool validade):
				Pessoa(nome, morada, generoArte, validade), numInscricao(nInscricao)
{
	this->dataNascimento = dataNascimento;
	numCandidato++;
}

string Candidato::getDataNasc() const{
	return this->dataNascimento;
}

int Candidato::getNumInscricao() const{
	return this->numInscricao;
}

vector <Participacao *> Candidato::getParticipacoes() const
{
	return this->participacoes;
}
bool Candidato::addParticipacao(Participacao * participacao)
{
	for (unsigned i = 0; i < this->participacoes.size(); ++i)
	{
		if((*participacao) == (*this->participacoes[i]))
		{
			return false;
		}
	}
	this->participacoes.push_back(participacao);
	return true;
}

Participacao * Candidato::getParticipacao(string const &dataSessao) const
{
	for (unsigned i = 0; i < this->participacoes.size(); ++i)
	{
		if(((this->participacoes[i]->getSessao()->getData()) == dataSessao) &&
				((this->participacoes[i]->getSessao()->getArtePerformativa())) == this->generoArte)
		{
			return participacoes[i];
		}
	}
	return NULL;
}
bool Candidato::operator == (const Candidato &c) const {
	return this->numInscricao == c.numInscricao;
}


ostream& operator <<(ostream & os, const Candidato *c){
	string validade= c->validade ? "valido" : "invalido";

	os << setw(20) << left << c->numInscricao;
	os << setw(30) << left << c->nome;
	os << setw(20) << left << c->dataNascimento;
	os << setw(30) << left << c->generoArte;
	os << setw(20) << left << c->morada;
	os << setw(20) << left << validade;
	os << "\n";

	return os;
}

void Candidato::printParticipacoes(){
		cout << "\n\n";
		cout << setw(20) << left << "Posicao";
		cout << setw(20) << left << "Fase";
		cout << setw(20) << left << "Pontuacao";
		cout << setw(30) << left << "Genero de Arte";
		cout << setw(20) << left << "Data";
		cout << "\n\n";

		for(unsigned i=0; i < participacoes.size(); i++){
			cout << participacoes[i];
		}

		waitEnterToContinue();
}

void Candidato::alterarMorada(){

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

				waitEnterToContinue();
				continue;
			}
		}

		this->morada = morada;
		cout << "A morada foi alterada com sucesso!";

		waitEnterToContinue();
}

void Candidato::alterarNome(){

		string nome;

		while(true)
		{
			clear_scrn();
			cout << "Introduza o novo nome: ";

			getline(cin, nome);

			if(nome.size() > 0){
				break;
			}
			else{
				cout << "Introduziu um nome invalido!";

				waitEnterToContinue();
				continue;
			}
		}

		this->nome = nome;
		cout << "O nome foi alterado com sucesso!";

		waitEnterToContinue();
}

bool Candidato::removeParticipacao(Participacao * participacao){
	bool verifica = false;

	if(participacao->getSessao()->getStatus() == false){
		verifica = false;
		cout << "Nao e possivel remover o candidato! A sessao ja comecou!";
	}
	else{
		for(unsigned int i = 0; i < participacoes.size(); i++){
			if(participacao == participacoes[i]){
				participacoes.erase(participacoes.begin()+i);
				verifica = true;
				break;
			}
		}
	}

	return verifica;
}
