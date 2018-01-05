#ifndef EMPRESA_HPP_
#define EMPRESA_HPP_

#include "Candidato.hpp"
#include "Jurado.hpp"
#include "Participacao.hpp"
#include "Pessoa.hpp"
#include "Sessao.hpp"
#include "utils.hpp"

struct ciHash
{
	int operator() (const Candidato &c) const
	{
		return c.getNumInscricao();
	}

	bool operator() (const Candidato &c1, const Candidato &c2) const
	{
		return c1==c2;
	}
};

typedef unordered_set<Candidato, ciHash, ciHash> candidatosIndisponiveisHash;


namespace castingspace
{
/**
 * Enum type used in the sorting methods
 */

enum sort_t /// all sorts are for Ascending order
{
	///name is sorted from a to z
	by_name,			///used for jurados, candidatos

	///name and art are sorted from a to z | elements are grouped by art and ordered alphabetically in the same art
	by_name_and_art,	///used for jurados, candidatos

	///age is sorted from younger to older; art is sorted from a to z | elements are grouped by art and ordered by age in the same art
	by_age_and_art,		///used for candidatos

	///date is sorted chronologically; art is sorted from a to z | elements are grouped by art and ordered chronologically in the same art
	by_date_and_art,	///used for sessoes
};
}

//TODO priority queue

class comp_candidatos{
public:
	comp_candidatos(){};
	bool operator()(Candidato * cand1, Candidato * cand2) const{
		return lowerThan(cand1->getDataMaisRecente(), cand2->getDataMaisRecente());
	}
};

typedef priority_queue<Candidato*, vector<Candidato*>, comp_candidatos> pq_recentes;

const Candidato NoCandidate = Candidato(0, "", "", "", "", false, "");

/**
 * \class Empresa
 * Classe que guarda em vetores toda a informacao
 */
class Empresa {
private:

	///usado para guardar os candidatos apagados, considerados como inválidos por forma a não perder os dados relativos a sessões antigas
	candidatosIndisponiveisHash candidatosInvalidos;

	///Vetor usado para guardar pointers para os objetos da classe Jurado
	vector<Jurado *> jurados;

	///árvore binária de pesquisa usada para guardar os candidatos ordenados alfabéticamente pela arte e por ordem de idades dentro da mesma arte
	BST<Candidato> candidatos;

	///Vetor usado para guardar os candidatos apagados, considerados como inválidos por forma a não perder os dados relativos a sessões antigas
	//vector<Candidato> candidatosInvalidos;

	///Vetor usado para guardar pointers para os objetos da classe Sessao
	vector<Sessao *> sessoes;

	///Fila de prioridade utilizada para guardar candidattos ordenados por sessao mais recente
	vector<pq_recentes> candidatos_ordenados;

	/**
	 * Metodo que chama as funcoes que leem os ficheiros
	 *
	 * @param nomes array que contem o nome dos ficheiros a ler
	 */
	void load_files(string (&nomes)[4]);

	/**
	 * Metodo usado para ler o ficheiro dos jurados
	 *
	 * @param s nome do ficheiro a ler
	 */
	void load_jurados(string &s);

	/**
	 * Metodo usado para ler o ficheiro das sessoes
	 *
	 * @param s nome do ficheiro a ler
	 */
	void load_sessoes(string &s);

	/**
	 * Metodo usado para ler o ficheiro dos candidatos
	 *
	 * @param s nome do ficheiro a ler
	 */
	void load_candidatos(string &s);

	/**
	 * Metodo usado para ler o ficheiro das participacoes
	 *
	 * @param s nome do ficheiro a ler
	 */
	void load_participacao(string &s);

	/**
	 *  Metodo usado para guardar a informacao dos jurados num ficheiro
	 *
	 * @param s nome do ficheiro onde é guardada a informacao
	 */
	void save_jurados(string &s);

	/**
	 * Metodo usado para guardar a informacao das sessoes num ficheiro
	 *
	 * @param s nome do ficheiro onde é guardada a informacao
	 */
	void save_sessoes(string &s);

	/**
	 * Metodo usado para guardar a informacao dos candidatos num ficheiro
	 *
	 * @param s nome do ficheiro onde é guardada a informacao
	 */
	void save_candidatos(string &s);

	/**
	 * Metodo usado para guardar a informacao das participacoes num ficheiro
	 *
	 * @param s nome do ficheiro onde é guardada a informacao
	 */
	void save_participacao(string &s);
public:

	/**
	 *Construtor da classe Empresa, que chama o metodo que le a informacao guardada nos ficheiros
	 *
	 * @param nomes array que contem o nome dos ficheiros a ler
	 */
	Empresa(string (&nomes)[4]);

	/**
	 * metodo que imprime todos os jurados
	 */
	void printJurados();

	/**
	 * metodo que imprime todos os candidatos validos
	 */
	void printCandidatosValidos();

	/**
	 * metodo que imprime todos os candidatos invalidos
	 */
	void printCandidatosInvalidos();


	/**
	 * metodo que imprime todas as sessoes
	 */
	void printSessoes();

	/**
	 * metodo que imprime a arte, a data, os jurados e os candidatos da primeira e segunda fase,
	 * caso nao tenham sido geradas as fases imprime a arte, a data, os jurados
	 *
	 * @param sessao sessao que se quer imprimir
	 */
	void printDetalhesSessao(Sessao * sessao);

	/**
	 * Metodo que chama as funcoes que guardam a informacao em ficheiros
	 *
	 * @param nomes array que contem o nome dos ficheiros onde vai ser guardada a informacao
	 */
	void save_files(string (&nomes)[4]);

	/**
	 * Metodo que ordena o vetor dos jurados
	 *
	 * @param by tipo de sort
	 */
	void sortJurados(castingspace::sort_t const & by);

	/**
	 * Metodo que ordena o vetor das sessoes
	 *
	 * @param by tipo de sort
	 */
	void sortSessoes(castingspace::sort_t const & by);

	/**
	 * Metodo que ordena o vetor dos candidatos
	 *
	 * @param by tipo de sort
	 */
	//void sortCandidatos(castingspace::sort_t const & by);


	/**
	 * Metodo que serve para escolher um candidato do vetor candidatos
	 *
	 * @return pointer para o candidato escolhido
	 */
	Candidato* escolher_candidato();

	/**
	 * Metodo que serve para escolher um jurado do vetor jurados
	 *
	 * @return pointer para o jurado escolhido
	 */
	Jurado*  escolher_jurado();

	/**
	 * Metodo que serve para escolher uma sessao do vetor sessoes
	 *
	 * @return pointer para a sessao escolhida
	 */
	Sessao *  escolher_sessao();

	/**
	 *Metodo usado para criar um novo candidato
	 */
	void adicionar_candidato();

	/**
	 * Metodo usado para criar um novo jurado
	 */
	void adicionar_jurado();

	/**
	 * Metodo usado para criar uma nova sessao
	 */
	void adicionar_sessao();

	/**
	 * Metodo que torna um jurado invalid (jurado nao pode ser usado mais)
	 */
	void remover_jurado();

	/**
	 * Metodo que torna um candidato invalid (candidato nao pode ser usado mais)
	 */
	void remover_candidato();

	/**
	 *Metodo que elimina uma sessao
	 */
	void remover_sessao();

	/**
	 * Metodo que altera a data de uma sessao
	 *
	 * @param sessao sessao a alterar
	 */
	void alterarDataSessao(Sessao* sessao);

	//outros metodos

	/**
	 *Metodo que serve para adicionar um candidato a uma sessao
	 *
	 * @param sessao sessao à qual é adicionado o candidato
	 */
	void adicionar_candidato_sessao(Sessao * sessao);

	/**
	 * Metodo que serve para eliminar um candidato de uma sessao
	 *
	 * @param sessao sessao da qual é eliminado o candidato
	 */
	void remover_candidato_sessao(Sessao * sessao);

	/**
	 * Metodo que gera aleatoriamente pontuacoes para a primeira fase
	 *
	 * @param sessao sessao em que vai ser gerada a primeira fase
	 */
	void gerarPrimeiraFase(Sessao * sessao);

	/**
	 * Metodo que gera aleatoriamente pontuacoes para a segunda fase,
	 * apenas passam os 5 melhores na primeira fase
	 *
	 * @param sessao sessao em que vai ser gerada a segunda fase
	 */
	void gerarSegundaFase(Sessao * sessao);

	//TODO priority_queue
	/**
	 * Metodo para adicionar um candidato à fila de prioridades
	 * da sua arte
	 *
	 * @param cand Candidato que vai ser adicionado à priority queue
	 */
	void adiciona_candidato_pq(Candidato * cand);


	/**
	 * Metodo para atualizar as informações de um candidato que já existe
	 * numa determinada fila do vetor de listas de prioridades
	 *
	 * @param cand Candidato que vai ser alterado na priority queue
	 */
	void atualiza_candidato_pq(Candidato cand);

	/**
	 * Metodo que retorna uma fila de prioridades de uma certa arte
	 *
	 * @param arte arte cuja fila se pretende retornar
	 */
	pq_recentes getPQ(string arte);

	/**
	 * Metodo que adiciona os candidatos a fila de prioridade
	 *
	 */
	void adicionar_candidatos_priority_queue();

	/**
	 * Metodo que torna um candidato valido
	 */
	void validar_candidato();

};

/**
 *Metodo que ordena por ordem decrescente a pontuacao do vetor candidatos passado como argumento
 *
 * @param candidatos vetor a ordenar
 * @param dataSessao data da sessao
 * @param fase fase da sessao
 */
void sortBy_points_in_session(vector<Candidato> &candidatos, string const &dataSessao, int fase);

/**
 * Metodo que percorre o argumento line ate encontrar ';' e poe no argumento ss o que foi lido ate ai
 *
 * @param line linha a percorrer
 * @param ss guarda o que esta escrito antes do proximo ';'
 */
void parse_line(string &line, stringstream &ss);

#endif /* EMPRESA_HPP_ */
