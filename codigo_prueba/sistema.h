#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <list>
#include "paciente.h"
#include "cita.h"

using std::list;
using std::string;

class Sistema{

	private:

		list <Paciente> pacientes_;
		list <Cita> citas_;
		void opciones();
		int buscaPaciente(const Paciente &p);
		void agregarPaciente(const Paciente &p);
		void modificaDatos(Paciente &p);
		void modificaDatosFich(const Paciente &p1, const Paciente &p2); //paciente 1 es el antiguo y el 2 el nuevo por si cambia el nombre o apellido
		void eliminarPacienteFich(const Paciente &p);
		void insertarCita(const Cita &c);
		void modificaDatosCita(Cita &c);

	public:

		void start();
		void menu();
		void setPaciente();
		inline list <Paciente> getPacientes() const {return pacientes_;}
		bool buscarPacientes(const Paciente &p);
		void mostrarPacientes();	//de la lista
		void leerPacientes();	//del fichero
		bool modificarPaciente(Paciente &p);
		bool eliminarPaciente(const Paciente &p);
		bool concertarCita(const Paciente &p);
		bool modificarCita(const Paciente &p);
		bool eliminarCita(const Paciente &p);
		void mostrarAgendaDia();
		void mostrarAgendaCompleta();

};

#endif