# Get_Next_Line

## Objetivo

El objetivo de este proyecto es crear una función en C que lea líneas una por una de un File Descriptor. Esta función debe ser capaz de manejar archivos de texto de manera eficiente, devolviendo cada línea de forma individual. El objetivo de este proyecto es la introducción a las variables estáticas y el manejo de la memoria con malloc en C.

## Descripción del Proyecto

En este proyecto, deberás implementar la función `get_next_line`, que toma un descriptor de archivo como entrada y devuelve una línea del archivo cada vez que se llama. La función debe gestionar correctamente la memoria para evitar fugas y errores de lectura.

## Requisitos

- Debes asegurarte de que la función maneje correctamente la memoria, liberándola después de cada uso.
- El programa no debe depender de funciones de la biblioteca estándar como `getline`.
