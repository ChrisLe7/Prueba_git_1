#include <string>
#include "clase_paciente.h"

using namespace std;

Paciente::Paciente(string nombre, int edad, double telefono){

	nombre_ = nombre;
	edad_ = edad;
	telefono_ = telefono;

}

void Paciente::modificarPaciente(){

	string nombre;
	int edad;
	double telefono;
	getline(cin,nombre);
	cin>>edad;
	cin>>telefono;
	nombre_ = nombre;
	edad_ = edad;
	telefono_ = telefono;

}