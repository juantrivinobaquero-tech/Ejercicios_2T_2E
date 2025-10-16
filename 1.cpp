#include <iostream>
#include <limits>  
#include <ios>     
using namespace std;

// Definición de las operaciones matemáticas disponibles
int CalcularSuma(int valorA, int valorB)
{
    return valorA + valorB;
}

int CalcularProducto(int valorA, int valorB)
{
    return valorA * valorB;
}

int CalcularDiferencia(int valorA, int valorB)
{
    return valorA - valorB;
}

// Ejecuta una operación matemática mediante un puntero a función
void EjecutarOperacionMatematica(int (*operacionElegida)(int, int), int primerValor, int segundoValor)
{
    cout << operacionElegida(primerValor, segundoValor) << endl;
}

int main() {
    int primerNumero, segundoNumero;
    int cantidadOperaciones;

    // Solicita al usuario la cantidad de operaciones a procesar
    do {
        cout << "Sistema de Operaciones Matemáticas\n¿Cuántas operaciones desea ejecutar? (1, 2 o 3): ";
        if (!(cin >> cantidadOperaciones)) {
            cout << "\nEntrada no válida, por favor seleccione 1, 2 o 3 operaciones: \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
            cantidadOperaciones = -1; // Permite que el bucle continúe
        } else if (cantidadOperaciones <= 0 || cantidadOperaciones > 3) {
            cout << "\nCantidad incorrecta, por favor elija entre 1, 2 o 3 operaciones: \n";
            cantidadOperaciones = -1; // Mantiene el bucle activo para valores fuera de rango
        }
    } while (cantidadOperaciones <= 0 || cantidadOperaciones > 3);

    // Captura de los valores numéricos para las operaciones
    cout << "\nIntroduzca el primer valor (primerNumero): ";
    cin >> primerNumero;
    cout << "Introduzca el segundo valor (segundoNumero): ";
    cin >> segundoNumero;

    // Colección de funciones disponibles para realizar operaciones
    int (*conjuntoOperaciones[])(int, int) = {CalcularSuma, CalcularProducto, CalcularDiferencia};

    // Procesamiento de cada operación solicitada por el usuario
    for (int indice = 0; indice < cantidadOperaciones; ++indice) {
        char simboloOperacion;
        int (*operacionActual)(int, int) = nullptr;
        bool entradaValida = false;

        // Menú de selección de tipo de operación
        do {
            cout << "\nSeleccione la operación número " << (indice + 1) << " (s para Suma, m para Multiplicación, r para Resta): ";
            cin >> simboloOperacion;

            if (simboloOperacion == 's' || simboloOperacion == 'S') {
                operacionActual = CalcularSuma;
                entradaValida = true;
            } else if (simboloOperacion == 'm' || simboloOperacion == 'M') {
                operacionActual = CalcularProducto;
                entradaValida = true;
            } else if (simboloOperacion == 'r' || simboloOperacion == 'R') {
                operacionActual = CalcularDiferencia;
                entradaValida = true;
            } else {
                cout << "Opción no reconocida. Utilice 's' para suma, 'm' para multiplicación o 'r' para resta." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
            }
        } while (!entradaValida);

        // Muestra el resultado de la operación seleccionada
        cout << "Resultado de la operación " << (indice + 1) << ": ";
        EjecutarOperacionMatematica(operacionActual, primerNumero, segundoNumero);
    }
    return 0;
}