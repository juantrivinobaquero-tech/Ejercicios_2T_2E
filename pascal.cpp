%%writefile triangulo_pascal.cpp
#include <iostream>
#include <vector>

class TrianguloPascal {
private:
    int filas; // Cantidad de filas del triángulo
    std::vector<std::vector<int>> datos; // Almacena todas las filas del triángulo

    void generar() {   // Construye el triángulo con el número de filas especificado
        datos.clear();
        for (int i = 0; i < filas; i++) {
            std::vector<int> fila_actual;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    fila_actual.push_back(1); // Los bordes siempre valen 1
                }
                else {
                    // Calcula sumando los dos elementos superiores
                    int valor = datos[i - 1][j - 1] + datos[i - 1][j];
                    fila_actual.push_back(valor);
                }
            }
            datos.push_back(fila_actual);
        }
    }

public:
    TrianguloPascal(int n) : filas(n) { // Constructor: recibe la cantidad de filas
        if (filas >= 0) {
            generar();
        }
    }

    std::vector<std::vector<int>> obtenerTriangulo() const { // Devuelve el triángulo completo
        return datos;
    }
};

int main() {
    int n_filas = 0;
    std::cout << "Ingrese el número de filas para el triángulo de Pascal: ";
    std::cin >> n_filas;
    
    TrianguloPascal mi_triangulo(n_filas); // Crea instancia del triángulo
    std::vector<std::vector<int>> resultado = mi_triangulo.obtenerTriangulo();

    std::cout << "Triángulo de Pascal con " << n_filas << " filas:" << std::endl;
    for (const auto& fila : resultado) {
        std::cout << "[";
        for (size_t i = 0; i < fila.size(); i++) {
            std::cout << fila[i];
            if (i < fila.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
