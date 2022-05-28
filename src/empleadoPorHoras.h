#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include <string>
#include <iostream>
#include <fstream>
#include "empleado.h"

using namespace std;

class EmpleadoPorHoras {

    int id;
    string nombre;
    string apellido;
    string correo;
    int tipoEmpleado;
    int idSupervisor;
    float pagoPorHoras;
    int horasTrabajadas;
    float salarioNeto;

    public:
    EmpleadoPorHoras();
    EmpleadoPorHoras(int id);
    EmpleadoPorHoras(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor, float pagoPorHorasNuevo, int nuevasHorasTrabajadas);
    ~EmpleadoPorHoras();

    virtual float CalculoPago();

    friend istream& operator >> (istream &o, EmpleadoPorHoras *empleadoPorHoras);
    friend ostream& operator << (ostream &o, const EmpleadoPorHoras *empleadoPorHoras);
};


#endif