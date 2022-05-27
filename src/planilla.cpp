#include "planilla.h"
#include "empleado.h"
#include "empleadoPorHoras.h"
#include "empleadoNomina.h"

Planilla::Planilla(Empleado *jefe) {
    int id = this->jefe->ObtenerId();
    int tipo = this->jefe->ObtenerTipo();

    if (tipo == 1) {
        EmpleadoNomina *jefe = new EmpleadoNomina(id);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(id, this->jefe) );
    }

    if (tipo == 2) {
        EmpleadoPorHoras *jefe = new EmpleadoPorHoras(id);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(id, this->jefe) );
    }
    

}

void Planilla::AgregarEmpleado(Empleado *empleadoNuevo) {

    int id = this->empleadoNuevo->ObtenerId();
    int tipo = this->empleadoNuevo->ObtenerTipo();
    int nuevaIdSupervisor = this->empleadoNuevo->ObtenerIdSupervisor();

    if (tipo == 1) {
        EmpleadoNomina *nuevoEmpleado = new EmpleadoNomina(id);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(id, this->empleadoNuevo) );
    }

    if (tipo == 2) {
        EmpleadoPorHoras *nuevoEmpleado = new EmpleadoPorHoras(id);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(id, this->empleadoNuevo) );
    }
    

    Empleado *empleadoSupervisor = this->indiceEmpleados.at(nuevaIdSupervisor);

    empleadoSupervisor->InsertarSubordinado(empleadoNuevo);
    empleadoNuevo->AsignarSupervisor(empleadoSupervisor);

    this->indiceEmpleados.insert( pair<int, Empleado *>(id, empleadoNuevo) );

}

string Planilla::EncontrarEmpleado(int idEmpleado) {

    Empleado *empleadoConElNombre = this->indiceEmpleados.at(idEmpleado);
    return empleadoConElNombre->ObtenerNombre();

    Empleado *empleadoConElApellido = this->indiceEmpleados.at(idEmpleado);
    return empleadoConElApellido->ObtenerApellido();

}