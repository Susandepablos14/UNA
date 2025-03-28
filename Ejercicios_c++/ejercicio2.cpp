//Ejercicio 2 Listas
#include <iostream>
using namespace std;

int main() {
    int lista1[100], lista2[100], listaIntercalada[200], listaResta[100];
    int n1, n2;

    // Ingresar la primera lista
    cout << "Cuantos elementos tiene la lista 1? ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> lista1[i];
    }

    // Ingresar la segunda lista
    cout << "Cuantos elementos tiene la lista 2? ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> lista2[i];
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