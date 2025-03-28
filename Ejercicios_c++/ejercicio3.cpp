//Ejercicio 3 Colas
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> cola;
    int opcion;
    string entrada;

    do {
        // Mostrar el menú
        cout << "====================================" << endl;
        cout << "1. Insertar un carácter a una cola" << endl;
        cout << "2. Mostrar todos los elementos de la cola" << endl;
        cout << "3. Salir" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un carácter: ";
                cin >> entrada;

                // Validar si la entrada es un solo carácter
                if (entrada.length() == 1) {
                    cola.push(entrada[0]); // Insertar el carácter en la cola
                    cout << "Carácter '" << entrada[0] << "' insertado correctamente." << endl;
                } else {
                    cout << "Error: Debe ingresar un solo carácter. Intente de nuevo." << endl;
                }
                break;

            case 2:
                if (cola.empty()) {
                    cout << "La cola está vacía. No hay elementos para mostrar." << endl;
                } else {
                    cout << "Elementos de la cola: ";
                    queue<char> temp = cola; // Copiar la cola para no modificar la original
                    while (!temp.empty()) {
                        cout << temp.front() << " "; // Mostrar el frente de la cola
                        temp.pop(); // Eliminar el frente de la cola
                    }
                    cout << endl;
                }
                break;

            case 3:
                cout << "Saliendo del programa... ¡Hasta luego!" << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}