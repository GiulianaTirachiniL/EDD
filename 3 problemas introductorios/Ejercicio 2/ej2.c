#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* En este código hay 3 errores */
    int a, b;
    scanf("%d %d", &a, &b);
    int i = 1;
    int maximo = 1;
    while (i <= a && i <= b){
        if (a%i==0 && b%i==0){
            maximo = i;
        }
        i++;
    }
    printf("%d", maximo);
    return 0;
}
