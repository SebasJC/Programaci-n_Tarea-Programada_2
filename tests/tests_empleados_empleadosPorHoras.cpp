#include <gtest/gtest.h>
#include "../src/empleadoPorHoras.h"

namespace
{
    TEST(Test_Empleados_EmpleadosNomina, Test_Calculo_Pago_Empleado_Nomina)
    {

        EmpleadoPorHoras empleado(1, "Carlos", "Perez", "cperez@gmail.com", 1, 1, 80000.0, 6);

        float actual = empleado.CalculoPago();
        float esperada = 480000;

        EXPECT_FLOAT_EQ(esperada, actual);
    }


}