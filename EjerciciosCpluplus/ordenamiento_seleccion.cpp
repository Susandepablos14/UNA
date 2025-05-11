#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class OrdenadorSeleccion {
private:
    int* lista;
    int cantidad;

    // Función recursiva para encontrar el índice del mínimo
    int encontrarMinimo(int indiceActual, int indiceMinimo) {
        if (indiceActual >= cantidad) {
            return indiceMinimo;
        }
        
        if (lista[indiceActual] < lista[indiceMinimo]) {
            return encontrarMinimo(indiceActual + 1, indiceActual);
        } else {
            return encontrarMinimo(indiceActual + 1, indiceMinimo);
        }
    }

    // Función recursiva para el ordenamiento por selección
    void ordenarRecursivo(int indiceInicio) {
        if (indiceInicio >= cantidad - 1) {
            return;
        }

        int indiceMinimo = encontrarMinimo(indiceInicio + 1, indiceInicio);

        if (indiceMinimo != indiceInicio) {
            int temp = lista[indiceMinimo];
            lista[indiceMinimo] = lista[indiceInicio];
            lista[indiceInicio] = temp;
        }

        ordenarRecursivo(indiceInicio + 1);
    }

public:
    OrdenadorSeleccion(int cant) : cantidad(cant) {
        lista = new int[cantidad];
    }
    
    ~OrdenadorSeleccion() {
        delete[] lista;
    }
    
    void generarNumerosAleatorios() {
        srand(time(0));
        for (int i = 0; i < cantidad; ++i) {
            lista[i] = rand() % 1000;
        }
    }
    
    // Interfaz para iniciar el ordenamiento recursivo
    void ordenarPorSeleccion() {
        ordenarRecursivo(0);
    }
    
    void imprimirLista() const {
        cout << "[";
        for (int i = 0; i < cantidad; ++i) {
            cout << lista[i];
            if (i < cantidad - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    
    static int obtenerEnteroValidado() {
        int valor;
        while (true) {
            cout << "Ingrese la cantidad de numeros a ordenar: ";
            if (cin >> valor) {
                cin.ignore(10000, '\n');
                return valor;
            } else {
                cout << "Error: Debe ingresar un numero entero valido.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }
};

int main() {
    int cantidad;
    do {
        cantidad = OrdenadorSeleccion::obtenerEnteroValidado();
        if (cantidad <= 0) {
            cout << "Error: La cantidad debe ser mayor que 0.\n";
        }
    } while (cantidad <= 0);
    
    OrdenadorSeleccion ordenador(cantidad);
    ordenador.generarNumerosAleatorios();
    
    cout << "\nLista original: ";
    ordenador.imprimirLista();
    
    ordenador.ordenarPorSeleccion();
    
    cout << "Lista ordenada: ";
    ordenador.imprimirLista();
    
    return 0;
}