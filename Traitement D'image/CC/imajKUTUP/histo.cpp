// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille;
  
  if (argc != 2) 
     {
       printf("Usage: ImageIn.pgm   \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;

   

   OCTET *ImgIn;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  int *OCC;
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(OCC, int, 255);
  
	
FILE* histo=fopen("./histo.dat","w");
 for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++)
     {
        OCC[ImgIn[i*nW+j]]+=1; 
     }

    for(int i=0;i<256;i++){
        {
            fprintf(histo,"%d %d\n",i,OCC[i]);
        }
    }
 }
fclose(histo);
   //ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   //free(ImgIn); free(ImgOut);

   return 1;
}
