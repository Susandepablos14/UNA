// Ejercicio 2 Cuadrado Mágico
#include <iostream>
using namespace std;
#include <limits> // Para numeric_limits

int main() {
    int n;
    int matriz[9][9] = {0}; // Inicializar la matriz con ceros

    do {
        cout << "Ingrese la dimension del cuadrado magico (debe ser un numero impar entre 1 y 9, o 0 para salir): ";
        cin >> n;
        
        // Validar que la entrada es un número
        if (cin.fail()) {
            cout << "Error: Debe ingresar un número válido." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada incorrecta
            continue; // Volver al inicio del bucle
        }

        // Si el usuario ingresa 0, salir del programa
        if (n == 0) {
            return 0; // Termina el programa sin mostrar nada más
        }

        // Validar que la dimensión sea un número impar entre 1 y 9
        if (n < 1 || n > 9 || n % 2 == 0) {
            cout << "Error: La dimension debe ser un numero impar entre 1 y 9." << endl;
        }
    } while (n < 1 || n > 9 || n % 2 == 0); // Repetir hasta que el número sea válido o 0

    // Iniciar en la primera fila, columna central
    int fila = 0, columna = n / 2;

    // Llenar el cuadrado mágico
    for (int num = 1; num <= n * n; num++) {
        matriz[fila][columna] = num;

        // Calcular la nueva posición
        int nuevaFila = (fila - 1 + n) % n;
        int nuevaColumna = (columna - 1 + n) % n;

        // Si la nueva posición está ocupada, moverse hacia abajo
        if (matriz[nuevaFila][nuevaColumna] != 0) {
            fila = (fila + 1) % n;
        } else {
            fila = nuevaFila;
            columna = nuevaColumna;
        }
    }

    // Mostrar el cuadrado mágico
    cout << "\nCuadrado magico de " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}