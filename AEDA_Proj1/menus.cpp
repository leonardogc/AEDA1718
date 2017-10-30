#include "menus.hpp"

const string titulo="Castings TV";

#define size 40

void draw_changeFileName_menu(string (&nomes)[4]) {
	clear_scrn();
	cout << ' ' << string(size, '_') << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << "|  Escolha nome do ficheiro a alterar:   |\n";
	cout << '|' << string(size, '_') << '|' << endl;
	cout << "  1 - Jurados guardados em\n    \"" << nomes[0] << "\"\n";
	cout << "  2 - Sessoes guardadas em\n    \"" << nomes[1] << "\"\n";
	cout << "  3 - Candidatos guardados em\n    \"" << nomes[2] << "\"\n";
	cout << "  4 - participacoes guardadas em\n    \"" << nomes[3] << "\"\n";
	cout << "  5 - Continuar com nomes atuais\n";
	cout << ' ' << string(size, '-') << endl;
	cout << "Escolha opcao: ";
}

void changeFileName_menu(string (&ficheiros)[4]) {
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_changeFileName_menu(ficheiros);
		valid_input = false;
		while (!valid_input) {
			try {option = readMenuInput();}
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
		case 4: //Participações
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

void draw_main_menu(){
	clear_scrn();
	cout << ' ' << string(size, '_') << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(15, ' ') << "Main Menu" << string(16, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << "  1 - Ver Informacao\n";
	cout << "  2 - Gerir Candidatos\n";
	cout << "  3 - Gerir Jurados\n";
	cout << "  4 - Gerir Sessoes\n";
	cout << "  5 - Exit\n";
	cout << ' ' << string(size, '-') << endl;
	cout << "Escolha opcao: ";
}

void main_menu(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_main_menu();
		valid_input = false;
		while (!valid_input) {
			try {option = readMenuInput();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //Ver Informacao
			menu_ver_info(empresa);
			break;
		case 2: //Gerir Candidatos

			break;
		case 3: //Gerir Jurados

			break;
		case 4: //Gerir Sessoes

			break;
		case 5: //Exit
			done=true;
			break;
		}
	}
}

/****************************/
/**       Main Menu        **/
/****************************/

void draw_menu_ver_info(){
	clear_scrn();
	cout << ' ' << string(size, '_') << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(8, ' ') << "Ver Informacao" << string(8, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << "  1 - Ver candidatos\n";
	cout << "  2 - Ver jurados\n";
	cout << "  3 - Ver sessoes\n";
	cout << "  4 - Exit\n";
	cout << ' ' << string(size, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_ver_info(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_ver_info();
		valid_input = false;
		while (!valid_input) {
			try {option = readMenuInput();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //ver candidatos
			menu_ver_candidatos(empresa);
			break;
		case 2: //ver jurados
			menu_ver_jurados(empresa);
			break;
		case 3: //ver sessoes
			menu_ver_sessoes(empresa);
			break;
		case 4: //Exit
			done=true;
			break;
		}
	}
}


/****************************/
/**       Ver info         **/
/****************************/

void draw_menu_ver_candidatos(){
	clear_scrn();
	cout << ' ' << string(size, '_') << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(8, ' ') << "Ver Candidatos" << string(8, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << "  1 - ?\n";
	cout << "  2 - ?\n";
	cout << "  3 - ?\n";
	cout << "  4 - Exit\n";
	cout << ' ' << string(size, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_ver_candidatos(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_ver_info();
		valid_input = false;
		while (!valid_input) {
			try {option = readMenuInput();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //?

			break;
		case 2: //?

			break;
		case 3: //?

			break;
		case 4: //Exit
			done=true;
			break;
		}
	}
}


void draw_menu_ver_jurados(){
	clear_scrn();
	cout << ' ' << string(size, '_') << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << "Ver Jurados" << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << "  1 - ?\n";
	cout << "  2 - ?\n";
	cout << "  3 - ?\n";
	cout << "  4 - Exit\n";
	cout << ' ' << string(size, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_ver_jurados(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_ver_info();
		valid_input = false;
		while (!valid_input) {
			try {option = readMenuInput();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //?

			break;
		case 2: //?

			break;
		case 3: //?

			break;
		case 4: //Exit
			done=true;
			break;
		}
	}
}

void draw_menu_ver_sessoes(){
	clear_scrn();
	cout << ' ' << string(size, '_') << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << titulo << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << '|' << string(size, ' ') << '|' << endl;
	cout << '|' << string(14, ' ') << "Ver Sessoes" << string(15, ' ') << '|' << endl;
	cout << '|' << string(size, '_') << '|' << endl;
	cout << "  1 - ?\n";
	cout << "  2 - ?\n";
	cout << "  3 - ?\n";
	cout << "  4 - Exit\n";
	cout << ' ' << string(size, '-') << endl;
	cout << "Escolha opcao: ";
}

void menu_ver_sessoes(Empresa * empresa){
	bool valid_input, done = false;
	int option;

	while (!done) {
		draw_menu_ver_info();
		valid_input = false;
		while (!valid_input) {
			try {option = readMenuInput();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1: //?

			break;
		case 2: //?

			break;
		case 3: //?

			break;
		case 4: //Exit
			done=true;
			break;
		}
	}
}
