#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct RegT{

	char fechainicio[20];
	char fechafinalizacion[20];
	char receta[50];
	
};

class Tratamiento{

	private:

		string fechainicio_;
		string fechafinalizacion_;
		string receta_;
		
	public:

		Tratamiento(string fechainicio = "XX", string fechafinalizacion = "XX", string receta = "XX"){
			fechainicio_ = fechainicio;  fechafinalizacion_ = fechafinalizacion; receta_ = receta;
		}
		~Tratamiento(){}
		friend ostream &operator<<(ostream &stream, const Tratamiento &t);
		friend istream &operator>>(istream &stream, Tratamiento &t);
		inline void setFechainicio(string fechainicio){fechainicio_ = fechainicio;}
		inline void setFechafinacilizacion(string fechafinalizacion){fechafinalizacion_ = fechafinalizacion;}
		inline void setReceta(string receta){receta_ = receta;}
		void setRegT(RegT r);
		inline string getFechainicio() const {return fechainicio_;}
		inline string getFechafinacilizacion() const {return fechafinalizacion_;}
		inline string getReceta() const {return receta_;}
		RegT getRegT() const;
		/*void mostrarTratamiento(string nomFich);
		void aniadirTratamiento(string nomFich);
		void finalizarTratamiento(string nomFich, string receta, string fechafinalizacion);*/

};

#endif