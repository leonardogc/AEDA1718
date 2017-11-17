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

		for(unsigned i = 0; i < candidatos.size(); i++){
			validade= candidatos[i]->getValidade() ? "valid" : "invalid";

			file << candidatos[i]->getNumInscricao() << ";";
			file << candidatos[i]->getNome() << ";";
			file << candidatos[i]->getDataNasc() << ";";
			file << candidatos[i]->getGeneroArte() << ";";
			file << candidatos[i]->getMorada() << ";";
			file << validade << ";";

			if(i != candidatos.size()-1){
				file << "\n";
			}
		}

		file.close();
	}
	else{
		//cout<<"error opening file!"<<endl;
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
		//cout<<"error opening file!"<<endl;
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

			if(i != sessoes.size()-1){
				file << "\n";
			}
		}

		file.close();
	}
	else{
		//cout<<"error opening file!"<<endl;
		throw(InvalidFileNameException(ficheiro));
	}
}

void Empresa::save_participacao(string &s){
	ofstream file;
	string ficheiro = "res/"+s;
	int lines=0;


	file.open(ficheiro.c_str(), ios::out | ios::trunc);

	if(file.is_open()){

		for(unsigned i = 0; i < candidatos.size(); i++){
			for(unsigned i2 = 0; i2 < candidatos[i]->getParticipacoes().size(); i2++){

				if(lines != 0){
					file << "\n";
				}

				file << candidatos[i]->getNumInscricao() << ";";
				file << candidatos[i]->getParticipacoes()[i2]->getFase() << ";";
				file << candidatos[i]->getParticipacoes()[i2]->getSessao()->getData() << ";";
				file << candidatos[i]->getParticipacoes()[i2]->getPontuacao()[1] << ";";
				file << candidatos[i]->getParticipacoes()[i2]->getPontuacao()[2] << ";";
				file << candidatos[i]->getParticipacoes()[i2]->getPontuacao()[3] << ";";
				file << candidatos[i]->getParticipacoes()[i2]->getPosicao() << ";";

				lines++;

			}
		}

		file.close();
	}
	else{
		//cout<<"error opening file!"<<endl;
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
			if(ss.str() == "valid"){
				validade = true;
			}
			else{
				validade = false;
			}

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

	waitEnterToContinue();
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

	for(unsigned i=0; i < candidatos.size(); i++){
		cout << candidatos[i];
	}

	waitEnterToContinue();
}

void Empresa::printSessoes(){
	cout << "\n\n";
	cout << setw(30) << left << "Genero de Arte";
	cout << setw(20) << left << "Data";
	cout << "\n\n";

	for(unsigned i=0; i < sessoes.size(); i++){
		cout << sessoes[i];
	}

	waitEnterToContinue();
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
			waitEnterToContinue();
			continue;
		}


		for(unsigned int i = 0; i < candidatos.size(); i++){
			if(candidatos[i]->getNumInscricao() == id){
				cout << "O candidato e valido!" << endl;
				return candidatos[i];
			}
		}

		cout << "Introduziu um id que nao existe!" << endl;
		waitEnterToContinue();
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
			}
		}

		if(!found){
			cout << "genero de arte invalido" << endl;
			waitEnterToContinue();
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
				waitEnterToContinue();
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
				waitEnterToContinue();
				continue;
			}
			if(numbr_size(telemovel) != 9){
				cout << "Introduziu um numero de telemovel invalido!";
				waitEnterToContinue();
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
		waitEnterToContinue();
	}
}

void Empresa::adicionar_candidato(){
	string nome, dataNascimento, generoArte, morada;

	cout << "Introduza o nome do candidato: ";
	getline(cin, nome);
	cout << "Introduza a data de nascimento no formato dd/mm/aaaa: ";
	getline(cin, dataNascimento);
	cout << "Introduza o genero de arte: ";
	getline(cin, generoArte);
	cout << "Introduza a sua cidade de morada: ";
	getline(cin, morada);

	candidatos.push_back(new Candidato(nome, morada, generoArte, dataNascimento));

	cout << "Foi introduzido um novo candidato com sucesso!";

	waitEnterToContinue();
}

void Empresa::adicionar_jurado(){
	string nome, generoArte, morada;
	int  telemovel;

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
			waitEnterToContinue();
			continue;
		}
		if(numbr_size(telemovel) != 9){
			cout << "Introduziu um numero de telemovel invalido!";
			waitEnterToContinue();
			continue;
		}
		break;
	}

	jurados.push_back(new Jurado (nome, morada, generoArte, telemovel));

	cout << "Foi introduzido um novo jurado com sucesso!";

	waitEnterToContinue();
}

void Empresa::adicionar_sessao(){
	//Selecionar tres jurados em que o primeiro é o responsável
	//selecionar data
	//selecionar arte

	string arte, data;
	vector <Jurado *> avaliadores;

	cout << "Introduza o genero de arte da sessao: ";
	getline(cin, arte);
	cout << "Introduza a data da sessao: ";
	getline(cin, arte);

	Sessao novaSessao(avaliadores, arte, data, true);


	cout << "Foi criada uma nova sessao com sucesso!";

	waitEnterToContinue();
}

void Empresa::remover_jurado(){
	Jurado * jurado = this->escolher_jurado();
	jurado->setValid(false);
	cout << "O jurado foi removido com sucesso!";
	waitEnterToContinue();
}

void Empresa::remover_candidato(){
	Candidato * candidato = this->escolher_candidato();
	candidato->setValid(false);
	cout << "O candidato foi removido com sucesso!";
	waitEnterToContinue();
}

void Empresa::remover_sessao(){
	bool found = false;

	Sessao * sessao = this->escolher_sessao();
	string arte = sessao->getArtePerformativa();

	if(!(sessao->getStatus()))
	{
		cout << "Não é possivel remover uma sessao que já tenha acontecido!";

	}
	this->sortCandidatos(by_name_and_art);
	vector<Candidato *> candidatos;
	candidatos.clear();

 	for (unsigned i = 0; i < this->candidatos.size(); ++i)
	{
		if(this->candidatos[i]->getGeneroArte() != arte)
		{
			if(found)
				break;
			else
				continue;
		}
		else
		{
			found = true;
			candidatos.push_back(this->candidatos[i]);
		}
	}

	for (unsigned i = 0; i < candidatos.size(); ++i)
	{
		candidatos[i]->removeParticipacao(new Participacao(sessao, {0, 0, 0}, 0, 1));
	}


	for (unsigned i = 0; i < this->sessoes.size(); ++i)
 {
	 if(*(this->sessoes[i]) == *sessao)
	 {
		 this->sessoes.erase(this->sessoes.begin() + i);
		 break;
	 }
 }

	cout << "A sessao foi removida com sucesso!";
	waitEnterToContinue();
}

void Empresa::adicionar_candidato_sessao(Sessao * sessao){
	//para adicionar um candidato a sessao tem que escolher dos já existentes

	Candidato * candidato = this->escolher_candidato();

	candidato->addParticipacao(new Participacao(sessao, {0,0,0,0}, 0, 1));//sao 3 ou 4 0 no array?

	cout << "O candidato foi adicionado a sessao com sucesso!\n" << endl;

	waitEnterToContinue();

}

void Empresa::remover_candidato_sessao(Sessao * sessao){
	Candidato * candidato = this->escolher_candidato();

	if(sessao->getStatus() == true){
		candidato->removeParticipacao(new Participacao(sessao, {0,0,0,0}, 0, 1));//sao 3 ou 4 0 no array?
	}

}

void Empresa::gerarPrimeiraFase(Sessao * sessao){
	//a sessao passada como parametro ja esta escolhida, e validada

	//colocar o status a false, para não se poder alterar mais a sessao
	sessao->setStatus(false);

	//funcao que percorre as participacoes do candidato para saber se ele pertence a esta sessao ou nao

	for(unsigned int i = 0; i < candidatos.size(); i++){
		//verificar se o candidato tem participacao nessa sessao
		//talvez criar um vetor para os candidatos da sessao
		//ate para depois se fazerem os prints dos que apuram e das pontuacoes gerais e assim
		if(candidatos[i]->getParticipacao(sessao->getData())){

		}
	}
}
