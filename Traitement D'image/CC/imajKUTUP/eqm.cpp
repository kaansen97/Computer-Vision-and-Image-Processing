// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"
#include <iostream>

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgLue2[250];
  int nH, nW, nTaille;
  
  if (argc != 3) 
     {
       printf("Usage: ImageIn.pgm ImageIn2.pgm ImageOut.pgm  \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgLue2) ;
   


   OCTET *ImgIn,*ImgIn2, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue2, &nH, &nW);

   nTaille = nH * nW;


  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

   allocation_tableau(ImgIn2, OCTET, nTaille);
   lire_image_pgm(cNomImgLue2, ImgIn2, nH * nW);


   allocation_tableau(ImgOut, OCTET, nTaille);
	

float k=0;
 for (int i=0; i < nH; i++){
   for (int j=0; j < nW; j++){
      k= k+((ImgIn[i*nW+j] - ImgIn2[i*nW+j])*(ImgIn[i*nW+j] - ImgIn2[i*nW+j]));
   }
      }

k=k/nTaille; 
 std::cout<<"eqm est "<<k<<std::endl;
     

   free(ImgIn); free(ImgOut);free(ImgIn2);

   return 1;
}
