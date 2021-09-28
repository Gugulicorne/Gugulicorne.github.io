#include <stdio.h>

void remplir(int matrice[10][10],int row, int col){

    for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      scanf("%d",&matrice[i][j]);
    }
  }

}

void main()
{
  int matrice[10][10];
  int i, j, row, col;
  
   printf(" Entrez le nombre de lignes (max 10): ");
   scanf("%d",&row);
  printf(" Entrez le nombre de colonne (max 10): ");
  scanf("%d",&col);
  printf(" Entrez les %d éléments de tableau : ",row*col);
  
  remplir(matrice,row,col);
  
  printf(" Le tableau 2D = \n");
  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%4d",matrice[i][j]);
    }
    printf("\n");
  }
}