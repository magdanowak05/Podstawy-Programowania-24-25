#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x;
    int rozmiarINT;
    rozmiarINT = sizeof(int);
    printf("Podaj x (nieujemna liczba calkowita/integer): ");
    scanf("%d", &x);

    if (x < rozmiarINT) {
        printf("Brak miejsca na minimum jeden element integer.\n");
        return -1; //zwraca -1, co oznacza, ze program nalezy przerwac (nie mozna uzyc break, bo nie jest to petla for/while
    }

    // Alokacja x bajtów - dane zebrane w obszarach pamieci
    int *obsz1 = (int*) malloc(x);
    int *obsz2 = (int*) malloc(x);

    if (obsz1 == NULL || obsz2 == NULL) {
        printf("Niepoprawna alokacja.\n");
        return -1;
    }

    int n;
    n = x / sizeof(int); // liczba integerów, które sie mieszcza w x bajtach
    printf("Alokowano miejsce na %d element/y/ow typu integer.\n", n);

    // Wypelnianie obszaru 1 kolejnymi potegami liczby 2 (lacznie i poteg)
    for (int i = 0; i < n; i++) {
        *(obsz1 + i) = (long double)pow(2, i);
    }

    // Obszar 2, czyli obszar 1 w odwrotnej kolejnosci
    for (int i = 0; i < n; i++) {
        *(obsz2 + i) = *(obsz1 + (n - 1 - i));
    }

    // Wyœwietlanie tego, co znajduje sie w obu obszarach pamieci
    printf("Obszar 1:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(obsz1 + i));
    }

    printf("\nObszar 2:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(obsz2 + i));
    }

    // Zwolnienie pamiêci
    free(obsz1);
    free(obsz2);
    printf("\nUwalniam miejsce.\n");

    return 0;
}

