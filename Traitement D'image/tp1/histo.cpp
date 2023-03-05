// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille;
  
  if (argc != 2) 
     {
       printf("Usage: ImageIn.pgm Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;


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

allocation_tableau(OCGRIS, int, 256);
FILE* histo=fopen("./histo.dat","w");

 for (int i=0; i < nH; i++)
   for (int j=0; j < nW; j++)
     {
       OCGRIS[ImgIn[i*nW+j]]+=1;
     }

  for(int i=0;i<256;i++)
  {
          fprintf(histo,"%d %d \n",i,OCGRIS[i]);
  }
fclose(histo);
   return 1;
}

