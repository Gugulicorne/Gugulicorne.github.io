#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hadamard.h"

#define TAILLE_SIGNAL 3
int main(){
    //Demande a l'utilisateur le nombre d'utilisateur
    int max_user;
    printf("Bienvenue :\n\nVeuillez choisir le nombre d'utilisateur maximum (1, 2, 4, 8, 16):\n");
    do{
        scanf("%i",&max_user);
        if(max_user != 1 && max_user != 2 && max_user != 4 && max_user != 8 && max_user != 16)
            printf("Veuillez reessayer\n");
    }while(max_user != 1 && max_user != 2 && max_user != 4 && max_user != 8 && max_user != 16);

    //Creer une matrice d'hadamard pour correspondre au nombre max d'utilisateur
    int taille_had = (int) log2(max_user);
    int puiss = pown(2,taille_had);
    int* had[puiss];
    HadamardCreer(taille_had,had);
    HadamardAfficher(taille_had,had);

    int ind_s = 0;
    int signal[TAILLE_SIGNAL];
    int signal2[TAILLE_SIGNAL];
    int bit;

    //Creation d'un 1er signal 
    printf("Veuillez écrire un signal composé de 0 et de 1 (Ecrire les 0 et les 1 séparés par la touche ENTREE) :\n");
    do{
        scanf("%i",&bit);
        if(bit == 0 || bit == 1){
            signal[ind_s] = bit;
            ind_s++;
        }
        else printf("Veuillez entrer un nombre compris entre 0 et 1\n");

    }while(ind_s < TAILLE_SIGNAL);
    int signal_etale[TAILLE_SIGNAL*max_user];

    //Etalament sur un numero d'utilisateur qui correspond a un ligne dans la matrice d'hadamard
    int num_user;
    printf("Veuillez entrer le numero de l'utilisateur (Compris entre 0 et %i) | RAPPEL : Le nombre d'usager maximum est de %i\n",max_user - 1, max_user);
    do{
        scanf("%i",&num_user);
        if(num_user < 0 || num_user >= max_user)
            printf("Veuillez reesayer \n");

    }while(num_user < 0 || num_user >= max_user);

    HadamardEtalement(signal, TAILLE_SIGNAL, signal_etale, num_user,taille_had, had);
    //Affichage de l'étalement du signal n° 1
    printf("\n Voici le premier signal etale : \n");
    for(int i = 0; i < TAILLE_SIGNAL * max_user ; i++){

        printf("%i ",signal_etale[i]);
        if((i+1)%max_user == 0 ) printf("   |   ");

    }
//------------------------------------------------------------------------------------------------------------------------

    //Creation d'un 2eme signal 
    printf("Veuillez écrire un signal composé de 0 et de 1 (Ecrire les 0 et les 1 séparés par la touche ENTREE) :\n");
    ind_s = 0;
    do{
        scanf("%i",&bit);
        if(bit == 0 || bit == 1){
            signal2[ind_s] = bit;
            ind_s++;
        }
        else printf("Veuillez entrer un nombre compris entre 0 et 1\n");

    }while(ind_s < TAILLE_SIGNAL);
    int signal_etale2[TAILLE_SIGNAL*max_user];

    //Etalament sur un numero d'utilisateur qui correspond a un ligne dans la matrice d'hadamard
    int num_user2;
    //Ici je ne vérifie pas le nouveau utilisateur a la même numero que l'ancien
    printf("Veuillez entrer le numero de l'utilisateur (Compris entre 0 et %i) | RAPPEL : Le nombre d'usager maximum est de %i\n",max_user - 1, max_user);
    do{
        scanf("%i",&num_user2);
        if(num_user2 < 0 || num_user2 >= max_user)
            printf("Veuillez reesayer \n");

    }while(num_user2 < 0 || num_user2 >= max_user);

    HadamardEtalement(signal2, TAILLE_SIGNAL, signal_etale2, num_user2,taille_had, had);
    //Affichage de l'étalement du signal n° 2
    printf("\n Voici le deuxième signal etale : \n");
    for(int i = 0; i < TAILLE_SIGNAL * max_user ; i++){

        printf("%i ",signal_etale2[i]);
        if((i+1)%max_user == 0 ) printf("   |   ");

    }

    //On créé un signal combiné qui est l'addition des deux précédents
    printf("\n\nMaintenant additionnons les deux signaux pour essayer de les retrouver\n\n");
    int signal_comb[TAILLE_SIGNAL * max_user];
    for(int i = 0; i < TAILLE_SIGNAL * max_user; i++){

        signal_comb[i] = signal_etale[i] + signal_etale2[i];

    }
    printf("Voici a quoi ressemble le signal combiné : \n");
    for(int i = 0; i < TAILLE_SIGNAL * max_user ; i++){

        printf("%i ",signal_comb[i]);
        if((i+1)%max_user == 0 ) printf("   |   ");

    }
    
}