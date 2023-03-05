// test_couleur.cpp : Seuille une image en niveau de gris

// seuillage 2 partie 
/*
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille, S1,S2;
  
  if (argc != 5) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   sscanf (argv[3],"%d",&S1);
   sscanf (argv[4],"%d",&S2);

    if (S1>S2){
        exit(1);
    }

   OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);
	
   //   for (int i=0; i < nTaille; i++)
   // {
   //  if ( ImgIn[i] < S) ImgOut[i]=0; else ImgOut[i]=255;
   //  }


 for (int i=0; i < nH; i++)
   for (int j=0; j < nW; j++)
     {
       if ( ImgIn[i*nW+j] < S1) 
       ImgOut[i*nW+j]=0; 
       else if ( ImgIn[i*nW+j] < S2)
       ImgOut[i*nW+j]=128;
       else
       ImgOut[i*nW+j]=128;
     }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
}
*/

//seuillage 3 partie

// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille, S1,S2,S3;
  
  if (argc != 6) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   sscanf (argv[3],"%d",&S1);
   sscanf (argv[4],"%d",&S2);
   sscanf (argv[5],"%d",&S3);


    if (S1>S2 && S2>S3){
        exit(1);
    }

   OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);

 for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++)
     {
       if ( ImgIn[i*nW+j] < S1) 
       ImgOut[i*nW+j]=0; 
       else if ( ImgIn[i*nW+j] < S2)
       ImgOut[i*nW+j]=(S1+S2)/2;
       else if  ( ImgIn[i*nW+j] < S3)
       ImgOut[i*nW+j]=(S3+S2)/2;
       else
       ImgOut[i*nW+j]=(255);
     }
 }
   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
}
