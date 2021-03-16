import numpy

def nuevo_tablero():
    global tablero
    tablero = numpy.array([[0,0,0],[0,0,0],[0,0,0]])

def imprime_tablero():
    for t in range(15):
        print("")
    for i in range(tablero.shape[0]):
        temp = ""
        for j in range(tablero.shape[1]):
            if tablero[i][j]==0:
                temp = temp+" "
            elif tablero[i][j]==1:
                temp = temp+"x"
            elif tablero[i][j]==2:
                temp = temp+"o"
            if j!=2:
                temp = temp+"|"
        print(temp)
        if i!=2:
            print("-----")

def verificar_jugada(play):
    if tablero[play[0]][play[1]]==0:
        return True
    else:
        return False


def registro_jugada():
    print("Jugador %d, ingrese su movimiento: " % turno)
    f = int(input("  fila: "))-1
    g = int(input("  columna: "))-1
    return [f,g]


def main():
    i = True

    nuevo_tablero()
    imprime_tablero()
    print("")
    
    global turno
    turno = 1

    while i:
        jugada = registro_jugada()
        if verificar_jugada(jugada):
            tablero[jugada[0]][jugada[1]] = turno
            if turno==1:
                turno = 2
            else:    
                turno = 1
            imprime_tablero()
            print("")
        else:
            imprime_tablero()
            print("Casilla ocupada")
        

        #if verificar_ganador():
        #    i = False

if __name__ == '__main__':
    main()
                


