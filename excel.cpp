
#include <iostream>
#include <string>
#include <cctype>  // Para toupper y isalpha

class Column_Title_to_Num {
public:
    int titleToNum(std::string columnTitle) {
        int columnNumber = 0; // Inicializa la variable entera columNumber en 0

        for (char c : columnTitle) { // Convierte la cadena de letras de char en el número respectivo que representa
            int value = c - 'A' + 1; // Obtiene el valor de letra en la que se encuentra por medio de restar su valor ASCII y A(65), luego se le suma 1, y así se obtiene el valor de la letra
            columnNumber = columnNumber * 26 + value; // Actualiza ColumNumber multiplicando el número de la posición actual por 26, y luego le suma el valor actual de "value"
        }

        return columnNumber;
    }
};

int main() {
    Column_Title_to_Num user_colum_title; // Crea el objeto user_colum_title
    std::string columnTitle; // Crea la variable string columnTitle

    bool validInput = false; // Declarar validInput FUERA del do-while para que esté en scope

    do {
        validInput = false; // Resetear al inicio de cada iteración
        std::cout << "Ingrese el título de la columna en formato Excel (solo letras A-Z o a-z): ";
        std::cin >> columnTitle;

        if (!columnTitle.empty()) { // Validación: Verificar que no este vacío y solo sean letras (mayúsculas o minúsculas)
            validInput = true; // Asumir válido inicialmente
            for (char c : columnTitle) {
                if (!isalpha(c)) { // isalpha verifica si es letra
                    validInput = false;
                    break;
                }
            }
        }

        if (!validInput) {
            std::cout << "Entrada inválida. Debe ser un string no vacío de solo letras (A-Z o a-z). Intente de nuevo." << std::endl;
        }
    } while (!validInput);

    for (char& c : columnTitle) {
        c = toupper(c); // Convierte a mayúscula todo el string
    }

    int result = user_colum_title.titleToNum(columnTitle);
    std::cout << "El número de la columna en Excel '" << columnTitle << "' es: " << result << std::endl;

    return 0;
}
