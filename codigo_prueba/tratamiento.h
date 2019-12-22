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
	char medicamento[50];
	char dosis[20];
	char frecuencia[30];
	
};

class Tratamiento{

	private:

		string fechainicio_;
		string fechafinalizacion_;
		string medicamento_;
		string dosis_;
		string frecuencia_;
		
	public:

		Tratamiento(string fechainicio = "XX", string fechafinalizacion = "XX", string medicamento = "XX", string dosis = "XX", string frecuencia = "XX"){
			fechainicio_ = fechainicio;  fechafinalizacion_ = fechafinalizacion; medicamento_ = medicamento; dosis_ = dosis; frecuencia_ = frecuencia;
		}
		~Tratamiento(){}
		friend ostream &operator<<(ostream &stream, const Tratamiento &t);
		friend istream &operator>>(istream &stream, Tratamiento &t);
		inline void setFechainicio(string fechainicio){fechainicio_ = fechainicio;}
		inline void setFechafinacilizacion(string fechafinalizacion){fechafinalizacion_ = fechafinalizacion;}
		inline void setMedicamento(string medicamento){medicamento_ = medicamento;}
		inline void setDosis(string dosis){dosis_ = dosis;}
		inline void setFrecuencia(string frecuencia){frecuencia_ = frecuencia;}
		void setRegT(RegT r);
		inline string getFechainicio() const {return fechainicio_;}
		inline string getFechafinacilizacion() const {return fechafinalizacion_;}
		inline string getMedicamento() const {return medicamento_;}
		inline string getDosis() const {return dosis_;}
		inline string getFrecuencia() const {return frecuencia_;}
		RegT getRegT() const;

};

#endif