#ifndef CANDIDATO_HPP_
#define CANDIDATO_HPP_
#include <string>
#include <vector>

using namespace std;

class Candidato{
private:
	string data;
	int id;
	vector <Participacao *> participacao;
public:
	Candidato();
	string getData();
	int getId();
	vector <Participacao *> getParticipacao();

};

#endif /* CANDIDATO_HPP_ */
