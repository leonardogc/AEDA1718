#ifndef UTILS_HPP_
#define UTILS_HPP_


#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

#include "BST.h"

using namespace std;


extern const string default_files[4];

/**
 * Le input do utilizador e verifica se é composto apenas por numeros
 *
 * @return numero introduzido pelo utilizador
 */
int read_number_Input();

/**
 * Metodo que limpa o ecra
 */
void clear_scrn();

/**
 * Metodo que devolve o numero de digitos de um numero
 *
 * @param numbr numero a processar
 * @return numero de digitos
 */
int numbr_size(int numbr);

/**
 * Calcula se uma data é anterior a outra
 *
 * @param d1 primeira data
 * @param d2 segunda data
 * @return true se a primeira data for antes da segunda data
 */
bool lowerThan(string d1, string d2);

/**
 * \class InvalidFileNameException classe usada para excecoes, no caso de um ficheiro nao ser encontrado
 */
class InvalidFileNameException
{
	///nome do ficheiro nao encontrado
	string filename;
public:
	/**
	 * Construtor da classe InvalidFileNameException
	 *
	 * @param filename nome do ficheiro nao encontrado
	 */
	InvalidFileNameException(string filename) {this->filename = filename;}

	/**
	 * Metodo que devolve o nome do ficheiro
	 *
	 * @return copia da variavel filename
	 */
	string getFilename() {return filename;}
};

/**
 * Metodo que verifica se uma data esta bem escrita e é valida
 *
 * @param date data a verificar
 * @return true se for valida, false se nao for
 */
bool isValidDate(string date);

/**
 * Metodo que espera que o utilizador pressione uma tecla
 *
 */
void pressKeyToContinue();

#endif /* UTILS_HPP_ */
