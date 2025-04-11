/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
int main()
{
    int typLiczby;
    printf("Liczby mają być całkowite (1) czy zmiennoprzecinkowe (2)?: ");
    scanf("%d", &typLiczby);
    if(typLiczby == 1)
    {
        int x;
        int y;
        printf("Podaj liczbę X: ");
        scanf("%d", &x);
        printf("Podaj liczbę Y: ");
        scanf("%d", &y);
        if (x%y==0)
        {
            printf("Liczba %d dzieli się przez liczbę %d", x, y);
        }
        else
        {
            printf("Liczba %d nie dzieli się przez liczbę %d", x, y);
        }
    }
    else
    {
        float x;
        float y;
        printf("Podaj liczbę X: ");
        scanf("%f", &x);
        printf("Podaj liczbę Y: ");
        scanf("%f", &y);
        printf("Liczby zostały zaokrąglone do dwóch miejsc po przecinku.\n");
        if (fmod(x, y) == 0)
        {
            printf("Liczba %.2f dzieli się przez liczbę %.2f", x, y);
        }
        else
        {
            printf("Liczba %.2f nie dzieli się przez liczbę %.2f", x, y);
        }
    }
}