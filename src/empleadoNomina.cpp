#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(int nuevaId, float pagoMensualNuevo) {
    this->id = nuevaId;
    this->pagoMensual = pagoMensualNuevo;
}

float  EmpleadoNomina::SacarPagoNeto() {
    float retencion = (this->pagoMensual * 7) / 100;
    float pagoNeto = this->pagoMensual - retencion;
}