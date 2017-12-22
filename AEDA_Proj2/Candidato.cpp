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

pair<Participacao *, Participacao *> Candidato::getParticipacao(string const &dataSessao) const
{
	int first = -1, second = -1;
	for (unsigned i = 0; i < this->participacoes.size(); ++i)
	{
		if(((this->participacoes[i]->getSessao()->getData()) == dataSessao) &&
				((this->participacoes[i]->getSessao()->getArtePerformativa())) == this->generoArte)
		{
			if(participacoes[i]->getFase() == 1)
				first = i;
			else
				second = i;
		}
	}
	if(first < 0)
	{
		if(second < 0)
			return pair<Participacao *, Participacao *>(NULL, NULL);
		else return pair<Participacao *, Participacao *>(NULL, participacoes[second]);
	}
	else
		if(second < 0)
			return pair<Participacao *, Participacao *>(participacoes[first], NULL);
		else
			return pair<Participacao *, Participacao *>(participacoes[first], participacoes[second]);
}

bool Candidato::operator == (const Candidato &c) const {
	return this->numInscricao == c.numInscricao;
}


ostream& operator <<(ostream & os, const Candidato c){
	string validade= c.validade ? "valido" : "invalido";

	os << setw(20) << left << c.numInscricao;
	os << setw(30) << left << c.nome;
	os << setw(20) << left << c.dataNascimento;
	os << setw(30) << left << c.generoArte;
	os << setw(20) << left << c.morada;
	os << setw(20) << left << validade;
	os << "\n";

	return os;
}

bool Candidato::operator< (const Candidato & c) const
{
	if(this->getGeneroArte() == c.getGeneroArte())
	{
		if(this->getDataNasc() != c.getDataNasc())
			return lowerThan(c.getDataNasc(), this->getDataNasc());
		else
		{
			if(this->getNome() != c.getNome())
				return this->getNome() < c.getNome();
		}
	}
	return this->getGeneroArte() < c.getGeneroArte();
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

		pressKeyToContinue();
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

				pressKeyToContinue();
				continue;
			}
		}

		this->morada = morada;
		cout << "A morada foi alterada com sucesso!";

		pressKeyToContinue();
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

				pressKeyToContinue();
				continue;
			}
		}

		this->nome = nome;
		cout << "O nome foi alterado com sucesso!";

		pressKeyToContinue();
}

bool Candidato::removeParticipacao(Sessao * sessao){
	bool verifica = false;

	if(sessao->getStatus() == false){

		cout << "Nao e possivel remover o candidato! A sessao ja comecou!";
		return false;
	}
	else{
		for(unsigned int i = 0; i < participacoes.size(); i++){
			if(*sessao == *(participacoes[i]->getSessao())){
				delete participacoes[i];
				participacoes.erase(participacoes.begin()+i);
				return true;
			}
		}
	}

	return false;
}
