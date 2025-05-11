#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class BuscadorBinario {
private:
    double* arreglo;      // Arreglo dinámico para almacenar los números
    int capacidad;        // Tamaño máximo del arreglo
    int cantidad;         // Cantidad actual de elementos

    // Función recursiva para ordenar usando QuickSort
    void ordenarRecursivo(int inicio, int fin) {
        if (inicio < fin) {
            int posicionPivote = particionar(inicio, fin);
            ordenarRecursivo(inicio, posicionPivote - 1);
            ordenarRecursivo(posicionPivote + 1, fin);
        }
    }

    // Función auxiliar para particionar el arreglo
    int particionar(int inicio, int fin) {
        double pivote = arreglo[fin];
        int i = inicio - 1;
        
        for (int j = inicio; j < fin; j++) {
            if (arreglo[j] <= pivote) {
                i++;
                intercambiar(arreglo[i], arreglo[j]);
            }
        }
        intercambiar(arreglo[i + 1], arreglo[fin]);
        return i + 1;
    }

    // Función recursiva para búsqueda binaria
    int buscarRecursivo(double valor, int izquierda, int derecha) {
        if (izquierda > derecha) return -1;  // Caso base: no encontrado
        
        int medio = izquierda + (derecha - izquierda) / 2;
        
        // Comparación con tolerancia para valores decimales
        if (fabs(arreglo[medio] - valor) < 0.001) return medio;
        
        if (arreglo[medio] < valor) 
            return buscarRecursivo(valor, medio + 1, derecha);
        else 
            return buscarRecursivo(valor, izquierda, medio - 1);
    }

    // Función para intercambiar valores
    void intercambiar(double &a, double &b) {
        double temp = a;
        a = b;
        b = temp;
    }

public:
    // Constructor: reserva memoria para el arreglo
    BuscadorBinario(int cap) : capacidad(cap), cantidad(0) {
        arreglo = new double[capacidad];
    }

    // Destructor: libera la memoria del arreglo
    ~BuscadorBinario() {
        delete[] arreglo;
    }

    // Genera números aleatorios con 2 decimales
    void generarNumeros(int cant) {
        if (cant > capacidad) return;
        
        srand(time(0));
        cantidad = cant;
        for (int i = 0; i < cantidad; i++) {
            // Genera números entre 0.00 y 2000.00 con 2 decimales
            arreglo[i] = round((rand() / (double)RAND_MAX * 2000) * 100) / 100;
        }
    }

    // Ordena el arreglo llamando al método recursivo
    void ordenar() {
        ordenarRecursivo(0, cantidad - 1);
    }

    // Muestra una muestra de los números ordenados
    void mostrarMuestra() {
        int mostrar = min(100, cantidad);
        cout << "\nMuestra de " << mostrar << " números ordenados:\n";
        for (int i = 0; i < mostrar; i++) {
            printf("%7.2f ", arreglo[i]);  // Formato de 7 espacios con 2 decimales
            if ((i+1) % 10 == 0) cout << endl;  // 10 números por línea
        }
        cout << endl;
    }

    // Inicia la búsqueda binaria
    int buscar(double valor) {
        return buscarRecursivo(valor, 0, cantidad - 1);
    }

    // Valida la entrada del usuario
    static double leerNumero() {
        const int TAM_BUFFER = 100;
        char buffer[TAM_BUFFER];
        double valor;
        
        while (true) {
            cout << "\nIngrese número a buscar (0-2000 con 2 decimales) o 0 para salir: ";
            cin.getline(buffer, TAM_BUFFER);
            
            // Verifica si la entrada es un número válido
            char* fin;
            valor = strtod(buffer, &fin);
            
            // Validaciones
            if (*fin != '\0' || fin == buffer) {
                cout << "Error: Debe ingresar un número válido.\n";
                continue;
            }
            
            if (valor == 0.0) return 0.0;  // Salir si ingresa 0
            
            if (valor < 0.0 || valor > 2000.0) {
                cout << "Error: El número debe estar entre 0.00 y 2000.00\n";
            } else if (fabs(valor * 100 - round(valor * 100)) > 0.001) {
                cout << "Error: Debe tener exactamente 2 decimales\n";
            } else {
                return valor;
            }
        }
    }
};

int main() {
    const int TOTAL = 999;
    BuscadorBinario buscador(TOTAL);
    
    // Paso 1: Generar y ordenar números
    cout << "Generando " << TOTAL << " números aleatorios...\n";
    buscador.generarNumeros(TOTAL);
    buscador.ordenar();
    buscador.mostrarMuestra();
    
    // Paso 2: Búsqueda interactiva
    while (true) {
        double num = BuscadorBinario::leerNumero();
        
        if (num == 0.0) {
            cout << "Saliendo del programa...\n";
            break;
        }
        
        int pos = buscador.buscar(num);
        
        if (pos != -1) {
            cout << "¡Número encontrado! Posición: " << pos << endl;
        } else {
            cout << "Número no encontrado. Intente con otro valor.\n";
        }
    }
    
    return 0;
}