// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;
  
  if (argc != 3) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   OCTET *ImgIn, *ImgOut,*TabB,*TabG,*TabR,*Rf,*Bf,*Vf;
   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille*3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille*3);
   
   allocation_tableau(TabR, OCTET, nTaille);
   allocation_tableau(TabG, OCTET, nTaille);	
   allocation_tableau(TabB, OCTET, nTaille);
    
   allocation_tableau(Rf, OCTET, nTaille);
   allocation_tableau(Bf, OCTET, nTaille);	
   allocation_tableau(Vf, OCTET, nTaille);

   for (int i=0; i < nTaille; i++)
    ImgOut[i]= ImgIn[i];
planR(TabR,ImgIn,nTaille);
planV(TabG,ImgIn,nTaille);
planB(TabB,ImgIn,nTaille);

for (int i=0;i<nTaille;i++)
{
    Rf[i]=TabR[i];
    Vf[i]=TabG[i];
    Bf[i]=TabB[i];
}
/*
 for (int ir=1; ir < nH-1; i+3)
   for (int jr=1; jr < nW-1; j+3)
     {
		int som=ImgIn[(ir-1)*nW+jr-1]+ImgIn[(ir-1)*nW+jr]+ImgIn[(ir-1)*nW+jr+1]+ImgIn[ir*nW+jr-1]+ImgIn[ir*nW+jr]+ImgIn[ir*nW+jr+1]+ImgIn[(ir+1)*nW+jr-1]+ImgIn[(ir+1)*nW+jr]+ImgIn[(ir+1)*nW+jr+1];
		
       ImgOut[ir*nW+jr]=som/9;
     }
*/
     for (int i=1; i < nH-1; i++)
   for (int j=1; j < nW-1; j++)
     {
		int som=TabR[(i-1)*nW+j-1]+TabR[(i-1)*nW+j]+TabR[(i-1)*nW+j+1]+TabR[i*nW+j-1]+TabR[i*nW+j]+TabR[i*nW+j+1]+TabR[(i+1)*nW+j-1]+TabR[(i+1)*nW+j]+TabR[(i+1)*nW+j+1];
		
       Rf[i*nW+j]=som/9;

	int som2=TabG[(i-1)*nW+j-1]+TabG[(i-1)*nW+j]+TabG[(i-1)*nW+j+1]+TabG[i*nW+j-1]+TabG[i*nW+j]+TabG[i*nW+j+1]+TabG[(i+1)*nW+j-1]+TabG[(i+1)*nW+j]+TabG[(i+1)*nW+j+1];
        Vf[i*nW+j]=som2/9;
    
	int som3=TabB[(i-1)*nW+j-1]+TabB[(i-1)*nW+j]+TabB[(i-1)*nW+j+1]+TabB[i*nW+j-1]+TabB[i*nW+j]+TabG[i*nW+j+1]+TabB[(i+1)*nW+j-1]+TabB[(i+1)*nW+j]+TabB[(i+1)*nW+j+1];
        Bf[i*nW+j]=som3/9;

     }
     for(int i=0;i<nTaille;i++)
     {
         ImgOut[3*i]=Rf[i];
         ImgOut[3*i+1]=Vf[i];
         ImgOut[3*i+2]=Bf[i];
     }


   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut); free(Rf);free(Bf);free(Vf);free(TabR);free(TabG);free(TabB);

   return 1;
}

