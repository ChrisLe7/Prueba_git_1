#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "cita.h"

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;

ostream &operator<<(ostream &stream, const Cita &c){

	stream << "Paciente: " << c.getPaciente() << endl;
	stream << "Fecha: " << c.getFecha() << endl;
	stream << "Hora: " << c.getHora() << endl;
	return stream;

}

istream &operator>>(istream &stream, Cita &c){

	string line;
	cout << "Introduzca la fecha: ";
	getline(stream, line);
	c.setFecha(line);
	cout << "Introduzca la hora: ";
	getline(stream, line);
	c.setHora(line);
	return stream;

}

void Cita::setRegC(RegC r){

	fecha_ = r.fecha;
	hora_ = r.hora;
	paciente_= r.paciente;

}

RegC Cita::getRegC() const {

	RegC r;
	strcpy(r.fecha, fecha_.c_str());
	strcpy(r.hora, hora_.c_str());
	strcpy(r.paciente, paciente_.c_str());		
	return r;

}

/*void Cita::InsertarCita(){

	RegC aux = getRegC();
	ofstream fichero("citas.bin", ios::app | ios::binary) ;
	fichero.write((char*)&aux, sizeof(RegC));
	fichero.close();

}*/


bool Cita::checkCita(){

	RegC r;
	//Cita aux_;
	ifstream fichero("citas.bin",ios::binary) ;
	// recorremos el fichero: 
	while(fichero.read((char*)&r, sizeof(RegC))) {
		//aux_.setRegC(aux);
		if((r.fecha == fecha_) && (r.hora == hora_)) {
			fichero.close();
			return false;
		}
	}
	fichero.close();
	return true;

}

/*bool Cita::ModificarCita(){

	RegC aux ;
	Cita aux_;
	check_cita();

	/*ifstream fichero ("citas.bin", ios::in | ios::binary) ;
	ofstream fichero_aux ("aux.bin", ios::out | ios::binary) ;
	while (!fichero.eof()) {
		fichero.read((char * ) &aux , sizeof (RegC) );
		aux_.setRegC(aux);
		if ((aux_.paciente_ == paciente_) ) {
			aux = getRegC (); 						
			fichero_aux.write((char*)&aux, sizeof(RegC));
		}
		else {
			fichero_aux.write((char*)&aux, sizeof(RegC));
		}
	}
	fichero.close ();
	fichero_aux.close();
	fstream fichero("citas.bin", ios::binary | ios::in | ios::out);
	while(fichero.read((char*)&aux, sizeof(RegC))){
		aux.setRegC(aux);
	}
	//ELIMINAR EL FICHERO CITAS.bin Y RENOMBRAR EL OTRO.
	return true;

}

bool Cita::EliminarCita(){
	
	RegC aux ;
	Cita aux_;

	ifstream fichero ("citas.bin", ios::in | ios::binary) ;
	ofstream fichero_aux ("aux.bin", ios::out | ios::binary) ;
	
	while (!fichero.eof()) {
		fichero.read((char * ) &aux , sizeof (RegC) );
		aux_.setRegC(aux);
		if ((aux_.paciente_ == paciente_) ) {
			aux = getRegC (); 						
			fichero_aux.write((char * )& aux , sizeof (RegC));
		}
		else {
			fichero_aux.write((char * )& aux , sizeof (RegC));

		}
	}
	fichero.close ();
	fichero_aux.close();
	//ELIMINAR EL FICHERO CITAS.bin Y RENOMBRAR EL OTRO.
	return true;

}*/


