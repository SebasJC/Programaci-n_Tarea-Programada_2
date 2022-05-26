#include "planilla.h"
#include "empleado.h"
#include "empleadoPorHoras.h"
#include "empleadoNomina.h"

Planilla::Planilla(int idJefe, string nombreJefe, string apellidoJefe, string correoJefe, int tipoEmpleadoJefe, int idSupervisorJefe) {
    this->jefe = new Empleado(idJefe, nombreJefe, apellidoJefe, correoJefe, tipoEmpleadoJefe, idSupervisorJefe);
    this->indiceEmpleados.insert( std::pair<int, Empleado *>(idJefe, this->jefe) );
}

void Planilla::AgregarEmpleado(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor) {
    
    Empleado *nuevoEmpleado = new Empleado(idNuevo, nombreNuevo, apellidoNuevo,correoNuevo, tipoNuevo, nuevaIdSupervisor);

    Empleado *empleadoSupervisor = this->indiceEmpleados.at(nuevaIdSupervisor);

    empleadoSupervisor->InsertarSubordinado(nuevoEmpleado);
    nuevoEmpleado->AsignarSupervisor(empleadoSupervisor);

    this->indiceEmpleados.insert( pair<int, Empleado *>(idNuevo, nuevoEmpleado) );

}

string Planilla::EncontrarEmpleado(int idEmpleado) {

    Empleado *empleadoConElNombre = this->indiceEmpleados.at(idEmpleado);
    return empleadoConElNombre->ObtenerNombre();

    Empleado *empleadoConElApellido = this->indiceEmpleados.at(idEmpleado);
    return empleadoConElApellido->ObtenerApellido();

}