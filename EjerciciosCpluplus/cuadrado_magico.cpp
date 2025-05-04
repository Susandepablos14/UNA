//Ejercicio 1 Cuadrado Mágico
#include <iostream>
using namespace std;

class CuadradoMagico {
private:
    int** vector; // Matriz dinámica para el cuadrado mágico
    int n; // Dimensión del cuadrado

    // Función auxiliar para llenar el cuadrado
    void llenar(int num, int fila, int columna);

public:
    CuadradoMagico(int dimension) {
        n = dimension;
        vector = new int*[n];
        for (int i = 0; i < n; i++) {
            vector[i] = new int[n];
            // Inicializar con ceros
            for (int j = 0; j < n; j++) {
                vector[i][j] = 0;
            }
        }
    }

    ~CuadradoMagico() {
        // Liberar memoria
        for (int i = 0; i < n; i++) {
            delete[] vector[i];
        }
        delete[] vector;
    }

    void llenarCuadradoMagico();
    void visualizarCuadradoMagico();
};

void CuadradoMagico::llenar(int num, int fila, int columna) {
    // Caso base: cuando hemos colocado todos los números
    if (num > n * n) {
        return;
    }
    
    // Colocar el número actual
    vector[fila][columna] = num;
    
    // Calcular la nueva posición
    int nuevaFila = (fila - 1 + n) % n;
    int nuevaColumna = (columna - 1 + n) % n;
    
    // Si la nueva posición está ocupada, moverse hacia abajo
    if (vector[nuevaFila][nuevaColumna] != 0) {
        llenar(num + 1, (fila + 1) % n, columna);
    } else {
        llenar(num + 1, nuevaFila, nuevaColumna);
    }
}

void CuadradoMagico::llenarCuadradoMagico() {
    // Iniciar la recursión desde el número 1 en la posición inicial
    llenar(1, 0, n / 2);
}

void CuadradoMagico::visualizarCuadradoMagico() {
    cout << "\nCuadrado magico de " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vector[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    
    while (true) {
        cout << "Ingrese la dimensión del cuadrado mágico (impar 1-9, 0 para salir): ";
        cin >> n;
        
        if (cin.fail()) {
            cout << "Error: Ingrese un número valido.\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (n == 0) {
            cout << "Programa finalizado.\n";
            break;
        }

        if (n < 1 || n > 9 || n % 2 == 0) {
            cout << "Error: Dimensión debe ser impar entre 1 y 9.\n\n";
            continue;
        }

        // Crear cuadrado mágico con el tamaño indicado
        CuadradoMagico* cuadradomagico = new CuadradoMagico(n);
        cuadradomagico->llenarCuadradoMagico();
        cuadradomagico->visualizarCuadradoMagico();
        
        // Liberar memoria
        delete cuadradomagico;
    }

    return 0;
}