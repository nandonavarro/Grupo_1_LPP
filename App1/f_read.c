#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_libro.h"

int j = 1;

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
char line[1024];
int main()
{
    FILE *libro_csv = read_file();
    int arr_size = cuenta_lineas(libro_csv);

    printf("tamano del array: %i\n", arr_size);
    
    struct struct_libro info_libro[arr_size+1];
    rewind(libro_csv);
    char line[1024];
    fgets(line, 1024, libro_csv);
    char *delimiter = ",";
    
    int i = 0;

    printf("%c este es\n", line[100]);
    fgets(line, 200, (FILE *)libro_csv);
    printf("este no");
    while (fgets(line, 200, (FILE *)libro_csv) != NULL)
    {
        
        strcpy(info_libro[i].titulo, strtok(line, delimiter));
        //printf("%s", info_libro[i].titulo);
        strcpy(info_libro[i].autor, strtok(line, delimiter));
        info_libro[i].anio = atoi(strtok(NULL, delimiter));
        info_libro[i].estante_numero = atof(strtok(NULL, delimiter));
        strcpy(info_libro[i].estante_seccion, strtok(line, delimiter));
        info_libro[i].piso = atoi(strtok(NULL, delimiter));
        strcpy(info_libro[i].edificio, strtok(line, delimiter));
        strcpy(info_libro[i].sede, strtok(line, delimiter));
        i++;
    }
    fclose(libro_csv);
    printf("%c", line[0]);

    for(int k = 0; k < 4; k++){
        printf("%d \n", info_libro[k].anio);
    }
    printf("\n");

    return 0;
    
    return 0;
}

/*
FILE* abrir_archivo(){
    FILE *the_file = fopen("ejemplo.csv", "r");
    
    if (the_file == NULL){
        perror("El archivo no pudo ser abierto");
        exit(1);
    }

    return(the_file);
}



int main(){
    
    FILE* the_file = abrir_archivo();
    
    char line[1024];
    fgets(line, 1024, the_file);
    char *delimiter = ",";

    int i = 0;


    for (char c = getc(the_file); c != EOF; c = getc(the_file))
    {
        if (c == '\n')
        {
            j++;
        }
    }

    struct struct_libro info_libro[j + 1];
    
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

    for(int k; k < 4; k++){
        printf("%d ", info_libro[k].piso);
    }
    printf("\n");

    return 0;
}

*/
