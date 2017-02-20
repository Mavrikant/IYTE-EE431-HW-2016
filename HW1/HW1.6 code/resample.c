#include "img_pro.h"

unsigned char **resample_image
  (unsigned char **img, int NC, int NR, int NC2, int NR2)

{
unsigned char **img_out;
int i,j,i_orig,j_orig;
float factor_NC,factor_NR;


factor_NC=(float)NC/NC2;
factor_NR=(float)NR/NR2;

img_out=alloc_img(NC2,NR2);

for(i=0;i<NR2;i++) 
	for(j=0;j<NC2;j++) {
		i_orig=i*factor_NR;
		j_orig=j*factor_NC;
		img_out[i][j]=img[i_orig][j_orig];  /*  Backwards mapping */
	}
		       
return(img_out);
}  
