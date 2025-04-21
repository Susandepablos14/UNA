#include <iostream>  // Para operaciones de entrada/salida estándar
#include <vector>    // Para usar la estructura de datos vector
#include <limits>    // Para numeric_limits (manejo de límites de buffers)
#include <sstream>   // Para stringstream (manejo de conversión de strings)

using namespace std;

// Función para validar y obtener un número entero del usuario
int obtenerEnteroValidado(const string& mensaje) {
    string entrada;
    int valor;
    
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        
        stringstream ss(entrada);
        // Verificar que sea numérico y no tenga caracteres extra
        if (!(ss >> valor) || !ss.eof()) {
            cout << "Error: Debe ingresar un numero entero valido.\n";
            continue;
        }
        
        return valor;
    }
}

// Función para intercambiar dos elementos en un vector
void intercambiar(vector<int>& vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

// Función para encontrar la posición del elemento más pequeño en un rango del vector
int encontrarMinimo(const vector<int>& vec, int inicio) {
    int min_idx = inicio;
    for (int i = inicio + 1; i < vec.size(); ++i) {
        if (vec[i] < vec[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

// Función que implementa el algoritmo de ordenación por selección
void ordenarPorSeleccion(vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        // Encontrar el mínimo en el subvector no ordenado
        int min_idx = encontrarMinimo(vec, i);
        
        // Intercambiar el mínimo encontrado con el primer elemento no ordenado
        intercambiar(vec, i, min_idx);
    }
}

// Función para imprimir los elementos de un vector
void imprimirVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Función para solicitar números al usuario con validación
vector<int> solicitarNumeros() {
    vector<int> numeros;
    
    int cantidad = obtenerEnteroValidado("Ingrese la cantidad de numeros a ordenar: ");
    while (cantidad <= 0) {
        cout << "Error: La cantidad debe ser mayor que 0.\n";
        cantidad = obtenerEnteroValidado("Ingrese la cantidad de numeros a ordenar: ");
    }
    
    cout << "Ingrese los " << cantidad << " numeros, uno por uno:\n";
    for (int i = 0; i < cantidad; ++i) {
        string mensaje = "Numero " + to_string(i + 1) + ": ";
        int numero = obtenerEnteroValidado(mensaje);
        numeros.push_back(numero);
    }
    
    return numeros;
}

int main() {
    // Solicitar números al usuario con validación
    vector<int> datos = solicitarNumeros();
    
    cout << "\nVector original: ";
    imprimirVector(datos);
    
    // Ordenar el vector usando el método de selección
    ordenarPorSeleccion(datos);
    
    cout << "Vector ordenado: ";
    imprimirVector(datos);
    
    return 0;
}