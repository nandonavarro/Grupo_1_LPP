#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
https://stackoverflow.com/questions/12911299/read-csv-file-in-c
De esta página saqué el código para intentar leer un .csv
*/
const char* getfield(char* line, int num) {
  const char* tok;
  for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")) {
    if (!--num) return tok;
  }
  return NULL;
}

/*
    stream es la variable que almacena los datos del .csv
    line es la variable temporal que almacena la fila
    la función getfield() es la que obtiene el valor de una celda en específico
*/
int main() {
  FILE* stream = fopen("ejemplo-app1.csv", "r");

  char line[1024];
  while (fgets(line, 1024, stream)) {
    char* tmp = strdup(line);
    printf("Field 3 would be %s\n", getfield(tmp, 2));
    // NOTE strtok clobbers tmp
    free(tmp);
  }
}