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

        int id {};
        string nombre {};
        string apellido {};
        string correo {};
        int tipoEmpleado {};
        int idSupervisor {};
        string nombreSupervisor = "";
        string apellidoSupervisor = "";
        float salarioNeto = 0;

    string stringDeSalida = "";

    ifstream archivoEmpleados("personas.txt", std::ifstream::in); // Por default abriendo como texto
    

    if (!archivoEmpleados.is_open()) {
        std::cerr << "Error abriendo archivo personas.txt" << std::endl;
        return -1;
    }

    string linea {};

    while (getline(archivoEmpleados, linea)) {
        string nombreSupervisor = "";
        string apellidoSupervisor = "";
        float salarioNeto = 0;

        istringstream stream(linea);

        stream >> id >> nombre >> apellido >> correo >> tipoEmpleado >> idSupervisor;
   
        if (tipoEmpleado == 1) {
            ifstream archivoNomina("nomina.txt", std::ifstream::in); // Por default abriendo como texto
            if (!archivoNomina.is_open()) {
                std::cerr << "Error abriendo archivo nomina.txt" << std::endl;
                return -1;
            }

            string lineaNomina {};

            while (getline(archivoNomina, lineaNomina)) {
                istringstream stream(lineaNomina);

                int idNomina {};
                float pagoMensual {};

                EmpleadoNomina *empleado = new EmpleadoNomina(id, nombre, apellido, correo, tipoEmpleado, idSupervisor, pagoMensual);

                if (idNomina == id) {
                    salarioNeto = empleado-> CalculoPago();
                }
            }
            
        }

        if (tipoEmpleado == 2) {
            ifstream archivoHoras("horastrabajadas.txt", std::ifstream::in); // Por default abriendo como texto
            if (!archivoHoras.is_open()) {
                std::cerr << "Error abriendo archivo horastrabajadas.txt" << std::endl;
                return -1;
            }

            string lineaHoras {};

            while (getline(archivoHoras, lineaHoras)) {
                istringstream stream(lineaHoras);

                int idHoras {};
                float pagoPorHoras {};
                int horasTrabajadas {};

                EmpleadoPorHoras *empleado = new EmpleadoPorHoras(id, nombre, apellido, correo, tipoEmpleado, idSupervisor, pagoPorHoras, horasTrabajadas);

                if (idHoras == id) {
                    salarioNeto = empleado-> CalculoPago();
                }
            }
            
        }

        ifstream archivoBuscaJefes("personas.txt", std::ifstream::in); // Por default abriendo como texto
        if (!archivoBuscaJefes.is_open()) {
            std::cerr << "Error abriendo archivo personas.txt" << std::endl;
            return -1;
        }

        string lineaBuscaJefes;

        while (getline(archivoBuscaJefes, lineaBuscaJefes)) {
            istringstream stream(lineaBuscaJefes);

            int idPosibleSupervisor {};
            string nombrePosibleSupervisor {};
            string apellidoPosibleSupervisor {};
            string correoPosibleSupervisor {};
            int tipoEmpleadoPosibleSupervisor {};
            int idSupervisorPosibleSupervisor {};

            stream >> idPosibleSupervisor >> nombrePosibleSupervisor >> apellidoPosibleSupervisor >> correoPosibleSupervisor >> tipoEmpleadoPosibleSupervisor >> idSupervisorPosibleSupervisor;

            if (idPosibleSupervisor == idSupervisor) {
                nombreSupervisor = nombrePosibleSupervisor;
                apellidoSupervisor = apellidoPosibleSupervisor;
            }
            
        }


    }

    ofstream ofs("Reporte.csv", std::ifstream::out); // Por default abriendo como texto

    if (!ofs.is_open())
    {
        std::cerr << "Error con archivo Reporte.csv" << std::endl;
        return -1;
    }

    ofs << id << ", " << nombre << ", " << apellido << ", " << nombreSupervisor << ", " << apellidoSupervisor << ", " << salarioNeto << endl;

    ofs.close();

    archivoEmpleados.close();

}