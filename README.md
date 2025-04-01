# Documentación de los Programas en C++
### Este repositorio contiene cuatro programas en C++ que realizan diferentes operaciones. A continuación se describe el propósito y funcionamiento de cada uno.

## 1. Cuadrado Mágico
#### Archivo: ejercicio1.cpp

### Descripción:
Este programa genera un cuadrado mágico de dimensiones impares (hasta 9x9). Un cuadrado mágico es una matriz donde la suma de los números en cada fila, columna y diagonal principal es la misma.

### Funcionamiento:
1. Solicita al usuario una dimensión impar entre 1 y 9.

2. Valida que la entrada sea correcta.

3.  Construye el cuadrado mágico usando el algoritmo de Siamese:
    
    -   Comienza en la fila 0, columna central.
    -   Coloca números secuenciales moviéndose en diagonal arriba-izquierda.
    -   Si la posición está ocupada, se mueve hacia abajo.

4. Imprime el cuadrado mágico resultante.

### Uso:
Ejecutar el programa y seguir las instrucciones para ingresar la dimensión deseada.

## 2. Operaciones con Listas
#### Archivo: ejercicio2.cpp

### Descripción:
Este programa realiza operaciones con dos listas de números enteros:

1. Intercala los elementos de ambas listas.

2. Resta elemento a elemento (lista1 - lista2).

### Funcionamiento:
1. Solicita al usuario el tamaño y elementos de dos listas (validando cada entrada).

2. Muestra las listas originales.

3. Genera y muestra:

    -   Una lista intercalada con elementos de ambas listas.

    -   Una lista con la resta elemento a elemento (si las listas son de diferente tamaño, completa con ceros).

### Validaciones:
- Verifica que las entradas sean numéricas.

- Limita el tamaño máximo de las listas a 100 elementos.

- Rechaza valores negativos.

### Uso:
Ejecutar el programa y seguir las instrucciones para ingresar los elementos de las listas.

## 3. Manejo de Colas
#### Archivo: ejercicio3.cpp

### Descripción:
Este programa implementa una cola de caracteres con las siguientes operaciones:

1. Insertar caracteres.

2. Mostrar todos los elementos de la cola.

3. Salir del programa.

### Funcionamiento:
- Usa la estructura queue de la STL de C++.

- Muestra un menú interactivo.

- Valida que solo se ingresen caracteres individuales.

### Características:
- No modifica la cola original al mostrar los elementos (usa una copia temporal).

- Maneja adecuadamente colas vacías.

### Uso:
Ejecutar el programa y seleccionar las opciones del menú.

## 4. Árbol Binario de Búsqueda
#### Archivo: ejercicio4.cpp

### Descripción:
Este programa determina el grado de un nodo en un árbol binario de búsqueda predefinido. El grado de un nodo es el número de hijos que tiene (0, 1 o 2).

### Estructura del Árbol:
~~~c++
        18
       /  \
     11    23
    / \   / \
   7 15 20 25
     /
    13
~~~
### Funcionamiento:
1. Construye el árbol binario de búsqueda con valores predefinidos.

2. Solicita al usuario un valor para buscar.

3. Implementa una función recursiva Grado() que:

    -   Busca el nodo.

    -   Cuenta sus hijos (grado).

4. Muestra el resultado o un mensaje si el nodo no existe.

### Uso:
Ejecutar el programa e ingresar el valor del nodo cuyo grado se desea conocer.

## Requisitos
- Compilador de C++ (g++, clang, etc.)

- Standard Library de C++
