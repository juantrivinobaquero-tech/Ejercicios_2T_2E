#include <iostream>
using namespace std;

class VerificadorPalindromo {  // Clase para comprobar números palíndromos
private:
    int valorNumerico;         // Almacena el número a evaluar
public:
    VerificadorPalindromo(){}  // Constructor por defecto
    void establecerNumero(int numero) {  // Asigna un valor al número
      valorNumerico = numero;
    }

    bool comprobarPalindromo(int numero) {  // Determina si el número es palíndromo
      bool resultado;
        // Los números negativos no se consideran palíndromos
        if (numero < 0) {
            resultado = false;
        }
        // Cualquier número de un dígito es palíndromo
        if (numero < 10) {
            resultado = true;
        }

        int numeroOriginal = numero;   // Conserva el valor original
        long numeroInvertido = 0;      // Almacena el número invertido

        // Invierte el número dígito por dígito
        while (numero > 0) {
            int digito = numero % 10;           // Extrae el último dígito
            numeroInvertido = numeroInvertido * 10 + digito;  // Construye el número invertido
            numero = numero / 10;               // Elimina el último dígito
        }
        
        // Compara el número original con el invertido
        if (numeroInvertido == numeroOriginal) {
            resultado = true;
        } else {
            resultado = false;
        }
        return resultado;
    }
};

int main(){
  VerificadorPalindromo verificador;  // Crea una instancia del verificador

  int entradaUsuario = 0;     // Número proporcionado por el usuario
  bool esPalindromo;          // Resultado de la verificación

  // Solicita y recibe el número del usuario
  cout << "Introduzca un número para verificar si es palíndromo: ";
  cin >> entradaUsuario;
  verificador.establecerNumero(entradaUsuario);

  // Realiza la verificación de palíndromo
  esPalindromo = verificador.comprobarPalindromo(entradaUsuario);

  // Muestra el resultado al usuario
  if (esPalindromo == true){
    cout << "\nEl número " << entradaUsuario << " es un palíndromo";
  }
  else{
    cout << "\nEl número " << entradaUsuario << " no es un palíndromo";
  }

  return 0;
}