// test_couleur.cpp : Seuille une image couleur 

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcriteY[250],cNomImgEcriteCb[250],cNomImgEcriteCr[250];
  int nH, nW, nTaille, nR, nG, nB;
  
  if (argc != 5) 
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcriteY);
   sscanf (argv[3],"%s",cNomImgEcriteCb);
   sscanf (argv[4],"%s",cNomImgEcriteCr);
   


  

   OCTET *ImgIn, *ImgOutY,*ImgOutCb,*ImgOutCr;
   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   int nTaille3 = nTaille * 3;
   allocation_tableau(ImgIn, OCTET, nTaille3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOutY, OCTET, nTaille);
   allocation_tableau(ImgOutCb, OCTET, nTaille);
   allocation_tableau(ImgOutCr, OCTET, nTaille);

	int k=0;
   for (int i=0; i < nTaille3; i+=3)
     {
         
         
       nR = ImgIn[i];
       nG = ImgIn[i+1];
       nB = ImgIn[i+2];
       ImgOutY[k]=nR*0.299+nG*0.587+nB*0.114;
       ImgOutCb[k]=-nR*0.168736-nG*0.331264+nB*0.5+128;
       ImgOutCr[k]=nR*0.5-nG*0.418688-nB*0.081312+128;
       k++;
       
     }
     

   ecrire_image_pgm(cNomImgEcriteY, ImgOutY,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteCb, ImgOutCb,  nH, nW);
   ecrire_image_pgm(cNomImgEcriteCr, ImgOutCr,  nH, nW);

   free(ImgIn);
   return 1;
}