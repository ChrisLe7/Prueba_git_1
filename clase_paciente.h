#ifndef PACIENTE_H
#define PACIENTE_H

#include <list>
#include <string>

using namespace std;

class Paciente{

	private:
		string nombre_;
		int edad_;
		double telefono_;
		
	public:
		Paciente(string, int = 0, double = 0);
		//~Paciente();
		void modificarPaciente();
	
};

#endif