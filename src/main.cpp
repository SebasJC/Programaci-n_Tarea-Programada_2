#include <sstream>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main() {

    Planilla *planilla = new Planilla();

    ifstream archivoEmpleados("personas.txt", std::ifstream::in); // Por default abriendo como texto
    

    if (!archivoEmpleados.is_open())
    {
        std::cerr << "Error abriendo archivo personas.txt" << std::endl;
        return -1;
    }

}