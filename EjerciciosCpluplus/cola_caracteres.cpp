//Ejercicio 3 Colas
#include <iostream>
#include <string>
using namespace std;

// Clase nodo representa cada elemento de la cola  
class Nodo {
public:
    char dato;       // Almacena el carácter en este nodo
    Nodo* siguiente; // Puntero al siguiente nodo en la cola
    
    // Constructor: Inicializa el nodo con un carácter y el siguiente en NULL
    Nodo(char c) {
        dato = c;
        siguiente = NULL; // Inicialmente no apunta a ningún otro nodo
    }
};

// Clase cola dinamica Implementación de la cola 

class ColaDinamica {
private:
    Nodo* frente;   // Puntero al primer elemento de la cola
    Nodo* final;    // Puntero al último elemento de la cola
    int tamano;    // Cantidad de elementos en la cola
    
    // Método recursivo privado para mostrar elementos
    // Recibe: Nodo actual que se está procesando
    void mostrarRecursivo(Nodo* actual) {
        // Caso base: si llegamos al final (NULL) terminamos la recursión
        if (actual == NULL) return;
        
        // Mostrar el dato del nodo actual
        cout << actual->dato << " ";
        
        // Llamada recursiva con el siguiente nodo
        mostrarRecursivo(actual->siguiente);
    }
    
public:
    // Constructor: Inicializa una cola vacía
    ColaDinamica() {
        frente = NULL; // No hay elementos al inicio
        final = NULL;  // No hay elementos al inicio
        tamano = 0;   // Tamaño inicial cero
    }
    
    // Destructor: Libera toda la memoria de los nodos al destruir la cola
    ~ColaDinamica() {
        // Desencola todos los elementos hasta que la cola esté vacía
        while (!estaVacia()) {
            desencolar();
        }
    }
    
    // Encolar: Agrega un nuevo elemento al final de la cola
    // Recibe: El carácter a agregar
    void encolar(char c) {
        // Crear un nuevo nodo con el carácter recibido
        Nodo* nuevo = new Nodo(c);
        
        // Si la cola está vacía, el nuevo nodo será el frente y el final
        if (estaVacia()) {
            frente = nuevo;
        } 
        // Si no está vacía, el nodo final actual apunta al nuevo nodo
        else {
            final->siguiente = nuevo;
        }
        
        // El nuevo nodo siempre será el nuevo final
        final = nuevo;
        tamano++; // Aumentamos el tamaño de la cola
    }
    
    // Desencolar: Elimina y retorna el elemento del frente de la cola
    // Retorna: El carácter que estaba al frente
    char desencolar() {
        // Verificar si la cola está vacía
        if (estaVacia()) {
            throw runtime_error("La cola está vacía");
        }
        
        // Guardamos temporalmente el nodo frente y su dato
        Nodo* temp = frente;
        char dato = temp->dato;
        
        // Movemos el frente al siguiente nodo
        frente = frente->siguiente;
        
        // Si al desencolar la cola queda vacía, actualizamos final a NULL
        if (frente == NULL) {
            final = NULL;
        }
        
        // Liberamos la memoria del nodo eliminado
        delete temp;
        tamano--; // Disminuimos el tamaño de la cola
        
        return dato; // Retornamos el dato del nodo eliminado
    }
    
    // Ver frente: Retorna el elemento del frente sin eliminarlo
    // Retorna: El carácter al frente de la cola
    char verFrente() {
        if (estaVacia()) {
            throw runtime_error("La cola está vacía");
        }
        return frente->dato;
    }
    
    // Esta vacia: Verifica si la cola no tiene elementos
    // Retorna: true si está vacía, false si tiene elementos
    bool estaVacia() {
        return frente == NULL;
    }
    
    // Obtener tamaño: Retorna la cantidad de elementos en la cola
    // Retorna: El tamaño actual de la cola
    int obtenerTamano() {
        return tamano;
    }
    
    // Mostrar elementos: Muestra todos los elementos de la cola
    // Usa el método recursivo para mostrar los elementos
    void mostrarElementos() {
        // Si la cola está vacía, mostramos un mensaje
        if (estaVacia()) {
            cout << "La cola está vacía." << endl;
            return;
        }
        
        // Mostramos los elementos usando el método recursivo
        cout << "Elementos de la cola: ";
        mostrarRecursivo(frente);
        cout << endl;
    }
};

// Clase menu cola: Maneja la interfaz de usuario
class MenuCola {
private:
    ColaDinamica cola; // La cola que manejará el menú
    
    // Mostra menu: Muestra las opciones disponibles
    void mostrarMenu() {
        cout << "\n====================================" << endl;
        cout << "1. Insertar un carácter a una cola" << endl;
        cout << "2. Mostrar todos los elementos de la cola" << endl;
        cout << "3. Salir" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opción: ";
    }
    
    // Insertar caracter: Solicita un carácter y lo encola
    void insertarCaracter() {
        string entrada;
        cout << "Ingrese un carácter: ";
        cin >> entrada;

        // Validamos que se haya ingresado exactamente un carácter
        if (entrada.length() == 1) {
            cola.encolar(entrada[0]); // Encolamos el carácter
            cout << "Carácter '" << entrada[0] << "' insertado correctamente." << endl;
        } else {
            cout << "Error: Debe ingresar un solo carácter. Intente de nuevo." << endl;
        }
    }
    
public:
    // Ejercutar: Inicia el ciclo principal del menú
    void ejecutar() {
        int opcion;
        
        do {
            mostrarMenu();  // Mostramos el menú
            cin >> opcion;  // Leemos la opción del usuario
            
            switch (opcion) {
                case 1: // Opción para insertar carácter
                    insertarCaracter();
                    break;
                    
                case 2: // Opción para mostrar la cola
                    cola.mostrarElementos();
                    break;
                    
                case 3: // Opción para salir
                    cout << "Saliendo del programa... ¡Hasta luego!" << endl;
                    break;
                    
                default: // Opción no válida
                    cout << "Opción no válida. Intente de nuevo." << endl;
            }
            
        } while (opcion != 3); // Repetir hasta que elija salir
    }
};

// Función Principal
int main() {
    // Creamos una instancia del menú
    MenuCola menu;
    
    // Ejecutamos el menú
    menu.ejecutar();
    
    return 0;
}