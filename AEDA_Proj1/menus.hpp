#ifndef MENUS_HPP_
#define MENUS_HPP_


#include "Empresa.hpp"

void draw_changeFileName_menu(string (&nomes)[4]);
void changeFileName_menu(string (&ficheiros)[4]);
void changeFileName (string &ficheiro);

void draw_main_menu();
void main_menu(Empresa * empresa);

/****************************/
/**       Main Menu        **/
/****************************/
void draw_menu_ver_info();
void menu_ver_info(Empresa * empresa);



/****************************/
/**       Ver info         **/
/****************************/
void draw_menu_ver_candidatos();
void menu_ver_candidatos(Empresa * empresa);

void draw_menu_ver_jurados();
void menu_ver_jurados(Empresa * empresa);//

void draw_menu_ver_sessoes();
void menu_ver_sessoes(Empresa * empresa);//

#endif /* MENUS_HPP_ */
