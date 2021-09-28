#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hadamard.h"

//Initialise une matrice d'hadamard de rang n
void HadamardCreer(int n ,int tab_h[(int) pow(2,n)][(int) pow(2,n)]){

    if(n == 0)
        tab_h[0][0] = 1; //Si n = 1, alors on connait la matrice d'Hadamard
    else{

        //Sinon on récupère la matrice précèdente N-1
        int tab_h_avant[(int) pow(2,n-1)][(int) pow(2,n-1)];
        HadamardCreer(n-1,tab_h_avant);

        //Puis on compose la matrice N

        int i,j;
        int i_max =(int) pow(2,n);
        int j_max =(int) pow(2,n);

        for(i = 0; i < (i_max/2); i++){
            for(j = 0; i < (j_max/2); j++){

                tab_h[i][j]= tab_h_avant[i][j];

            }
            for(j = j_max/2; i < j_max; j++){

                tab_h[i][j]= tab_h_avant[i][j-(j_max)/2];

            }
        }
        for(i = i_max/2; i < i_max; i++){
            for(j = 0; i < (j_max/2); j++){

                tab_h[i][j]= tab_h_avant[i-i_max/2][j];

            }
            //Cas avec le -H(n-1)
            for(j = j_max/2; i < j_max; j++){

                tab_h[i][j]= -(tab_h_avant[i-i_max/2][j-j_max/2]);

            }
        }  
    }
}
//Affiche la matrice d'Hadamard pour vérifier
void HadamardAfficher(int n,int tab_h[(int) pow(2,n)][(int) pow(2,n)]){

    int i_max =(int) pow(2,n);
    int j_max =(int) pow(2,n);

    for(int i = 0; i < i_max; i++){
        for(int j = 0; j<j_max;j++){
            printf("%i ",tab_h[i][j]);
        }
        printf("\n");
    }
}

//Etale le signal de l'utilisateur grace a la ligne dans la matrice d'hadamard qui lui a été donné
int HadamardEtalement(int signal,int taille_signal,int indice_etal,int n, int tab_h[(int) pow(2,n)][(int) pow(2,n)]){

    int bit;
    int ind;
    int decalage = (int) pow(2,n);
    int taille_s_etal = taille_signal * decalage;
    int signal_etale[taille_s_etal];

    for(int i = 0;i < taille_signal; i++){

        //On récupère le bit tout a droite pour le traiter
        bit = signal & 1;
        signal >>= 1;

        //On part de la fin du tableau pour remplir dans l'ordre, mais on garde la taille d'une ligne
        //d'une matrice d'Hadamard de taille n pour pouvoir remplir les cases.
        //Puis on va décaler a chaque fois de cette taille en arrière.
        for(ind = taille_s_etal - decalage * (1 + i); ind < taille_s_etal - decalage * i; ind ++){

            //Remplissage de l'étalement
            if(bit = 0)
                signal_etale[ind] = -tab_h[indice_etal][ind];
            else    
                signal_etale[ind] = tab_h[indice_etal][ind];

        }
    }
}

