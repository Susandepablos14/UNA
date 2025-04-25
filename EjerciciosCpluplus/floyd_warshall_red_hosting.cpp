#include <iostream>      // Para operaciones de entrada/salida estándar
#include <vector>        // Para usar la estructura de datos vector
#include <climits>       // Para INT_MAX (valor máximo de un entero)
#include <iomanip>       // Para setw y setprecision (formato de salida)

using namespace std;

const int INF = INT_MAX / 2; // Valor que representa infinito

class GrafoFloydWarshall {
private:
    int numNodos;
    vector<vector<int>> distancias;
    vector<vector<int>> saltos;

    // Inicializa la matriz de saltos
    void inicializarMatrizSaltos() {
        saltos.resize(numNodos, vector<int>(numNodos, INF));
        for (int i = 0; i < numNodos; ++i) {
            for (int j = 0; j < numNodos; ++j) {
                saltos[i][j] = (i == j) ? 0 : (distancias[i][j] != INF ? 1 : INF);
            }
        }
    }

public:
    // Constructor que recibe la matriz de adyacencia
    GrafoFloydWarshall(const vector<vector<int>>& matrizAdyacencia) 
        : numNodos(matrizAdyacencia.size()), distancias(matrizAdyacencia) {
        inicializarMatrizSaltos();
    }

    // Ejecuta el algoritmo Floyd-Warshall
    void ejecutarFloydWarshall() {
        for (int k = 0; k < numNodos; ++k) {
            for (int i = 0; i < numNodos; ++i) {
                for (int j = 0; j < numNodos; ++j) {
                    if (distancias[i][k] != INF && distancias[k][j] != INF) {
                        int nuevaDist = distancias[i][k] + distancias[k][j];
                        int nuevosSaltos = saltos[i][k] + saltos[k][j];
                        
                        if (nuevaDist < distancias[i][j] || 
                           (nuevaDist == distancias[i][j] && nuevosSaltos < saltos[i][j])) {
                            distancias[i][j] = nuevaDist;
                            saltos[i][j] = nuevosSaltos;
                        }
                    }
                }
            }
        }
    }

    // Calcula el promedio de saltos desde un nodo específico
    double calcularPromedioSaltos(int nodoOrigen) const {
        int totalSaltos = 0;
        int nodosAlcanzables = 0;
        
        for (int j = 0; j < numNodos; ++j) {
            if (j != nodoOrigen && saltos[nodoOrigen][j] != INF) {
                totalSaltos += saltos[nodoOrigen][j];
                nodosAlcanzables++;
            }
        }
        
        return nodosAlcanzables > 0 ? static_cast<double>(totalSaltos) / nodosAlcanzables : 0.0;
    }

    // Imprime una matriz con formato
    void imprimirMatriz(const vector<vector<int>>& matriz, const string& titulo) const {
        cout << "\n" << titulo << ":\n";
        cout << "    ";
        for (int j = 0; j < numNodos; ++j) {
            cout << setw(6) << (j == 0 ? "S" : to_string(j));
        }
        cout << "\n";
        
        for (int i = 0; i < numNodos; ++i) {
            cout << (i == 0 ? "S" : to_string(i)) << " ";
            for (int j = 0; j < numNodos; ++j) {
                cout << setw(6) << (matriz[i][j] == INF ? "INF" : to_string(matriz[i][j]));
            }
            cout << "\n";
        }
    }

    // Métodos para acceder a las matrices (opcional)
    const vector<vector<int>>& getDistancias() const { return distancias; }
    const vector<vector<int>>& getSaltos() const { return saltos; }
};

int main() {
    // Matriz de adyacencia con los costos entre nodos
    vector<vector<int>> matrizAdyacencia = {
        {0,   1,   9,   7},  // S (nodo 0)
        {1,   0,   2,   5},   // 1
        {9,   2,   0,   2},   // 2
        {7,   5,   2,   0}    // 3
    };

    // Crear grafo y ejecutar algoritmo
    GrafoFloydWarshall grafo(matrizAdyacencia);
    
    grafo.imprimirMatriz(grafo.getDistancias(), "Matriz de costos original");
    
    grafo.ejecutarFloydWarshall();
    
    // Mostrar resultados
    grafo.imprimirMatriz(grafo.getDistancias(), "Matriz de distancias minimas");
    grafo.imprimirMatriz(grafo.getSaltos(), "Matriz de numero de enlaces");

    // Calcular y mostrar promedio de saltos desde S (nodo 0)
    double promedio = grafo.calcularPromedioSaltos(0);
    cout << fixed << setprecision(2);
    cout << "\nNumero medio de enlaces desde S: " << promedio << endl;

    return 0;
}