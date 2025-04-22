#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int x;
    printf("Podaj nieujemną liczbę całkowitą: ");
    scanf("%d", &x); //wczytujemy wartość x do programu

    if (x < 0)
    {
        printf("Wpisana liczba ujemna.\n");
        return -1; //return -1 zwraca to, że program należy przerwać, nie można użyć break, bo nie jest to pętla for/while
    }

    int *tab1 = (int*) malloc(x * sizeof(int));
    int *tab2 = (int*) malloc(x * sizeof(int));
    printf("Alokacja miejsca na tablice 1 oraz 2.\n"); //alokowanie miejsca na tablice - rozmiar w bajtach*liczba int podana do konsoli

    if (tab1 == NULL || tab2 == NULL)
    {
        printf("Niepoprawna alokacja.\n");
        return -1; //w przypadku błędu alokacji - również zwrócenie, żeby przerwano program
    }
//tworzenie tablic
    for (i = 0; i < x; i++)
    {
        *(tab1 + i) = i * 10;
    }

    for (i = 0; i < x; i++)
    {
        *(tab2 + i) = *(tab1 + (x - 1 - i)); //odwrócenie kolejności liczb z tablicy 1
    }
//wyświetlanie tablic
    printf("Tablica 1:\n");
    for (i = 0; i < x; i++)
    {
        printf("%d ", *(tab1 + i));
    }

    printf("\nTablica 2:\n");
    for (i = 0; i < x; i++)
    {
        printf("%d ", *(tab2 + i));
    }

//uwalnianie pamięci
    free(tab1);
    free(tab2);
    printf("\nUwalniam miejsce.");
    return 0;
}

