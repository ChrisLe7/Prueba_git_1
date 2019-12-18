#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include <list>
#include "cita.h"
#include "tratamiento.h"
#include "historial.h"

using std::istream;
using std::ostream;
using std::list;
using std::string;

struct Reg{

	char nombre[20];
	char apellidos[30];
	char fechanacimiento[20];
	double telefono;
	float peso;
	float altura;
	char seguro[10];

};

class Paciente{

	private:

		string nombre_;
		string apellidos_;
		string fechanacimiento_;
		double telefono_;
		float peso_;
		float altura_;
		string seguro_;

	public:

		Paciente(string nombre, string apellidos, string seguro, string fechanacimiento = "", double telefono = 0, float peso = 0, float altura = 0){
			nombre_ = nombre;
			apellidos_ = apellidos;
			seguro_ = seguro;
			fechanacimiento_ = fechanacimiento;
			telefono_ = telefono;
			peso_ = peso;
			altura_ = altura;
		}
		~Paciente(){}
		friend ostream &operator<<(ostream &stream, const Paciente &p);
		friend istream &operator>>(istream &stream, Paciente &p);
		inline void setNombre(string nombre){nombre_ = nombre;}
		inline void setApellidos(string apellidos){apellidos_ = apellidos;}
		inline void setFechanacimiento(string fechanacimiento){fechanacimiento_ = fechanacimiento;}
		inline void setTelefono(double telefono){telefono_ = telefono;}
		inline void setPeso(float peso){peso_ = peso;}
		inline void setAltura(float altura){altura_ = altura;}
		inline void setSeguro(string seguro){seguro_ = seguro;}
		void setReg(Reg r);
		inline string getNombre() const {return nombre_;}
		inline string getApellidos() const {return apellidos_;}
		inline string getFechanacimiento() const {return fechanacimiento_;}
		inline double getTelefono() const {return telefono_;}
		inline float getPeso() const {return peso_;}
		inline float getAltura() const {return altura_;}
		inline string getSeguro() const {return seguro_;}
		Reg getReg() const;
		void mostrarHistorial();
		void aniadirHistorial();
		void mostrarTratamiento();
		void aniadirTratamiento();
		void finalizarTratamiento(string medicamento, string fechafinalizacion);

};

#endif