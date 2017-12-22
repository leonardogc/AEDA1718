#ifndef MENUS_HPP_
#define MENUS_HPP_


#include "Empresa.hpp"

//===========================//
//      Change File Name     //
//===========================//

/**
 * Desenha o menu de mudar o nome dos ficheiros
 *
 * @param nomes nome dos ficheiros
 */
void draw_changeFileName_menu(string (&nomes)[4]);

/**
 * Menu de mudar o nome do ficheiro
 *
 * @param ficheiros file names
 */
void changeFileName_menu(string (&ficheiros)[4]);

/**
 * Muda o nome do ficheiro
 *
 * @param ficheiro nome do ficheiro passado por referencia
 */
void changeFileName (string &ficheiro);



//===========================//
//         Main Menu         //
//===========================//

/**
 *Desenha o menu principal
 */
void draw_main_menu();

/**
 * Menu principal
 *
 * @param empresa
 */
void main_menu(Empresa * empresa);


//===========================//
//         Candidatos        //
//===========================//

/**
 * Desenha o menu de gerir candidatos
 */
void draw_menu_gerir_candidatos();

/**
 * Menu gerir candidatos
 *
 * @param empresa
 */
void menu_gerir_candidatos(Empresa * empresa);

/**
 *Desenha o menu de gerir um candidato
 *
 * @param candidato
 */
void draw_menu_candidato(Candidato * candidato);

/**
 *Menu gerir um candidato
 *
 * @param candidato
 */
void menu_candidato(Candidato * candidato);

/**
 * Desenha o menu de ordenar os candidatos
 */
void draw_menu_ordenar_candidatos();

/**
 * Menu de ordenar os candidatos
 *
 * @param empresa
 */
void menu_ordenar_candidatos(Empresa * empresa);


//===========================//
//          Jurados          //
//===========================//

/**
 * Desenha o menu gerir jurados
 */
void draw_menu_gerir_jurados();

/**
 * Menu gerir jurados
 *
 * @param empresa
 */
void menu_gerir_jurados(Empresa * empresa);

/**
 * Desenha o menu de gerir um jurado
 *
 * @param jurado
 */
void draw_menu_jurado(Jurado * jurado);

/**
 * Menu gerir um jurado
 *
 * @param jurado
 */
void menu_jurado(Jurado * jurado);

/**
 * Desenha o menu ordenar jurados
 */
void draw_menu_ordenar_jurados();

/**
 * Menu ordenar jurados
 *
 * @param empresa
 */
void menu_ordenar_jurados(Empresa * empresa);

//===========================//
//          Sessoes          //
//===========================//

/**
 * Desenha o menu gerir sessoes
 */
void draw_menu_gerir_sessoes();

/**
 * Menu gerir sessoes
 *
 * @param empresa
 */
void menu_gerir_sessoes(Empresa * empresa);

/**
 * Desenha o menu gerir sessao
 *
 * @param sessao
 */
void draw_menu_sessao(Sessao * sessao);

/**
 * Menu gerir sessao
 *
 * @param sessao
 * @param empresa
 */
void menu_sessao(Sessao * sessao, Empresa * empresa);


#endif /* MENUS_HPP_ */
