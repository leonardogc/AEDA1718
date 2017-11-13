
#include "Empresa.hpp"
#include "menus.hpp"

const string default_files[] = {"jurados.txt","sessoes.txt","candidatos.txt", "participacao.txt"};

int main(){
	string ficheiros[] = {"jurados.txt","sessoes.txt","candidatos.txt", "participacao.txt"};
	Empresa *empresa;
	changeFileName_menu(ficheiros);

	try{
	empresa = new Empresa(ficheiros);
	}
	catch(InvalidFileNameException &e2){
		clear_scrn();
		cout << e2.getFilename() << ": ficheiro nao encontrado!" << endl << "Terminando o programa!";
		return 1;
	}

	main_menu(empresa);

	empresa->save_files(ficheiros);

	clear_scrn();
	delete empresa;
	return 0;

}
