//Ejercicio 4 Nodos
#include <iostream>

// Definición de la estructura del nodo
struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Función para insertar un nodo en el árbol binario de búsqueda
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return new Nodo(valor);
    }
    if (valor < raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->valor) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    return raiz;
}

// Función recursiva para buscar un nodo y determinar su grado
int Grado(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        std::cout << "Nodo no encontrado." << std::endl;
        return -1;
    }
    if (raiz->valor == valor) {
        int grado = 0;
        if (raiz->izquierdo != nullptr) grado++;
        if (raiz->derecho != nullptr) grado++;
        return grado;
    }
    if (valor < raiz->valor) {
        return Grado(raiz->izquierdo, valor);
    } else {
        return Grado(raiz->derecho, valor);
    }
}

int main() {
    // Construcción del árbol binario de búsqueda según la descripción
    Nodo* raiz = nullptr;
    raiz = insertar(raiz, 18);
    insertar(raiz, 11);
    insertar(raiz, 7);
    insertar(raiz, 15);
    insertar(raiz, 13);
    insertar(raiz, 23);
    insertar(raiz, 20);
    insertar(raiz, 25);

    // Solicitar al usuario el valor del nodo que desea buscar
    int valorBuscado;
    std::cout << "Ingrese el valor del nodo que desea buscar: ";
    std::cin >> valorBuscado;

    // Llamar a la función Grado para buscar el nodo y determinar su grado
    int grado = Grado(raiz, valorBuscado);
    if (grado != -1) {
        std::cout << "El grado del nodo con valor " << valorBuscado << " es: " << grado << std::endl;
    }

    return 0;
}