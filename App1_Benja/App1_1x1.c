#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Variables Globales
int contador = 1;
FILE *libros_csv;
char *delimiter = ",";
/*                  */

typedef struct libro_data
{
    char titulo[75];
    char autor[50];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[1];
    char sede[20];
} Libros;

//leer archivo
void read_file(libros_csv)
{

    libros_csv = fopen("ejemplo.csv", "r");
    if (libros_csv == NULL)
    {
        printf("el archivo no pudo ser abierto");
    }

    return libros_csv;
}

//cuenta las lineas en el csv
void count_lines(libros_csv, contador)
{

    for (char c = getc(libros_csv); c != EOF; c = getc(libros_csv))
    {
        if (c == '\n')
        {
            contador++;
        }
    }
    return contador;
}
/*
char function_populate(line, info_libro, delimiter, i)
{

    fgets(line, 200, (FILE *)libros_csv);
    while (fgets(line, 200, (FILE *)libros_csv) != NULL)
    {
        //titulo
        strcpy(info_libro[i].titulo, strtok(line, delimiter));
        //auto
        strcpy(info_libro[i].autor, strtok(line, delimiter));
        //anio
        info_libro[i].anio = atoi(strtok(NULL, delimiter));
        //estante_numero
        info_libro[i].estante_numero = atof(strtok(NULL, delimiter));
        //estante_seccion
        strcpy(info_libro[i].estante_seccion, strtok(line, delimiter));
        //piso
        info_libro[i].piso = atoi(strtok(NULL, delimiter));
        //edificio
        strcpy(info_libro[i].edificio, strtok(line, delimiter));
        //sede
        strcpy(info_libro[i].sede, strtok(line, delimiter));
        i++;
    }
    return info_libro;
}
*/
/*
void print_struct(info_libro, contador)
{

    for (int k = 0; k < contador - 1; k++)
    {
        printf("\n\n");
        printf("Titulo: %s\n", info_libro[k].titulo);
        printf("Autor: %.1f\n", info_libro[k].autor);
        printf("Anio: %.1f\n", info_libro[k].anio);
        printf("Estante numero: %.1f\n", info_libro[k].estante_numero);
        printf("Estante Seccion: %.1f\n", info_libro[k].estante_seccion);
        printf("Piso: %.1f\n", info_libro[k].piso);
        printf("Edificio: %.2f\n", info_libro[k].edificio);
        printf("sede: %.2f\n", info_libro[k].sede);
        printf("\n");
    }
}
*/
int main(int argc, char const *argv[])
{
    //f1
    read_file(*libros_csv);
    //f2
    count_lines(libros_csv, contador);
    rewind(libros_csv);
    //variables
    char line[1024];
    fgets(line, 1024, libros_csv);

    printf("contador: \n%i", contador);
    printf("primer character %c", line[0]);

    /*Libros info_libro[contador + 1];
    int i = 0;
    
    rewind(libros_csv);
    //f3
    function_read(line, info_libro, *delimiter, i);

    fclose(libros_csv);
    //f4
    print_struct(info_libro, contador);
    */
    return 0;
}
