#include "menus.hpp"

void draw_changeFileName_menu(string (&nomes)[3]) {
	clear_scrn();
	cout << "Escolha nome do ficheiro a alterar: \n";
	cout << "1 - Jurados guardados em \"" << nomes[0] << "\"\n";
	cout << "2 - Sessoes guardadas em \"" << nomes[1] << "\"\n";
	cout << "3 - Candidatos guardados em \"" << nomes[2] << "\"\n";
	cout << "4 - Continuar com nomes atuais\n";
	cout << "Escolha opcao: ";
}

void changeFileName_menu(string (&ficheiros)[3]) {
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
		case 4: //Continuar
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
