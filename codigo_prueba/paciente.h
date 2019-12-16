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
	int edad;
	double telefono;
	float peso;
	float altura;

};

class Paciente{

	private:

		string nombre_;
		string apellidos_;
		int edad_;
		double telefono_;
		float peso_;
		float altura_;

	public:

		Paciente(string, string, int = 0, double = 0, float = 0, float = 0);
		~Paciente(){}
		friend ostream &operator<<(ostream &stream, const Paciente &p);
		friend istream &operator>>(istream &stream, Paciente &p);
		inline void setNombre(string nombre){nombre_ = nombre;}
		inline void setApellidos(string apellidos){apellidos_ = apellidos;}
		inline void setEdad(int edad){edad_ = edad;}
		inline void setTelefono(double telefono){telefono_ = telefono;}
		inline void setPeso(float peso){peso_ = peso;}
		inline void setAltura(float altura){altura_ = altura;}
		void setReg(Reg r);
		inline string getNombre() const {return nombre_;}
		inline string getApellidos() const {return apellidos_;}
		inline int getEdad() const {return edad_;}
		inline double getTelefono() const {return telefono_;}
		inline float getPeso() const {return peso_;}
		inline float getAltura() const {return altura_;}
		Reg getReg() const;
		void mostrarHistorial();
		void aniadirHistorial();
		void mostrarTratamiento();
		void aniadirTratamiento();
		void finalizarTratamiento(string receta, string fechafinalizacion);

};

#endif