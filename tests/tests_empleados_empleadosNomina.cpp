#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"

namespace
{
    TEST(Test_Empleados_EmpleadosNomina, Test_Calculo_Pago_Empleado_Nomina)
    {

        EmpleadoNomina empleado(1, "Carlos", "Perez", "cperez@gmail.com", 1, 1, 500000.0);

        float actual = empleado.CalculoPago();
        float esperada = 465000;

        EXPECT_FLOAT_EQ(esperada, actual);
    }

}