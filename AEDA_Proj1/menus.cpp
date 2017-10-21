#include "menus.hpp"

void draw_changeFileName_menu(string (&nomes)[3]) {
	cout << "Escolha nome do ficheiro a alterar: \n";
	cout << "1 - Jurados guardados em \"" << nomes[0] << "\"\n";
	cout << "2 - Sessoes guardadas em \"" << nomes[1] << "\"\n";
	cout << "3 - Candidatos guardados em \"" << nomes[2] << "\"\n";
	cout << "4 - Continuar com nomes atuais\n";
	cout << "Escolha opcao: ";
}

void changeFileName_menu(string (&ficheiros)[3]) {
	bool valid_input = false, done = false;
	int option;

	while (!done) {
		draw_changeFileName_menu(ficheiros);
		while (!valid_input) {
			try {option = readMenuInput();}
			catch (invalid_argument &e) { cout << "Opcao Invalida!\nTente outra vez: "; continue;}
			valid_input = true;
		}

		switch (option) {
		case 1:
			//TODO
			break;
		case 2:
			//TODO
			break;
		case 3:
			//TODO
			break;
		case 4:
			done=true;
			break;
		}
	}
}
