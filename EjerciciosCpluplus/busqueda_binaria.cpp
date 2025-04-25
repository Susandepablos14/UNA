#include <iostream>      // Para operaciones de entrada/salida estándar
#include <cstdlib>       // Para rand() y srand() (generación de números aleatorios)
#include <ctime>         // Para time() (obtención de semilla aleatoria)
#include <sstream>       // Para stringstream (manejo de conversión de strings)
#include <cmath>         // Para funciones matemáticas (round, fabs)
#include <iomanip>       // Para setprecision (control de decimales en salida)

using namespace std;

class BuscadorBinario {
private:
    double* arreglo;     // Arreglo dinámico para almacenar números
    int capacidad;       // Tamaño máximo del arreglo
    int cantidad;        // Cantidad actual de elementos

    // Intercambia dos valores en el arreglo
    void intercambiar(double &a, double &b) {
        double temp = a;
        a = b;
        b = temp;
    }

public:
    // Constructor que inicializa el arreglo
    BuscadorBinario(int cap) : capacidad(cap), cantidad(0) {
        arreglo = new double[capacidad];
    }

    // Destructor que libera la memoria
    ~BuscadorBinario() {
        delete[] arreglo;
    }

    // Genera números aleatorios con 2 decimales
    void generarNumeros(int cant) {
        if (cant > capacidad) return;
        
        srand(time(0));
        cantidad = cant;
        for (int i = 0; i < cantidad; i++) {
            arreglo[i] = round((rand() / (double)RAND_MAX * 2000) * 100) / 100;
        }
    }

    // Ordena el arreglo usando Bubble Sort
    void ordenar() {
        for (int i = 0; i < cantidad-1; i++) {
            for (int j = 0; j < cantidad-i-1; j++) {
                if (arreglo[j] > arreglo[j+1]) {
                    intercambiar(arreglo[j], arreglo[j+1]);
                }
            }
        }
    }

    // Muestra los primeros 100 números
    void imprimirMuestra() {
        int mostrar = min(100, cantidad);
        cout << "Primeros " << mostrar << " números (ordenados):\n";
        for (int i = 0; i < mostrar; i++) {
            cout << fixed << setprecision(2) << arreglo[i] << " ";
            if ((i+1) % 10 == 0) cout << endl;
        }
        cout << endl;
    }

    // Implementación de búsqueda binaria
    int busquedaBinaria(double valor) {
        int izquierda = 0;
        int derecha = cantidad - 1;
        
        while (izquierda <= derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;
            
            if (arreglo[medio] == valor) return medio;
            if (arreglo[medio] < valor) izquierda = medio + 1;
            else derecha = medio - 1;
        }
        return -1;
    }

    // Valida la entrada del usuario
    static double obtenerNumeroValidado() {
        string entrada;
        double x;
        
        while (true) {
            cout << "Ingrese el numero a buscar (0.00-2000.00): ";
            getline(cin, entrada);
            
            stringstream ss(entrada);
            if (!(ss >> x) || !ss.eof()) {
                cout << "Error: Debe ingresar un valor numerico valido (ej. 123.45).\n";
                continue;
            }
            
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
};

int main() {
    const int TOTAL = 999;
    BuscadorBinario buscador(TOTAL);
    
    // Generar y ordenar números
    buscador.generarNumeros(TOTAL);
    buscador.ordenar();
    buscador.imprimirMuestra();
    
    // Buscar número
    double num = BuscadorBinario::obtenerNumeroValidado();
    int pos = buscador.busquedaBinaria(num);
    
    // Mostrar resultados
    if (pos != -1) {
        cout << "Número encontrado en posición: " << pos << endl;
    } else {
        cout << "Número no encontrado\n";
    }
    
    return 0;
}