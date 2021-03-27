#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    FILE *libro_csv = read_file();
    int arr_size = cuenta_lineas(libro_csv);
    printf("tamano del array: %i\n", arr_size);
    return 0;
}
