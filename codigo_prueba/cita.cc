#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "cita.h"

using std::string;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;

bool Cita::checkFecha(int dia, int mes, int anio){

	time_t fecha = time(NULL);
	struct tm * aniosistema = localtime(&fecha);
	char buffer[5];
	strftime(buffer, 5, "%Y", aniosistema);
	if(anio >= atoi(buffer)){
		if(mes >= 1 && mes <= 12){
			if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
				if(dia >= 1 && dia <= 31){
					return true;
				}
				return false;
			}
			else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
				if(dia >= 1 && dia <= 30){
					return true;
				}
				return false;
			}
			else if(mes == 2){
				if(anio % 4 == 0){
					if(dia >= 1 && dia <= 29){
						return true;
					}
					return false;
				}
				else{
					if(dia >= 1 && dia <= 28){
						return true;
					}
					return false;
				}
			}
			return false;
		}
		return false;
	}
	return false;

}

bool Cita::checkHora(int hora, int minuto){

	time_t hour = time(NULL);
	struct tm * horasistema = localtime(&hour);
	char buffer[20];
	strftime(buffer, 20, "%d/%m/%Y", horasistema);
	string line = buffer;
	if(line == getFecha()){
		strftime(buffer, 5, "%H", horasistema);
		if(hora >= atoi(buffer) && hora <=23){
			if(hora == atoi(buffer)){
				strftime(buffer, 5, "%M", horasistema);
				if(minuto >= atoi(buffer) && minuto <= 59){
					return true;
				}
				return false;
			}
			else if(minuto >= 0 && minuto <= 59){
				return true;
			}
			return false;
		}
		return false;
	}
	else{
		if(hora >= 0 && hora <=23){
			if(minuto >= 0 && minuto <= 59){
				return true;
			}
			return false;
		}
		return false;
	}
	return false;

}

void Cita::introducirFecha(){

	time_t date = time(NULL);
	struct tm * time = localtime(&date);
	char buffer[20];
	strftime(buffer, 20, "%Y/%m/%d", time);
	string dia, mes, anio;
	string line;
	string fecha = buffer;
	do{
		do{
			cout << "Introduzca la fecha (dd/mm/aaaa): ";
			getline(cin, line);
			dia = line.substr(0, line.find("/"));
			anio = line.substr(line.rfind("/") + 1);
			mes = line.substr(line.find("/") + 1, line.length() - dia.length() - anio.length() - 2);
		}while(checkFecha(stoi(dia), stoi(mes), stoi(anio)) == false);
		if(stoi(dia) < 10 && dia.length() < 2){
			dia = "0" + dia;
		}
		if(stoi(mes) < 10 && mes.length() < 2){
			mes = "0" + mes;
		}
	}while((anio + "/" + mes + "/" + dia) < fecha);
	setFecha(dia + "/" + mes + "/" + anio);

}

void Cita::introducirHora(){

	time_t hour = time(NULL);
	struct tm * time = localtime(&hour);
	char buffer[20];
	strftime(buffer, 20, "%H:%M", time);
	string hora, minuto;
	string line;
	string tiempo = buffer;
	do{
		cout << "Introduzca la hora (hh:mm, formato 24h): ";
		getline(cin, line);
		hora = line.substr(0, line.find(":"));
		minuto = line.substr(line.find(":") + 1);
	}while(checkHora(stoi(hora), stoi(minuto)) == false);
	if(stoi(hora) < 10 && hora.length() < 2){
		hora = "0" + hora;
	}
	if(stoi(minuto) < 10 && minuto.length() < 2){
		minuto = "0" + minuto;
	}
	setHora(hora + ":" + minuto);

}

ostream &operator<<(ostream &stream, const Cita &c){

	stream << "Paciente: " << c.getPaciente() << endl;
	stream << "Fecha: " << c.getFecha() << endl;
	stream << "Hora: " << c.getHora() << endl;
	return stream;

}

istream &operator>>(istream &stream, Cita &c){

	c.introducirFecha();
	c.introducirHora();
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

bool Cita::checkCita(){

	RegC r;
	ifstream fichero("citas.bin",ios::binary) ;
	while(fichero.read((char*)&r, sizeof(RegC))) {
		if((r.fecha == fecha_) && (r.hora == hora_)) {
			fichero.close();
			return false;
		}
	}
	fichero.close();
	return true;

}