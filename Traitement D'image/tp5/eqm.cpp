// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"
#include <iostream>
//1 SEUIL
int main(int argc, char* argv[])
{
 char cNomImgS[250],cNomImgD[250];
 int nH, nW, nTaille;
 
 if (argc != 3) 
 {
 printf("Usage: ImagePGM.pgm ImageY.pgm ImageOut.pgm \n"); 
 exit (1) ;
 }
 
 sscanf (argv[1],"%s",cNomImgS) ;
 sscanf (argv[2],"%s",cNomImgD) ;

 

 OCTET *ImgS, *ImgD;
 

 
lire_nb_lignes_colonnes_image_pgm(cNomImgS, &nH, &nW);
 nTaille = nH * nW;

allocation_tableau(ImgS, OCTET, nTaille);
 lire_image_pgm(cNomImgS, ImgS, nH * nW);
 allocation_tableau(ImgD, OCTET, nTaille);
 lire_image_pgm(cNomImgD, ImgD, nH * nW);


float k=0;
 for (int i=0; i < nH; i++)
 for (int j=0; j < nW; j++)
 {
 k=k+((ImgS[i*nW+j]-ImgD[i*nW+j])*(ImgS[i*nW+j]-ImgD[i*nW+j]));
 }
 k=k/nTaille;

 free(ImgS); free(ImgD);
std::cout<<"La valeur EQM :"<<k<<std::endl;
 return 1;
}

