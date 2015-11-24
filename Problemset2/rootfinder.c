#include <stdio.h>
#include <math.h>

//int main(void)
//{
//    int* a;
//    printf("%d",*a);
//}

/**
*   Rootfinder-Function
*
*/
double findRoot(double* neMin, double* neMax, double* T, int* itUsed)
{
    double middle = (*neMax + *neMin) / 2;
    double result = 13.37;
    double bufferResult = 0;

    *itUsed = 0;

    if(SAHA_(neMin,T) * SAHA_(neMax,T) < 0)
    {
    // Bedingung: So lange, wie der Abstand des Zwischenergebnis zum vorhergegangen Zwischenergebnis größer als 0.5% des aktuellen
    // Wertes ist:
        while(abs(result - bufferResult) > result * 0.005)
        {
            if(SAHA_(neMin,T) * SAHA_(middle,T) < 0)
            {
                middle = (*neMin + middle) / 2;
            }
            else if(SAHA_(neMin,T) * SAHA_(middle,T) >= 0)
            {
                middle = (middle + *neMax) / 2;
            }

            *itUsed++;
        }
    }
    return result;
}
