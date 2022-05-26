#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>
#include "empleado.h"
#include <string>

class Planilla {

    Empleado *jefe;

    map<int, Empleado *> indiceEmpleados;

    public:
    Planilla(int idJefe, string nombreJefe, string apellidoJefe, string correoJefe, int tipoEmpleadoJefe, int idSupervisorJefe);
    ~Planilla();

    void AgregarEmpleado(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor);
    string EncontrarEmpleado(int idEmpleado); 

    friend istream& operator >> (istream &o, Planilla *planilla);
    friend ostream& operator << (ostream &o, const Planilla *planilla);
};

#endif