#include <stdio.h>

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

int main(int argc, char **argv){
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

    printf("Titulo: %s\n Autor: %s\n Anio: %i\n  ",libro.titulo ,libro.autor,libro.anio );

}
