#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Empleado {

    protected:
    int id;
    string nombre;
    string apellido;
    string correo;
    int tipoEmpleado;
    int idSupervisor;
    string nombreSupervisor = "";
    string apellidoSupervisor = "";
    int salarioNeto = 0;
    vector<Empleado *> subordinados;

    public:
    Empleado();
    Empleado(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor);
    ~Empleado();

    void InsertarSubordinado(Empleado *subordinado);

    int ObtenerId();
    string ObtenerNombre();
    string ObtenerApellido();
    int ObtenerTipo();
    int ObtenerIdSupervisor();

    virtual float CalculoPago() = 0;
    void AsignarSupervisor(Empleado *supervisor); 
    vector<Empleado *> ObtenerSubordinados();

    friend istream& operator >> (istream &o, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
};

#endif