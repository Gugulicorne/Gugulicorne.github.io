#include <stdio.h>
#include <stdlib.h>
#include "hadamard.h"


#define TAILLE_HAD 3
int main(){

    int puiss = pown(2,TAILLE_HAD);
    
    int* had[puiss];

    printf("Coucou je suis là :D");
    HadamardCreer(TAILLE_HAD,had);
    printf("Heeeeeeeeeey je suis passé ! :D");
    HadamardAfficher(TAILLE_HAD,had);

}