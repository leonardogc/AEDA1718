#include "Empresa.hpp"


using namespace castingspace;

Empresa::Empresa(string (&nomes)[4]):candidatos(NoCandidate) {
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

void Empresa::save_files(string (&nomes)[4]){
	save_candidatos(nomes[2]);
	save_jurados(nomes[0]);
	save_sessoes(nomes[1]);
	save_participacao(nomes[3]);
}

void Empresa::save_candidatos(string &s){
	ofstream file;
	string ficheiro = "res/"+s,validade;

	file.open(ficheiro.c_str(), ios::out | ios::trunc);


	if(file.is_open()){
		//TODO CHECK BST
		BSTItrIn<Candidato> it(candidatos);

		while(! it.isAtEnd())
		{
			validade= it.retrieve().getValidade() ? "valid" : "invalid";

			file << it.retrieve().getNumInscricao() << ";";
			file << it.retrieve().getNome() << ";";
			file << it.retrieve().getDataNasc() << ";";
			file << it.retrieve().getGeneroArte() << ";";
			file << it.retrieve().getMorada() << ";";
			file << validade << ";";

			it.advance();

			if(! it.isAtEnd()){
				file << "\n";
			}
		}
		file.close();
	}
	else{
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::save_jurados(string &s){
	ofstream file;
	string ficheiro = "res/"+s,validade;

	file.open(ficheiro.c_str(), ios::out | ios::trunc);

	if(file.is_open()){

		for(unsigned i = 0; i < jurados.size(); i++){
			validade= jurados[i]->getValidade() ? "valid" : "invalid";

			file << jurados[i]->getNome() << ";";
			file << jurados[i]->getMorada() << ";";
			file << jurados[i]->getTelemovel() << ";";
			file << jurados[i]->getGeneroArte() << ";";
			file << validade << ";";

			if(i != jurados.size()-1){
				file << "\n";
			}
		}

		file.close();
	}
	else{
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::save_sessoes(string &s){
	ofstream file;
	string ficheiro = "res/"+s;


	file.open(ficheiro.c_str(), ios::out | ios::trunc);

	if(file.is_open()){

		for(unsigned i = 0; i < sessoes.size(); i++){

			file << sessoes[i]->getJurados()[0]->getTelemovel() << ";";
			file << sessoes[i]->getJurados()[1]->getTelemovel() << ";";
			file << sessoes[i]->getJurados()[2]->getTelemovel() << ";";
			file << sessoes[i]->getArtePerformativa() << ";";
			file << sessoes[i]->getData() << ";";

			if(sessoes[i]->getStatus()){
				file << "changeable" << ";";
			}

			if(i != sessoes.size()-1){
				file << "\n";
			}
		}

		file.close();
	}
	else{
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::save_participacao(string &s){
	ofstream file;
	string ficheiro = "res/"+s;
	int lines=0;


	file.open(ficheiro.c_str(), ios::out | ios::trunc);

	if(file.is_open()){

		//TODO CHECK BST
		BSTItrIn<Candidato> it(candidatos);

		while(! it.isAtEnd())
		{

			for(unsigned i2 = 0; i2 < it.retrieve().getParticipacoes().size(); i2++){

				if(lines != 0){
					file << "\n";
				}

				file << it.retrieve().getNumInscricao() << ";";
				file << it.retrieve().getParticipacoes()[i2]->getFase() << ";";
				file << it.retrieve().getParticipacoes()[i2]->getSessao()->getData() << ";";
				file << it.retrieve().getParticipacoes()[i2]->getPontuacao()[1] << ";";
				file << it.retrieve().getParticipacoes()[i2]->getPontuacao()[2] << ";";
				file << it.retrieve().getParticipacoes()[i2]->getPontuacao()[3] << ";";
				file << it.retrieve().getParticipacoes()[i2]->getPosicao() << ";";

				lines++;

			}

			it.advance();
		}

		file.close();
	}
	else{
		throw(InvalidFileNameException(ficheiro));
	}
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
			if(ss.str() == "valid"){
				validade = true;
			}
			else{
				validade = false;
			}

			ss.str(string());
			ss.clear();

			jurados.push_back(new Jurado(nome, morada, generoArte, telemovel, validade));
		}
		file.close();

	}
	else{
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::load_sessoes(string &s){
	ifstream file;
	stringstream ss;
	string ficheiro = "res/"+s, line, artePerformativa, data;
	vector<Jurado *> jurados;
	int numTelemJurado1, numTelemJurado2, numTelemJurado3;
	bool changeable;

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

			//changeable

			parse_line(line, ss);
			if(ss.str() == "changeable"){
				changeable = true;
			}
			else{
				changeable = false;
			}

			ss.str(string());
			ss.clear();

			jurados.clear();

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

			sessoes.push_back(new Sessao(jurados, artePerformativa, data, changeable));
		}
		file.close();

	}
	else{
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
			if(ss.str() == "valid"){
				validade = true;
			}
			else{
				validade = false;
			}

			ss.str(string());
			ss.clear();
			//TODO CHECK BST
			candidatos.insert(Candidato(numInscricao,nome,morada,generoArte,dataNascimento, validade));
		}
		file.close();
	}
	else{
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

			//TODO CHECK BST
			BSTItrIn<Candidato> it(this->candidatos);

			while(! it.isAtEnd())
			{
				if(it.retrieve().getNumInscricao() == numInscricao){
					generoArte=it.retrieve().getGeneroArte();
				}

				it.advance();
			}

			for (unsigned i = 0; i < sessoes.size(); i++){
				if((sessoes[i]->getData()==data) && (sessoes[i]->getArtePerformativa() == generoArte)){
					sessao = i;
				}
			}

			pontuacao_array[0]=pontuacao1;
			pontuacao_array[1]=pontuacao2;
			pontuacao_array[2]=pontuacao3;

			//TODO CHECK BST
			BSTItrIn<Candidato> it2(candidatos);

			while(! it2.isAtEnd())
			{
				if(it2.retrieve().getNumInscricao() == numInscricao){
					it2.retrieve().addParticipacao(new Participacao(sessoes[sessao], pontuacao_array, posicao, fase));
					break;
				}

				it2.advance();
			}
		}
		file.close();
	}
	else{
		throw(InvalidFileNameException(ficheiro));
	}
}

vector <Candidato *> Empresa::getCandidatos(){
	vector<Candidato *> ret;

	//TODO CHECK BST
	BSTItrIn<Candidato> it(candidatos);

	while(! it.isAtEnd())
	{

		ret.push_back(&it.retrieve());

		it.advance();
	}
	return ret;
}

vector <Jurado *> Empresa::getJurados(){

	return jurados;
}

vector <Sessao *> Empresa::getSessoes(){

	return sessoes;
}


void Empresa::sortJurados(sort_t const & by)
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

void Empresa::sortSessoes(sort_t const & by)
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
/*
void Empresa::sortCandidatos(sort_t const & by)
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
}*/

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

void sortBy_points_in_session(vector<Candidato *> &candidatos, string const &dataSessao, int fase)
{
	sort(candidatos.begin(), candidatos.end(), [&dataSessao, fase](Candidato * c1, Candidato * c2){
		int pontC1 = 0, pontC2 = 0;
		pair<Participacao *, Participacao *> partC1 = c1->getParticipacao(dataSessao);
		pair<Participacao *, Participacao *> partC2 = c2->getParticipacao(dataSessao);

		if(fase == 1)
		{
			if(partC1.first != NULL)
				pontC1 = partC1.first->getPontuacaoFinal();
			if(partC2.first != NULL)
				pontC2 = partC2.first->getPontuacaoFinal();
		}
		else
			if(fase == 2)
			{
				if(partC1.second != NULL)
					pontC1 = partC1.second->getPontuacaoFinal();
				if(partC2.second != NULL)
					pontC2 = partC2.second->getPontuacaoFinal();
			}

		return pontC1 > pontC2;
	});
}

void Empresa::printJurados(){
	cout << "\n\n";
	cout << setw(30) << left << "Nome";
	cout << setw(30) << left << "Genero de Arte";
	cout << setw(20) << left << "Telemovel";
	cout << setw(20) << left << "Morada";
	cout << setw(20) << left << "Validade";
	cout << "\n\n";

	for(unsigned i=0; i < jurados.size(); i++){
		cout << jurados[i];
	}

	pressKeyToContinue();
}

void Empresa::printCandidatos(){
	cout << "\n\n";
	cout << setw(20) << left << "Num. Inscricao";
	cout << setw(30) << left << "Nome";
	cout << setw(20) << left << "Data Nascimento";
	cout << setw(30) << left << "Genero de Arte";
	cout << setw(20) << left << "Morada";
	cout << setw(20) << left << "Validade";
	cout << "\n\n";

	BSTItrIn<Candidato> it(candidatos);

	while(! it.isAtEnd())
	{
		cout << it.retrieve();

		it.advance();
	}

	pressKeyToContinue();
}

void Empresa::printSessoes(){
	cout << "\n\n";
	cout << setw(30) << left << "Genero de Arte";
	cout << setw(20) << left << "Data";
	cout << "\n\n";

	for(unsigned i=0; i < sessoes.size(); i++){
		cout << sessoes[i];
	}

	pressKeyToContinue();
}

void Empresa::printDetalhesSessao(Sessao * sessao){
	int pos = 0, pontuacao = 0;
	map<Candidato *, pair<Participacao *,Participacao *>> info_1;
	map<Candidato *, pair<Participacao *,Participacao *>> info_2;
	vector<Candidato *> candidatosOrdenar_1;
	vector<Candidato *> candidatosOrdenar_2;
	candidatosOrdenar_1.clear();
	candidatosOrdenar_2.clear();

	//TODO CHECK BST
	BSTItrIn<Candidato> it(candidatos);

	while(! it.isAtEnd())
	{
		pair<Participacao *,Participacao *> infoCandidato = it.retrieve().getParticipacao(sessao->getData());
		if(infoCandidato.first != NULL)
		{
			info_1[&it.retrieve()] = infoCandidato;
			candidatosOrdenar_1.push_back(&it.retrieve());
		}

		if(infoCandidato.second != NULL)
		{
			info_2[&it.retrieve()] = infoCandidato;
			candidatosOrdenar_2.push_back(&it.retrieve());
		}

		it.advance();
	}

	cout << "\n\n";
	cout << "Genero de Arte: " << sessao->getArtePerformativa();
	cout << "         Data: " << sessao->getData();

	cout << "\n\nJurados:\n\n";

	cout << "Nome: " << setw(30) << left << sessao->getJurados()[0]->getNome();
	cout << "Contacto: " << sessao->getJurados()[0]->getTelemovel();
	cout << "\n";
	cout << "Nome: " << setw(30) << left << sessao->getJurados()[1]->getNome();
	cout << "Contacto: " << sessao->getJurados()[1]->getTelemovel();
	cout << "\n";
	cout << "Nome: " << setw(30) << left << sessao->getJurados()[2]->getNome();
	cout << "Contacto: " << sessao->getJurados()[2]->getTelemovel();
	cout << "\n";


	unsigned max_fase;

	if(sessao->getStatus()){
		max_fase=1;
	}else{
		max_fase=3;
	}

	for(unsigned counter = 1; counter < max_fase; counter++)
	{
		if(counter==1){
			sortBy_points_in_session(candidatosOrdenar_1, sessao->getData(), counter);
		}
		else if(counter==2){
			sortBy_points_in_session(candidatosOrdenar_2, sessao->getData(), counter);
		}

		cout << "\n\n\n" << "Fase " << counter <<":\n\n";

		cout << setw(10) << left << "Posicao";
		cout << setw(30) << left << "Nome";
		cout << setw(30) << left << "Numero de Inscricao";
		cout << setw(10) << left << "Pontuacao";
		cout << "\n\n";


		if(counter==1){
			for(unsigned i = 0; i < candidatosOrdenar_1.size(); ++i)
			{

				pos = info_1[candidatosOrdenar_1[i]].first->getPosicao();
				pontuacao = info_1[candidatosOrdenar_1[i]].first->getPontuacaoFinal();

				cout << setw(10) << left << pos;
				cout << setw(30) << left << candidatosOrdenar_1[i]->getNome();
				cout << setw(30) << left << candidatosOrdenar_1[i]->getNumInscricao();
				cout << setw(10) << left << pontuacao;
				cout << "\n";
			}
		}
		else if(counter==2){
			for(unsigned i = 0; i < candidatosOrdenar_2.size(); ++i)
			{
				if(counter == 1)
				{
					pos = info_2[candidatosOrdenar_2[i]].first->getPosicao();
					pontuacao = info_2[candidatosOrdenar_2[i]].first->getPontuacaoFinal();
				}
				else
				{
					pos = info_2[candidatosOrdenar_2[i]].second->getPosicao();
					pontuacao = info_2[candidatosOrdenar_2[i]].second->getPontuacaoFinal();
				}

				cout << setw(10) << left << pos;
				cout << setw(30) << left << candidatosOrdenar_2[i]->getNome();
				cout << setw(30) << left << candidatosOrdenar_2[i]->getNumInscricao();
				cout << setw(10) << left << pontuacao;
				cout << "\n";
			}
		}
	}

	pressKeyToContinue();
}

Candidato *  Empresa::escolher_candidato(){
	int id;

	while(true){
		clear_scrn();
		printCandidatos();

		cout << "Introduza o id do candidato: " << endl;


		try{
			id = read_number_Input();
		}
		catch(invalid_argument &e){
			cout << "Introduziu um numero invalido!";
			pressKeyToContinue();
			continue;
		}

		//TODO CHECK BST
		BSTItrIn<Candidato> it(this->candidatos);

		while(! it.isAtEnd())
		{
			if(it.retrieve().getNumInscricao() == id){
				cout << "O candidato e valido!" << endl;
				return &it.retrieve();
			}

			it.advance();
		}

		cout << "Introduziu um id que nao existe!" << endl;
		pressKeyToContinue();
	}
}

Sessao *  Empresa::escolher_sessao(){
	string arte;
	bool found = false;
	string data;

	while(!found){
		clear_scrn();
		printSessoes();

		cout << "Introduza o género de arte: " << endl;

		getline(cin, arte);


		for(unsigned int i = 0; i < sessoes.size(); i++){
			if(sessoes[i]->getArtePerformativa() == arte){
				cout << "O genero de arte e valido!" << endl;
				found = true;
				break;
			}
		}

		if(!found){
			cout << "genero de arte invalido" << endl;
			pressKeyToContinue();
		}
	}

	found = false;

	while(!found){
		cout << "Introduza a data: " << endl;

		getline(cin, data);

		for(unsigned int i = 0; i < sessoes.size(); i++){
			if((sessoes[i]->getArtePerformativa() == arte) && (sessoes[i]->getData() == data)){
				cout << "A sessao e valido!" << endl;
				found = true;
				return sessoes[i];
			}
		}

		if(!found){
			cout << "data invalida" << endl;
			pressKeyToContinue();
		}
	}
}

Jurado *  Empresa::escolher_jurado(){
	int telemovel;

	while(true){
		clear_scrn();
		printJurados();
		cout << "Introduza o numero de telemovel do jurado: " << endl;

		while(true)
		{
			try{
				telemovel = read_number_Input();
			}
			catch(invalid_argument &e){
				cout << "Introduziu um numero de telemovel invalido!";
				pressKeyToContinue();
				continue;
			}
			if(numbr_size(telemovel) != 9){
				cout << "Introduziu um numero de telemovel invalido!";
				pressKeyToContinue();
				continue;
			}
			break;
		}

		for(unsigned int i = 0; i < jurados.size(); i++){
			if(jurados[i]->getTelemovel() == telemovel){
				cout << "O jurado e valido!" << endl;
				return jurados[i];
			}
		}
		cout << "Introduziu um telemovel que nao existe!" << endl;
		pressKeyToContinue();
	}
}

void Empresa::adicionar_candidato(){
	string nome, dataNascimento, generoArte, morada;

	cout << "Introduza o nome do candidato: ";
	getline(cin, nome);

	while(true)
	{
		cout << "Introduza a data de nascimento no formato dd/mm/aaaa: ";
		getline(cin, dataNascimento);
		if(isValidDate(dataNascimento))
			break;
		else
			cout << "formato invalido, tente outra vez!\n";
	}

	cout << "Introduza o genero de arte: ";
	getline(cin, generoArte);
	cout << "Introduza a sua cidade de morada: ";
	getline(cin, morada);
	//TODO CHECK BST
	candidatos.insert(Candidato(nome, morada, generoArte, dataNascimento));

	cout << "Foi introduzido um novo candidato com sucesso!";

	pressKeyToContinue();
}

void Empresa::adicionar_jurado(){
	string nome, generoArte, morada;
	int  telemovel;
	bool unique;

	cout << "Introduza o nome do jurado: ";
	getline(cin, nome);
	cout << "Introduza o genero de arte: ";
	getline(cin, generoArte);
	cout << "Introduza a cidade de morada: ";
	getline(cin, morada);

	while(true)
	{
		cout << "Introduza o numero de telemovel: ";

		try{
			telemovel = read_number_Input();
		}
		catch(invalid_argument &e){
			cout << "Introduziu um numero de telemovel invalido!";
			pressKeyToContinue();
			continue;
		}
		if(numbr_size(telemovel) != 9){
			cout << "Introduziu um numero de telemovel invalido!";
			pressKeyToContinue();
			continue;
		}

		unique=true;

		for(unsigned i=0; i < jurados.size() ; i++){
			if(jurados[i]->getTelemovel() == telemovel){
				unique=false;
				cout << "Ja existe um jurado com esse numero!";
				pressKeyToContinue();
				break;
			}
		}

		if(!unique){
			continue;
		}

		break;
	}

	jurados.push_back(new Jurado (nome, morada, generoArte, telemovel));

	cout << "Foi introduzido um novo jurado com sucesso!";

	pressKeyToContinue();
}

void Empresa::adicionar_sessao(){
	//Selecionar tres jurados em que o primeiro é o responsável
	//selecionar data
	//selecionar arte

	string arte, data;
	vector<Jurado *> juradosValidos;
	vector <Jurado *> avaliadores;
	vector <string> artes;
	vector <string> artesValidas;
	int counter;
	int pos;
	bool found= false;

	for (unsigned i = 0; i < jurados.size(); i++){
		if(jurados[i]->getValidade()){
			artes.push_back(jurados[i]->getGeneroArte());
		}
	}


	for (unsigned i1 = 0; i1 < artes.size(); i1++){
		counter=1;
		for (unsigned i2 = 0; i2 < artes.size(); i2++){
			if(i2!=i1){
				if(artes[i1]==artes[i2]){
					counter++;
				}
			}
		}

		if(counter >= 3){
			artesValidas.push_back(artes[i1]);
		}

		for(unsigned i3=0; i3 < artes.size(); i3++){
			if(i3!=i1){
				if(artes[i1]==artes[i3]){
					artes.erase(artes.begin()+i3);
					i3--;
				}
			}
		}
		artes.erase(artes.begin()+i1);
		i1--;
	}

	if(artesValidas.size() > 0){

		while(!found){
			clear_scrn();

			cout << "\nArtes Válidas\n\n";

			for(unsigned i = 0;i < artesValidas.size();i++){
				cout << i+1 << " - ";
				cout << artesValidas[i] << "\n";
			}

			cout << "Introduza a posicao na lista do genero de arte\n";

			try{
				pos = read_number_Input();
			}
			catch(invalid_argument &e){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			if((pos > artesValidas.size()) || (pos < 1)){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			arte = artesValidas[pos - 1];
			found=true;

		}

		found=true;

		while(found){
			clear_scrn();
			found=false;

			cout << "Introduza a data da sessao: ";
			getline(cin, data);

			if(!isValidDate(data)){
				cout << "Data invalida" << endl;
				pressKeyToContinue();
				found=true;
				continue;
			}

			for(unsigned i = 0; i< sessoes.size();i++){
				if((arte==sessoes[i]->getArtePerformativa()) && (data == sessoes[i]->getData())){
					found = true;
					break;
				}
			}

			if(found){
				cout << "Ja existe uma sessao nessa data..." << endl;
				pressKeyToContinue();
			}
		}



		for (unsigned i = 0; i < jurados.size(); i++){
			if(jurados[i]->getValidade()){
				if(arte == jurados[i]->getGeneroArte()){
					juradosValidos.push_back(jurados[i]);
				}
			}
		}

		found=false;

		while(!found){
			clear_scrn();

			for (unsigned i = 0; i < juradosValidos.size(); i++){
				cout << i + 1 << " - ";
				cout << juradosValidos[i];
			}

			cout << "Introduza a posicao na lista do jurado principal\n";

			try{
				pos = read_number_Input();
			}
			catch(invalid_argument &e){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			if((pos > juradosValidos.size()) || (pos < 1)){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			avaliadores.push_back(juradosValidos[pos - 1]);
			juradosValidos.erase(juradosValidos.begin() + pos - 1);
			found=true;
		}

		found=false;

		while(!found){
			clear_scrn();

			for( unsigned i = 0; i < juradosValidos.size(); i++){
				cout << i + 1 << " - ";
				cout << juradosValidos[i];
			}

			cout << "Introduza a posicao na lista do jurado\n";

			try{
				pos = read_number_Input();
			}
			catch(invalid_argument &e){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			if((pos > juradosValidos.size()) || (pos < 1)){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			avaliadores.push_back(juradosValidos[pos - 1]);
			juradosValidos.erase(juradosValidos.begin() + pos - 1);
			found=true;
		}


		found=false;

		while(!found){
			clear_scrn();

			for( unsigned i = 0; i < juradosValidos.size(); i++){
				cout << i + 1 << " - ";
				cout << juradosValidos[i];
			}

			cout << "Introduza a posicao na lista do jurado\n";

			try{
				pos = read_number_Input();
			}
			catch(invalid_argument &e){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			if((pos > juradosValidos.size()) || (pos < 1)){
				cout << "Introduziu um numero invalido!";

				pressKeyToContinue();
				continue;
			}

			avaliadores.push_back(juradosValidos[pos - 1]);
			juradosValidos.erase(juradosValidos.begin() + pos - 1);
			found=true;
		}

		sessoes.push_back(new Sessao(avaliadores, arte, data, true));
		cout << "Foi criada uma nova sessao com sucesso!";

		pressKeyToContinue();
	}
	else{
		cout << "Nao ha jurados suficientes para criar uma sessao..." << endl;
		pressKeyToContinue();
	}
}

void Empresa::remover_jurado(){
	Jurado * jurado = this->escolher_jurado();
	jurado->setValid(false);
	cout << "O jurado foi removido com sucesso!";
	pressKeyToContinue();
}

void Empresa::remover_candidato(){
	Candidato * candidato = this->escolher_candidato();
	candidato->setValid(false);
	cout << "O candidato foi removido com sucesso!";
	pressKeyToContinue();
}

void Empresa::remover_sessao(){

	Sessao * sessao = this->escolher_sessao();

	if(!(sessao->getStatus()))
	{
		cout << "Não é possivel remover uma sessao que já tenha acontecido!";
		pressKeyToContinue();
		return;
	}

	string arte = sessao->getArtePerformativa();

	vector<Candidato *> candidatos;
	candidatos.clear();

	//TODO CHECK BST
	BSTItrIn<Candidato> it(this->candidatos);

	while(! it.isAtEnd())
	{
		if(it.retrieve().getGeneroArte() == arte)
		{
			candidatos.push_back(&it.retrieve());
		}

		it.advance();
	}

	for (unsigned i = 0; i < candidatos.size(); ++i)
	{
		candidatos[i]->removeParticipacao(sessao);
	}


	for (unsigned i = 0; i < this->sessoes.size(); ++i)
	{
		if(*(this->sessoes[i]) == *sessao)
		{
			this->sessoes.erase(this->sessoes.begin() + i);
			delete sessao;
			break;
		}
	}

	cout << "A sessao foi removida com sucesso!";
	pressKeyToContinue();
}

void Empresa::adicionar_candidato_sessao(Sessao * sessao){
	//para adicionar um candidato a sessao tem que escolher dos já existentes
	bool found=false;
	int id;
	vector <Candidato> candidatos_possiveis;
	Candidato *candidato;

	//TODO CHECK BST
	BSTItrIn<Candidato> it(candidatos);

	while(! it.isAtEnd())
	{
		if(it.retrieve().getGeneroArte() == sessao->getArtePerformativa() && it.retrieve().getParticipacao(sessao->getData()).first == NULL){
			candidatos_possiveis.push_back(it.retrieve());
		}
		it.advance();
	}

	if(candidatos_possiveis.size() < 1){
		cout << "Nao ha candidatos para adicionar a esta sessao" << endl;
		pressKeyToContinue();
		return;
	}

	while(!found){
		clear_scrn();

		cout << "\n\n";
		cout << setw(20) << left << "Num. Inscricao";
		cout << setw(30) << left << "Nome";
		cout << setw(20) << left << "Data Nascimento";
		cout << setw(30) << left << "Genero de Arte";
		cout << setw(20) << left << "Morada";
		cout << setw(20) << left << "Validade";
		cout << "\n\n";

		for( unsigned i = 0; i < candidatos_possiveis.size(); i++){
			cout << candidatos_possiveis[i];
		}

		cout <<"\n\nIntroduza o numero de incricao do candidato:\n";

		try{
			id = read_number_Input();
		}
		catch(invalid_argument &e){
			cout << "Introduziu um numero invalido!";

			pressKeyToContinue();
			continue;
		}

		for( unsigned i = 0; i < candidatos_possiveis.size(); i++){
			if(id == candidatos_possiveis[i].getNumInscricao()){
				found=true;
				candidato= &(candidatos_possiveis[i]);
			}
		}

		if(!found){
			cout << "Introduziu um numero invalido!";

			pressKeyToContinue();
			continue;
		}

	}


	int points[3] = {0,0,0};
	candidato->addParticipacao(new Participacao(sessao, points, 0, 1));

	//Atualizar a Priority Queue
	//atualiza_candidato_pq(*candidato);

	cout << "O candidato foi adicionado a sessao com sucesso!\n" << endl;

	pressKeyToContinue();

}

void Empresa::remover_candidato_sessao(Sessao * sessao){
	vector <Candidato> candidatos_possiveis;
	Candidato* candidato;
	bool found;
	int id;

	//TODO CHECK BST
	BSTItrIn<Candidato> it(candidatos);

	while(! it.isAtEnd())
	{
		if(it.retrieve().getParticipacao(sessao->getData()).first != NULL){
			candidatos_possiveis.push_back(it.retrieve());
		}

		it.advance();
	}

	if(candidatos_possiveis.size()<1){
		cout << "\nNao ha candidatos nesta sessao\n";
		pressKeyToContinue();
		return;
	}

	found=false;

	while(!found){
		clear_scrn();

		cout << "\n\n";
		cout << setw(20) << left << "Num. Inscricao";
		cout << setw(30) << left << "Nome";
		cout << setw(20) << left << "Data Nascimento";
		cout << setw(30) << left << "Genero de Arte";
		cout << setw(20) << left << "Morada";
		cout << setw(20) << left << "Validade";
		cout << "\n\n";

		for( unsigned i = 0; i < candidatos_possiveis.size(); i++){
			cout << candidatos_possiveis[i];
		}

		cout <<"\n\nIntroduza o numero de incricao do candidato:\n";

		try{
			id = read_number_Input();
		}
		catch(invalid_argument &e){
			cout << "Introduziu um numero invalido!";

			pressKeyToContinue();
			continue;
		}

		for( unsigned i = 0; i < candidatos_possiveis.size(); i++){
			if(id == candidatos_possiveis[i].getNumInscricao()){
				found=true;
				candidato= &(candidatos_possiveis[i]);
			}
		}

		if(!found){
			cout << "Introduziu um numero invalido!";

			pressKeyToContinue();
			continue;
		}

	}

	candidato->removeParticipacao(sessao);

	cout << "\nCandidato removido com sucesso!\n" << endl;

	pressKeyToContinue();
}

void Empresa::gerarPrimeiraFase(Sessao * sessao){
	vector <Candidato *> candidatos_primeira_fase;

	srand (time(NULL));

	//TODO CHECK BST
	BSTItrIn<Candidato> it(candidatos);

	while(! it.isAtEnd())
	{
		if(it.retrieve().getParticipacao(sessao->getData()).first != NULL){
			it.retrieve().removeParticipacao(sessao);

			int a, b, c;
			a = rand() % 11;
			b = rand() % 11;
			c = rand() % 11;
			int points[] = {a,b,c};

			it.retrieve().addParticipacao(new Participacao(sessao, points, 0, 1));

			candidatos_primeira_fase.push_back(&it.retrieve());
		}


		it.advance();
	}

	if(candidatos_primeira_fase.size() < 1){
		cout << "\nNao ha candidatos suficientes...\n\n";
		pressKeyToContinue();
		return;
	}


	sortBy_points_in_session(candidatos_primeira_fase, sessao->getData(), 1);

	for(unsigned int j = 0; j < candidatos_primeira_fase.size(); j++){

		candidatos_primeira_fase[j]->getParticipacao(sessao->getData()).first->setPosicao(j+1);

		cout << setw(30)<< left << candidatos_primeira_fase[j]->getNome() << "Pontuacao = " << candidatos_primeira_fase[j]->getParticipacao(sessao->getData()).first->getPontuacaoFinal();

		if(j < 5){
			cout << "   Aprovado!";
		}
		cout << "\n";
	}

	cout << "\nPara a fase 2 do casting apuram os 5 primeiros da lista anterior! Boa sorte a todos!\n";

	pressKeyToContinue();

	cout << "\n\n\n\n";

	gerarSegundaFase(sessao);
}

void Empresa::gerarSegundaFase(Sessao * sessao){

	vector <Candidato *> candidatos_primeira_fase;
	vector <Candidato *> candidatos_apurados;

	srand (time(NULL));

	//TODO CHECK BST
	BSTItrIn<Candidato> it(candidatos);

	while(! it.isAtEnd())
	{
		if(it.retrieve().getParticipacao(sessao->getData()).first != NULL ){
			candidatos_primeira_fase.push_back(&it.retrieve());
		}

		it.advance();
	}

	sortBy_points_in_session(candidatos_primeira_fase, sessao->getData(), 1);

	for(unsigned int i = 0; i < candidatos_primeira_fase.size()  && i < 5; i++){
		candidatos_apurados.push_back(candidatos_primeira_fase[i]);
	}

	for(unsigned int i = 0; i < candidatos_apurados.size(); i++){

		int a, b, c;
		a = rand() % 11; //Valor de 0 a 10
		b = rand() % 11;
		c = rand() % 11;
		int points[] = {a,b,c}; //posicao é atualizada no final de todos terem pontuacoes atribuidas

		candidatos_apurados[i]->addParticipacao(new Participacao(sessao,points,0,2));
	}

	sortBy_points_in_session(candidatos_apurados, sessao->getData(), 2);

	for(unsigned int i = 0; i < candidatos_apurados.size(); i++){
		candidatos_apurados[i]->getParticipacao(sessao->getData()).second->setPosicao(i+1);
	}

	cout << "O vencedor e: "<< candidatos_apurados[0]->getNome()<<endl;

	sessao->setStatus(false);

	pressKeyToContinue();

}



void Empresa::alterarDataSessao(Sessao* sessao){

	bool found=true;
	string data;

	while(found){
		clear_scrn();
		found=false;

		cout << "Introduza a nova data da sessao: ";
		getline(cin, data);

		if(!isValidDate(data)){
			cout << "Data invalida" << endl;
			pressKeyToContinue();
			found=true;
			continue;
		}

		for( unsigned i = 0; i< sessoes.size();i++){
			if(!(*sessao == *sessoes[i]) && (sessao->getArtePerformativa() == sessoes[i]->getArtePerformativa()) && (data == sessoes[i]->getData())){
				found = true;
				break;
			}
		}

		if(found){
			cout << "Ja existe uma sessao nessa data..." << endl;
			pressKeyToContinue();
		}
	}

	cout << "\nData alterada com sucesso!\n";

	sessao->setData(data);
}

void Empresa::adiciona_candidato_pq(Candidato * cand){

	bool existe = false;

	for(unsigned int i = 0; i < this->candidatos_ordenados.size(); i++){
		if(candidatos_ordenados[i].top()->getGeneroArte() == cand->getGeneroArte()){
			existe = true;
			candidatos_ordenados[i].push(cand);
		}
	}

	if(existe == false){
		pq_recentes nova;
		nova.push(cand);
		candidatos_ordenados.push_back(nova);
	}

}

//TODO Check PQ
void Empresa::atualiza_candidato_pq(Candidato cand){
	//O candidato cand já contem as informações atualizadas
	//Assim, o objetivo é procurar o candidato cand na fila da sua arte e substitui-lo pelo cand

	for(unsigned int i = 0; i < candidatos_ordenados.size(); i++){
		if(candidatos_ordenados[i].top()->getGeneroArte() == cand.getGeneroArte()){
			pq_recentes aux;

			while(!candidatos_ordenados[i].empty()){
				cout << *(candidatos_ordenados[i].top());
				if(candidatos_ordenados[i].top()->getNumInscricao() == cand.getNumInscricao()){
					candidatos_ordenados[i].pop();
					candidatos_ordenados[i].push(&cand);
					break;
				}
				aux.push(candidatos_ordenados[i].top());
				candidatos_ordenados[i].pop();
			}

			while(!aux.empty()){
				candidatos_ordenados[i].push(aux.top());
				aux.pop();
			}

			}
		}

	}

pq_recentes Empresa::getPQ(string arte){

	pq_recentes vazio;

	for(unsigned int i = 0; i < candidatos_ordenados.size(); i++){
		if(candidatos_ordenados[i].top()->getGeneroArte() == arte){

			return candidatos_ordenados[i];

			vazio = candidatos_ordenados[i];
			return vazio;
		}
	}

	return vazio;

}

