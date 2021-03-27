#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_libro.h"

int j = 1;

char f_read()
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

    //variables
    char line[1024];
    fgets(line, 1024, the_file);
    char *delimiter = ",";
    int i = 0;
    struct_libro info_libro[j + 1];

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
    f_read(j);

    printf("titulo: \n%s", info_libro[0].titulo);
    return 0;
}
