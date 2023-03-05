// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250];
  int nH, nW, nTaille,indice;
  int col=true;
  
  if (argc != 4) 
     {
       printf("Usage: ImageIn.pgm (col=0 ou ligne=1) numero \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%d",&col) ;
   sscanf (argv[3],"%d",&indice) ;


   

   OCTET *ImgIn;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  int *OCC;
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(OCC, int, 256);
  
	
FILE* histo=fopen("./profil.dat","w");

if(col==0){
   for (int j=0; j < nH; j++)
     {
        OCC[j]=ImgIn[j*nW+indice]; 
     }

}
else{
for (int i=0; i < nW; i++)
     {
        OCC[i]=ImgIn[indice*nW+i]; 
     }

}

  

    for(int i=0;i<256;i++){
        {
            fprintf(histo,"%d %d\n",i,OCC[i]);
        }
    }


   
   free(ImgIn); 
   free(OCC);

   return 1;
}
