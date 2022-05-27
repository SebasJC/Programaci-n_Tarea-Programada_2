#include "empleado.h"
#include <string>

Empleado::Empleado() {

}

Empleado::Empleado(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor) {
    this->id = idNuevo;
    this->nombre = nombreNuevo;
    this->apellido = apellidoNuevo;
    this->correo = correoNuevo;
    this->tipoEmpleado = tipoNuevo;
    this->idSupervisor = nuevaIdSupervisor;
    this->nombreSupervisor = "";
    this->apellidoSupervisor = "";
    this->salarioNeto = 0;
}

Empleado::~Empleado() {

    for (Empleado *subordinado : this->subordinados)
    {
        delete subordinado;
    }

}

void Empleado::InsertarSubordinado(Empleado *subordinado) 
{
    this->subordinados.push_back(subordinado);

}

int Empleado::ObtenerId() {

    return this->id;
}

string Empleado::ObtenerNombre() {

    return this->nombre;
}

string Empleado::ObtenerApellido() {

    return this->apellido;
}

int Empleado::ObtenerTipo() {

    return this->tipoEmpleado;
}

int Empleado::ObtenerIdSupervisor() {

    return this->idSupervisor;
}

void Empleado::AsignarSupervisor(Empleado *supervisor)
{
    
}

vector<Empleado *> Empleado::ObtenerSubordinados()
{
    return this->subordinados;
}