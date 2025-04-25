#include <iostream>      // Para operaciones de entrada/salida estándar
#include <cstdlib>       // Para rand() y srand() (generación de números aleatorios)
#include <ctime>         // Para time() (obtención de semilla aleatoria)
#include <limits>        // Para numeric_limits (manejo de límites de buffers)
#include <sstream>       // Para stringstream (manejo de conversión de strings)
#include <cmath>         // Para funciones matemáticas (round, fabs)
#include <iomanip>       // Para setprecision (control de decimales en salida)

using namespace std;

const int TOTAL_NUMEROS = 999; // Tamaño fijo del arreglo

// Función que genera un vector de números reales aleatorios con exactamente 2 decimales
void generarNumeros(double arreglo[], int cantidad) {
    srand(time(0));
    for (int i = 0; i < cantidad; ++i) {
        arreglo[i] = round((double)rand() / RAND_MAX * 2000.0 * 100) / 100.0;
    }
}


// Función para intercambiar dos valores double
void intercambiar(double &a, double &b) {
    double tmp = b;
    b = a;
    a = tmp;
}

// Función para ordenar el vector usando Bubble Sort
void ordenarArreglo(double arreglo[], int tamano) {
    for (int i = 0; i < tamano - 1; i++) {
        for (int j = 0; j < tamano - 1 - i; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                intercambiar(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}


// Función que imprime los primeros 100 números del vector
void imprimirNumeros(const double arreglo[], int tamano) {
    int mostrar = min(100, tamano);
    cout << "Primeros " << mostrar << " numeros (ordenados):" << endl;
    
    for (int i = 0; i < mostrar; ++i) {
        cout << fixed << setprecision(2) << arreglo[i] << ", ";
    }
    cout << "\n...\n" << endl;
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
int busquedaBinaria(const double arr[], int tamano, double x) {
    int izquierda = 0;
    int derecha = tamano - 1;  // Ahora recibimos el tamaño como parámetro

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
    double listaNumeros[TOTAL_NUMEROS]; 

    // 1. Generar números aleatorios
    generarNumeros(listaNumeros, TOTAL_NUMEROS);

    // 2. Ordenar los números con Bubble Sort
    ordenarArreglo(listaNumeros, TOTAL_NUMEROS);

    // 3. Mostrar muestra de los números (opcional, para verificación)
    imprimirNumeros(listaNumeros, TOTAL_NUMEROS);

    // 4. Obtener número a buscar del usuario con validación robusta
    double x = obtenerNumeroValidado();
    
    // 5. Realizar búsqueda binaria
    int posicion = busquedaBinaria(listaNumeros, TOTAL_NUMEROS, x);

    // 6. Presentación de resultados
    if (posicion != -1) {
        cout << "El número " << x << " existe en la posición " << posicion << endl;
    } else {
        cout << "El número " << x << " no existe en la lista." << endl;
    }
    return 0; // Finalización exitosa del programa
}