#include <iostream>
#include <cstring>
#include "historial.h"

using std::ostream;
using std::istream;
using std::cout;
using std::endl;

ostream &operator<<(ostream &stream, const Historial &h){

	stream << "Fecha: " << h.getFecha() << endl;
	stream << "Motivo: " << h.getMotivo() << endl;
	return stream;

}

istream &operator>>(istream &stream, Historial &h){

	string line;
	cout << "Introduzca la fecha de la consulta que desee introducir en el historial: ";
	getline(stream,line);
	h.setFecha(line);
	cout << "Introduzca los motivos de la consulta: ";
	getline(stream, line);
	h.setMotivo(line);
	return stream;

}

RegH Historial::getRegH() const {

	RegH r;
	strcpy(r.fecha, fecha_.c_str());
	strcpy(r.motivo, motivo_.c_str());
	return r;

}

void Historial::setRegH(RegH r){

	fecha_ = r.fecha;
	motivo_ = r.motivo;

}
/*
void Historial::mostrarHistorial(string nomFich){

	Historial aux("");
	RegH r;
	ifstream fichero(nomFich + "_historial.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegH))){
		aux.setRegH(r);
		cout << aux;
	}
	fichero.close();

}

void Historial::aniadirHistorial(string nomFich){

	RegH r = getRegH();
	ofstream fichero(nomFich + "_historial.bin", ios::binary | ios::app);
	fichero.write((char*)&r, sizeof(RegH));
	fichero.close();

}*/