%%writefile Mejor_Tiempo_Compra_Venta.cpp
#include <iostream>
#include <vector>
#include <random>  
#include <limits>  
#include <ios>     

class CalculadoraGanancia {
public:
    int calcularMaximaGanancia(std::vector<int>& precios, int& diaCompra, int& diaVenta) {
        diaCompra = 0; 
        diaVenta = 0; 
        int maximaGanancia = 0; 

        int precioMinimo = precios[0]; 
        int diaCompraTemporal = 0;    

        for (int i = 1; i < precios.size(); i++) { 
            if (precios[i] < precioMinimo) {
                precioMinimo = precios[i];
                diaCompraTemporal = i; 
            }

            int gananciaActual = precios[i] - precioMinimo; 
            if (gananciaActual > maximaGanancia) {
                maximaGanancia = gananciaActual;
                diaVenta = i + 1; 
                diaCompra = diaCompraTemporal + 1; 
            }
        }

        return maximaGanancia;
    }
};

int main() {
    CalculadoraGanancia calculadora; 
    int cantidadDias; 
    int diaCompra = 0; 
    int diaVenta = 0; 

    do {  
        std::cout << "Ingrese el número de días a considerar para la máxima ganancia: " << std::endl;
        if (!(std::cin >> cantidadDias)) { 
            std::cout << "\nComando inválido, por favor ingrese un número entero positivo mayor o igual a 2, que representa el número de días" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cantidadDias = -1; 
        } else if (cantidadDias < 2) { 
            std::cout << "\nComando inválido, por favor ingrese un número entero positivo mayor o igual a 2, que representa el número de días" << std::endl;
            cantidadDias = -1; 
        }
    } while (cantidadDias < 2);

    std::vector<int> precios(cantidadDias); 
    std::random_device generadorSemilla;  
    std::mt19937 generador(generadorSemilla()); 
    std::uniform_int_distribution<int> distribucion(0, 9); 

    std::cout << "\nPrecios generados para los " << cantidadDias << " días (simulando mercado):" << std::endl;
    for (int i = 0; i < cantidadDias; i++) {
        precios[i] = distribucion(generador);  
        std::cout << "Día " << i + 1 << ": " << precios[i] << std::endl; 
    }

    int ganancia = calculadora.calcularMaximaGanancia(precios, diaCompra, diaVenta);
    if (ganancia > 0) {
        std::cout << "\nLa máxima ganancia según los valores del mercado es: " << ganancia
                  << ". Comprando en el día " << diaCompra << " y vendiendo en el día " << diaVenta << std::endl;
    } else {
        std::cout << "\nNo se puede obtener ganancia con estos valores del mercado." << std::endl;
    }

    return 0;
}
