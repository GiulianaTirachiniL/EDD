#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* Retorna true si ambos strings son iguales */
static bool string_equals(char *string1, char *string2)
{
    return !strcmp(string1, string2);
}

static bool check_arguments(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
        printf("Donde:\n");
        printf("\tINPUT es la ruta del archivo de input\n");
        printf("\tOUTPUT es la ruta del archivo de output\n");
        exit(1);
    }
    return true;
}

int main(int argc, char **argv)
{

    /* Definicion de argumentos */
    check_arguments(argc, argv);
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    int S; // Cantidad maxima de magneZones
    int E; // Cantidad de eventos

    // La funcion fscanf lee desde el archivo de input segun los especificadores de formato en el string
    // del segundo argumento. Lo que lea, se guarda en la dirección de memoria especificada en el tercer argumento
    // Se guarda en buffer un int de status para confirmar si todo salió bien.
    int buffer = fscanf(input_file, "%d", &S);

    if (buffer != 1)
    {
        printf("Error reading maximum number of sectors");
        return 1;
    }

    buffer = fscanf(input_file, "%d", &E);

    if (buffer != 1)
    {
        printf("Error reading number of events");
        return 1;
    }

    /* Eventos */

    char command[32];

    for (int i = 0; i < E; i++)
    {

        buffer = fscanf(input_file, "%s", command);
        if (buffer != 1)
        {
            printf("Error reading event");
            return 1;
        }

        if (string_equals(command, "ENTER"))
        {

            int magezone_id;
            int magemite_id;
            int atk;
            int speed;

            fscanf(input_file, "%i", "%i", "%i", "%i", &magezone_id, &magemite_id, &atk, &speed);
            /* fscanf(input_file, "%i", &magezone_id);
            fscanf(input_file, "%i", &magemite_id);
            fscanf(input_file, "%i", &atk);
            fscanf(input_file, "%i", &speed); */ 

            char output[256];
            sprintf(output, "Magemite %d entered MageZone %d with ATK %d and Speed %d\n", magemite_id, magezone_id, atk, speed);
            fprintf(output_file, "%s", output);
        }
    }
    return 0;
}