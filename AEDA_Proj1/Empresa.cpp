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
	//read

//TODO after format is final
}
