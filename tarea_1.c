#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Defino el struct
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

//Defino Contador Global

int contador = 1;

int main(int argc, char const *argv[])
{
    //abro archivo CSV
    FILE *notas_csv;
    notas_csv = fopen("notas.csv", "r");

    //Si no se abre bien el archivo lanza error
    if (notas_csv == NULL)
    {
        printf("No se abrio el archivo csv. \n");
    }
    rewind(notas_csv);

    //declaro Array que tomara las lineas del archivo CSV
    char lineas[200];
    fgets(lineas, 1024, notas_csv);

    //cuento cuantas lineas tiene el CSV
    for (char c = getc(notas_csv); c != EOF; c = getc(notas_csv))
    {
        if (c == '\n')
        {
            contador++;
        }
    }

    //Declaro el array que contendra todos nuestros struct
    Notas notas[contador];
    rewind(notas_csv);

    //Defino variables
    char *delimitador = ",";
    int i = 0;

    //Elimina la primera linea que contiene los labels
    fgets(lineas, 200, (FILE *)notas_csv);

    //Agrego los datos de el archivo CSV al Array que contiene los struct
    while (fgets(lineas, 200, (FILE *)notas_csv) != NULL)
    {
        //copio el string y lo agrego a la variable nombre dentro del struct
        strcpy(notas[i].nombre, strtok(lineas, delimitador));
        //transformo a float las notas y las agrego al struct
        notas[i].prueba_1 = atof(strtok(NULL, delimitador));
        notas[i].prueba_2 = atof(strtok(NULL, delimitador));
        notas[i].prueba_3 = atof(strtok(NULL, delimitador));
        notas[i].prueba_4 = atof(strtok(NULL, delimitador));
        notas[i].proyecto = atof(strtok(NULL, delimitador));
        notas[i].tareas = atof(strtok(NULL, delimitador));

        i++;
    }
    //cierro el archivo CSV
    fclose(notas_csv);

    //imprime los struct
    for (int k = 0; k < contador - 1; k++)
    {
        printf("\n\n");
        printf("Nombre: %s\n", notas[k].nombre);
        printf("Prueba 1: %.1f\n", notas[k].prueba_1);
        printf("Prueba 2: %.1f\n", notas[k].prueba_2);
        printf("Prueba 3: %.1f\n", notas[k].prueba_3);
        printf("Prueba 4: %.1f\n", notas[k].prueba_4);
        printf("Proyecto: %.1f\n", notas[k].proyecto);
        printf("Tareas: %.2f\n", notas[k].tareas);
        printf("\n");
    }

    return 0;
}
