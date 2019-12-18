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

ostream &operator<<(ostream &stream, const Paciente &p){

	stream<<"Nombre: "<<p.getNombre()<<endl;
	stream<<"Apellidos: "<<p.getApellidos()<<endl;
	stream<<"Seguro: "<<p.getSeguro()<<endl;
	stream<<"Fecha de nacimiento: "<<p.getFechanacimiento()<<endl;
	stream<<"Telefono: "<<p.getTelefono()<<endl;
	stream<<"Peso: "<<p.getPeso()<<endl;
	stream<<"Altura: "<<p.getAltura()<<endl;
	return stream;

}

istream &operator>>(istream &stream, Paciente &p){

	string line;
	double m;
	float q;
	char SN;	//Opcion que indica si quiere o no introducir el resto de datos
	bool valida = false;	//Gestiona el bucle para que no salga en caso de introducir algo distinto de si o no
	cout<<"Introduzca el nombre del paciente: ";
	getline(stream, line);
	p.setNombre(line);
	cout<<"Introduzca los apellidos del paciente: ";
	getline(stream, line);
	p.setApellidos(line);
	cout<<"Introduzca el tipo de seguro: ";
	getline(stream, line);
	p.setSeguro(line);
	do{
		cout<<"¿Desea introducir la edad, el telefono, el peso y la altura del paciente? (S/N): ";
		SN = getchar();
		if('s' == SN || 'S' == SN){
			cout<<"Introduzca la fecha de nacimiento del paciente: ";
			stream>>line;
			p.setFechanacimiento(line);
			getchar();
			cout<<"Introduzca el telefono del paciente: ";
			stream>>m;
			p.setTelefono(m);
			getchar();
			cout<<"Introduzca el peso del paciente: ";
			stream>>q;
			p.setPeso(q);
			getchar();
			cout<<"Introduzca la altura del paciente: ";
			stream>>q;
			p.setAltura(q);
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
	fechanacimiento_ = r.fechanacimiento;
	telefono_ = r.telefono;
	peso_ = r.peso;
	altura_ = r.altura;
	seguro_ = r.seguro;

}

Reg Paciente::getReg() const {

	Reg r;
	strcpy(r.nombre, nombre_.c_str());
	strcpy(r.apellidos, apellidos_.c_str());
	strcpy(r.fechanacimiento, fechanacimiento_.c_str());
	r.telefono = telefono_;
	r.peso = peso_;
	r.altura = altura_;
	strcpy(r.seguro, seguro_.c_str());
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

void Paciente::finalizarTratamiento(string medicamento, string fechafinalizacion){

	Tratamiento aux;
	RegT r;
	int pos;
	fstream fichero(nombre_ + "_" + apellidos_ + "_tratamiento.bin", ios::binary | ios::in | ios::out);
	while(fichero.read((char*)&r, sizeof(RegT))){
		if(r.medicamento == medicamento){
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