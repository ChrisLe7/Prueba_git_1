#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "paciente.h"

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::string;

Paciente::Paciente(string nombre, string apellidos, int edad, double telefono, float peso, float altura){

	nombre_ = nombre;
	apellidos_ = apellidos;
	edad_ = edad;
	telefono_ = telefono;
	peso_ = peso;
	altura_ = altura;

}

ostream &operator<<(ostream &stream, const Paciente &p){

	stream<<"Nombre: "<<p.getNombre()<<endl;
	stream<<"Apellidos: "<<p.getApellidos()<<endl;
	stream<<"Edad: "<<p.getEdad()<<endl;
	stream<<"Telefono: "<<p.getTelefono()<<endl;
	stream<<"Peso: "<<p.getPeso()<<endl;
	stream<<"Altura: "<<p.getAltura()<<endl;
	return stream;

}

istream &operator>>(istream &stream, Paciente &p){

	string nombre, apellidos;
	int edad;
	double telefono;
	float peso, altura;
	char SN;	//Opcion que indica si quiere o no introducir el resto de datos
	bool valida = false;	//Gestiona el bucle para que no salga en caso de introducir algo distinto de si o no
	cout<<"Introduzca el nombre del paciente: ";
	getline(stream, nombre);
	p.setNombre(nombre);
	cout<<"Introduzca los apellidos del paciente: ";
	getline(stream, apellidos);
	p.setApellidos(apellidos);
	do{
		cout<<"¿Desea introducir la edad, el telefono, el peso y la altura del paciente? (S/N): ";
		SN = getchar();
		if('s' == SN || 'S' == SN){
			cout<<"Introduzca la edad del paciente: ";
			stream>>edad;
			p.setEdad(edad);
			getchar();
			cout<<"Introduzca el telefono del paciente: ";
			stream>>telefono;
			p.setTelefono(telefono);
			getchar();
			cout<<"Introduzca el peso del paciente: ";
			stream>>peso;
			p.setPeso(peso);
			getchar();
			cout<<"Introduzca la altura del paciente: ";
			stream>>altura;
			p.setAltura(altura);
			getchar();
			//Paciente p(nombre, apellidos, edad, telefono, peso, altura);
			//agregarPaciente(p);
			valida = true;
		}
		else if('n' == SN || 'N' == SN){
			//Paciente p(nombre, apellidos);
			//agregarPaciente(p);
			valida = true;
		}
		else{
			cout<<"Opcion no valida"<<endl;
			getchar();
		}
	}while(valida != true);

	return stream;

}

void Paciente::setReg(Reg r){

	nombre_ = r.nombre;
	apellidos_ = r.apellidos;
	edad_ = r.edad;
	telefono_ = r.telefono;
	peso_ = r.peso;
	altura_ = r.altura;

}

Reg Paciente::getReg() const {

	Reg r;
	strcpy(r.nombre, nombre_.c_str());
	strcpy(r.apellidos, apellidos_.c_str());
	r.edad = edad_;
	r.telefono = telefono_;
	r.peso = peso_;
	r.altura = altura_;
	return r;

}

void Paciente::mostrarHistorial(){

	Historial aux(nombre_ + "_" + apellidos_ + "_historial.bin");
	RegH r;
	ifstream fichero(nombre_ + "_" + apellidos_ + "_historial.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegH))){
		aux.setRegH(r);
		cout << aux;
	}
	fichero.close();

}

void Paciente::aniadirHistorial(){

	Historial aux(nombre_ + "_" + apellidos_ + "_historial.bin");
	cin >> aux;
	RegH r = aux.getRegH();
	ofstream fichero(nombre_ + "_" + apellidos_ + "_historial.bin", ios::binary | ios::app);
	fichero.write((char*)&r, sizeof(RegH));
	fichero.close();

}

void Paciente::mostrarTratamiento(){

	RegT r;
	Tratamiento aux;
	ifstream fichero(nombre_ + "_" + apellidos_ + "_tratamiento.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegT))){
		aux.setRegT(r);
		cout << aux;
	}
	fichero.close();

}

void Paciente::aniadirTratamiento(){

	Tratamiento aux;
	cin >> aux;
	RegT r = aux.getRegT();
	ofstream fichero(nombre_ + "_" + apellidos_ + "_tratamiento.bin", ios::app | ios::binary);
	fichero.write((char*)&r, sizeof(RegT));
	fichero.close();

}

void Paciente::finalizarTratamiento(string receta, string fechafinalizacion){

	Tratamiento aux;
	RegT r;
	int pos;
	fstream fichero(nombre_ + "_" + apellidos_ + "_tratamiento.bin", ios::binary | ios::in | ios::out);
	while(fichero.read((char*)&r, sizeof(RegT))){
		if(r.receta == receta){
			aux.setRegT(r);
			aux.setFechafinacilizacion(fechafinalizacion);
			pos = fichero.tellg() / sizeof(RegT);
			fichero.seekg((pos-1) * sizeof(RegT), ios::beg);
			r = aux.getRegT();
			fichero.write((char*)&r, sizeof(RegT));
		}		
	}
	fichero.close();

}