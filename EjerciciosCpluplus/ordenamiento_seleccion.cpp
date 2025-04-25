#include <iostream>  // Para operaciones de entrada/salida estándar
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
#include <limits>    // Para numeric_limits
#include <sstream>   // Para stringstream

using namespace std;

// Función para validar y obtener un número entero del usuario
int obtenerEnteroValidado(const string& mensaje) {
    string entrada;
    int valor;
    
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        
        stringstream ss(entrada);
        if (!(ss >> valor) || !ss.eof()) {
            cout << "Error: Debe ingresar un numero entero valido.\n";
            continue;
        }
        
        return valor;
    }
}

// Función para generar números aleatorios en un arreglo
void generarNumerosAleatorios(int lista[], int cantidad) {
    srand(time(0)); // Semilla basada en el tiempo actual
    for (int i = 0; i < cantidad; ++i) {
        lista[i] = rand() % 1000; // Números aleatorios entre 0 y 999
    }
}

// Implementación del algoritmo de ordenación por selección
void ordenarPorSeleccion(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        // Encontrar el mínimo en el subarreglo no ordenado
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;
            }
        }
        
        // Intercambiar el mínimo encontrado con el primer elemento no ordenado
        int temp = lista[min_idx];
        lista[min_idx] = lista[i];
        lista[i] = temp;
    }
}

// Función para imprimir los elementos de un arreglo
void imprimirLista(const int lista[], int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << lista[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    // Solicitar cantidad de números al usuario
    int cantidad = obtenerEnteroValidado("Ingrese la cantidad de numeros a ordenar: ");
    while (cantidad <= 0) {
        cout << "Error: La cantidad debe ser mayor que 0.\n";
        cantidad = obtenerEnteroValidado("Ingrese la cantidad de numeros a ordenar: ");
    }
    
    // Crear e inicializar la lista con números aleatorios
    int* lista = new int[cantidad];
    generarNumerosAleatorios(lista, cantidad);
    
    cout << "\nLista original: ";
    imprimirLista(lista, cantidad);
    
    // Ordenar la lista usando el método de selección
    ordenarPorSeleccion(lista, cantidad);
    
    cout << "Lista ordenada: ";
    imprimirLista(lista, cantidad);
    
    // Liberar memoria
    delete[] lista;
    
    return 0;
}