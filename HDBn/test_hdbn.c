#include "../commun.h"
#include "hdbn.h"

int main ()
{
    int signal;
    int signal_fin;
    int n;
    printf("TEST du codage hdbn\nSaisir un signal de 0 et de 1 : ");
    scanf("%i", &signal);
    printf("Saisir la valeur de n : ");
    scanf("%i", &n);
    printf("\nLe signal saisi est : %i\n", signal);
    printf("\n\nTRAITEMENT ...");
    signal_fin = codage_hdbn(signal, n);
    printf("\n\nLe signal de fin est : %i\n", signal_fin);

    return 0;
}