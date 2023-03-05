// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250] ,cImgD[250];
  int nH,/*nH2*/nW /*nW2*/, nTaille/*,nTaille2*/;
  
  if (argc != 4) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cImgD) ;
   sscanf (argv[3],"%s",cNomImgEcrite);


   OCTET *ImgIn,*ImgIn2, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);

   nTaille = nH * nW;

  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgIn2, OCTET, nTaille);
   lire_image_pgm(cImgD, ImgIn2, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);


 for (int i=0; i < nH; i++)
   for (int j=0; j < nW; j++)
     {
       if ( ImgIn[i*nW+j]==ImgIn2[i+nW+j]&&ImgIn2[i+nW+j]==0) {  ImgOut[i*nW+j]=255;}
       else if ( ImgIn[i*nW+j]==ImgIn2[i+nW+j]&&ImgIn2[i+nW+j]==255) {ImgOut[i*nW+j]=255; }
        else ImgOut[i*nW+j]=0;
     }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut); free(ImgIn2);

   return 1;
}

