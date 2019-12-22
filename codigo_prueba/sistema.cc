#ifdef _WIN32
	#define CLEAN "cls"
#else
	#define CLEAN "clear"
#endif

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <ctime>
#include <cstring>
#include "paciente.h"
#include "sistema.h"
#include "cita.h"

using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

void Sistema::opciones(){

	cout<<"1) Crear paciente."<<endl;
	cout<<"2) Buscar paciente."<<endl;
	cout<<"3) Mostrar pacientes del dia."<<endl;
	cout<<"4) Modificar paciente."<<endl;
	cout<<"5) Eliminar paciente."<<endl;
	cout<<"6) Mostrar todos los pacientes."<<endl;
	cout<<"7) Concertar cita."<<endl;
	cout<<"8) Modificar cita."<<endl;
	cout<<"9) Eliminar cita."<<endl;
	cout<<"10) Mostrar agenda del dia."<<endl;
	cout<<"11) Mostrar agenda completa."<<endl;
	cout<<"12) Mostrar historial medico de un paciente."<<endl;
	cout<<"13) Aniadir un nuevo historial medico de un paciente."<<endl;
	cout<<"14) Mostrar tratamiento medico de un paciente."<<endl;
	cout<<"15) Aniadir un nuevo tratamiento medico a un paciente."<<endl;
	cout<<"16) Finalizar un tratamiento medico de un paciente."<<endl;
	cout<<"17) Salir del programa."<<endl;

}

int Sistema::buscaPaciente(const Paciente &p){

	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			return 1;
		}
	}
	Reg r;
	ifstream fichero("pacientes.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(Reg))){
		if(r.nombre == p.getNombre() && r.apellidos == p.getApellidos()){
			fichero.close();
			return 2;
		}
	}
	fichero.close();
	return 0;


}

void Sistema::leerPacientes(){

	Paciente aux("", "", "");
	Reg r;
	ifstream fichero("pacientes.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(Reg))){
		aux.setReg(r);
		cout << aux;
	}
	fichero.close();

}

void Sistema::agregarPaciente(const Paciente &p){

	pacientes_.push_back(p);
	Reg aux = p.getReg();
	ofstream fichero("pacientes.bin", ios::app | ios::binary);
	fichero.write((char*)&aux, sizeof(Reg));
	fichero.close();

}


void Sistema::modificaDatos(Paciente &p){

	int opc;
	int n;
	string line;
	double m;
	float q;
	do{
		cout<<"¿Que desea modificar?"<<endl;
		cout<<"1. Nombre"<<endl;
		cout<<"2. Apellidos"<<endl;
		cout<<"3. Seguro"<<endl;
		cout<<"4. Fecha de nacimiento"<<endl;
		cout<<"5. Telefono"<<endl;
		cout<<"6. Peso"<<endl;
		cout<<"7. Altura"<<endl;
		cout<<"8. Guardar cambios"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opc;
		getchar();
		switch(opc){
			case 1:
				cout<<"Introduce el nuevo nombre: ";
				getline(cin, line);
				p.setNombre(line);
			break;
			case 2:
				cout<<"Introduce los nuevos apellidos: ";
				getline(cin, line);
				p.setApellidos(line);
			break;
			case 3:
				cout<<"Introduce el nuevo tipo de seguro: ";
				getline(cin, line);
				p.setSeguro(line);
			break;
			case 4:
				cout<<"Introduce la nueva fecha de nacimiento  (dd/mm/aaaa): ";
				cin>>line;
				p.setFechanacimiento(line);
			break;
			case 5:
				cout<<"Introduce el nuevo telefono: ";
				cin>>m;
				getchar();
				p.setTelefono(m);
			break;
			case 6:
				cout<<"Introduce el nuevo peso: ";
				cin>>q;
				getchar();
				p.setPeso(q);
			break;
			case 7:
				cout<<"Introduce la nueva altura: ";
				cin>>q;
				getchar();
				p.setAltura(q);
			break;
			case 8:
				cout<<"Cambios guardados"<<endl;
			break;
			default:
				cout<<"Opcion no valida"<<endl;
		}
	}while(opc != 8);

}

void Sistema::modificaDatosFich(const Paciente &old_p, const Paciente &new_p){

	Reg r;
	int pos;
	fstream fichero("pacientes.bin", ios::binary | ios::in | ios::out);
	while(fichero.read((char*)&r, sizeof(Reg))){
		if(r.nombre == old_p.getNombre() && r.apellidos == old_p.getApellidos()){
			pos = fichero.tellg() / sizeof(Reg);
			fichero.seekg((pos-1) * sizeof(Reg), ios::beg);
			r = new_p.getReg();
			fichero.write((char*)&r, sizeof(Reg));
		}
	}
	fichero.close();

}

void Sistema::eliminarPacienteFich(const Paciente &p){

	Reg r;
	ifstream fichero("pacientes.bin", ios::binary);
	ofstream temp("temporal.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(Reg))){
		if(r.nombre != p.getNombre() && r.apellidos != p.getApellidos()){
			temp.write((char*)&r, sizeof(Reg));
		}
	}
	fichero.close();
	temp.close();
	remove("pacientes.bin");
	rename("temporal.bin", "pacientes.bin");

}

void Sistema::insertarCita(const Cita &c){

	RegC r = c.getRegC();
	ofstream fichero("citas.bin", ios::binary | ios::app);
	fichero.write((char*)&r, sizeof(RegC));
	fichero.close();

}

void Sistema::modificaDatosCita(Cita &c){

	int opc;
	string line;
	do{
		cout<<"¿Que desea modificar?"<<endl;
		cout<<"1. Fecha"<<endl;
		cout<<"2. Hora"<<endl;
		cout<<"3. Guardar cambios"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opc;
		getchar();
		switch(opc){
			case 1:
				c.introducirFecha();
			break;
			case 2:
				c.introducirHora();
			break;
			case 3:
				cout<<"Cambios guardados"<<endl;
			break;
			default:
				cout<<"Opcion no valida"<<endl;
		}
	}while(opc != 3);

}

void Sistema::start(){

	cout<<"--------Inicializando sistema--------"<<endl;
	time_t fecha = time(NULL);
	struct tm * dia = localtime(&fecha);
	char buffer[20];
	strftime(buffer, 20, "%d/%m/%Y", dia);
	Cita c;
	RegC rc;
	ifstream ficheroC("citas.bin", ios::binary);
	while(ficheroC.read((char*)&rc, sizeof(RegC))){
		if(strcmp(rc.fecha, buffer) == 0){
			c.setRegC(rc);
			citas_.push_back(c);
		}
	}
	ficheroC.close();
	Paciente aux("", "", "");
	Reg r;
	ifstream fichero("pacientes.bin", ios::binary);
	list<Cita>::iterator i;
	string line1, line2;
	for(i = citas_.begin(); i != citas_.end(); i++){
		while(fichero.read((char*)&r, sizeof(Reg))){
			line1 = r.nombre;
			line2 = r.apellidos;
			if((line1 + " " + line2) == i->getPaciente()){
				aux.setReg(r);
				pacientes_.push_back(aux);
			}
		}
	}
	fichero.close();
	menu();

}

void Sistema::menu(){

	int opc;
	string nombre, apellidos;
	Paciente aux("", "", "");
	string medicamento, fecha, motivo; 
	do{
		cout<<"Pulse intro para continuar."<<endl;
		getchar();
		system(CLEAN);
		opciones();
		cout<<"Elige una opcion: ";
		cin>>opc;
		getchar();
		switch(opc){
			case 1:
				setPaciente();
			break;
			case 2:
				cout<<"Introduce el nombre del paciente a buscar: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente a buscar: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				if(buscarPacientes(aux)){
					cout<<"Se encontro al paciente."<<endl;
				}
				else{
					cout<<"No se encontro al paciente."<<endl;
				}
			break;
			case 3:
				mostrarPacientes();
			break;
			case 4:
				cout<<"Introduce el nombre del paciente a modificar: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente a modificar: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				if(modificarPaciente(aux)){
					cout<<"Paciente modificado correctamente."<<endl;
				}
				else{
					cout<<"No se encontro al paciente."<<endl;
				}
			break;
			case 5:
				cout<<"Introduce el nombre del paciente a eliminar: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente a eliminar: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				if(eliminarPaciente(aux)){
					cout<<"Paciente borrado correctamente."<<endl;
				}
				else{
					cout<<"No se encontro al paciente."<<endl;
				}
			break;
			case 6:
				leerPacientes();
			break;
			case 7:
				cout<<"Introduce el nombre del paciente para concertar cita: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente para concertar cita: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				concertarCita(aux);
			break;
			case 8:
				cout<<"Introduce el nombre del paciente para modificar cita: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente para modificar cita: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				modificarCita(aux);
			break;
			case 9:
				cout<<"Introduce el nombre del paciente para eliminar cita: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente para eliminar cita: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				eliminarCita(aux);
			break;
			case 10:
				mostrarAgendaDia();
			break;
			case 11:
				mostrarAgendaCompleta();
			break;
			case 12:
				cout<<"Introduce el nombre del paciente que desea visualizar su historial medico: ";
				getline(cin,nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente que desea visualizar su historial medico: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				aux.mostrarHistorial();
			break;
			case 13:
				cout<<"Introduzca el nombre del paciente al que desea aniadir un historial medico: ";
				getline(cin,nombre);
				aux.setNombre(nombre);
				cout<<"Introduzca los apellidos del paciente al que desea aniadir un historial medico: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				aux.aniadirHistorial();
			break;
			case 14:
				cout<<"Introduzca el nombre del paciente del que desea visualizar su tratamiento medico: ";
				getline(cin,nombre);
				aux.setNombre(nombre);
				cout<<"Introduzca los apellidos del paciente del que desea visualizar su tratamiento medico: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				aux.mostrarTratamiento();
			break;
			case 15 :
				cout<<"Introduzca el nombre del paciente al que desea aniadir un tratamiento medico: ";
				getline(cin,nombre);
				aux.setNombre(nombre);
				cout<<"Introduzca los apellidos del paciente al que desea aniadir un tratamiento medico: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				aux.aniadirTratamiento();
			break;
			case 16:
				cout<<"Introduzca el nombre del paciente del que desea finalizar un tratamiento medico: ";
				getline(cin,nombre);
				aux.setNombre(nombre);
				cout<<"Introduzca los apellidos del paciente del que desea finalizar un tratamiento medico: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				cout<<"Introduzca el medicamento del tratamiento que desea finalizar: ";
				getline(cin, medicamento);
				cout<<"Introduzca la fecha de finalizacion del tratamiento (dd/mm/aaaa): ";
				getline(cin,fecha);
				aux.finalizarTratamiento(medicamento, fecha);
			break;
			case 17:
				cout<<"Saliendo del programa."<<endl;
			break;
			default:
				cout<<"Opcion no valida"<<endl;
		}

	}while(opc != 17);

}

void Sistema::setPaciente(){

	Paciente aux("", "", "");
	cin>>aux;
	agregarPaciente(aux);

}

bool Sistema::buscarPacientes(const Paciente &p){
		
	if(buscaPaciente(p) == 1){
		list <Paciente> :: iterator i;
		for(i = pacientes_.begin(); i != pacientes_.end(); i++){
			if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
				cout << (*i);
				return true;
			}
		}
	}
	else if(buscaPaciente(p) == 2){
		Paciente aux("", "", "");
		Reg r;
		ifstream fichero("pacientes.bin", ios::binary);
		while(fichero.read((char*)&r, sizeof(Reg))){
			if(r.nombre == p.getNombre() && r.apellidos == p.getApellidos()){
				aux.setReg(r);
				cout << aux;
			}
		}
		fichero.close();
		return true;
	}
	return false;

}

void Sistema::mostrarPacientes(){

	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		cout<<(*i);		//Sobrecargado el operador << en las clase paciente
	}

}

bool Sistema::modificarPaciente(Paciente &p){

	if(buscaPaciente(p) == 1){
		Paciente old_p("", "", "");
		list <Paciente> :: iterator i;
		for(i = pacientes_.begin(); i != pacientes_.end(); i++){
			if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
				old_p = *i;
				modificaDatos(*i);
				modificaDatosFich(old_p, *i);
				string new_nombre = (*i).getNombre() + "_" + (*i).getApellidos() + "_tratamiento.bin";
				string old_nombre = old_p.getNombre() + "_" + old_p.getApellidos() + "_tratamiento.bin";
				rename(old_nombre.c_str(), new_nombre.c_str());
				new_nombre = (*i).getNombre() + "_" + (*i).getApellidos() + "_historial.bin";
				old_nombre = old_p.getNombre() + "_" + old_p.getApellidos() + "_historial.bin";
				rename(old_nombre. c_str(), new_nombre.c_str());
				return true;
			}
		}
	}
	else if(buscaPaciente(p) == 2){
		Paciente old_p("", "", "");
		old_p = p;
		modificaDatos(p);
		modificaDatosFich(old_p, p);
		string new_nombre = p.getNombre() + "_" + p.getApellidos() + "_tratamiento.bin";
		string old_nombre = old_p.getNombre() + "_" + old_p.getApellidos() + "_tratamiento.bin";
		rename(old_nombre.c_str(), new_nombre.c_str());
		new_nombre = p.getNombre() + "_" + p.getApellidos() + "_historial.bin";
		old_nombre = old_p.getNombre() + "_" + old_p.getApellidos() + "_historial.bin";
		rename(old_nombre. c_str(), new_nombre.c_str());
		return true;
	}
	return false;

}


bool Sistema::eliminarPaciente(const Paciente &p){
	
	if(buscaPaciente(p) == 1){
		list <Paciente> :: iterator i;
		for(i = pacientes_.begin(); i != pacientes_.end(); i++){
			if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
				pacientes_.erase(i);
				eliminarPacienteFich(p);
				return true;
			}
		}
	}
	else if(buscaPaciente(p) == 2){
		eliminarPacienteFich(p);
		return true;
	}
	return false;

}

bool Sistema::concertarCita(const Paciente &p){

	Cita c;
	time_t fecha = time(NULL);
	struct tm * dia = localtime(&fecha);
	char buffer[20];
	strftime(buffer, 20, "%d/%m/%Y", dia);
	string line = buffer;
	if(buscaPaciente(p) != 0){
		c.setPaciente(p.getNombre() + " " + p.getApellidos());
		cin>>c;
		if(c.checkCita() == true){
			insertarCita(c);
			if(c.getFecha() == line){
				citas_.push_back(c);
			}
			return true;
		}
	}
	return false;

}

bool Sistema::modificarCita(const Paciente &p){

	Cita c;
	RegC r;
	int pos;
	fstream fichero("citas.bin", ios::binary | ios::in | ios::out);
	while(fichero.read((char*)&r, sizeof(RegC))){
		if(r.paciente == p.getNombre() + " " + p.getApellidos()){
			c.setRegC(r);
			modificaDatosCita(c);
			pos = fichero.tellg() / sizeof(RegC);
			fichero.seekg((pos-1) * sizeof(RegC), ios::beg);
			r = c.getRegC();
			fichero.write((char*)&r, sizeof(RegC));
			return true;
		}
	}
	return false;

}

bool Sistema::eliminarCita(const Paciente &p){

	RegC r;
	int cont = 0;
	ifstream fichero("citas.bin", ios::binary);
	ofstream temp("temporal.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegC))){
		if(p.getNombre() + " " + p.getApellidos() != r.paciente){
			temp.write((char*)&r, sizeof(RegC));
		}
		else{
			cont = 1;
		}
	}
	fichero.close();
	temp.close();
	remove("citas.bin");
	rename("temporal.bin", "citas.bin");
	if(cont != 0){
		return true;
	}
	return false;

}

void Sistema::mostrarAgendaDia(){

	list<Cita>::iterator i;
	for(i = citas_.begin(); i != citas_.end(); i++){
		cout << (*i);
	}

}

void Sistema::mostrarAgendaCompleta(){

	Cita c;
	RegC r;
	ifstream fichero("citas.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegC))){
		c.setRegC(r);
		cout << c;
	}
	fichero.close();

}