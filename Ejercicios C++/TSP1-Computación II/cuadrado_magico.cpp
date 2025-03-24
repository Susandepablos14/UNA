//Ejercicio 1
#include <iostream>
using namespace std;

int main() {
    int n;
    int matriz[9][9] = {0}; // Inicializar la matriz con ceros

    cout << "Ingrese la dimension del cuadrado magico (debe ser un numero impar entre 1 y 9): ";
    cin >> n;

    // Validar que la dimensión sea un número impar entre 1 y 9
    if (n < 1 || n > 9 || n % 2 == 0) {
        cout << "Error: La dimension debe ser un numero impar entre 1 y 9." << endl;
        return 1;
    }

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