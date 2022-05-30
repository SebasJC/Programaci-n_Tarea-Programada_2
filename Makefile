FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ $(FLAGS) src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/envios bin/envioPostal.o bin/envioFedEx.o bin/main.o bin/tipoEnvio.o
	
test:
	mkdir -p bin
	g++ $(FLAGS) tests/tests_empleado_empleadosNomina.cpp -o bin/tests_envios_enviosPostales.o
	g++ $(FLAGS) tests/tests_empleado_empleadosPorHoras.cpp -o bin/tests_envios_enviosFedEx.o
	g++ -g -o bin/tests bin/tests_empleado_empleadosNomina.o bin/tests_empleado_empleadosPorHoras.o bin/main.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin