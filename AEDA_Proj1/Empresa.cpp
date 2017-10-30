#include "Empresa.hpp"


Empresa::Empresa(string (&nomes)[4]) {
	load_files(nomes);
}

/*
 * Formato dos ficheiros: (deve sofrer alteração)
 *
 * jurados.txt
 * Nome;morada;telemovel;generoArte;\n
 *
 * Sessoes.txt
 * numTelemJurado1(responsável),numTelemJurado2,numTelemJurado3;artePerformativa;data;\n
 *
 * Candidatos.txt
 * numInscrição;nome;dataNascimento;generoArte;morada;\n
 *
 * Participacao.txt
 * numInscrição;Fase,Data,Pontuação1(juradoResponsável),Pontuação2,Pontuação3,Posição;
 */

void Empresa::load_files(string (&nomes)[4]){
	load_candidatos(nomes[2]);
	load_jurados(nomes[0]);
	load_sessoes(nomes[1]);
	load_participacao(nomes[3]);
}

void Empresa::load_jurados(string &s){


}

void Empresa::load_sessoes(string &s){

}

void Empresa::load_candidatos(string &s){
	ifstream file;
	stringstream ss;
	string line,nome,dataNascimento,generoArte,morada;
	int numInscricao;

	file.open("/res/"+s);

	while(getline(file,line)){

		//numInscricao

		for (int i=0; i < line.size(); i++){
			if(line[i] != ';'){
				ss<<line[i];
			}
			else if(line[i] == ';'){
				line.erase(line.begin(),line.begin()+i);
				break;
			}
		}
		numInscricao=stoi(ss.str());
		ss.clear();

		//nome

		for (int i=0; i < line.size(); i++){
			if(line[i] != ';'){
				ss<<line[i];
			}
			else if(line[i] == ';'){
				line.erase(line.begin(),line.begin()+i);
				break;
			}
		}

		nome=ss.str();
		ss.clear();

		//dataNascimento

		for (int i=0; i < line.size(); i++){
			if(line[i] != ';'){
				ss<<line[i];
			}
			else if(line[i] == ';'){
				line.erase(line.begin(),line.begin()+i);
				break;
			}
		}

		dataNascimento=ss.str();
		ss.clear();

		//generoArte

		for (int i=0; i < line.size(); i++){
			if(line[i] != ';'){
				ss<<line[i];
			}
			else if(line[i] == ';'){
				line.erase(line.begin(),line.begin()+i);
				break;
			}
		}

		generoArte=ss.str();
		ss.clear();


		//morada

		for (int i=0; i < line.size(); i++){
			if(line[i] != ';'){
				ss<<line[i];
			}
			else if(line[i] == ';'){
				line.erase(line.begin(),line.begin()+i);
				break;
			}
		}

		morada=ss.str();
		ss.clear();

		candidatos.push_back(new Candidato(numInscricao,nome,dataNascimento,generoArte,morada));
	}

}

void Empresa::load_participacao(string &s){

}
