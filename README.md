<h1 align="center">
  <img src="https://iili.io/2mYwfzG.png" alt="push swap header krub" width="1200" height="auto" style="align: bottom;"> 
</h1>

## Descripción

Proyecto que tiene como objetivo ordenar una lista de números enteros utilizando un conjunto limitado de operaciones en dos stacks (`a` y `b`).

Se debe implementar un algoritmo de ordenación eficiente teniendo en cuenta su complejidad (*Big O notation*).

🇬🇧 [Read in English](README_EN.md)

## Estructura del Proyecto

### Makefile

- Reglas: `all`, `clean`, `fclean`, `re`.
- No debe relinkear los archivos en ningún caso.

## Archivos de Funciones

- `push_swap.c`: Función principal del programa.
- `check_error_free.c`: Validaciones y liberación de memoria.
- `utils.c`: Funciones auxiliares para manejar listas.
- `utils_extra.c`: Funciones de utilidad general.
- `path_to_sort.c`: Algoritmos para ordenar pequeñas listas.
- `algo.c`: Implementación del algoritmo de ordenación (*Radix*).
- `push.c`: Funciones para mover elementos entre stacks.
- `swap.c`: Funciones de intercambio.
- `rotate.c`: Funciones de rotación de elementos.
- `reverse_rotate.c`: Funciones de rotación inversa.

## Reglas del Proyecto

- Se trabaja con dos stacks (`a` y `b`).
- Inicialmente, `a` contiene los números desordenados y `b` está vacío.
- El objetivo es ordenar `a` en orden ascendente con el menor número de movimientos posibles.
- Solo se pueden usar un conjunto limitado de operaciones (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

## Algoritmo Utilizado

Se ha implementado **Radix Sort** optimizado con operadores bitwise para reducir la cantidad de buckets y mejorar el rendimiento.

Se procesa cada número analizando sus bits y distribuyéndolos en los stacks de manera eficiente hasta lograr un orden ascendente.

## Funciones Permitidas

- `read`, `write`, `malloc`, `free`, `exit`.
- `ft_printf` y cualquier otra función de la **libft**.

## Bonus

Se incluye un **checker** que verifica si la secuencia de instrucciones generada realmente ordena el stack correctamente.
La parte de bonus consiste en hacer tu propio **checker**.

## Consideraciones Finales

Este proyecto ha sido una introducción práctica al análisis de complejidad y la optimización de algoritmos. Se ha trabajado con **Big O notation**, se han explorado diferentes estrategias de ordenación y se ha implementado una solución eficiente usando *bitwise operations*.

