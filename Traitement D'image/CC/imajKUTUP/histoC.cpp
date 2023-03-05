// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille;
  
  if (argc != 2) 
     {
       printf("Usage: ImageIn.pgm  Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   //sscanf (argv[2],"%s",cNomImgEcrite);
   

   OCTET *ImgIn;
   int *OCCR;
   int *OCCG;
   int *OCCB;

   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   int nTaille3 = nTaille*3;

   allocation_tableau(ImgIn, OCTET, nTaille3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(OCCR, int, 255);
   allocation_tableau(OCCG, int, 255);
   allocation_tableau(OCCB, int, 255);

   

  
	
   //   for (int i=0; i < nTaille; i++)
   // {
   //  if ( ImgIn[i] < S) ImgOut[i]=0; else ImgOut[i]=255;
   //  }

//int OCC[255]={0};
FILE* histo=fopen("./histoC.dat","w");
 for (int i=0; i < nTaille3; i+=3){
   
        OCCR[ImgIn[i]]+=1;
        OCCG[ImgIn[i+1]]+=1; 
        OCCB[ImgIn[i+2]]+=1; 

     }

    for(int i=0;i<256;i++){
        {
            fprintf(histo,"%d %d %d %d\n",i,OCCR[i],OCCG[i],OCCB[i]);
        }
    }

    fclose(histo);
   free(ImgIn);
   free(OCCB);
   free(OCCG);
   free(OCCR);


   return 1;
}
