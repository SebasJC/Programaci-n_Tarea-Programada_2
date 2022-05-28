#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>
#include "empleado.h"
#include <string>

class Planilla {

    protected:
    Empleado *jefe;
    Empleado *empleadoNuevo;

    map<int, Empleado *> indiceEmpleados;

    public:
    Planilla();
    Planilla(Empleado *jefe);
    ~Planilla();

    void AgregarEmpleado(Empleado *empleadoNuevo);
    string EncontrarEmpleado(int idEmpleado); 

    friend istream& operator >> (istream &o, Planilla *planilla);
    friend ostream& operator << (ostream &o, const Planilla *planilla);
};

#endif