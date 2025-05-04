//Ejercicio 4 Nodos
#include <iostream>

using namespace std;

// Clase principal que representa un árbol binario de búsqueda
class ArbolBinario {
    private:
        // Estructura interna para los nodos del árbol
        struct Nodo {
            int valor;
            Nodo* izquierdo;
            Nodo* derecho;
            Nodo(int v) : valor(v), izquierdo(0), derecho(0) {}
        };
        
        Nodo* raiz;
        
        // Inserta un nuevo valor en el árbol manteniendo la propiedad BST
        Nodo* insertar(Nodo* nodo, int valor) {
            if (nodo == 0) return new Nodo(valor);
            if (valor < nodo->valor) nodo->izquierdo = insertar(nodo->izquierdo, valor);
            else if (valor > nodo->valor) nodo->derecho = insertar(nodo->derecho, valor);
            return nodo;
        }
        
        // Busca un nodo y retorna su grado (número de hijos)
        int buscarGrado(Nodo* nodo, int valor) {
            if (nodo == 0) return -1;
            if (nodo->valor == valor) {
                int grado = 0;
                if (nodo->izquierdo != 0) grado++;
                if (nodo->derecho != 0) grado++;
                return grado;
            }
            return valor < nodo->valor ? buscarGrado(nodo->izquierdo, valor) : buscarGrado(nodo->derecho, valor);
        }
        
        // Libera toda la memoria utilizada por el árbol
        void liberarArbol(Nodo* nodo) {
            if (nodo != 0) {
                liberarArbol(nodo->izquierdo);
                liberarArbol(nodo->derecho);
                delete nodo;
            }
        }
        
    public:
        // Constructor inicializa el árbol vacío
        ArbolBinario() : raiz(0) {}
        
        // Destructor se encarga de liberar la memoria
        ~ArbolBinario() { liberarArbol(raiz); }
        
        // Método público para insertar valores
        void insertar(int valor) { raiz = insertar(raiz, valor); }
        
        // Método público para obtener el grado de un nodo
        int gradoNodo(int valor) { return buscarGrado(raiz, valor); }
};

// Función para obtener un número válido del usuario
int obtenerNumero() {
    int valor;
    while (true) {
        cout << "\nIngrese el valor del nodo que desea buscar (0 para salir): ";
        cin >> valor;
        if (cin.fail()) {
            cout << "Error: Debe ingresar un valor numerico.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cin.ignore(10000, '\n');
            return valor;
        }
    }
}
    
// Función principal del programa
int main() {
    // Crear instancia del árbol
    ArbolBinario arbol;
    
    // Construir el árbol con los valores dados
    arbol.insertar(18);
    arbol.insertar(11);
    arbol.insertar(7);
    arbol.insertar(15);
    arbol.insertar(13);
    arbol.insertar(23);
    arbol.insertar(20);
    arbol.insertar(25);
    
    int opcion;
    do {
        opcion = obtenerNumero();
        
        if(opcion != 0) {
            // Mostrar resultado de la búsqueda
            int grado = arbol.gradoNodo(opcion);
            if (grado != -1) cout << "El grado del nodo es: " << grado << endl;
            else cout << "Nodo no encontrado." << endl;
        }
    } while(opcion != 0);
    
    cout << "Programa finalizado." << endl;
    return 0;
}