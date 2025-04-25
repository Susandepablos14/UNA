#include <iostream>   // Para operaciones de entrada/salida
#include <cstdlib>    // Para funciones rand() y srand()
#include <ctime>      // Para función time()
#include <limits>     // Para numeric_limits
#include <sstream>    // Para stringstream

using namespace std;

class OrdenadorSeleccion {
private:
    int* lista;       // Puntero al arreglo de números
    int cantidad;     // Cantidad de elementos en el arreglo

public:
    // Constructor que recibe la cantidad de elementos
    OrdenadorSeleccion(int cant);
    
    // Destructor para liberar memoria
    ~OrdenadorSeleccion();
    
    // Llena el arreglo con números aleatorios
    void generarNumerosAleatorios();
    
    // Ordena el arreglo usando el método de selección
    void ordenarPorSeleccion();
    
    // Muestra el contenido del arreglo
    void imprimirLista() const;
    
    // Método estático para validar entrada de usuario
    static int obtenerEnteroValidado(const string& mensaje);
};

// Implementación del constructor
OrdenadorSeleccion::OrdenadorSeleccion(int cant) : cantidad(cant) {
    lista = new int[cantidad];  // Asignar memoria para el arreglo
}

// Implementación del destructor
OrdenadorSeleccion::~OrdenadorSeleccion() {
    delete[] lista;  // Liberar memoria del arreglo
}

// Implementación para generar números aleatorios
void OrdenadorSeleccion::generarNumerosAleatorios() {
    srand(time(0));  // Inicializar semilla aleatoria
    
    // Llenar el arreglo con valores aleatorios entre 0 y 999
    for (int i = 0; i < cantidad; ++i) {
        lista[i] = rand() % 1000;
    }
}

// Implementación del algoritmo de ordenación por selección
void OrdenadorSeleccion::ordenarPorSeleccion() {
    // Recorrer todo el arreglo
    for (int i = 0; i < cantidad - 1; i++) {
        int min_idx = i;  // Suponer que el primer elemento es el mínimo
        
        // Buscar el mínimo en el subarreglo no ordenado
        for (int j = i + 1; j < cantidad; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;  // Actualizar índice del mínimo encontrado
            }
        }
        
        // Intercambiar el mínimo encontrado con el primer elemento no ordenado
        int temp = lista[min_idx];
        lista[min_idx] = lista[i];
        lista[i] = temp;
    }
}

// Implementación para mostrar el arreglo
void OrdenadorSeleccion::imprimirLista() const {
    cout << "[";
    for (int i = 0; i < cantidad; ++i) {
        cout << lista[i];
        if (i < cantidad - 1) {
            cout << ", ";  // Separador entre elementos
        }
    }
    cout << "]" << endl;  // Cierre del arreglo
}

// Implementación del método estático para validar entrada
int OrdenadorSeleccion::obtenerEnteroValidado(const string& mensaje) {
    string entrada;
    int valor;
    
    while (true) {
        cout << mensaje;
        getline(cin, entrada);  // Leer toda la línea
        
        stringstream ss(entrada);  // Convertir string a stream
        
        // Verificar si la conversión a entero es válida y no hay sobrantes
        if (!(ss >> valor) || !ss.eof()) {
            cout << "Error: Debe ingresar un numero entero valido.\n";
            continue;
        }
        
        return valor;
    }
}

int main() {
    // Solicitar cantidad de números al usuario con validación
    int cantidad = OrdenadorSeleccion::obtenerEnteroValidado(
        "Ingrese la cantidad de numeros a ordenar: ");
    
    // Validar que la cantidad sea positiva
    while (cantidad <= 0) {
        cout << "Error: La cantidad debe ser mayor que 0.\n";
        cantidad = OrdenadorSeleccion::obtenerEnteroValidado(
            "Ingrese la cantidad de numeros a ordenar: ");
    }
    
    // Crear instancia del ordenador con el tamaño especificado
    OrdenadorSeleccion* ordenador = new OrdenadorSeleccion(cantidad);
    
    // Generar números aleatorios en el arreglo
    ordenador->generarNumerosAleatorios();
    
    // Mostrar lista original
    cout << "\nLista original: ";
    ordenador->imprimirLista();
    
    // Ordenar la lista
    ordenador->ordenarPorSeleccion();
    
    // Mostrar lista ordenada
    cout << "Lista ordenada: ";
    ordenador->imprimirLista();
    
    // Liberar memoria del ordenador
    delete ordenador;
    
    return 0;
}