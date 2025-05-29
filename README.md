# Parcial-3er-corte-juan-felipe-amador


## Explcación del código en c++

En el codigo de c++ se uso conceptos usados en clase como bucles, condicionales, booleanos.

Por temas de comodidad y comprensión no se utilizaron librerias ni funciones, ya que se quiso hacer de la manera mas eficiente y simplificada.

## Explicación del codigo en python

```py
for i in range(filas):
    fila = []
    for j in range(columnas):
        if i == 0 and j == 3:
            fila.append('E')
        elif i == filas - 1 and j == 4:
            fila.append('S')
        elif 1 <= i <= 6 and 1 <= j <= 6 and (i + j) % 2 == 0:
            fila.append('L')
        else:
            fila.append('V')
    mapa.append(fila)

```

En esta parte del código se usaron las funciones para las listas, como append, que agrega un elemento a la lista ya establecida.

En la parte restante del codigo hay bucles y condicionales que no son de mayor complejidad



