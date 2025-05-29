
filas = 8
columnas = 8
tarifa_hora = 2000


mapa = []
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


vehiculos = {}


while True:
   
    print("\nMapa del Parqueadero:")
    for fila in mapa:
        print(" ".join(fila))

    
    libres = 0
    ocupados = 0
    for i in range(1, filas - 1):
        for j in range(1, columnas - 1):
            if mapa[i][j] == 'L':
                libres += 1
            elif mapa[i][j] == 'X':
                ocupados += 1
    print("\nEspacios libres:", libres)
    print("Espacios ocupados:", ocupados)

   
    print("\n1. Registrar entrada")
    print("2. Registrar salida")
    print("3. Salir")
    opcion = input("Seleccione una opción: ")

    if opcion == "1":
        placa = input("Ingrese la placa del vehículo: ").upper()
        encontrado = False
        for i in range(1, filas - 1):
            for j in range(1, columnas - 1):
                if mapa[i][j] == 'L':
                    mapa[i][j] = 'X'
                    hora = int(input("Ingrese la hora de entrada (entero): "))
                    vehiculos[placa] = [[i, j], hora]
                    print("Vehículo registrado en la posición:", i, j)
                    encontrado = True
                    break
            if encontrado:
                break
        if not encontrado:
            print("No hay espacios disponibles.")

    elif opcion == "2":
        placa = input("Ingrese la placa del vehículo: ").upper()
        if placa in vehiculos:
            posicion = vehiculos[placa][0]
            hora_entrada = vehiculos[placa][1]
            hora_salida = int(input("Ingrese la hora de salida (entero): "))
            tiempo = hora_salida - hora_entrada
            if tiempo < 0:
                print("Hora inválida.")
            else:
                total = tiempo * tarifa_hora
                print("Tiempo de permanencia:", tiempo, "horas")
                print("Total a pagar: $", total)
                mapa[posicion[0]][posicion[1]] = 'L'
                del vehiculos[placa]
        else:
            print("Vehículo no encontrado.")

    elif opcion == "3":
        print("Saliendo del sistema. ¡Gracias!")
        break

    else:
        print("Opción inválida. Intente de nuevo.")


