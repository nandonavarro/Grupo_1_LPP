#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_libro
{
    char titulo[75];
    char autor[50];
    int anio;
    int estante_numero;
    char estante_seccion[50];
    int piso;
    char edificio[1];
    char sede[20];
};

FILE *read_file(void)
{
    FILE *archivo_csv = fopen("ejemplo.csv", "r");
    if (archivo_csv == NULL)
    {
        printf("el archivo no pudo ser abierto");
        exit(1);
    }

    return archivo_csv;
}

int cuenta_lineas(FILE *libro_csv)
{
    int contador = 0;
    for (char c = fgetc(libro_csv); c != EOF; c = fgetc(libro_csv))
    {
        if (c == '\n')
        {
            contador++;
        }
    }
    return contador;
}

char f_populate(FILE *libro_csv, struct struct_libro info_libro[]) /* im having trouble here */
{
    int i = 0;
    char *delimiter = ",";
    char line[1024];
    fgets(line, 1024, libro_csv);
    rewind(libro_csv);

    fgets(line, 200, (FILE *)libro_csv);
    while (fgets(line, 200, (FILE *)libro_csv) != NULL)
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
    return 0;
}

int main()
{
    FILE *libro_csv = read_file();
    int arr_size = cuenta_lineas(libro_csv);
    printf("tamano del array: %i\n", arr_size);
    rewind(libro_csv);
    struct struct_libro info_libro[arr_size];
    f_populate(libro_csv, info_libro); /* im having trouble here */
    printf("name %s\n", info_libro[0].titulo);

    return 0;
}