#include "Empresa.hpp"


using namespace castingspace;

Empresa::Empresa(string (&nomes)[4]) {
	load_files(nomes);
}

/*
 * Formato dos ficheiros: (pode sofrer alteração)
 *
 * jurados.txt
 * Nome;morada;telemovel;generoArte;validade;\n
 *
 * Sessoes.txt
 * numTelemJurado1(responsável);numTelemJurado2;numTelemJurado3;artePerformativa;data;\n
 *
 * Candidatos.txt
 * numInscrição;nome;dataNascimento;generoArte;morada;validade;\n
 *
 * Participacao.txt
 * numInscrição;Fase;Data;Pontuação1(juradoResponsável);Pontuação2;Pontuação3;Posição;
 */

void Empresa::load_files(string (&nomes)[4]){
	load_candidatos(nomes[2]);
	load_jurados(nomes[0]);
	load_sessoes(nomes[1]);
	load_participacao(nomes[3]);
}

void Empresa::load_jurados(string &s){
	ifstream file;
	stringstream ss;
	string ficheiro="res/"+s, line, nome, morada, generoArte;
	int telemovel;
	bool validade = false;

	file.open(ficheiro.c_str());

	if(file.is_open()){
		while(getline(file, line)){
			//nome

			parse_line(line, ss);
			nome=ss.str();

			ss.str(string());
			ss.clear();

			//morada

			parse_line(line, ss);

			morada=ss.str();

			ss.str(string());
			ss.clear();

			//telemovel

			parse_line(line, ss);

			ss >> telemovel;

			ss.str(string());
			ss.clear();

			//generoArte

			parse_line(line, ss);

			generoArte=ss.str();

			ss.str(string());
			ss.clear();

			//validade

			parse_line(line, ss);
			if(ss.str() == "valid")
				validade = true;

			ss.str(string());
			ss.clear();

			jurados.push_back(new Jurado(nome, morada, generoArte, telemovel, validade));
		}
		file.close();

	}
	else{
		//cout<<"error opening file!"<<endl;
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::load_sessoes(string &s){
	ifstream file;
	stringstream ss;
	string ficheiro = "res/"+s, line, artePerformativa, data;
	vector<Jurado *> jurados;
	int numTelemJurado1, numTelemJurado2, numTelemJurado3;

	file.open(ficheiro.c_str());

	if(file.is_open()){
		while(getline(file, line)){
			//numTelemJurado1(responsável)

			parse_line(line, ss);

			ss >> numTelemJurado1;

			ss.str(string());
			ss.clear();

			//numTelemJurado2

			parse_line(line, ss);

			ss >> numTelemJurado2;

			ss.str(string());
			ss.clear();

			//numTelemJurado3

			parse_line(line, ss);

			ss >> numTelemJurado3;

			ss.str(string());
			ss.clear();

			//artePerformativa
			parse_line(line, ss);

			artePerformativa=ss.str();

			ss.str(string());
			ss.clear();

			//data

			parse_line(line, ss);

			data=ss.str();

			ss.str(string());
			ss.clear();

			for (unsigned i=0; i< this->jurados.size();i++){
				if(this->jurados[i]->getTelemovel() == numTelemJurado1){
					jurados.push_back(this->jurados[i]);
				}
			}

			for (unsigned i=0; i< this->jurados.size();i++){
				if(this->jurados[i]->getTelemovel() == numTelemJurado2){
					jurados.push_back(this->jurados[i]);
				}
			}

			for (unsigned i=0; i< this->jurados.size();i++){
				if(this->jurados[i]->getTelemovel() == numTelemJurado3){
					jurados.push_back(this->jurados[i]);
				}
			}

			sessoes.push_back(new Sessao(jurados, 0, artePerformativa, data));
		}
		file.close();

	}
	else{
		//cout<<"error opening file!"<<endl;
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::load_candidatos(string &s){
	ifstream file;
	stringstream ss;
	string ficheiro = "res/"+s, line, nome, dataNascimento, generoArte, morada;
	int numInscricao;
	bool validade = false;

	file.open(ficheiro.c_str());


	if(file.is_open()){
		while(getline(file,line)){

			//numInscricao

			parse_line(line, ss);

			ss >> numInscricao;

			ss.str(string());
			ss.clear();

			//nome

			parse_line(line, ss);

			nome=ss.str();

			ss.str(string());
			ss.clear();

			//dataNascimento

			parse_line(line, ss);

			dataNascimento=ss.str();

			ss.str(string());
			ss.clear();

			//generoArte

			parse_line(line, ss);

			generoArte=ss.str();

			ss.str(string());
			ss.clear();


			//morada

			parse_line(line, ss);

			morada=ss.str();

			ss.str(string());
			ss.clear();

			//validade

			parse_line(line, ss);
			if(ss.str() == "valid")
				validade = true;

			ss.str(string());
			ss.clear();

			candidatos.push_back(new Candidato(numInscricao,nome,morada,generoArte,dataNascimento, validade));
		}
		file.close();
	}
	else{
		//cout<<"error opening file!"<<endl;
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::load_participacao(string &s){
	ifstream file;
	stringstream ss;
	string ficheiro = "res/"+s, data, line, generoArte;
	int numInscricao, fase, pontuacao1, pontuacao2, pontuacao3, posicao;
	int pontuacao_array[3];
	int sessao;

	file.open(ficheiro.c_str());

	if(file.is_open()){
		while(getline(file, line)){
			//numInscrição

			parse_line(line, ss);

			ss >> numInscricao;


			ss.str(string());
			ss.clear();

			//Fase

			parse_line(line, ss);

			ss >> fase;

			ss.str(string());
			ss.clear();

			//Data

			parse_line(line, ss);

			data = ss.str();

			ss.str(string());
			ss.clear();

			//Pontuação1(juradoResponsável)

			parse_line(line, ss);

			ss >> pontuacao1;

			ss.str(string());
			ss.clear();

			//Pontuação2

			parse_line(line, ss);

			ss >> pontuacao2;

			ss.str(string());
			ss.clear();

			//Pontuação3

			parse_line(line, ss);

			ss >> pontuacao3;

			ss.str(string());
			ss.clear();

			//Posicao

			parse_line(line, ss);

			ss >> posicao;

			ss.str(string());
			ss.clear();

			for (unsigned i = 0; i < candidatos.size(); i++){
				if(candidatos[i]->getNumInscricao() == numInscricao){
					generoArte=candidatos[i]->getGeneroArte();
				}
			}


			for (unsigned i = 0; i < sessoes.size(); i++){
				if((sessoes[i]->getData()==data) && (sessoes[i]->getArtePerformativa() == generoArte)){
					sessao = i;
				}
			}

			pontuacao_array[0]=pontuacao1;
			pontuacao_array[1]=pontuacao2;
			pontuacao_array[2]=pontuacao3;

			for (unsigned i = 0; i < candidatos.size(); i++){
				if(candidatos[i]->getNumInscricao() == numInscricao){
					candidatos[i]->addParticipacao(new Participacao(sessoes[sessao], pontuacao_array, posicao, fase));
					break;
				}
			}
		}
		file.close();
	}
	else{
		//cout<<"error opening file!"<<endl;
		throw(InvalidFileNameException(ficheiro));
	}
}

vector <Candidato *> Empresa::getCandidatos(){
	return candidatos;
}

vector <Jurado *> Empresa::getJurados(){

	return jurados;
}

vector <Sessao *> Empresa::getSessoes(){

	return sessoes;
}


void Empresa::remove_candidato(int id){
	for (unsigned i = 0; i < this->candidatos.size(); ++i)
		if(this->candidatos[i]->getNumInscricao() == id)
		{
			this->candidatos.erase(this->candidatos.begin()+i);
			return;
		}
	//TODO throw exception
}


void Empresa::sortJurados(castingspace::sort_t const & by)
{
	switch(by)
	{
	case by_name:
		sort(this->jurados.begin(), this->jurados.end(), [](Jurado * j1, Jurado * j2){
			return j1->getNome() < j2->getNome();
		});
		break;
	case by_name_and_art:
		sort(this->jurados.begin(), this->jurados.end(), [](Jurado * j1, Jurado * j2){
			if(j1->getGeneroArte() == j2->getGeneroArte())
			{
				return j1->getNome() < j2->getNome();
			}
			else return j1->getGeneroArte() < j2->getGeneroArte();
		});
		break;
	default:
		break;
	}
}

void Empresa::sortSessoes(castingspace::sort_t const & by)
{
	switch(by)
	{
	case by_date_and_art:
		sort(this->sessoes.begin(), this->sessoes.end(), [](Sessao * s1, Sessao * s2){
			if(s1->getArtePerformativa() == s2->getArtePerformativa())
			{
				return lowerThan(s1->getData(), s2->getData());
			}
			else return s1->getArtePerformativa() < s2->getArtePerformativa();
		});
		break;
	default:
		break;
	}
}

void Empresa::sortCandidatos(castingspace::sort_t const & by)
{
	switch(by)
	{
	case by_name:
		sort(this->candidatos.begin(), this->candidatos.end(), [](Candidato * c1, Candidato * c2){
			return c1->getNome() < c2->getNome();
		});
		break;
	case by_name_and_art:
		sort(this->candidatos.begin(), this->candidatos.end(), [](Candidato * c1, Candidato * c2){
			if(c1->getGeneroArte() == c2->getGeneroArte())
			{
				return c1->getNome() < c2->getNome();
			}
			else return c1->getGeneroArte() < c2->getGeneroArte();
		});
		break;
	case by_age_and_art:
		sort(this->candidatos.begin(), this->candidatos.end(), [](Candidato * c1, Candidato * c2){
			if(c1->getGeneroArte() == c2->getGeneroArte())
			{
				return lowerThan(c2->getDataNasc(), c1->getDataNasc());
				//younger people were born later, so birthdate is larger for the younger
			}
			else return c1->getGeneroArte() < c2->getGeneroArte();
		});
		break;
	default:
		break;
	}
}

void parse_line(string &line, stringstream &ss){
	for (unsigned i=0; i < line.size(); i++){
		if(line[i] != ';'){
			ss<<line[i];
		}
		else if(line[i] == ';'){
			line.erase(0,i+1);
			break;
		}
	}
}

void sortBy_points_in_session(vector<Candidato *> &candidatos, string const &dataSessao)
{
	sort(candidatos.begin(), candidatos.end(), [&dataSessao](Candidato * c1, Candidato * c2){
		return c1->getParticipacao(dataSessao)->getPontuacaoFinal() < c2->getParticipacao(dataSessao)->getPontuacaoFinal();
	});
}


/*
Candidato * Empresa::remove_candidato(int id){

	for(unsigned int i = 0; i < getCandidatos.size(); i++){
		if(id == getCandidatos[i]->getNumInscricao){

		}

	}

	return -1;
}

 */


