// test_couleur.cpp : Seuille une image couleur 

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLueY[250], cNomImgEcrite[250],cNomImgLueCb[250],cNomImgLueCr[250];
  int nH, nW, nTaille, nR, nG, nB;
  
  if (argc != 5) 
     {
      printf("Usage: ImgY.pgm ImgCb.pgm ImgCr.pgm ImgOut.ppm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLueY) ;
   sscanf (argv[2],"%s",cNomImgLueCb);
   sscanf (argv[3],"%s",cNomImgLueCr);
   sscanf (argv[4],"%s",cNomImgEcrite);
   


  

   OCTET *ImgInY, *ImgOut,*ImgInCb,*ImgInCr;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLueY, &nH, &nW);
   nTaille = nH * nW;
  
   int nTaille3 = nTaille * 3;
   allocation_tableau(ImgInY, OCTET, nTaille);
   allocation_tableau(ImgInCb, OCTET, nTaille);
   allocation_tableau(ImgInCr, OCTET, nTaille);

   lire_image_pgm(cNomImgLueY, ImgInY, nH * nW);
   lire_image_pgm(cNomImgLueCb, ImgInCb, nH * nW);
   lire_image_pgm(cNomImgLueCr, ImgInCr, nH * nW);

   allocation_tableau(ImgOut, OCTET, nTaille3);
  

	int k=0;
   for (int i=0; i < nTaille; i++)
     {
         
         
       nR = ImgInY[i];
       nG = ImgInCb[i];
       nB = ImgInCr[i];
       float Y=nR +(1.402*(nB-128));
       float Cb=nR-(0.34414*(nG-128))-(0.71414*(nB-128));
       float Cr=nR+(1.772*(nG-128));


       ImgOut[k]=Y;
       ImgOut[k+1]=Cb;
       ImgOut[k+2]=Cr;
       if(Y>255){
           ImgOut[k]=255;
       }
       else if (Y<0){
           ImgOut[k]=0;
       }
       if(Cb>255){
           ImgOut[k+1]=255;
       }
       else if (Cb<0){
           ImgOut[k+1]=0;
       }
       if(Cr>255){
           ImgOut[k+2]=255;
       }
       else if (Cr<0){
           ImgOut[k+2]=0;
       }

    
       k=k+3;
       
     }
     
/*
       ImgOut[k]=nR>255?255:nR<0?0:nR;  RGB
       ImgOut[k+1]=nG>255?255:nG<0?0:nG;
       ImgOut[k+2]=nB>255?255:nB<0?0:nB;
       k=k+3;
*/

   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);


   free(ImgInY);free(ImgInCb);free(ImgInCr);
   return 1;
}
