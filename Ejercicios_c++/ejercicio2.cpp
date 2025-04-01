//Ejercicio 2 Listas
#include <iostream>
#include <limits>  // Necesario para numeric_limits y manejo de buffers
using namespace std;

int main() {
    int lista1[100], lista2[100], listaIntercalada[200], listaResta[100];
    int n1, n2;

    // Ingresar la primera lista
    while (true) {  // Bucle infinito hasta obtener entrada válida
        cout << "Cuantos elementos tiene la lista 1? ";
        
        // Validación 1: Verificar si la entrada es numérica
        if (!(cin >> n1)) {
            cout << "Error: Debe ingresar un valor numerico.\n";
            cin.clear();  // Limpiar flags de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpiar buffer
            continue;  // Volver a solicitar el dato
        }
        
        // Validación 2: Verificar que no exceda el límite de 100
        if (n1 > 100) {
            cout << "Error: El valor debe ser <= 100.\n";
            continue;
        }
        
        // Validación 3: Verificar que no sea negativo
        if (n1 < 0) {
            cout << "Error: El valor no puede ser negativo.\n";
            continue;
        }
        
        break;  // Si pasa todas las validaciones, salir del bucle
    }

    // Ingreso de valores para lista1
    for (int i = 0; i < n1; i++) {
        while (true) {  // Bucle para cada valor hasta que sea válido
            cout << "Ingrese el valor " << i + 1 << ": ";
            // Validación 1: Entrada numérica
            if (!(cin >> lista1[i])) {
                cout << "Error: Debe ingresar un valor numerico.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }     
            break;  // Valor aceptado
        }
    }

    // Ingresar la segunda lista (con validación idéntica a lista1)
    while (true) {
        cout << "Cuantos elementos tiene la lista 2? ";
        if (!(cin >> n2)) {
            cout << "Error: Debe ingresar un valor numerico.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (n2 > 100) {
            cout << "Error: El valor debe ser <= 100.\n";
            continue;
        }
        if (n2 < 0) {
            cout << "Error: El valor no puede ser negativo.\n";
            continue;
        }
        break;
    }

    for (int i = 0; i < n2; i++) {
        while (true) {
            cout << "Ingrese el valor " << i + 1 << ": ";
            if (!(cin >> lista2[i])) {
                cout << "Error: Debe ingresar un valor numerico.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
    }

    // Mostrar las listas originales
    cout << "Lista 1: ";
    for (int i = 0; i < n1; i++) {
        cout << lista1[i] << " ";
    }
    cout << endl;

    cout << "Lista 2: ";
    for (int i = 0; i < n2; i++) {
        cout << lista2[i] << " ";
    }
    cout << endl;

    // Intercalar las listas
    int k = 0;
    for (int i = 0; i < max(n1, n2); i++) {
        if (i < n1) {
            listaIntercalada[k++] = lista1[i];
        }
        if (i < n2) {
            listaIntercalada[k++] = lista2[i];
        }
    }

    cout << "Lista intercalada: ";
    for (int i = 0; i < k; i++) {
        cout << listaIntercalada[i] << " ";
    }
    cout << endl;

    // Calcular la resta de las listas
    for (int i = 0; i < max(n1, n2); i++) {
        int valor1 = (i < n1) ? lista1[i] : 0;
        int valor2 = (i < n2) ? lista2[i] : 0;
        listaResta[i] = valor1 - valor2;
    }

    cout << "Lista resta: ";
    for (int i = 0; i < max(n1, n2); i++) {
        cout << listaResta[i] << " ";
    }
    cout << endl;

    return 0;
}