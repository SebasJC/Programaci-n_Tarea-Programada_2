#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(int idNuevo, string nombreNuevo, string apellidoNuevo, string correoNuevo, int tipoNuevo, int nuevaIdSupervisor, float pagoMensualNuevo) {
    this->id = idNuevo;
    this->pagoMensual = pagoMensualNuevo;
}

float  EmpleadoNomina::CalculoPago() {
    float retencion = (this->pagoMensual * 7) / 100;
    float pagoNeto = this->pagoMensual - retencion;
    this->salarioNeto = pagoNeto;
    return pagoNeto;
}