#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Empleado {

    int id;
    string nombre;
    string apellido;
    string correo;
    int tipoEmpleado;
    int idSupervisor;
    string nombreSupervisor = "";
    string apellidoSupervisor = "";
    int salarioNeto = 0;

    public:
    Empleado();
    Empleado(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor);
    ~Empleado();

    virtual float CalculoPago();
    virtual string EncontrarSupervisor(); 

    friend istream& operator >> (istream &o, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
};

#endif