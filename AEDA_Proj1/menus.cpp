#include "menus.hpp"

const string titulo="Castings TV";

using namespace castingspace;

const int WIDTH = 40;



//===========================//
//      Change File Name     //
//===========================//

void draw_changeFileName_menu(string (&nomes)[4]) {
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << "|  Escolha nome do ficheiro a alterar:   |\n";
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "  1 - Jurados guardados em\n    \"" << nomes[0] << "\"\n";
	cout << "  2 - Sessoes guardadas em\n    \"" << nomes[1] << "\"\n";
	cout << "  3 - Candidatos guardados em\n    \"" << nomes[2] << "\"\n";
	cout << "  4 - participacoes guardadas em\n    \"" << nomes[3] << "\"\n";
	cout << "  5 - Continuar com nomes atuais\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void changeFileName_menu(string (&ficheiros)[4]) {
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_changeFileName_menu(ficheiros);
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Jurados
			changeFileName(ficheiros[0]);
			break;
		case 2: //Sessoes
			changeFileName(ficheiros[1]);
			break;
		case 3: //Candidatos
			changeFileName(ficheiros[2]);
			break;
		case 4: //Participa��es
			changeFileName(ficheiros[3]);
			break;
		case 5: //Continuar
			done=true;
			break;
		}
	}
}

void changeFileName (string &ficheiro) {
	string nome;
	cout << string(20, '-') << endl;
	cout << "Nome atual: \"" << ficheiro << "\", introduza novo nome:\n";
	getline(cin, nome);

	ficheiro=nome;
}



//===========================//
//         Main Menu         //
//===========================//

void draw_main_menu(){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(15, ' ') << "Main Menu" << string(16, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "  1 - Gerir Candidatos\n";
	cout << "  2 - Gerir Jurados\n";
	cout << "  3 - Gerir Sessoes\n";
	cout << "  4 - Exit\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void main_menu(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_main_menu();
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Gerir Candidatos
			menu_gerir_candidatos(empresa);
			break;
		case 2: //Gerir Jurados
			menu_gerir_jurados(empresa);
			break;
		case 3: //Gerir Sessoes
			menu_gerir_sessoes(empresa);
			break;
		case 4: //Exit
			done=true;
			break;
		}
	}
}



//===========================//
//         Candidatos        //
//===========================//

void draw_menu_gerir_candidatos(){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(12, ' ') << "Gerir Candidatos" << string(12, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "  1 - Ver todos\n";
	cout << "  2 - Escolher Candidato\n";
	cout << "  3 - Adicionar\n";
	cout << "  4 - Remover\n";
	cout << "  5 - Ordenar\n";
	cout << "  6 - Return\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_gerir_candidatos(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_gerir_candidatos();
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Ver todos
			empresa->printCandidatos();
			break;
		case 2: //Escolher Candidato
			menu_candidato(empresa->escolher_candidato());
			break;
		case 3: //adicionar
			empresa->adicionar_candidato();
			break;
		case 4: //remover
			empresa->remover_candidato();
			break;
		case 5: //Ordenar
			menu_ordenar_candidatos(empresa);
			break;
		case 6: //Return
			done=true;
			break;
		}
	}
}


void draw_menu_candidato(Candidato * candidato){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(15, ' ') << "Candidato" << string(16, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "\nNumero de Inscricao: "<< candidato->getNumInscricao()<< endl;
	cout <<	"Arte: " << candidato->getGeneroArte() << endl;
	cout << "Nome: " << candidato->getNome() << endl;
	cout << "Data Nascimento: " << candidato->getDataNasc() << endl;
	cout << "Morada: " << candidato->getMorada() << endl;
	cout << "Estado de inscricao: " << (candidato->getValidade() ? "valida" : "invalida") << "\n\n";

	cout << "  1 - Ver Participacoes\n";
	cout << "  2 - Alterar nome\n";
	cout << "  3 - Alterar morada\n";
	cout << "  4 - ?\n";
	cout << "  5 - ?\n";
	cout << "  6 - Return\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_candidato(Candidato * candidato){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_candidato(candidato);
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //candidato->Ver Participacoes
			candidato->printParticipacoes();
			break;
		case 2: //pessoa->Alterar nome
			candidato->alterarNome();
			break;
		case 3: //pessoa->Alterar morada
			candidato->alterarMorada();
			break;
		case 4: //?

			break;
		case 5: //?

			break;
		case 6: //Return
			done=true;
			break;
		}
	}
}


void draw_menu_ordenar_candidatos(){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(11, ' ') << "Ordenar Candidatos" << string(11, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "  1 - Por nome\n";
	cout << "  2 - Por nome e arte\n";
	cout << "  3 - Por idade e arte\n";
	cout << "  4 - Return\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_ordenar_candidatos(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_ordenar_candidatos();
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Por nome
			empresa->sortCandidatos(by_name);
			done=true;
			break;
		case 2: //Por nome e arte
			empresa->sortCandidatos(by_name_and_art);
			done=true;
			break;
		case 3: //Por idade e arte
			empresa->sortCandidatos(by_age_and_art);
			done=true;
			break;
		case 4: //Return
			done=true;
			break;
		}
	}
}



//===========================//
//          Jurados          //
//===========================//

void draw_menu_gerir_jurados(){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(13, ' ') << "Gerir Jurados" << string(14, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "  1 - Ver todos\n";
	cout << "  2 - Escolher Jurado\n";
	cout << "  3 - Adicionar\n";
	cout << "  4 - Remover\n";
	cout << "  5 - Ordenar\n";
	cout << "  6 - Return\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_gerir_jurados(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_gerir_jurados();
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Ver todos
			empresa->printJurados();
			break;
		case 2: //Escolher Jurado
			menu_jurado(empresa->escolher_jurado());
			break;
		case 3: //adicionar
			empresa->adicionar_jurado();
			break;
		case 4: //remover
			empresa->remover_jurado();
			break;
		case 5: //Ordenar
			menu_ordenar_jurados(empresa);
			break;
		case 6: //Return
			done=true;
			break;
		}

	}
}


void draw_menu_jurado(Jurado * jurado){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(15, ' ') << "Candidato" << string(16, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout  << "Arte: " << jurado->getGeneroArte() << endl;
	cout << "Nome: " << jurado->getNome() << "    Telemovel: " << jurado->getTelemovel() << endl;
	cout << "Morada: " << jurado->getMorada() << endl;
	cout << "Estado do contrato: " << (jurado->getValidade() ? "valida" : "invalida") << endl;

	cout << "  1 - ?\n";
	cout << "  2 - Alterar nome\n";
	cout << "  3 - Alterar morada\n";
	cout << "  4 - Alterar telemovel\n";
	cout << "  5 - ?\n";
	cout << "  6 - Return\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_jurado(Jurado * jurado){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_jurado(jurado);
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //?

			break;
		case 2: //juri->Alterar nome
			jurado->alterarNome();
			break;
		case 3: //juri->Alterar morada
			jurado->alterarMorada();
			break;
		case 4: //juri->Alterar telemovel
			jurado->alterarTelemovel();
			break;
		case 5: //?

			break;
		case 6: //Return
			done=true;
			break;
		}
	}
}


void draw_menu_ordenar_jurados(){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(12, ' ') << "Ordenar Jurados" << string(13, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "  1 - Por nome\n";
	cout << "  2 - Por nome e arte\n";
	cout << "  3 - Return\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_ordenar_jurados(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_ordenar_jurados();
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Por nome
			empresa->sortJurados(by_name);
			done=true;
			break;
		case 2: //Por nome e arte
			empresa->sortJurados(by_name_and_art);
			done=true;
			break;
		case 3: //Return
			done=true;
			break;
		}

	}
}



//===========================//
//          Sessoes          //
//===========================//

void draw_menu_gerir_sessoes(){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(13, ' ') << "Gerir Sessoes" << string(14, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << "  1 - Ver todas\n";
	cout << "  2 - Escolher Sessao\n";
	cout << "  3 - Adicionar\n";
	cout << "  4 - Remover\n";
	cout << "  5 - Ordenar por data e arte\n";
	cout << "  6 - Return\n";
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_gerir_sessoes(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_gerir_sessoes();
		valid_input = false;
		while (!valid_input) {
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Ver todas
			empresa->printSessoes();
			break;
		case 2: //empresa->Escolher Sessao
			menu_sessao(empresa->escolher_sessao(), empresa);
			break;
		case 3: //Adicionar Sessao
			empresa->adicionar_sessao();
			break;
		case 4: //empresa->Remover Sessao
			empresa->remover_sessao();
			break;
		case 5: //Ordenar por data e arte
			empresa->sortSessoes(by_date_and_art);
			break;
		case 6: //Return
			done=true;
			break;
		}
	}
}


void draw_menu_sessao(Sessao * sessao){
	clear_scrn();
	cout << ' ' << string(WIDTH, '_') << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout << '|' << string(WIDTH, ' ') << '|' << endl;
	cout << '|' << string(15, ' ') << "Candidato" << string(16, ' ') << '|' << endl;
	cout << '|' << string(WIDTH, '_') << '|' << endl;
	cout  << "\nArte: " << sessao->getArtePerformativa() << endl;
	cout << "Jurado responsavel: " << sessao->getJurados()[0]->getNome() << "      Telemovel: " << sessao->getJurados()[0]->getTelemovel() << endl;
	cout << "Jurado: " << sessao->getJurados()[1]->getNome() << "      Telemovel: " << sessao->getJurados()[1]->getTelemovel() << endl;
	cout << "Jurado: " << sessao->getJurados()[2]->getNome() << "      Telemovel: " << sessao->getJurados()[2]->getTelemovel() << endl;
	cout << "Data: " << sessao->getData() << "\n\n";

	cout << "  1 - Ver detalhes\n";
	if(sessao->getStatus())
	{
		cout << "  2 - Gerar Fases\n";
		cout << "  3 - Adicionar Candidato\n";
		cout << "  4 - Remover Candidato\n";
		cout << "  5 - Alterar data\n";
		cout << "  6 - Return\n";
	}
	else
	{
		cout << "  2 - Return\n";
	}
	cout << ' ' << string(WIDTH, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_sessao(Sessao * sessao, Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_sessao(sessao);
		valid_input = false;
		while (!valid_input)
		{
			try {option = read_number_Input();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}
		if(sessao->getStatus())
		{
			switch (option) {
			case 1: //empresa->ver detalhes sessao (candidatos por ordem de pontua��o / fase)
				empresa->printDetalhesSessao(sessao);
				break;
			case 2: //TODO (testar) gerar fases
				empresa->gerarPrimeiraFase(sessao);
				break;
			case 3: //sessao->Adicionar Candidato
				empresa->adicionar_candidato_sessao(sessao);
				break;
			case 4: //TODO (testar) sessao->Remover Candidato -> Testar a ver se funciona (o pc da Ver�nica n�o gosta de aeda)
				empresa->remover_candidato_sessao(sessao);
				break;
			case 5: //TODO (testar) sessao->Alterar data Testar a ver se funciona (o pc da Ver�nica n�o gosta de aeda) feita depois da meia noite, nao prometo nada xD
				sessao->alterarData();
				break;
			case 6: //Return
				done=true;
				break;

			}
		}
		else
		{
			switch (option) {
			case 1: //empresa->ver detalhes sessao (candidatos por ordem de pontua��o / fase)
				empresa->printDetalhesSessao(sessao);
				break;
			case 2: //Return
				done=true;
				break;
			}
		}
	}
}

