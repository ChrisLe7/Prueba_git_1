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
		//bool ConcertarCita() {if (check_cita() == true) {InsertarCita();return true;} else {/*VOLVER A INTRODUCIR UNA CITA _ SE PUEDE IMPLEMENTAR AQUI O EN LA FUNCION PRINCIPAL*/ return false;}}
		//bool ModificarCita () ;
		//bool EliminarCita () ;
	
};

#endif