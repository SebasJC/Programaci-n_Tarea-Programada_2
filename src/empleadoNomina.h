#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include <string>
#include <iostream>
#include <fstream>
#include "empleado.h"

using namespace std;

class EmpleadoNomina: public Empleado {

    int id;
    float pagoMensual;

    public:
    EmpleadoNomina();
    EmpleadoNomina(int id);
    EmpleadoNomina(int nuevaId, float pagoMensualNuevo);
    ~EmpleadoNomina();

    virtual float CalculoPago();

    friend istream& operator >> (istream &o, EmpleadoNomina *empleadoNomina);
    friend ostream& operator << (ostream &o, const EmpleadoNomina *empleadoNomina);
};


#endif