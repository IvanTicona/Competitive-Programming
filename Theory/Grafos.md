# Algoritmo Havel - Hakimi

Dado una secuencia de enteros en un array, la tarea es revisar si se puede armar un grafo con la secuencia de grados dados. Notar que un grafo simple es un grafo que no tiene ciclos ni aristas paralelas.

Algoritmo:
- Ordenar la secuencia en orden ascendente.
- Borrar el primer elemento k, restar 1 a los siguientes k elementos.
- Repetir el proceso hasta que se cumpla una condición de parada.

Stopping conditions:
- Todos los elementos restantes son igual a 0 (Grafo simple existe).
- Luego de la resta se encuentra un numero negativo (Grafo simple no existe).
- No hay k elementos para el paso de la sustraccion (Grafo simple no existe).