#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hadamard.h"


#define TAILLE_HAD 3
int main(){

    int puiss = (int) pow(2,TAILLE_HAD);
    
    int had[puiss][puiss];

    HadamardCreer(TAILLE_HAD,had);
    HadamardAfficher(TAILLE_HAD,had);

}