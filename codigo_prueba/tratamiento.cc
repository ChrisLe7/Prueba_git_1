#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "tratamiento.h"

using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

ostream &operator<<(ostream &stream, const Tratamiento &t){

	stream << "Fecha de inicio del tratamiento: " << t.getFechainicio() << endl;
	stream << "Fecha de finalizacion del tratamiento: " << t.getFechafinacilizacion() << endl;
	stream << "Medicamento: " << t.getMedicamento() << endl;
	stream << "Dosis: " << t.getDosis() << endl;
	stream << "Frecuencia: " << t.getFrecuencia() << endl;
	return stream;

}

istream &operator>>(istream &stream, Tratamiento &t){

	string line;
	cout << "Introduzca la fecha de inicio del tratamiento: ";
	getline(stream, line);
	t.setFechainicio(line);
	cout << "Introduzca la fecha de finalizacion del tratamiento: ";
	getline(stream, line);
	t.setFechafinacilizacion(line);
	cout << "Introduzca el medicamento del tratamiento: ";
	getline(stream, line);
	t.setMedicamento(line);
	cout << "Introduzca la dosis del medicamento del tratamiento: ";
	getline(stream, line);
	t.setDosis(line);
	cout << "Introduzca la frecuencia del medicamento del tratamiento: ";
	getline(stream, line);
	t.setFrecuencia(line);
	return stream;

}
void Tratamiento::setRegT(RegT r) {

	fechainicio_ = r.fechainicio;
	fechafinalizacion_ = r.fechafinalizacion;
	medicamento_ = r.medicamento;
	dosis_ = r.dosis;
	frecuencia_ = r.frecuencia;

}

RegT Tratamiento::getRegT() const {

	RegT r;
	strcpy(r.fechainicio, fechainicio_.c_str());
	strcpy(r.fechafinalizacion, fechafinalizacion_.c_str());
	strcpy(r.medicamento, medicamento_.c_str());
	strcpy(r.dosis, dosis_.c_str());
	strcpy(r.frecuencia, frecuencia_.c_str());
	return r;

}
/*
void Tratamiento::mostrarTratamiento(string nomFich){

	RegT r;
	Tratamiento aux;
	ifstream fichero(nomFich + "_tratamiento.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegT))){
		aux.setRegT(r);
		cout << aux;
	}
	fichero.close();

}

void Tratamiento::aniadirTratamiento(string nomFich){

	RegT r = getRegT();
	ofstream fichero(nomFich + "_tratamiento.bin", ios::app | ios::binary);
	fichero.write((char*)&r, sizeof(RegT));
	fichero.close();

}

void Tratamiento::finalizarTratamiento(string nomFich, string receta, string fechafinalizacion){

	RegT r;
	int pos;
	fstream fichero(nomFich + "_tratamiento.bin", ios::binary | ios::in | ios::out);
	while(fichero.read((char*)&r, sizeof(RegT))){
		if(r.receta == receta){
			setRegT(r);
			setFechafinacilizacion(fechafinalizacion);
			pos = fichero.tellg() / sizeof(RegT);
			fichero.seekg((pos-1) * sizeof(RegT), ios::beg);
			r = getRegT();
			fichero.write((char*)&r, sizeof(RegT));
		}		
	}
	fichero.close();

}*/