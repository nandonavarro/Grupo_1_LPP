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
    #print("Jugador ", turno, ", ingrese su movimiento: ")
    f = int(input("  fila: "))-1
    g = int(input("  columna: "))-1
    return [f,g]

def verificar_ganador():

    for i in range(3):
        if tablero[i][0]==1 and tablero[i][1]==1 and tablero[i][2]==1:
            return True
        if tablero[i][0]==2 and tablero[i][1]==2 and tablero[i][2]==2:
            return True
    for j in range(3):
        if tablero[0][j]==1 and tablero[1][j]==1 and tablero[2][j]==1:
            return True
        if tablero[0][j]==2 and tablero[1][j]==2 and tablero[2][j]==2:
            return True
    for i in [1,2]:
        if tablero[0][0]==i and tablero[1][1]==i and tablero[2][2]==i:
            return True
        if tablero[0][2]==i and tablero[1][1]==i and tablero[2][0]==i:
            return True

def verificar_empate():
    temp = True
    for i in range(3):
        for j in range(3):
            if tablero[i][j]==0:
                temp = False
    return temp

def main():
    nuevo_tablero()
    imprime_tablero()
    print("")
    
    global turno
    turno = 1

    while True:
        jugada = registro_jugada()
        if verificar_jugada(jugada):
            tablero[jugada[0]][jugada[1]] = turno
            if verificar_ganador():
                break
            if turno==1:
                turno = 2
            else:    
                turno = 1
            imprime_tablero()
            print("")
        else:
            imprime_tablero()
            print("Casilla ocupada")
        
        if verificar_empate():
            break

    if verificar_empate():
        print("hubo empate :)")
        print("Gracias por nada par de inútiles")
    else:
        print("Felicidades ha ganado jugador ", turno)

if __name__ == '__main__':
    main()