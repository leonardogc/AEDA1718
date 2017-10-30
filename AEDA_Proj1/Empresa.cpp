#include "Empresa.hpp"



Empresa::Empresa(string (&nomes)[4]) {
	load_files(nomes);
}

/*
 * Formato dos ficheiros: (deve sofrer altera��o)
 *
 * jurados.txt
 * Nome;morada;telemovel;generoArte\n
 *
 * Sessoes.txt
 * numTelemJurado1(respons�vel),numTelemJurado2,numTelemJurado3;artePerformativa;data\n
 *
 * Candidatos.txt
 * numInscri��o;nome;dataNascimento;generoArte;morada\n
 *
 * Participacao.txt
 * numInscri��o;Fase,Data,Pontua��o1(juradoRespons�vel),Pontua��o2,Pontua��o3,Posi��o)
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
	istream file;
	file.open("/res/"+s);


}

void Empresa::load_participacao(string &s){

}
