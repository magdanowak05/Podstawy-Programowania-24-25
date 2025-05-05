#include <stdio.h>
#include <stdlib.h>
#include "moja.h"


char* mojaFunkcja(char *daneWejsciowe, unsigned int dlugoscDanychWejsciowych, unsigned int *dlugoscDanychWyjsciowych) {
    if (daneWejsciowe == NULL || dlugoscDanychWyjsciowych == NULL || dlugoscDanychWejsciowych == 0)
    {
        return NULL;
    }

    char* wynik = malloc(dlugoscDanychWejsciowych * 2);

    if (wynik == NULL)
    {
        return NULL;
    }
    wynik[0] = 0;
    wynik[1] = 0;
    unsigned int indeksWyniku;
    indeksWyniku = 2;
    unsigned int i;
    for (i = 0; i < dlugoscDanychWejsciowych;)
    {
        char znak = daneWejsciowe[i];
        unsigned int licznik = 1;

        while ((i + licznik < dlugoscDanychWejsciowych) && (daneWejsciowe[i + licznik] == znak) && (licznik < 255))
        {
            licznik++;
        }

        wynik[indeksWyniku++] = licznik;
        wynik[indeksWyniku++] = (char)znak;

        i = i + licznik;

    }

    *dlugoscDanychWyjsciowych = indeksWyniku;
    return wynik;
}

