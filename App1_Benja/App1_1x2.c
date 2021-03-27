#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_libro.h"

typedef struct struct_libro
{
    char titulo[75];
    char autor[50];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[1];
    char sede[20];
} struct_libro;

int j = 1;

int count_lines(j)
{
    FILE *the_file = fopen("ejemplo.csv", "r");
    if (the_file == NULL)
    {
        perror("el archivo no pudo ser abierto");
        exit(1);
    }

    for (char c = getc(the_file); c != EOF; c = getc(the_file))
    {
        if (c == '\n')
        {
            j++;
        }
    }
    char line[1024];
    fgets(line, 1024, the_file);

    fclose(the_file);
    return j;
}

struct_libro f_read(info_libro)
{

    FILE *the_file = fopen("ejemplo.csv", "r");
    if (the_file == NULL)
    {
        printf("no se pudo abrir el archivo");
    }

    //populacion
    fgets(line, 200, (FILE *)the_file);
    while (fgets(line, 200, (FILE *)the_file) != NULL)
    {
        strcpy(info_libro[i].titulo, strtok(line, delimiter));
        strcpy(info_libro[i].autor, strtok(line, delimiter));
        info_libro[i].anio = atoi(strtok(NULL, delimiter));
        info_libro[i].estante_numero = atof(strtok(NULL, delimiter));
        strcpy(info_libro[i].estante_seccion, strtok(line, delimiter));
        info_libro[i].piso = atoi(strtok(NULL, delimiter));
        strcpy(info_libro[i].edificio, strtok(line, delimiter));
        strcpy(info_libro[i].sede, strtok(line, delimiter));
        i++;
    }
    fclose(the_file);
    return info_libro;
}

int main(int argc, char const *argv[])
{

    int contador = count_lines(j);

    char *delimiter = ",";
    int i = 0;
    struct_libro info_libro[contador + 1];
    struct_libro info_libro = f_read(info_libro);

    printf("titulo: \n%s", info_libro[0].titulo);

    return 0;
}
