#include <stdio.h>
#include <stdlib.h>

struct ListJednK {
    int fb;
    int szereg;
    struct ListJednK* nastepny;
    int indeks;
};

int main() {
    int i;
    int il;
    printf("Podaj liczbę elementów, którą chcesz zobaczyć:: ");
    scanf("%d", &il);

    if (il <= 0) {
        printf("Liczba musi być większa od zera!.\n");
        return -1;
    }

    struct ListJednK* poczatek = NULL;
    struct ListJednK* koniec = NULL;

    int a, b;
    a = 0;
    b = 1;

    for (i = 0; i < il; i++)
    {
        struct ListJednK* nowy = (struct ListJednK*)malloc(sizeof(struct ListJednK));

        if (i == 0)
        {
            nowy->fb = 0;
        }
        else if (i == 1)
        {
            nowy->fb = 1;
        }
        else
        {
            int temp = a + b;
            a = b;
            b = temp;
            nowy->fb = temp;
        };

        int suma;
        suma = 0;
        int j;
        for (j = 1; j <= i + 1; j++)
        {
            if (j % 2 == 0)
                suma -= j;
            else
                suma += j;
        };

        nowy->szereg = suma;
        nowy->indeks = i;
        nowy->nastepny = NULL;

        if (poczatek == NULL)
        {
            poczatek = nowy;
            koniec = nowy;
        }
        else
        {
            koniec->nastepny = nowy;
            koniec = nowy;
        }
    };

    printf("\nLista przed usunięciem nieparzystych indeksów:\n");
    struct ListJednK* wsk = poczatek;
    while (wsk)
    {
        printf("Element %d: w ciągu Fibonacciego: = %d, w szeregu: = %d\n", wsk->indeks, wsk->fb, wsk->szereg);
        wsk = wsk->nastepny;
    };

    struct ListJednK* poprzedni = NULL;
    wsk = poczatek;
    int indeks = 0;
    while (wsk)
    {
        struct ListJednK* kolejny = wsk->nastepny;
        if (indeks % 2 == 1)
        {
            if (poprzedni)
            {
                poprzedni->nastepny = kolejny;
            }

            free(wsk);
        }
        else
        {
            poprzedni = wsk;
        };
        wsk = kolejny;
        indeks++;
    }

    printf("\nLista po usunięciu nieparzystych indeksów:\n");
    wsk = poczatek;
    while (wsk)
    {
        printf("Element %d: w ciągu Fibonacciego: = %d, w szeregu: = %d\n", wsk->indeks, wsk->fb, wsk->szereg);
        wsk = wsk->nastepny;
    }

    wsk = poczatek;
    while (wsk)
    {
        struct ListJednK* doSkasowania = wsk;
        wsk = wsk->nastepny;
        free(doSkasowania);
    }

    return 0;
}
