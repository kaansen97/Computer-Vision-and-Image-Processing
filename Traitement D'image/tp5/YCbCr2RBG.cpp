
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLueY[250],  cNomImgLueCr[250],cNomImgLueCb[250], cNomImgEcrite[250];
  int nH, nW, nTaille, Y, Cb, Cr;
  
  if (argc != 5) 
     {
       printf("Usage: ImageY.ppm ImageCb.ppm ImageCr.ppm ImageSortie.ppm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLueY) ;
   sscanf (argv[2],"%s",cNomImgLueCb);
   sscanf (argv[3],"%s",cNomImgLueCr);
   sscanf (argv[4],"%s",cNomImgEcrite);


   OCTET *ImgInY, *ImgOut,*ImgInCr,*ImgInCb;
   
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
       Y = ImgInY[i];
       Cb = ImgInCb[i];
       Cr = ImgInCr[i];

       float nR=Y+(1.402*(Cr-128));
       float nG=Y-(0.34414*(Cb-128))-(0.71414*(Cr-128));
       float nB=Y+(1.772*(Cb-128));

       ImgOut[k]=nR>255?255:nR<0?0:nR;
       ImgOut[k+2]=nG>255?255:nG<0?0:nG;
       ImgOut[k+1]=nB>255?255:nB<0?0:nB;
       k=k+3;
     }

   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgInY);free(ImgInCb);free(ImgInCr);
   return 1;
}