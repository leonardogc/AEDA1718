#ifndef CANDIDATO_HPP_
#define CANDIDATO_HPP_

#include "Participacao.hpp"
#include "Pessoa.hpp"
#include "utils.hpp"


/**
 * \class Candidato
 * Classe filha da classe pessoa, representando um candidato
 */
class Candidato: public Pessoa {
private:

	/// Data de Nascimento do candidato no formato dd/mm/aaaa (dia/mes/ano)
	string dataNascimento;

	/// Numero de candidato atribuido sequencialmente na inscricao
	const int numInscricao;

	/// vetor com as participacoes do candidato
	vector <Participacao *> participacoes;
	/*
	 * se cada pessoa guardar as suas participações o vetor é mais pequeno do que se fosse guardado nas sessoes
	 * e para saber quem participou em cada sessão pode-se evitar percorrer todos os candidatos saltando os que não sejam da arte da sessao
	 */
public:

	/// contador que regista o ultimo valor atribuido na inscricao de um candidato
	static unsigned int numCandidato;

	/**
	 * Construtor usado na criacao de um novo candidato atribuindo os valores de validade (na classe Pessoa) e numero de inscricao de forma automatica
	 * @param nome nome do candidato a criar
	 * @param morada local de residencia do candidato
	 * @param generoArte arte performativa a que o candidato se dedica
	 * @param dataNascimento data de nascimento do candidato no formato dd/mm/aaaa (dia/mes/ano)
	 */
	Candidato(string nome, string  morada, string  generoArte, string dataNascimento);

	/**
	 * Construtor usado na criacao de um candidato com base nos registos em ficheiros, permite definir todos os membros dado da classe
	 * @param nInscricao numero de inscricao a atribuir ao candidato (atualizado de forma conveniente no contador)
	 * @param nome nome do candidato
	 * @param morada local de residencia do candidato
	 * @param generoArte arte performativa a que o candidato se dedica
	 * @param dataNascimento data de nascimento do candidato no formato dd/mm/aaaa (dia/mes/ano)
	 * @param validade define a validade do candidato na classe mae
	 */
	Candidato(int nInscricao, string nome, string  morada, string  generoArte, string dataNascimento, bool validade);

	//Gets
	/**
	 * Metodo que devolve a data de nascimento do candidato
	 * @return copia da string da data de nascimento do candidato no formato dd/mm/aaaa (dia/mes/ano)
	 */
	string getDataNasc() const;

	/**
	 * Metodo que devolve o numero de inscricao do candidato
	 * @return copia do numero de inscricao do candidato
	 */
	int getNumInscricao() const;

	/**
	 * Metodo que devolve as participacoes do candidato
	 * @return copia do vector de participacoes do candidato
	 */
	vector <Participacao *> getParticipacoes() const;

	/**
	 * Adiciona ao candidato uma participacao numa sessao
	 * @param participacao apontador para uma participacao previamente criada
	 * @return true se a participacao for adicionada com sucesso, false caso o candidato já tenha uma participaçao igual (tal como dado pelo operador == na classe Participacao)
	 */
	bool addParticipacao(Participacao * participacao);

	/**
	 * Remove do candidato todas as participacoes numa dada sessao (primeira e segunda fases)
	 * @param sessao apontador para a sessao a remover
	 * @return true se a participacao for removida com sucesso, false caso o candidato nao tenha participado na sessao dada
	 */
	bool removeParticipacao(Sessao * sessao);

	/**
	 * Metodo qu devolve as participacoes de prieira e segunda fased do candidato numa sessao
	 * @param dataSessao tring com a data da sessao em causa
	 * @return par com apontadores para as participacoes na primeira e segunda fases da sessao, null em elementos que nao existam (caso o candidato nao tiver participado numa dada fase da sessao)
	 */
	pair<Participacao *, Participacao *> getParticipacao(string const &dataSessao) const;

	/**
	 * Operador que compara o candidato atual com o candidato passado em parametro
	 * @param c candidato a comparar com o candidato atual
	 * @return true se os candidatos tiverem o mesmo numero de inscricao, false em caso contrario
	 */
	bool operator == (const Candidato &c) const;

	/**
	 * Metodo que imprime no ecra uma tabela com todas as participacoes do candidato
	 */
	void printParticipacoes();

	/**
	 * Metodo que permite escolher uma nova morada para o candidato
	 */
	void alterarMorada();

	/**
	 * Metodo que permite escolher uma nova morada para o candidato
	 */
	void alterarNome();

	/**
	 * Matodo que compara dois candidatos de acordo com a sua arte performativa e idade
	 * @param c candidato a comparar com o candidato atual
	 * @return verdadeiro se o candidato atual for de uma arte performativa alfabeticamente anterior à do candidato dado ou caso sejam da mesma arte, se a idade for menor. Devolve falso caso contrário
	 */
	bool operator< (const Candidato & c) const;

	friend ostream& operator <<(ostream & os,const Candidato c);
};

/**
 * Operador para facilitar a escrita dos dados no ecra
 * @param os stream onde sao guardados os dados a imprimir
 * @param c apontador para o candidato do qual se quer imprimir as informacoes
 * @return ostream os passada como parametro
 */
ostream& operator <<(ostream & os, const Candidato c);


#endif /* CANDIDATO_HPP_ */
