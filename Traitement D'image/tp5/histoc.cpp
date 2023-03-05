// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille;
  
  if (argc != 2) 
     {
       printf("Usage: ImageIn.ppm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;


   OCTET *ImgIn;
   int *OCROUGE;
   int *OCGREEN;
   int *OCBLEU;
   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
	

allocation_tableau(OCROUGE, int, 256);
allocation_tableau(OCGREEN, int, 256);
allocation_tableau(OCBLEU, int, 256);

FILE* histo=fopen("./histoc.dat","w");

 for (int i=0; i < nH; i++)
   for (int j=0; j < nW; j++)
     {
       OCROUGE[ImgIn[i*nW+j]]+=1;
       OCGREEN[ImgIn[i+1*nW+j]]+=1;
       OCBLEU[ImgIn[i+2*nW+j]]+=1;
     }

  for(int i=0;i<256;i++)
  {
          fprintf(histo,"%d %d %d %d \n",i,OCROUGE[i],OCGREEN[i],OCBLEU[i]);
          
  }
    fclose(histo);
    free(ImgIn); 
    free(OCROUGE);
    free(OCGREEN);
    free(OCBLEU);

   return 1;
}

