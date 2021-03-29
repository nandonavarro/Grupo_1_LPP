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
int simon = 0;

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

char f_populate(FILE *libro_csv, struct struct_libro values[], int n_lineas) /* im having trouble here */
{
    int i = 0;
    char buff[n_lineas];
    fgets(buff, 200, (FILE *)libro_csv);
    while (fgets(buff, n_lineas, libro_csv))
    {
        int field_count = 0;
        if (n_lineas == 1)
            continue;

        int commas = 0;

        if (*buff == '"')
        {
            int index = 1;
            while (*(buff + index) != '"')
            {

                if (*(buff + index) == ',')
                {
                    ++commas;
                }
                ++index;
            }
        }

        char *field = strtok(buff, ",");

        while (field)
        {

            if (field_count == 0)
            {
                strcpy(values[i].titulo, field);
                while (commas--)
                {
                    field = strtok(NULL, ",");
                    strcat(values[i].titulo, field);
                }
            }

            if (field_count == 1)
                strcpy(values[i].autor, field);
            if (field_count == 2)
                values[i].anio = atoi(field);
            if (field_count == 3)
                values[i].estante_numero = atoi(field);
            if (field_count == 4)
                strcpy(values[i].estante_seccion, field);
            if (field_count == 5)
                values[i].piso = atoi(field);
            if (field_count == 6)
                strcpy(values[i].edificio, field);
            if (field_count == 7)
                strcpy(values[i].sede, field);
            field = strtok(NULL, ",");
            field_count++;
        }
        i++;
        ++simon;
    }

    return 0;
}

void printmenu()
{
    printf("1. Agregar un libro a la Bibloteca\n");
    printf("2. Quitar un libro de la Biblioteca\n");
    printf("3. Agregar una sede\n");
    printf("4. Quitar una sede (sólo si no hay libros)\n");
    printf("5. Editar un libro\n"); // A qué se refiere con editar
    printf("6. Cambiar un libro de sede\n");
    printf("7. Cambiar un libro de sección\n");
    printf("8. Cambiar un libro de piso\n");
    printf("9. Agregar secciones\n");
    printf("10. Eliminar secciones (sólo si no hay libros)\n");
    printf("11. Agregar un piso\n");
    printf("12. Eliminar piso (sólo si no hay libros)\n");
    printf("13. Buscar un libro\n");
    printf("14. Salir\n");
}

char agregar_libro(struct struct_libro libro_agregado[])
{
    int index = 0;
    while (libro_agregado[index].titulo != NULL)
    {
        /* code */
    }

    //cuantos libros quiere agregar?
    printf("cuantos libros quiere agregar? ");
    int n_a;
    fgets(n_a, 10, stdin);

    for (int p = 0; p < n_a; p++)
    {

        printf("Ingrese el titulo del libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Ingrese el autor del libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Ingrese el anio del libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Ingrese el numero del estante en donde se encuentra el libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Ingrese la seccion en la cual se encuentra el libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Ingrese el piso del edificio en donde se encuentra el libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Ingrese la letra del edificio en donde se encuentra el libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Ingrese la sede en donde se encuentra el libro: ");
        fgets(libro_agregado[p].titulo, 30, stdin);

        printf("Titulo: %s\n Autor: %s\n Anio: %i\n  ", libro_agregado[p].titulo, libro_agregado[p].autor,
               libro_agregado[p].anio);
    }

    return 0;
};

int main(int argc, char **argv)
{
    FILE *libro_csv = read_file();
    int arr_size = cuenta_lineas(libro_csv);
    rewind(libro_csv);
    struct struct_libro values[arr_size];
    f_populate(libro_csv, values, arr_size);

    printf("Bienvenido/a a la Biblioteca UAI\n");
    printf("Seleccione la opción que quiera realizar\n");

    int flag = 1;
    int menu;
    struct struct_libro libro_agregado2[1024];
    if (libro_agregado2[0].titulo == 0)
        printf("cualquierwea");

    //     while (flag)
    //     {
    //         printmenu();
    //         printf("\n");
    //         printf("Ingrese el número de la acción: ");
    //         scanf("%d", &menu);

    //         switch (menu)
    //         {
    //         case 1:
    //             printf("esta en el menu 1");
    //             break;

    //         case 2:
    //             /*Agregar/Quitar sede*/
    //             printf("esta en el menu 2");
    //             break;

    //         case 3:
    //             printf("esta en el menu 3");
    //             break;

    //         case 4:
    //             printf("¿Qué quiere hacer?\n");
    //             printf("1) agregar libro\n");
    //             printf("2) quitar libro\n");
    //             printf("Ingrese su opción: ");
    //             scanf("%d", &menu);

    //             if (menu == 1)
    //             {
    //                 agregar_libro(libro_agregado);
    //             }
    //             else if (menu == 2)
    //             {
    //                 /*funcion quitar libro*/
    //             }
    //             break;

    //         default:
    //             break;
    //         }

    //         /*Editar informacion de algun libro*/

    //         /*Agregar/Quitar seccion*/

    //         /*Agregar/Quitar piso*/
    //         else if (menu == 5)
    //         {
    //             printf("esta en el menu 5\n");
    //         }

    //         /*Buscar un Libro*/
    //         else if (menu == 6)
    //         {
    //             printf("esta en el menu 6");
    //         }

    //         /*Salir del sistema*/
    //         else
    //         {
    //             printf("esta en el menu 7");
    //             // escribir break en vez
    //         }
    //     }
    return 0;
}