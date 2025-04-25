#include <iostream>      // Para operaciones de entrada/salida estándar
#include <vector>        // Para usar la estructura de datos vector
#include <climits>       // Para INT_MAX (valor máximo de un entero)
#include <iomanip>       // Para setw y setprecision (formato de salida)

using namespace std;

const int N = 4;         // Número de nodos en el grafo
const int INF = INT_MAX / 2; // Valor que representa infinito (dividido por 2 para evitar overflow)

// Implementación del algoritmo Floyd-Warshall que calcula distancias mínimas y número de saltos
void floydWarshallConHops(vector<vector<int>>& dist, vector<vector<int>>& hops) {
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    int newDist = dist[i][k] + dist[k][j];
                    int newHops = hops[i][k] + hops[k][j];
                    if (newDist < dist[i][j] || (newDist == dist[i][j] && newHops < hops[i][j])) {
                        dist[i][j] = newDist;
                        hops[i][j] = newHops;
                    }
                }
}

// Calcula el promedio de saltos desde el nodo central S (índice 0) a todos los demás nodos
double calcularPromedioSaltosDesdeS(const vector<vector<int>>& hops) {
    int totalSaltos = 0;
    for (int j = 1; j < N; ++j) {
        totalSaltos += hops[0][j];
    }
    return static_cast<double>(totalSaltos) / (N - 1);
}

// Función para imprimir matrices con formato
void imprimirMatriz(const vector<vector<int>>& matrix, const string& title) {
    cout << "\n" << title << ":\n";
    cout << "     S     1     2     3\n";
    for (int i = 0; i < N; ++i) {
        cout << (i == 0 ? "S" : to_string(i)) << " ";
        for (int j = 0; j < N; ++j)
            cout << setw(6) << (matrix[i][j] == INF ? "INF" : to_string(matrix[i][j]));
        cout << "\n";
    }
}

int main() {
    // Matriz de adyacencia con los costos entre nodos
    vector<vector<int>> dist = {
        {0,   1,   9,   7},  // S
        {1,   0,   2,   5},   // 1
        {9,   2,   0,   2},   // 2
        {7,   5,   2,   0}    // 3
    };

    // Inicialización de matriz de saltos (1 salto para conexiones directas)
    vector<vector<int>> hops(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            hops[i][j] = (i == j) ? 0 : (dist[i][j] != INF ? 1 : INF);

    imprimirMatriz(dist, "Matriz de costos original");

    // Aplicar algoritmo Floyd-Warshall
    floydWarshallConHops(dist, hops);

    // Mostrar resultados
    imprimirMatriz(dist, "Matriz de distancias minimas");
    imprimirMatriz(hops, "Matriz de numero de enlaces");

    // Calcular y mostrar promedio de saltos desde S
    double promedio = calcularPromedioSaltosDesdeS(hops);
    cout << fixed << setprecision(2);
    cout << "\nNumero medio de enlaces desde S: " << promedio << endl;

    return 0;
}