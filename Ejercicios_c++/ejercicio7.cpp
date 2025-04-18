#include <iostream>      // Para operaciones de entrada/salida estándar
#include <cstdlib>       // Para rand() y srand() (generación de números aleatorios)
#include <ctime>         // Para time() (obtención de semilla aleatoria)
#include <vector>        // Para usar la estructura de datos vector
#include <algorithm>     // Para sort() (ordenamiento de vectores)
#include <limits>        // Para numeric_limits (manejo de límites de buffers)
#include <sstream>       // Para stringstream (manejo de conversión de strings)
#include <cmath>         // Para funciones matemáticas (round, fabs)
#include <iomanip>       // Para setprecision (control de decimales en salida)

using namespace std;

// Función que genera un vector de números reales aleatorios con exactamente 2 decimales
vector<double> generarNumeros(int cantidad) {
    vector<double> numeros;  // Vector para almacenar los números generados
    srand(time(0)); // Inicializa semilla aleatoria basada en el tiempo actual

    for (int i = 0; i < cantidad; ++i) {
        // Genera número entre 0 y 2000 con 2 decimales exactos:
        // 1. Genera número entre 0 y 2000
        // 2. Multiplica por 100 para trabajar con centésimas
        // 3. Redondea al entero más cercano
        // 4. Divide por 100 para obtener 2 decimales exactos
        double numero = round((double)rand() / RAND_MAX * 2000.0 * 100) / 100.0;
        numeros.push_back(numero);
    }

    return numeros;
}

// Función que imprime los primeros 100 números del vector
void imprimirNumeros(const vector<double>& numeros) {
    cout << "Primeros 100 numeros (ordenados):" << endl;

    // Itera sobre los primeros 100 elementos del vector
    for (int i = 0; i < 100; ++i) {
        cout << numeros[i] << ", "; // Imprime cada número seguido de espacio
    }
    cout << "\n...\n" << endl;  // Indicador de que hay más números no mostrados
}

// Función para validar y obtener un número con exactamente 2 decimales dentro del rango [0.00, 2000.00]
double obtenerNumeroValidado() {
    string entrada;
    double x;
    
    while (true) {
        cout << "Ingrese el numero a buscar (0.00-2000.00): ";
        getline(cin, entrada);
        
        // Validación 1: Verificar que sea numérico y no tenga caracteres extra
        stringstream ss(entrada);
        if (!(ss >> x) || !ss.eof()) {
            cout << "Error: Debe ingresar un valor numerico valido (ej. 123.45).\n";
            continue;
        }
        
        // Validación 2: Verificar rango y decimales en un solo paso
        if (x < 0.00) {
            cout << "Error: El valor no puede ser negativo.\n";
        } 
        else if (x > 2000.00) {
            cout << "Error: El valor no puede ser mayor a 2000.00.\n";
        }
        else if (fabs(x - round(x * 100) / 100.0) > 0.0001) {
            cout << "Error: El numero debe tener exactamente 2 decimales.\n";
        }
        else {
            return x;
        }
    }
}

// Función de búsqueda binaria en un vector ordenado
int busquedaBinaria(const vector<double>& arr, double x) {
    int izquierda = 0; // Límite izquierdo inicial
    int derecha = arr.size() - 1; // Límite derecho inicial

    while (izquierda <= derecha) { // Mientras haya elementos por buscar
        int medio = izquierda + (derecha - izquierda) / 2; // Calcula punto medio
        
        if (arr[medio] == x) {
            return medio; // Retorna posición si encuentra el elemento
        }
        
        if (arr[medio] < x) {
            izquierda = medio + 1; // Busca en la mitad derecha
        } else {
            derecha = medio - 1; // Busca en la mitad izquierda
        }
    }
    
    return -1; // Retorna -1 si el elemento no se encuentra
}

// Función principal del programa
int main() {
    const int TOTAL_NUMEROS = 999; // Cantidad de números a generar

    // 1. Generar números aleatorios
    vector<double> listaNumeros = generarNumeros(TOTAL_NUMEROS);

    // 2. Ordenar los números (requisito para búsqueda binaria)
    sort(listaNumeros.begin(), listaNumeros.end());

    // 3. Mostrar muestra de los números (opcional, para verificación)
    imprimirNumeros(listaNumeros);

    // 4. Obtener número a buscar del usuario con validación robusta
    double x = obtenerNumeroValidado();
    
    // 5. Realizar búsqueda binaria
    int posicion = busquedaBinaria(listaNumeros, x);

    // 6. Presentación de resultados
    if (posicion != -1) {
        cout << "El número " << x << " existe en la posición " << posicion << endl;
    } else {
        cout << "El número " << x << " no existe en la lista." << endl;
    }
    return 0; // Finalización exitosa del programa
}