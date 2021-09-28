#include "../commun.h"
#include "hdbn.h"

/*cette fonction va retourner la taille du signal donné en parametre*/
int taille_signal(int signal)
{
    int cpt = 0;
    while(signal != 0)
    {
        signal >>= 1;
        cpt ++;
    }
    return cpt;
}

/*cette fonction réalise l'algorithme de hbn et renvoie un entier qui correspond à une combinaison 
cf : td1 codage de l'information*/
int algo_hdbn(int pol_viol, int pol_1, int n)
{
    /*pol_viol correspond à la polarité du dernier viol*/
    if(pol_viol == 1)
    {
        /*pol_1 correspond à la polarité du dernier bit à 1*/
        if(pol_1 == 1)
            return 1;
        else
            return 2;
    }
    else
    {
        if(pol_1 == 1)
            return 3;
        else
            return 4;
    }
}

/*cette fonction traduit l'entier reçu dans combi par une suite de 0 et de 1 
combi est soit 1, 2, 3, 4 (la valeur obtenue par la fonction algo_hdbn*/
int trad_hdbn(int combi, int n)
{
    int val_result;
    switch(combi)
    {
        case 1: 
            val_result += 1;
            while(n>2)
            {
                val_result <<= 1;
            }
            val_result += 1;

            break;
        case 2:
            val_result += 1;
            while(n>2)
            {
                val_result >>= 1;
            }
            val_result >>= 1;

            break;
        case 3:
            val_result += 1;
            while(n>2)
            {
                val_result >>= 1;
            }
            val_result >>= 1;

            break;
        case 4:
            val_result += 1;
            while(n>2)
            {
                val_result <<= 1;
            }
            val_result += 1;

            break;
        default : break;
    }

    return val_result;
}

/*le signal correspond à la suite de 0 et de 1 
n est la valeurs autoriser pour une suite de 0*/
int codage_hdbn(int signal, int n)
{
    int pol_viol = POLARITE;
    int pol_1 = 1;
    int signal_fin;
    int val_bit;
    int combinaison;

    int taille = taille_signal(signal);
    int masque = taille-1;

    int cpt_0 = 0;
    int i;

    for(i=0; i<taille; i++)
    {
        val_bit = signal & (int)pow(2, masque);

        if (val_bit == 1)
        {
            signal_fin <<= 1+cpt_0;
            signal_fin += 1;
        }
        else
            cpt_0 ++;
        
        //signal_fin += 1;
        
        if(cpt_0 > n)
        {
            combinaison = algo_hdbn(pol_viol, pol_1, n);
            if(combinaison <= 2)
            {
                pol_1 = -1;
                signal_fin <<= cpt_0;
                signal_fin += trad_hdbn(combinaison, n);
            }
            else
            {
                pol_1 = 1;
                signal_fin <<= cpt_0;
                signal_fin += trad_hdbn(combinaison, n);
            }
            pol_viol *= -1;          
        }
    }
    return signal_fin;
}