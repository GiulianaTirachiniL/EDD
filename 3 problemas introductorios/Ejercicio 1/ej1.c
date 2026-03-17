#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Este código tiene 4 errores */
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
