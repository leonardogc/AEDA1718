#ifndef MENUS_HPP_
#define MENUS_HPP_


#include "Empresa.hpp"

void draw_changeFileName_menu(string (&nomes)[4]);
void changeFileName_menu(string (&ficheiros)[4]);
void changeFileName (string &ficheiro);

void draw_main_menu();
void main_menu(Empresa * empresa);

#endif /* MENUS_HPP_ */
