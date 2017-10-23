
#include "Empresa.hpp"
#include "menus.hpp"


const string default_files[] = {"jurados.txt","sessoes.txt","candidatos.txt", "participacao.txt"};

int main(){
	string ficheiros[] = {"jurados.txt","sessoes.txt","candidatos.txt", "participacao.txt"};

	changeFileName_menu(ficheiros);
	Empresa empresa = Empresa(ficheiros);

	main_menu(&empresa);

	clear_scrn();
	return 0;

}
