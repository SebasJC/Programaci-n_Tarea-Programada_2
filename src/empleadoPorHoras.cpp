#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(int nuevaId, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor, float pagoPorHorasNuevo, int nuevasHorasTrabajadas) {
    this->id = nuevaId;
    this->pagoPorHoras = pagoPorHorasNuevo;
    this->horasTrabajadas = nuevasHorasTrabajadas
}

float  EmpleadoPorHoras::CalculoPago() {
    float pagoNeto = this->pagoPorHoras * this->horasTrabajadas;
    this->salarioNeto = pagoNeto;
    return pagoNeto;
}