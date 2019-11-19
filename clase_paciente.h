#include <string>
#include <list>

using namespace std;


class Paciente{

    private:

    string nombre_;
    int edad_;
    double telefono_;
    float peso_;
    float altura_;



    public:

    Paciente();
    ~Paciente();
    inline void setNombre(string nombre){
        nombre_ = nombre;
        };
    inline void setEdad(int edad){
        edad_ = edad;
    };
    inline void setTelefono(double telefono){
        telefono_ = telefono;
    };
    inline void setPeso(float peso){
        peso_ = peso;
    };
    inline void setAltura(float altura){
        altura_ = altura;
    };



};


