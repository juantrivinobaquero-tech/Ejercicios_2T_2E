#include <iostream>
#include <limits>  
#include <ios>     
#include <vector>  

using namespace std;

class BuscadorSumaObjetivo {
private:
    int valorObjetivo;
    vector<int> indicesResultado;

public:
    BuscadorSumaObjetivo() : indicesResultado(2) {}
    ~BuscadorSumaObjetivo() {}

    void establecerObjetivo(int objetivo) {
        valorObjetivo = objetivo;
    }

    int* encontrarIndicesSuma(int arregloNumeros[], int longitud, int objetivo) {
        for (int indiceActual = 0; indiceActual < longitud; indiceActual++) {
            for (int indiceSiguiente = indiceActual + 1; indiceSiguiente < longitud; indiceSiguiente++) {
                if (arregloNumeros[indiceActual] + arregloNumeros[indiceSiguiente] == objetivo) {
                    indicesResultado[0] = indiceActual;
                    indicesResultado[1] = indiceSiguiente;
                    return indicesResultado.data();
                }
            }
        }
        return nullptr;
    }
};

void ingresarElementosArreglo(int arreglo[], int longitud) {
    for (int posicion = 0; posicion < longitud; posicion++) {
        bool entradaValida = false;
        do {
            cout << "Ingrese el valor para la posición " << posicion << ": ";
            if (cin >> arreglo[posicion]) {
                entradaValida = true;
            } else {
                cout << "Error: Debe ingresar un número entero válido" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!entradaValida);
    }
}

int main() {
    BuscadorSumaObjetivo buscador;
    int sumaDeseada = 0;
    int cantidadElementos = 0;
    int* arregloNumeros = nullptr;

    // Solicitar y validar el tamaño del arreglo
    do {
        cout << "Cantidad de elementos en la lista (mínimo 2): ";
        if (!(cin >> cantidadElementos)) {
            cout << "Error: Debe ingresar un número válido" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cantidadElementos = -1;
        } else if (cantidadElementos <= 1) {
            cout << "Error: La lista debe contener al menos 2 elementos" << endl;
        }
    } while (cantidadElementos <= 1);

    // Crear arreglo dinámico
    arregloNumeros = new int[cantidadElementos];
    
    // Llenar el arreglo con valores del usuario
    ingresarElementosArreglo(arregloNumeros, cantidadElementos);

    // Obtener el valor objetivo
    cout << "Ingrese el valor objetivo (suma de dos elementos): ";
    cin >> sumaDeseada;
    buscador.establecerObjetivo(sumaDeseada);

    // Buscar los índices que suman al objetivo
    int* resultado = buscador.encontrarIndicesSuma(arregloNumeros, cantidadElementos, sumaDeseada);
    
    // Mostrar resultados
    if (resultado) {
        cout << "Los elementos en las posiciones " << resultado[0] 
             << " y " << resultado[1] << " suman " << sumaDeseada << endl;
    } else {
        cout << "No se encontraron dos elementos que sumen " << sumaDeseada << endl;
    }

    // Liberar memoria
    delete[] arregloNumeros;

    return 0;
}