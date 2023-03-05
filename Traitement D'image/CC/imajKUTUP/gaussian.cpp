// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;
  
  if (argc != 3) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm  \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   

   OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);



 for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++)
     {
       if (((i-1>=0)&&(i+1<nH))|| ((j-1>=0)&& (j+1<nW)) ){

            ImgOut[i*nW+j]=(4*ImgIn[i*nW+j]+2*ImgIn[i*nW+(j-1)]+2*ImgIn[i*nW+(j+1)]+2*ImgIn[(i-1)*nW+j]+ImgIn[(i-1)*nW+(j-1)]+
            ImgIn[(i-1)*nW+(j+1)]+2*ImgIn[(i+1)*nW+j]+ImgIn[(i+1)*nW+(j-1)]+ImgIn[(i+1)*nW+(j+1)])/16;

       }
     }
 }
        /*

         |1|2|1|
         |2|4|2| * kendi resmimiz
         |1|2|1|

        */
     

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
}
