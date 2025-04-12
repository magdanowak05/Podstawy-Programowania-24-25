#include <stdio.h>
#include <math.h>

int main() {
    int tablica[10];
    int i;
    double suma = 0;
    long double iloczyn = 1.0; 
/* te liczby mogą być duże i przy mnożeniu przekroczą zakres integera, a nawet samego double'a; przy dodawaniu też mogą -
- wtedy będzie źle obliczane (w przypadku podanych liczb pokazywało, że w tablicy jest 0 lub liczba ujemna,
chociaż tego nie było)
*/
    for (i = 0; i < 10; i++) // indeksy od 0 do 9
    {
        suma += tablica[i];
        iloczyn *= tablica[i];
    }

    double sredniaArytmetyczna = suma / 10;
    double sredniaGeometryczna = pow(iloczyn, 1.0 / 10.0);
    
    if(iloczyn == 0 || iloczyn<0)
    {
        printf("Średnia arytmetyczna wynosi: %.2f\n", sredniaArytmetyczna);
        printf("Nie można obliczyć średniej geometrycznej - w tablicy jest element 0/iloczyn jest ujemny");
    }
    else
    {
        printf("Średnia arytmetyczna wynosi: %.2f\n", sredniaArytmetyczna);
        printf("Średnia geometryczna wynosi: %.2f\n", sredniaGeometryczna);
    }
    return 0;
}
/* przy podanych wartościach działa bardzo dobrze. przy przypadkowych wartościach liczby są bardzo duże, nie mieszczą się
przy mnożeniu w long double'u, dlatego pokazuje komunikat o niemożności wyliczenia średniej geometrycznej
*/