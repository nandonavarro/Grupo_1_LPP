#include <stdio.h>
#include <string.h>

void agregar_libros(char *filename){

    FILE *file = fopen(filename, "a");

    int count;
    char titulo[100];
    char autor[100];
    int anio;
    int estante_numero;
    char estante_seccion[100];
    int piso;
    char edificio[10];
    char sede[100];

    printf("Numero de libros a agregar: \n");
    scanf("%i", &count);

    if(count!=0){

        for(int i = 1; i <= count; i++){
            printf("Ingrese el nombre del libro: \n");            
            fgets(titulo,100,stdin); //
            printf("Ingrese el nombre del autor: \n");
            fgets(autor,100,stdin); //
            printf("Ingrese el año de publicación: \n");
            scanf("%i",&anio);
            printf("Ingrese el numero de estante: \n");
            scanf("%i",&estante_numero);
            printf("Ingrese la seccion del estante: \n");
            scanf("%s", estante_seccion);
            printf("Ingrese el piso del estante: \n");
            scanf("%i",&piso);
            printf("Ingrese el edificio del piso: \n");
            scanf("%s", edificio);
            printf("Ingrese la sede del edificio: \n");
            scanf("%s", sede);

            fprintf(file,"\n%s,%s,%d,%d,%s,%d,%s,%s",titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede);
            }
        fclose(file);
    }
    else{
        printf("Operación cancelada\n");
    }
}