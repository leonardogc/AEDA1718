
#include "Empresa.hpp"
#include "menus.hpp"

#include <Windows.h>

int main(){
	string ficheiros[3] = {"jurados.txt","sessoes.txt","candidatos.txt"};

	changeFileName_menu(ficheiros);
	Empresa empresa = Empresa();

	main_menu(&empresa);

	clear_scrn();
	return 0;

}
