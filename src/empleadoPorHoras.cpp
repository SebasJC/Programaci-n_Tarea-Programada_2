#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(int nuevaId, float pagoPorHorasNuevo, int nuevasHorasTrabajadas) {
    this->id = nuevaId;
    this->pagoPorHoras = pagoPorHorasNuevo;
    this->horasTrabajadas = nuevasHorasTrabajadas
}

float  EmpleadoPorHoras::SacarPagoNeto() {
    float pagoNeto = this->pagoPorHoras * this->horasTrabajadas;
}