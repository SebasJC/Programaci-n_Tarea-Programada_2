#include "empleado.h"

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

float Empleado::CalculoPago() {
    if (this->tipoEmpleado = 1) {
        
    }

    if (this->tipoEmpleado = 2) {
        //La duda x2
    }
}

string Empleado::EncontrarSupervisor() {
    //La duda x3
}