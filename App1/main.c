#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_libro.h"

struct libro_data {
  char titulo[75];
  char autor[50];
  int anio;
  int estante_numero;
  char estante_seccion[50];
  int piso;
  char edificio[1];
  char sede[20];
};

void printmenu() {
  printf("1. Agregar un libro a la Bibloteca\n");
  printf("2. Quitar un libro de la Biblioteca\n");
  printf("3. Agregar una sede\n");
  printf("4. Quitar una sede (sólo si no hay libros)\n");
  printf("5. Editar un libro\n");  // A qué se refiere con editar
  printf("6. Cambiar un libro de sede\n");
  printf("7. Cambiar un libro de sección\n");
  printf("8. Cambiar un libro de piso\n");
  printf("9. Agregar secciones\n");
  printf("10. Eliminar secciones (sólo si no hay libros)\n");
  printf("11. Agregar un piso\n");
  printf("12. Eliminar piso (sólo si no hay libros)\n");
  printf("13. Buscar un libro\n");
  printf("14. Salir\n");
}

void agregar_libro() {
  struct libro_data libro;

  printf("Ingrese el titulo del libro: ");
  scanf("%[^\n]%*c", libro.titulo);
  printf("ingrese autor del libro: ");
  scanf("%[^\n]%*c", libro.autor);
  printf("ingrese anio del libro: ");
  scanf("%i\n", &libro.anio);
  printf("ingrese el numero del estante en donde se encuentra el libro: ");
  scanf("%i\n", &libro.estante_numero);
  printf("ingrese la seccion en la cual se encuentra el libro: ");
  scanf("%[^\n]%*c", libro.estante_seccion);
  printf("\ningrese el piso del edificio en donde se encuentra el libro: ");
  scanf("%i\n", &libro.piso);
  printf("ingrese la letra del edificio en donde se encuentra el libro: ");
  scanf("%[^\n]%*c", libro.edificio);
  printf("ingrese la sede en donde se encuentra el libro: ");
  scanf("%[^\n]%*c", libro.sede);

  printf("Titulo: %s\n Autor: %s\n Anio: %i\n  ", libro.titulo, libro.autor,
         libro.anio);
};

int quitarlibro(struct libro_data libro);
int agregarsede(struct libro_data libro);
int quitarsede(struct libro_data libro);
int editarlibro(struct libro_data libro);
int cambio_sede_libro(struct libro_data libro);
int cambio_secc_libro(struct libro_data libro);
int cambio_piso_libro(struct libro_data libro);
int agregar_secc(struct libro_data libro);
int eliminar_secc(struct libro_data libro);
int agregar_pisos(struct libro_data libro);
int eliminar_pisos(struct libro_data libro);
int buscar_libro(struct libro_data libro);
int inventario(struct libro_data libro);

int main(int argc, char **argv) {
  printf("Bienvenido/a a la Biblioteca UAI\n");
  printf("Seleccione la opción que quiera realizar\n");

  int flag = 1;
  int menu;

  while (flag) {
    printmenu();
    printf("\n");
    printf("Ingrese el número de la acción: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
      printf("esta en el menu 1");
      break;
    
    
    case 2:
      /*Agregar/Quitar sede*/
      printf("esta en el menu 2");
      break;

    case 3:
      printf("esta en el menu 3");
      break;

    case 4:
      printf("¿Qué quiere hacer?\n");
      printf("1) agregar libro\n");
      printf("2) quitar libro\n");
      printf("Ingrese su opción: ");
      scanf("%d", &menu);

      if (menu == 1) {
        /*funcion que agrega libro*/
      } else if (menu == 2) {
        /*funcion quitar libro*/
      }
      break;

    default:
      break;
    }

    

    /*Editar informacion de algun libro*/
    
    

    /*Agregar/Quitar seccion*/
    
    

    /*Agregar/Quitar piso*/
    if (menu == 5) {
      printf("esta en el menu 5\n");
    }

    /*Buscar un Libro*/
    else if (menu == 6) {
      printf("esta en el menu 6");
    }

    /*Salir del sistema*/
    else {
      printf("esta en el menu 7");
      // escribir break en vez
    }
  }

  return 0;
}