#include "Empresa.hpp"

int numCandidato = 1;

Empresa::Empresa() {
	//load_files();
}

/*
 * Formato dos ficheiros: (deve sofrer alteração)
 * jurados.txt
 * Nome;morada;telemovel;generoArte\n
 *
 * Sessoes.txt
 * numTelemJurado1(responsável),numTelemJurado2,numTelemJurado3;artePerformativa;data\n
 *
 * Candidatos.txt
 * numInscrição;nome;dataNascimento;generoArte;morada;Participação1;Participação2...\n
 *
 * (Participação# = Fase,Data,Pontuação1(juradoResponsável),Pontuação2,Pontuação3,Posição)
 */

void Empresa::load_files(){
//TODO after format is final
}
