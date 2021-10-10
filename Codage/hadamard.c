#include <stdio.h>
#include <stdlib.h>
#include "hadamard.h"

int pown(int n, int p){

    int np = n;

    if(p == 0) return 1;
    if(p == 1) return n;
    for(int i = 2; i <= p; i++ ){

        np = np * n; 

    }

    return np;
}

//Initialise une matrice d'hadamard de rang n
void HadamardCreer(int n ,int* tab_h[]){

    int init;
    //On créé les cases de la matrice principale
    for(init = 0; init < pown(2,n); init++){

        tab_h[init] = malloc(sizeof(int) * pown(2,n));

    }

    if(n == 0){
        tab_h[0][0] = 1; //Si n = 0, alors on connait la matrice d'Hadamard
    }
    else{

        //Sinon on récupère la matrice précèdente N-1
        int nmoins1 = pown(2, n-1);
        int* tab_h_avant[nmoins1];
        HadamardCreer(n-1,tab_h_avant);
        //Puis on compose la matrice N

        int i,j;
        int i_max =(int) pown(2,n);
        int j_max =(int) pown(2,n);

        for(i = 0; i < (i_max/2); i++){
            for(j = 0; j < (j_max/2); j++){
                tab_h[i][j]= tab_h_avant[i][j];
            }
            for(j = j_max/2; j < j_max; j++){

                tab_h[i][j]= tab_h_avant[i][j-(j_max)/2];

            }
        }
        for(i = i_max/2; i < i_max; i++){
            for(j = 0; j < (j_max/2); j++){

                tab_h[i][j]= tab_h_avant[i-i_max/2][j];

            }
            //Cas avec le -H(n-1)
            for(j = j_max/2; j < j_max; j++){

                tab_h[i][j]= -(tab_h_avant[i-i_max/2][j-j_max/2]);

            }
        }
        //On libère la mémoire de la matrice de
        for(init = 0; init < pown(2,n-1); init++){

            free(tab_h_avant[init]);    

        }  
    }
}
//Affiche la matrice d'Hadamard pour vérifier
void HadamardAfficher(int n,int* tab_h[]){

    int i_max =pown(2,n);
    int j_max =pown(2,n);

    for(int i = 0; i < i_max; i++){
        for(int j = 0; j<j_max;j++){
            if(tab_h[i][j] == 1)
                printf("%i  | ",tab_h[i][j]);
            else    
                printf("%i | ",tab_h[i][j]);
        }
        printf("\n");
        for(int j = 0; j<j_max; j++)
            printf("-----");
        printf("\n");
    }
}

//Etale le signal de l'utilisateur grace a la ligne dans la matrice d'hadamard qui lui a été donné
void HadamardEtalement(int signal[],int taille_signal, int signal_etale[], int indice_etal,int taille_had, int* tab_h[]){

    int bit;
    int ind;
    int ind_etal = 0;
    int taille_etal = pown(2,taille_had);
    for(int i = 0;i < taille_signal; i++){

        //On récupère le bit tout a droite pour le traiter
        bit = signal[i];

        
        for(ind = 0 ; ind < taille_etal ; ind ++, ind_etal++){

            //Remplissage de l'étalement
            if(bit == 0)
                signal_etale[ind_etal] = -tab_h[indice_etal][ind];
            else    
                signal_etale[ind_etal] = tab_h[indice_etal][ind];

        }
    }
}

