#include <stdio.h>

typedef struct magemite{
    int magemite_id; 
    int atk;
    int speed;
    struct magemite *next; // puntero al siguiente magemite
} Magemite;

typedef struct magezone{
    int magezone_id; // va del 0 al S-1
    int cant_magemites;
    Magemite *first_magemite; // puntero a la cabeza de la lista de magemites
} MageZone;

void Enter(int magezone_id, int magemite_id, int atk, int speed);
