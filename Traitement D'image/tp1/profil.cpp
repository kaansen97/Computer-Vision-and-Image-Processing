// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille,indice;
  int col=true;
  
  if (argc != 4) 
     {
       printf("Usage: ImageIn.pgm col(true si colonne) Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%d",&col) ;
   sscanf (argv[3],"%d",&indice) ;
     
     if (col != 0 && col !=1) 
     {
       printf("Usage: Col True ou False Seuil \n"); 
       exit (1) ;
     }
   

   OCTET *ImgIn;
   int *OCGRIS;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
	
   //   for (int i=0; i < nTaille; i++)
   // {
   //  if ( ImgIn[i] < S) ImgOut[i]=0; else ImgOut[i]=255;
   //  }
 int n=col==0?nW:nH;
allocation_tableau(OCGRIS, int, n);
FILE* histo=fopen("./profil.dat","w");

 for (int j=0; j < n; j++)
     {
       OCGRIS[j]=ImgIn[indice*n+j];
     }

  for(int i=0;i<n;i++)
  {
          fprintf(histo,"%d %d \n",i,OCGRIS[i]);
  }
fclose(histo);
   return 1;
}

