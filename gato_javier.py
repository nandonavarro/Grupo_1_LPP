tablero = [  
            [" "," ", " ", "|"," "," ", " ", "|"," "," ", " "], #1      5      9
            ["-","-", "-", "+","-","-", "-", "+","-","-", "-"],
            [" "," ", " ", "|"," "," ", " ", "|"," "," ", " "], #23     27     31
            ["-","-", "-", "+","-","-", "-", "+","-","-", "-"],
            [" "," ", " ", "|"," "," ", " ", "|"," "," ", " "]  #45     49     53gi
          ]
jugador = True 
def print_tblro(tablero): ###funcion para dibujar tablero
    for fila in tablero:
        for slot in fila:
            print(slot,end = "")
        print("")

def exit (accion): ##funcion para terminar programa
    if accion.lower() == "q":
        return True
    else:
        return False

def check_accion(accion):  ##funcion comprobar input (dentro del rango y que sea un numero
    if not isnum(accion):
        return False    
    if not rango(accion):
        return False
    return True

def isnum(accion): ##funcion que revisa si es un numero 
    if not accion.isnumeric():
        print(f"el espacio {accion} no existe ...")
        return False
    else:
        return True

def rango (accion): ##funcion que revisa si esta entre 1 y 9

    if int(accion) > 9 or int(accion) < 1:
        print (f"la posición {accion} no existe en el tablero")
        return False
    else:
        return True

def ocupado (cordenadas, tablero): #
    fila = cordenadas[0]
    columna = cordenadas[1]
    if tablero[fila][columna] != " ":
        print("Amigue date cuenta, el espacio esta ocupado ...")
        return True
    else:
        return False

def cordenadas (accion): ## (esta funcion asigna las posiciones del tablero a los numeros) 
    fila = 0             ## ESTO SE PUEDE HACER MEJOR ....!!!!!
    columna = 0
    if accion == 1:
        fila = 0
        columna = 1
    elif accion == 2:
        fila = 0
        columna = 5
    elif accion == 3:
        fila = 0
        columna = 9
    elif accion == 4:
        fila = 2
        columna = 1
    elif accion == 5:
        fila = 2
        columna = 5
    elif accion == 6:
        fila = 2
        columna = 9
    elif accion == 7:
        fila = 4
        columna = 1
    elif accion == 8:
        fila = 4
        columna = 5
    elif accion == 9:
        fila = 4
        columna = 9
    return (fila,columna)

def add_jugada(cordenada,tablero, jugando): ##añade jugada al tablero
    fila = cordenada[0]
    columna = cordenada[1]
    tablero[fila][columna] = jugando

def jugador_actual(jugador): ## funcion cambia de jugador
    if jugador:
        return "X"
    else:
        return "O"


def revisa_fila(jugador, tablero):
    for fila in tablero:
        fila_completa = True
        for slot in fila:
            if slot != jugador:
                fila_completa = False
                break
        if fila_completa:
            return True
    return False



def ganador(jugador, tablero):
    if revisa_fila(jugador, tablero):
        return True
    return False

while True:
    jugando = jugador_actual(jugador)
    print_tblro(tablero)
    accion = input("seleccione el lugar donde desea jugar(1 - 9) o presione Q para salir:")
    if exit(accion):
       break
    if not check_accion(accion):
        print("introduce una movida aceptada ... -_-")
        continue
    accion = int(accion)
    cordenada = cordenadas(accion)
    if ocupado(cordenada,tablero):
        print("Ingresa nuevamente una posición en el tablero")
        continue
    add_jugada(cordenada,tablero, jugando)
    if ganador (jugando, tablero):
        print(f"{jugando} has ganado!!!")
        break
    jugador = not jugador
