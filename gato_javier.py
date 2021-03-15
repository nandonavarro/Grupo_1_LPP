tablero = [  
            [" "," ", " ", "|"," "," ", " ", "|"," "," ", " "], #1      5      9
            ["-","-", "-", "+","-","-", "-", "+","-","-", "-"],
            [" "," ", " ", "|"," "," ", " ", "|"," "," ", " "], #23     27     31
            ["-","-", "-", "+","-","-", "-", "+","-","-", "-"],
            [" "," ", " ", "|"," "," ", " ", "|"," "," ", " "]  #45     49     53gi
          ]
def print_tblro(tablero): ###funcion para dibujar tablero
    for row in tablero:
        for slot in row:
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

def isnum(accion):
    if not accion.isnumeric():
        print(f"el espacio {accion} no existe ...")
        return False
    else:
        return True

def rango (accion):
    if accion > 9 and accion < 1:
        print (f"la posición {accion} no existe en el tablero")
        return False
    else:
        return True
##def ocupado (accion):

def cordenadas (accion):
    fila = 
    columna =

while True:
    print_tblro(tablero)
    accion = input("seleccione el lugar donde desea jugar(1 - 9) o presione Q para salir:")
    if exit(accion):
       break
    if not check_accion(accion):
        print("introduce una movida aceptada ... -_-")
        continue
    accion = int(accion) - 1


