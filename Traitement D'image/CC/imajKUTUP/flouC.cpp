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
   

   OCTET *ImgIn, *ImgOut ,*TabR, *TabG,*TabB,*FlouR,*FlouG,*FlouB;
   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille*3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille*3);
   allocation_tableau(TabR,OCTET,nTaille);
   allocation_tableau(TabG,OCTET,nTaille);
   allocation_tableau(TabB,OCTET,nTaille);
   allocation_tableau(FlouR,OCTET,nTaille);
   allocation_tableau(FlouG,OCTET,nTaille);
   allocation_tableau(FlouB,OCTET,nTaille);




planR(TabR,ImgIn,nTaille);
planV(TabG,ImgIn,nTaille);
planB(TabB,ImgIn,nTaille);

for(int i=0;i<nTaille;i++){
    FlouR[i]=TabR[i];
    FlouG[i]=TabG[i];
    FlouB[i]=TabB[i];
}



 for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++)
     {
       if (((i-1>=0)&&(i+1<nH))|| ((j-1>=0)&& (j+1<nW)) ){

            FlouR[i*nW+j]=(TabR[i*nW+j]+TabR[i*nW+(j-1)]+TabR[i*nW+(j+1)]+TabR[(i-1)*nW+j]+TabR[(i-1)*nW+(j-1)]+TabR[(i-1)*nW+(j+1)]+TabR[(i+1)*nW+j]+TabR[(i+1)*nW+(j-1)]+TabR[(i+1)*nW+(j+1)])/9;
            FlouG[i*nW+j]=(TabG[i*nW+j]+TabG[i*nW+(j-1)]+TabG[i*nW+(j+1)]+TabG[(i-1)*nW+j]+TabG[(i-1)*nW+(j-1)]+TabG[(i-1)*nW+(j+1)]+TabG[(i+1)*nW+j]+TabG[(i+1)*nW+(j-1)]+TabG[(i+1)*nW+(j+1)])/9;
            FlouB[i*nW+j]=(TabB[i*nW+j]+TabB[i*nW+(j-1)]+TabB[i*nW+(j+1)]+TabB[(i-1)*nW+j]+TabB[(i-1)*nW+(j-1)]+TabB[(i-1)*nW+(j+1)]+TabB[(i+1)*nW+j]+TabB[(i+1)*nW+(j-1)]+TabB[(i+1)*nW+(j+1)])/9;

       }
     }
 }
     for (int i=0;i<nTaille;i++){
         ImgOut[3*i]=FlouR[i];
         ImgOut[3*i+1]=FlouG[i];
         ImgOut[3*i+2]=FlouB[i];

     }
        
     

   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);free(FlouR);free(FlouB);free(FlouG);free(TabR);free(TabG);free(TabB);

   return 1;
}
