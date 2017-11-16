#ifndef MENUS_HPP_
#define MENUS_HPP_


#include "Empresa.hpp"

//===========================//
//      Change File Name     //
//===========================//

void draw_changeFileName_menu(string (&nomes)[4]);
void changeFileName_menu(string (&ficheiros)[4]);
void changeFileName (string &ficheiro);



//===========================//
//         Main Menu         //
//===========================//

void draw_main_menu();
void main_menu(Empresa * empresa);


//===========================//
//         Candidatos        //
//===========================//

void draw_menu_gerir_candidatos();
void menu_gerir_candidatos(Empresa * empresa);

void draw_menu_candidato(Candidato * candidato);
void menu_candidato(Candidato * candidato);

void draw_menu_ordenar_candidatos();
void menu_ordenar_candidatos(Empresa * empresa);


//===========================//
//          Jurados          //
//===========================//

void draw_menu_gerir_jurados();
void menu_gerir_jurados(Empresa * empresa);

void draw_menu_jurado(Jurado * jurado);
void menu_jurado(Jurado * jurado);

void draw_menu_ordenar_jurados();
void menu_ordenar_jurados(Empresa * empresa);

//===========================//
//          Sessoes          //
//===========================//

void draw_menu_gerir_sessoes();
void menu_gerir_sessoes(Empresa * empresa);
void draw_menu_sessao(Sessao * sessao);
void menu_sessao(Sessao * sessao);


#endif /* MENUS_HPP_ */
