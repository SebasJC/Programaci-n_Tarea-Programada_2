#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "empleado.h"
#include "empleadoPorHoras.h"
#include "empleadoNomina.h"


using namespace std;

int main() {

    Planilla *planilla = new Planilla();

    ifstream archivoEmpleados("personas.txt", std::ifstream::in); // Por default abriendo como texto
    

    if (!archivoEmpleados.is_open())
    {
        std::cerr << "Error abriendo archivo personas.txt" << std::endl;
        return -1;
    }

    string linea {};

    while (getline(archivoEmpleados, linea)) {
        // Mientras el getline obtenga alguna línea,
        // procesar línea
        istringstream stream(linea);

        int id {};
        string nombre {};
        string apellido {};
        string correo {};
        int tipoEmpleado {};
        int idSupervisor {};
       

        stream >> id >> nombre >> apellido >> correo >> tipoEmpleado >> idSupervisor;
   
        if (tipoEmpleado == 1) {
            EmpleadoNomina *empleado = new EmpleadoNomina();
            empleado-> CalculoPago();
        }
        }

    archivoEmpleados.close();

}