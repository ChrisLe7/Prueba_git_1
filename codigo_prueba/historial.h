#ifndef HISTORIAL_H
#define HISTORIAL_H 

#include <fstream>
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ios;


struct RegH{

	char fecha[20];
	char motivo[50];
	
};

class Historial{

	private:

		string fecha_;
		string motivo_;

	public:

		Historial(string nomFich){
			ofstream fichero;
			fichero.open(nomFich, ios::app | ios::binary) ;
			fichero.close();
		}
		~Historial(){}
		friend ostream &operator<<(ostream &stream, const Historial &h);
		friend istream &operator>>(istream &stream, Historial &h);
		inline void setFecha(string fecha){fecha_  = fecha ;}
		inline void setMotivo(string motivo){motivo_ = motivo;}
		void setRegH(RegH r);
		inline string getFecha() const {return fecha_;}
		inline string getMotivo() const {return motivo_;}
		RegH getRegH() const;
		/*void mostrarHistorial(string nomFich);
		void aniadirHistorial(string nomFich);*/

};

#endif