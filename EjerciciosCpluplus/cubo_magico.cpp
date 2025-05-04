//Ejercicio 1 Cubo Mágico
#include <iostream>
using namespace std;

class CuboMagico {
private:
    int** vector; // Matriz dinámica para el cuadrado mágico
    int n; // Dimensión del cubo

    // Función auxiliar para llenar el cubo
    void llenar(int num, int fila, int columna);

public:
    CuboMagico(int dimension) {
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

    ~CuboMagico() {
        // Liberar memoria
        for (int i = 0; i < n; i++) {
            delete[] vector[i];
        }
        delete[] vector;
    }

    void llenarCuboMagico();
    void visualizarCuboMagico();
};

void CuboMagico::llenar(int num, int fila, int columna) {
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

void CuboMagico::llenarCuboMagico() {
    // Iniciar la recursión desde el número 1 en la posición inicial
    llenar(1, 0, n / 2);
}

void CuboMagico::visualizarCuboMagico() {
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
        cout << "Ingrese la dimension del cubo magico (impar 1-9, 0 para salir): ";
        cin >> n;
        
        if (cin.fail()) {
            cout << "Error: Ingrese un numero valido.\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (n == 0) {
            cout << "Programa finalizado.\n";
            break;
        }

        if (n < 1 || n > 9 || n % 2 == 0) {
            cout << "Error: Dimension debe ser impar entre 1 y 9.\n\n";
            continue;
        }

        // Crear cubo mágico con el tamaño indicado
        CuboMagico* cubomagico = new CuboMagico(n);
        cubomagico->llenarCuboMagico();
        cubomagico->visualizarCuboMagico();
        
        // Liberar memoria
        delete cubomagico;
    }

    return 0;
}