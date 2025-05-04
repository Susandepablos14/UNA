//Ejercicio 2 Listas Enlazadas
#include <iostream>
using namespace std;

// Clase que representa un nodo de la lista enlazada
class Nodo {
public:
    int dato;         // Valor almacenado en el nodo
    Nodo* siguiente;  // Puntero al siguiente nodo en la lista

    // Constructor que inicializa el nodo con un valor
    Nodo(int valor) : dato(valor), siguiente(NULL) {}
};

// Clase que implementa una lista enlazada simple
class ListaEnlazada {
private:
    Nodo* cabeza;     // Puntero al primer nodo de la lista

    // Función auxiliar para mostrar los elementos
    void mostrar(Nodo* actual, bool primero) {
        if (actual == NULL) {
            cout << endl;
            return;
        }
        if (!primero) {
            cout << ", ";
        }
        cout << actual->dato;
        mostrar(actual->siguiente, false);
    }

    // Función auxiliar para liberar la memoria
    void liberar(Nodo* actual) {
        if (actual == NULL) return;
        Nodo* siguiente = actual->siguiente;
        delete actual;
        liberar(siguiente);
    }

    // Función auxiliar para insertar al final
    void agregar(Nodo* actual, Nodo* nuevo) {
        if (actual->siguiente == NULL) {
            actual->siguiente = nuevo;
            return;
        }
        agregar(actual->siguiente, nuevo);
    }

public:
    // Constructor que inicializa una lista vacía
    ListaEnlazada() : cabeza(NULL) {}

    // Destructor que libera toda la memoria
    ~ListaEnlazada() {
        liberar(cabeza);
    }

    // Método que verifica si la lista está vacía
    bool estaVacia() {
        return cabeza == NULL;
    }

    // Inserta un nuevo elemento al final de la lista
    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            cabeza = nuevo;
        } else {
            agregar(cabeza, nuevo);
        }
    }

    // Muestra todos los elementos de la lista
    void imprimir() {
        mostrar(cabeza, true);
    }

    // Método estático que intercala dos listas
    static void mezclar(Nodo* actual1, Nodo* actual2, ListaEnlazada& resultado) {
        if (actual1 == NULL && actual2 == NULL) return;
        
        // Primero insertamos de la lista1 si existe
        if (actual1 != NULL) {
            resultado.insertar(actual1->dato);
            // Luego de la lista2 si existe
            if (actual2 != NULL) {
                resultado.insertar(actual2->dato);
                // Avanzamos en ambas listas
                mezclar(actual1->siguiente, actual2->siguiente, resultado);
            } else {
                // Si solo queda lista1, avanzamos solo en ella
                mezclar(actual1->siguiente, actual2, resultado);
            }
        } else {
            // Si solo queda lista2, insertamos y avanzamos
            resultado.insertar(actual2->dato);
            mezclar(actual1, actual2->siguiente, resultado);
        }
    }

    // Método público para intercalar listas
    static ListaEnlazada intercalar(ListaEnlazada& lista1, ListaEnlazada& lista2) {
        ListaEnlazada resultado;
        mezclar(lista1.cabeza, lista2.cabeza, resultado);
        return resultado;
    }

    // Método estático que resta dos listas
    static void diferencia(Nodo* actual1, Nodo* actual2, ListaEnlazada& resultado) {
        if (actual1 == NULL && actual2 == NULL) return;
        
        if (actual1 != NULL && actual2 != NULL) {
            resultado.insertar(actual1->dato - actual2->dato);
            diferencia(actual1->siguiente, actual2->siguiente, resultado);
        }
        else if (actual1 != NULL) {
            resultado.insertar(actual1->dato);
            diferencia(actual1->siguiente, actual2, resultado);
        }
        else {
            resultado.insertar(-actual2->dato);
            diferencia(actual1, actual2->siguiente, resultado);
        }
    }

    // Método público para restar listas
    static ListaEnlazada restar(ListaEnlazada& lista1, ListaEnlazada& lista2) {
        ListaEnlazada resultado;
        diferencia(lista1.cabeza, lista2.cabeza, resultado);
        return resultado;
    }
};

// Función para obtener un número válido del usuario
int obtenerNumero(const string& mensaje, bool debeSerPositivo = false) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cout << "Error: Debe ingresar un valor numerico.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (debeSerPositivo && valor < 0) {
            cout << "Error: El numero debe ser positivo.\n";
            cin.ignore(10000, '\n');
        } else {
            cin.ignore(10000, '\n');
            return valor;
        }
    }
}

// Función principal del programa
int main() {
    ListaEnlazada lista1, lista2;
    int cantidad;

    // Ingreso de datos para la lista 1
    cout << "INGRESO DE DATOS PARA LA LISTA 1\n";
    cantidad = obtenerNumero("¿Cuantos elementos tendra la lista 1? ", true);
    for (int i = 0; i < cantidad; i++) {
        lista1.insertar(obtenerNumero("Ingrese el elemento " + to_string(i+1) + ": "));
    }

    // Ingreso de datos para la lista 2
    cout << "\nINGRESO DE DATOS PARA LA LISTA 2\n";
    cantidad = obtenerNumero("¿Cuantos elementos tendra la lista 2? ", true);
    for (int i = 0; i < cantidad; i++) {
        lista2.insertar(obtenerNumero("Ingrese el elemento " + to_string(i+1) + ": "));
    }

    // Mostrar las listas originales
    cout << "\nLISTA 1: ";
    lista1.imprimir();
    cout << "LISTA 2: ";
    lista2.imprimir();

    // Operaciones con las listas
    ListaEnlazada lista3 = ListaEnlazada::intercalar(lista1, lista2);
    cout << "\nLISTA INTERCALADA: ";
    lista3.imprimir();

    ListaEnlazada lista4 = ListaEnlazada::restar(lista1, lista2);
    cout << "\nRESTA DE LISTAS: ";
    lista4.imprimir();

    return 0;
}