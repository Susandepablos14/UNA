#include <iostream>

using namespace std;

const int INF = 99999; // Valor que representa infinito (usamos un valor grande en lugar de INT_MAX)

class GrafoFloydWarshall {
private:
    int numNodos;
    int** distancias;
    int** saltos;

    // Función auxiliar para inicializar matrices
    void inicializarMatrices(int**& matriz, int valorInicial) {
        matriz = new int*[numNodos];
        for (int i = 0; i < numNodos; i++) {
            matriz[i] = new int[numNodos];
            for (int j = 0; j < numNodos; j++) {
                matriz[i][j] = (i == j) ? 0 : valorInicial;
            }
        }
    }

    // Función recursiva para el algoritmo de Floyd-Warshall
    void floydWarshallRecursivo(int k, int i, int j) {
        if (k >= numNodos) return;
        if (i >= numNodos) {
            floydWarshallRecursivo(k + 1, 0, 0);
            return;
        }
        if (j >= numNodos) {
            floydWarshallRecursivo(k, i + 1, 0);
            return;
        }

        if (distancias[i][k] != INF && distancias[k][j] != INF) {
            int nuevaDist = distancias[i][k] + distancias[k][j];
            int nuevosSaltos = saltos[i][k] + saltos[k][j];
            
            if (nuevaDist < distancias[i][j] || 
               (nuevaDist == distancias[i][j] && nuevosSaltos < saltos[i][j])) {
                distancias[i][j] = nuevaDist;
                saltos[i][j] = nuevosSaltos;
            }
        }

        floydWarshallRecursivo(k, i, j + 1);
    }

public:
    // Constructor que recibe la matriz de adyacencia
    GrafoFloydWarshall(int** matrizAdyacencia, int n) : numNodos(n) {
        // Inicializar matriz de distancias
        inicializarMatrices(distancias, INF);
        for (int i = 0; i < numNodos; i++) {
            for (int j = 0; j < numNodos; j++) {
                if (matrizAdyacencia[i][j] != 0 || i == j) {
                    distancias[i][j] = matrizAdyacencia[i][j];
                }
            }
        }

        // Inicializar matriz de saltos
        inicializarMatrices(saltos, INF);
        for (int i = 0; i < numNodos; i++) {
            for (int j = 0; j < numNodos; j++) {
                saltos[i][j] = (i == j) ? 0 : (distancias[i][j] != INF ? 1 : INF);
            }
        }
    }

    // Destructor para liberar memoria
    ~GrafoFloydWarshall() {
        for (int i = 0; i < numNodos; i++) {
            delete[] distancias[i];
            delete[] saltos[i];
        }
        delete[] distancias;
        delete[] saltos;
    }

    // Ejecuta el algoritmo Floyd-Warshall de forma recursiva
    void ejecutarFloydWarshall() {
        floydWarshallRecursivo(0, 0, 0);
    }

    // Calcula el promedio de saltos desde un nodo específico (recursivo)
    double calcularPromedioSaltos(int nodoOrigen, int j = 0, int totalSaltos = 0, int nodosAlcanzables = 0) {
        if (j >= numNodos) {
            return nodosAlcanzables > 0 ? static_cast<double>(totalSaltos) / nodosAlcanzables : 0.0;
        }

        if (j != nodoOrigen && saltos[nodoOrigen][j] != INF) {
            return calcularPromedioSaltos(nodoOrigen, j + 1, totalSaltos + saltos[nodoOrigen][j], nodosAlcanzables + 1);
        } else {
            return calcularPromedioSaltos(nodoOrigen, j + 1, totalSaltos, nodosAlcanzables);
        }
    }

    // Imprime una matriz con formato
    void imprimirMatriz(int** matriz, const string& titulo) {
        cout << "\n" << titulo << "\n";
        cout << "    ";
        for (int j = 0; j < numNodos; ++j) {
            cout << "  " << (j == 0 ? "S" : to_string(j)) << " ";
        }
        cout << "\n";
        
        for (int i = 0; i < numNodos; ++i) {
            cout << (i == 0 ? "S" : to_string(i)) << " ";
            for (int j = 0; j < numNodos; ++j) {
                if (matriz[i][j] == INF) {
                    cout << " INF";
                } else {
                    if (matriz[i][j] < 10) cout << "   ";
                    else if (matriz[i][j] < 100) cout << "  ";
                    else cout << " ";
                    cout << matriz[i][j];
                }
            }
            cout << "\n";
        }
    }

    // Métodos para acceder a las matrices
    int** getDistancias() { return distancias; }
    int** getSaltos() { return saltos; }
};

int main() {
    const int numNodos = 4;
    
    // Crear matriz de adyacencia manualmente
    int** matrizAdyacencia = new int*[numNodos];
    for (int i = 0; i < numNodos; i++) {
        matrizAdyacencia[i] = new int[numNodos];
    }
    
    // Inicializar matriz con los valores del problema
    // Nodo 0 es S, nodos 1-3 son 1-3
    matrizAdyacencia[0][0] = 0; matrizAdyacencia[0][1] = 1; matrizAdyacencia[0][2] = 9; matrizAdyacencia[0][3] = 7;
    matrizAdyacencia[1][0] = 1; matrizAdyacencia[1][1] = 0; matrizAdyacencia[1][2] = 2; matrizAdyacencia[1][3] = 5;
    matrizAdyacencia[2][0] = 9; matrizAdyacencia[2][1] = 2; matrizAdyacencia[2][2] = 0; matrizAdyacencia[2][3] = 2;
    matrizAdyacencia[3][0] = 7; matrizAdyacencia[3][1] = 5; matrizAdyacencia[3][2] = 2; matrizAdyacencia[3][3] = 0;

    // Crear grafo y ejecutar algoritmo
    GrafoFloydWarshall grafo(matrizAdyacencia, numNodos);
    
    cout << "Matriz de costos original: ";
    grafo.imprimirMatriz(grafo.getDistancias(), "");
    
    grafo.ejecutarFloydWarshall();
    
    // Mostrar resultados
    grafo.imprimirMatriz(grafo.getDistancias(), "Matriz de distancias minimas: ");
    grafo.imprimirMatriz(grafo.getSaltos(), "Matriz de numero de enlaces: ");

    // Calcular y mostrar promedio de saltos desde S (nodo 0)
    double promedio = grafo.calcularPromedioSaltos(0);
    cout.precision(2);
    cout << fixed;
    cout << "\nNumero medio de enlaces desde S: " << promedio << endl;

    // Liberar memoria de la matriz de adyacencia
    for (int i = 0; i < numNodos; i++) {
        delete[] matrizAdyacencia[i];
    }
    delete[] matrizAdyacencia;

    return 0;
}