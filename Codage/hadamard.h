#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void HadamardCreer(int n, int had[(int) pow(2,n)][(int) pow(2,n)]);
void HadamardAfficher(int n,int had[(int) pow(2,n)][(int) pow(2,n)]);
int HadamardEtalement(int signal,int taille_signal,int indice_etal,int n, int had[(int) pow(2,n)][(int) pow(2,n)]);