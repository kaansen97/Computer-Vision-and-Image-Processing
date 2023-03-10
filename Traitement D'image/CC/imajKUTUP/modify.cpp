// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille,k;
  
  if (argc != 4) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm nombre k pour luminosit√© \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   sscanf (argv[3],"%d",&k);
   

   OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);


int pixel;
 for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++)
     {
       if (((i-1>0)&&(i+1<nH))||((j-1>0)&& (j+1<nW)) ){

           pixel=0;
           pixel=ImgIn[i*nW+j]+k;
           if(pixel>255){
               ImgOut[i*nW+j]=255;
           }
           else if ( pixel <0){
               ImgOut[i*nW+j]=0;
           }
           else{
               ImgOut[i*nW+j]=pixel;
           }

           
       }
     }
 }
        
     

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
}