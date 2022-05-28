#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include <string>
#include <iostream>
#include <fstream>
#include "empleado.h"

using namespace std;

class EmpleadoNomina: public Empleado {

    protected:
    int id;
    string nombre;
    string apellido;
    string correo;
    int tipoEmpleado;
    int idSupervisor;
    float pagoMensual;
    float salarioNeto;
    

    public:
    EmpleadoNomina();
    EmpleadoNomina(int id);
    EmpleadoNomina(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor, float pagoMensualNuevo);
    ~EmpleadoNomina();

    virtual float CalculoPago();

    friend istream& operator >> (istream &o, EmpleadoNomina *empleadoNomina);
    friend ostream& operator << (ostream &o, const EmpleadoNomina *empleadoNomina);
};


#endif