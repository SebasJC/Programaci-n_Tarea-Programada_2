#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "empleado.h"
#include "empleadoPorHoras.h"
#include "empleadoNomina.h"
#include "planilla.h"


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
            float salarioNeto = 0;
            ifstream archivoNomina("nomina.txt", std::ifstream::in); // Por default abriendo como texto
            if (!archivoNomina.is_open())
            {
                std::cerr << "Error abriendo archivo nomina.txt" << std::endl;
                return -1;
            }

            string lineaNomina {};

            while (getline(archivoNomina, lineaNomina)) {
                istringstream stream(linea);

                int idNomina {};
                float pagoMensual {};

                EmpleadoNomina *empleado = new EmpleadoNomina(id, nombre, apellido, correo, tipoEmpleado, idSupervisor, pagoMensual);

                if (idNomina == id) {
                    salarioNeto = empleado-> CalculoPago();
                }
            }
            
        }

        if (tipoEmpleado == 2) {
            float salarioNeto = 0;
            ifstream archivoHoras("horastrabajadas.txt", std::ifstream::in); // Por default abriendo como texto
            if (!archivoHoras.is_open())
            {
                std::cerr << "Error abriendo archivo nomina.txt" << std::endl;
                return -1;
            }

            string lineaHoras {};

            while (getline(archivoHoras, lineaHoras)) {
                istringstream stream(linea);

                int idHoras {};
                float pagoPorHoras {};
                int horasTrabajadas {};

                EmpleadoPorHoras *empleado = new EmpleadoPorHoras(id, nombre, apellido, correo, tipoEmpleado, idSupervisor, pagoPorHoras, horasTrabajadas);

                if (idHoras == id) {
                    salarioNeto = empleado-> CalculoPago();
                }
            }
            
        }


        }

    archivoEmpleados.close();

}