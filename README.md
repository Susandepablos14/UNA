# Documentación de los Programas en C++
### Este repositorio contiene siete programas en C++ que realizan diferentes operaciones. A continuación se describe el propósito y funcionamiento de cada uno.

## 1. Cuadrado Mágico
#### Archivo: EjerciciosCplusplus/cuadrado_magico.cpp

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
#### Archivo: EjerciciosCplusplus/listas_enlazadas.cpp

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
#### Archivo: EjerciciosCplusplus/cola_caracteres.cpp

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
#### Archivo: EjerciciosCplusplus/arbol_grado_nodo.cpp

### Descripción:
Este programa determina el grado de un nodo en un árbol binario de búsqueda predefinido. El grado de un nodo es el número de hijos que tiene (0, 1 o 2).

### Estructura del Árbol:
~~~c++
        18
       /  \
     11    23
    / \   / \
   7  15 20  25
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

## 5. Optimización de Rutas para Hosting
#### Archivo: EjerciciosCplusplus/floyd_warshall_red_hosting.cpp

### Descripción:
Este programa implementa el algoritmo Floyd-Warshall para calcular las distancias mínimas y número de saltos entre nodos en una red de hosting, mostrando además el promedio de enlaces desde el nodo central.


### Funcionamiento:
1. Inicialización del Grafo:

    -   Crea una matriz de adyacencia con los costos entre nodos (S, 1, 2, 3)

    -   Inicializa la matriz de saltos con 1 para conexiones directas e INF para no conexiones

2. Algoritmo Floyd-Warshall:

    -   Compara todas las posibles rutas entre cada par de nodos

    -   Actualiza las matrices de distancias y saltos cuando encuentra caminos más cortos

    -   Considera tanto la distancia total como el número de saltos

    -   Completa el procesamiento en O(n³) operaciones

3. Cálculo de Métricas:

    -   Calcula el número medio de enlaces desde el nodo central S

    -   Considera solo nodos alcanzables en el cálculo del promedio

4. Visualización de Resultados:

    -   Muestra la matriz de costos original con formato tabular

    -   Presenta las matrices resultantes de distancias mínimas y saltos

    -   Incluye el promedio de saltos desde el nodo S con 2 decimales de precisión

## 6. Ordenación por Selección de Lista de Números Enteros
#### Archivo: EjerciciosCplusplus/ordenamiento_seleccion.cpp

### Descripción:
Este programa implementa el algoritmo de ordenación por selección para ordenar una lista de números enteros ingresados por el usuario en orden ascendente, incluyendo validaciones robustas para las entradas.

### Funcionamiento:
1. Entrada de Datos:

    -   Solicita al usuario la cantidad de números a ordenar.

    -   Valida que la cantidad sea un entero positivo.

    -   Pide cada número individualmente validando que sean enteros válidos.

2. Algoritmo de Ordenación por Selección:

    -   Recorre la lista para encontrar el elemento más pequeño.

    -   Intercambia este elemento con la primera posición no ordenada.

    -   Repite el proceso para el resto de la lista no ordenada.

    -   Completa la ordenación en O(n²) comparaciones

3. Salida de Resultados:

    -   Muestra el vector original ingresado por el usuario.

    -   Presenta el vector ordenado ascendentemente.

    -   El formato de salida es claro con corchetes y comas separando los valores.

### Validaciones:
- Validación de Entrada: Rechaza entradas no numéricas (ej: "abc" → "Error: Debe ingresar un numero entero valido").

- Validación de Cantidad: Asegura que la cantidad de números sea mayor que cero (Mensaje claro: "Error: La cantidad debe ser mayor que 0.").

## 7. Búsqueda Binaria en Lista de Números Reales
#### Archivo: EjerciciosCplusplus/busqueda_binaria.cpp

### Descripción:
Este programa genera una lista de 999 números reales aleatorios en el rango [0.00, 2000.00] y permite buscar valores mediante el algoritmo de búsqueda binaria.

### Funcionamiento:
1. Generación de Datos:

    -   Crea una lista de 999 números con exactamente 2 decimales.

    -   Ordena la lista ascendentemente (requisito para la búsqueda binaria).

    -   Muestra los primeros 100 números para verificación.

2. Búsqueda Binaria:

    -   Solicita un número al usuario (ej: 150.75).

    -   Valida que:

        -   Sea un valor numérico.

        -   Tenga exactamente 2 decimales.

        -   Esté en el rango [0.00, 2000.00].

    -   Busca el número en la lista ordenada, dividiendo repetidamente el espacio de búsqueda a la mitad.

3. Resultados:

    -   Si encuentra el número: muestra su posición en la lista ordenada.

    -   Si no existe: informa que no está presente.

### Validaciones:
- Entradas no numéricas: Rechaza letras o símbolos (ej: abc → "Error: Debe ingresar un valor numérico válido").

- Decimales incorrectos: Asegura exactamente 2 decimales (ej: 123.456 → "Error: Debe tener 2 decimales").

- Rango: Bloquea números negativos o mayores a 2000.00.

## Requisitos
- Compilador de C++ (g++, clang, etc.)

- Standard Library de C++
