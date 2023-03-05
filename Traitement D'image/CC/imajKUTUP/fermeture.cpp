// test_couleur.cpp : Seuille une image en niveau de gris

//dilatation
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;
  
  if (argc != 3) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   

   OCTET *ImgIn, *ImgOut,*ImgOut2;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);
   allocation_tableau(ImgOut2, OCTET, nTaille);

	
//dilatation :P

 for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++)
     {
         ImgOut[i*nW+j]=255;
         for (int ip=i-1; ip < i+1; ip++)
            for (int jp=j-1; jp < j+1; jp++){
            if( ip<0|| ip>=nH || jp <0 || jp>= nH){
                continue;
            }else{
                if ( ImgIn[ip*nW+jp]==0){
                    ImgOut[i*nW+j]=0;
                }
            }
                
     }
     }
 }
//erosion  
for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++)
     {
         for (int ip=i-1; ip < i+1; ip++)
            for (int jp=j-1; jp < j+1; jp++){
            if( ip<0|| ip>=nH || jp <0 || jp>= nH){
                continue;
            }else{
                if ( ImgOut[ip*nW+jp]==255){
                    ImgOut2[i*nW+j]=255;
                }
                }
        }
     }
}

     
   ecrire_image_pgm(cNomImgEcrite, ImgOut2,  nH, nW);
   free(ImgIn); free(ImgOut); free(ImgOut2);

   return 1;
}
