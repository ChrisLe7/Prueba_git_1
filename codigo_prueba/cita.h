#ifndef CITA_H
#define CITA_H 

#include <string>

using std::string;
using std::istream;
using std::ostream;

struct RegC{

	char fecha[20];
	char hora[10];
	char paciente[50];

};

class Cita{

	private:

		string fecha_;
		string hora_;
		string paciente_;
		bool checkFecha(int dia, int mes, int anio);
		bool checkHora(int hora, int minuto);
	
	public:
	
		Cita(string fecha = "NO_ASIGNADO", string hora = "NO_ASIGNADO", string paciente = "NO_ASIGNADO"){
			fecha_ = fecha; hora_ = hora; paciente_ = paciente;
		}
		~Cita(){}
		friend ostream &operator<<(ostream &stream, const Cita &c);
		friend istream &operator>>(istream &stream, Cita &c);
		inline void setFecha(string fecha){fecha_ =fecha;}
		inline void setHora(string hora){hora_ = hora;}
		inline void setPaciente(string paciente){paciente_ = paciente;}
		void setRegC(RegC r);
		inline string getFecha() const {return fecha_;}
		inline string getHora() const {return hora_;}
		inline string getPaciente() const {return paciente_;}
		RegC getRegC() const;
		bool checkCita();
		void introducirFecha();
		void introducirHora();
	
};

#endif