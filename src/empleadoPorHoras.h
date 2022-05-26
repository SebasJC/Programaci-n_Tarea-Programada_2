#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class EmpleadoPorHoras {

    int id;
    float pagoPorHoras;
    int horasTrabajadas;

    public:
    EmpleadoPorHoras();
    EmpleadoPorHoras(int nuevaId, float pagoPorHorasNuevo, int nuevasHorasTrabajadas);
    ~EmpleadoPorHoras();

    virtual float SacarPagoNeto();

    friend istream& operator >> (istream &o, EmpleadoPorHoras *empleadoPorHoras);
    friend ostream& operator << (ostream &o, const EmpleadoPorHoras *empleadoPorHoras);
};


#endif