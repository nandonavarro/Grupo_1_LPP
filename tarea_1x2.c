#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct str_notas
{
    char nombre[40];
    float prueba_1;
    float prueba_2;
    float prueba_3;
    float prueba_4;
    float proyecto;
    float tareas;

} Notas;

int j = 1;

int main(int argc, char const *argv[])
{
    FILE *notas_csv;
    notas_csv = fopen("notas.csv", "r");

    if (notas_csv == NULL)
    {
        printf("No se abrio el archivo csv. \n");
    }

    rewind(notas_csv);

    char lineas[200];
    fgets(lineas, 1024, notas_csv);
    char *delimiter = ",";

    int i = 0;

    for (char c = getc(notas_csv); c != EOF; c = getc(notas_csv))
    {
        if (c == '\n')
        {
            j++;
        }
    }

    Notas notas[j + 1];
    rewind(notas_csv);

    fgets(lineas, 200, (FILE *)notas_csv);

    while (fgets(lineas, 200, (FILE *)notas_csv) != NULL)
    {
        strcpy(notas[i].nombre, strtok(lineas, delimiter));

        notas[i].prueba_1 = atof(strtok(NULL, delimiter));
        notas[i].prueba_2 = atof(strtok(NULL, delimiter));
        notas[i].prueba_3 = atof(strtok(NULL, delimiter));
        notas[i].prueba_4 = atof(strtok(NULL, delimiter));
        notas[i].proyecto = atof(strtok(NULL, delimiter));
        notas[i].tareas = atof(strtok(NULL, delimiter));

        i++;
    }

    fclose(notas_csv);
    int contador = 4;

    printf("%s\n", notas[0].nombre);
    printf("%.2f\n", notas[0].prueba_2);

    return 0;
}
