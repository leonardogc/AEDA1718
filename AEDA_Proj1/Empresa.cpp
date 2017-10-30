#include "Empresa.hpp"


Empresa::Empresa(string (&nomes)[4]) {
	load_files(nomes);
}

/*
 * Formato dos ficheiros: (deve sofrer altera��o)
 *
 * jurados.txt
 * Nome;morada;telemovel;generoArte;\n
 *
 * Sessoes.txt
 * numTelemJurado1(respons�vel);numTelemJurado2;numTelemJurado3;artePerformativa;data;\n
 *
 * Candidatos.txt
 * numInscri��o;nome;dataNascimento;generoArte;morada;\n
 *
 * Participacao.txt
 * numInscri��o;Fase;Data;Pontua��o1(juradoRespons�vel);Pontua��o2;Pontua��o3;Posi��o;
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
		string line,nome,morada,generoArte;
		int telemovel;

		file.open("res/"+s);

		if(file.is_open()){
			while(getline(file, line)){
				//nome

				for (int i=0; i < line.size(); i++){
					if(line[i] != ';'){
						ss<<line[i];
					}
					else if(line[i] == ';'){
						line.erase(0,i+1);
						break;
					}
				}
				nome=ss.str();

				ss.str(string());
				ss.clear();

				//morada

				for (int i=0; i < line.size(); i++){
					if(line[i] != ';'){
						ss<<line[i];
					}
					else if(line[i] == ';'){
						line.erase(0,i+1);
						break;
					}
				}

				morada=ss.str();

				ss.str(string());
				ss.clear();

				//telemovel

				for (int i=0; i < line.size(); i++){
					if(line[i] != ';'){
						ss<<line[i];
					}
					else if(line[i] == ';'){
						line.erase(0,i+1);
						break;
					}
				}

				telemovel=stoi(ss.str());

				ss.str(string());
				ss.clear();

				//generoArte

				for (int i=0; i < line.size(); i++){
					if(line[i] != ';'){
						ss<<line[i];
					}
					else if(line[i] == ';'){
						line.erase(0,i+1);
						break;
					}
				}

				generoArte=ss.str();

				ss.str(string());
				ss.clear();

				jurados.push_back(new Jurado(nome, morada, generoArte, telemovel));
			}
			file.close();
		}
		else{
			cout<<"error opening file!"<<endl;
		}
}

void Empresa::load_sessoes(string &s){
	ifstream file;
	stringstream ss;
	string line,artePerformativa,data;
	vector<Jurado *> jurados;
	int numTelemJurado1,numTelemJurado2,numTelemJurado3;

	file.open("res/"+s);

	if(file.is_open()){
		while(getline(file, line)){
			//numTelemJurado1(respons�vel)

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}
			numTelemJurado1=stoi(ss.str());

			ss.str(string());
			ss.clear();

			//numTelemJurado2

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			numTelemJurado2=stoi(ss.str());

			ss.str(string());
			ss.clear();

			//numTelemJurado3

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			numTelemJurado3=stoi(ss.str());

			ss.str(string());
			ss.clear();

			//artePerformativa

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			artePerformativa=ss.str();

			ss.str(string());
			ss.clear();

			//data

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			data=ss.str();

			ss.str(string());
			ss.clear();

			for(int i=0; i< jurados.size();i++){
				if(jurados[i]->getTelemovel() == numTelemJurado1){
					jurados.push_back(jurados[i]);
				}
			}

			for(int i=0; i< jurados.size();i++){
				if(jurados[i]->getTelemovel() == numTelemJurado2){
					jurados.push_back(jurados[i]);
				}
			}

			for(int i=0; i< jurados.size();i++){
				if(jurados[i]->getTelemovel() == numTelemJurado3){
					jurados.push_back(jurados[i]);
				}
			}

			sessoes.push_back(new Sessao(jurados, 0, artePerformativa, data));
		}
		file.close();
	}
	else{
		cout<<"error opening file!"<<endl;
	}
}

void Empresa::load_candidatos(string &s){
	ifstream file;
	stringstream ss;
	string line,nome,dataNascimento,generoArte,morada;
	int numInscricao;

	file.open("res/"+s);


	if(file.is_open()){
		while(getline(file,line)){

			//numInscricao

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}
			numInscricao=stoi(ss.str());

			ss.str(string());
			ss.clear();

			//nome

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			nome=ss.str();

			ss.str(string());
			ss.clear();

			//dataNascimento

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			dataNascimento=ss.str();

			ss.str(string());
			ss.clear();

			//generoArte

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			generoArte=ss.str();

			ss.str(string());
			ss.clear();


			//morada

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}


			morada=ss.str();

			ss.str(string());
			ss.clear();


			candidatos.push_back(new Candidato(numInscricao,nome,morada,generoArte,dataNascimento));
		}
		file.close();
	}
	else{
		cout<<"error opening file!"<<endl;
	}
}

void Empresa::load_participacao(string &s){
	/*ifstream file;
	stringstream ss;
	string line,artePerformativa,data;
	vector<Jurado *> jurados;
	int numTelemJurado1,numTelemJurado2,numTelemJurado3;

	file.open("res/"+s);

	if(file.is_open()){
		while(getline(file, line)){
			//numInscri��o;Fase,Data,Pontua��o1(juradoRespons�vel),Pontua��o2,Pontua��o3,Posi��o;

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}
			numTelemJurado1=stoi(ss.str());

			ss.str(string());
			ss.clear();

			//numTelemJurado2

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			numTelemJurado2=stoi(ss.str());

			ss.str(string());
			ss.clear();

			//numTelemJurado3

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			numTelemJurado3=stoi(ss.str());

			ss.str(string());
			ss.clear();

			//artePerformativa

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			artePerformativa=ss.str();

			ss.str(string());
			ss.clear();

			//data

			for (int i=0; i < line.size(); i++){
				if(line[i] != ';'){
					ss<<line[i];
				}
				else if(line[i] == ';'){
					line.erase(0,i+1);
					break;
				}
			}

			data=ss.str();

			ss.str(string());
			ss.clear();

			for(int i=0; i< jurados.size();i++){
				if(jurados[i]->getTelemovel() == numTelemJurado1){
					jurados.push_back(jurados[i]);
				}
			}

			for(int i=0; i< jurados.size();i++){
				if(jurados[i]->getTelemovel() == numTelemJurado2){
					jurados.push_back(jurados[i]);
				}
			}

			for(int i=0; i< jurados.size();i++){
				if(jurados[i]->getTelemovel() == numTelemJurado3){
					jurados.push_back(jurados[i]);
				}
			}

			sessoes.push_back(new Sessao(jurados, 0, artePerformativa, data));
		}
		file.close();
	}
	else{
		cout<<"error opening file!"<<endl;
	}*/
}
