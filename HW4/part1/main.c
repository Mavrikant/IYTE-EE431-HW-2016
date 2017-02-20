// Homework sent by
// Serhat Çillidağ - 200206001
// M. Serdar Karaman - 190206038

/*
To compile type:
gcc -o tilt_shiftA main.c img_pro.c -lm
or just write make if you have UNIX Makefiles
*/

#include "my_header.h"

void usage()
{
    printf("Usage: ./tilt_shiftA [row number K] [distance d] [.pgm file]");
}

void image_copy(color **img_old, color **img_new, int NC, int NR)
{
    for (int i=0; i<NR; i++)
        for (int j=0; j<NC; j++)
            img_old[i][j] = img_new[i][j];
}

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        usage();
        exit(-1);
    }

    int i, j, NR, NC, row_number, distance, iteration;
    char *ppm_file;
    char new_file_name [64];
    color **img_old;
    color **img_new;
    row_number = atoi(argv[1]);
    distance = atoi(argv[2]);
    ppm_file = argv[3];

    img_old = (color **)ppm_file_to_img(ppm_file, &NC, &NR);
    img_new = (color **)ppm_file_to_img(ppm_file, &NC, &NR);

    iteration=1;
    while(row_number-distance*iteration>0 || row_number+distance*iteration<NR){
        for (j=0; j<NC; j++){
			for (i=2; i<row_number-distance*iteration; i++){
				img_new[i][j].r = (1*img_old[i-2][j].r + 4*img_old[i-1][j].r + 6*img_old[i][j].r + 4*img_old[i+1][j].r + 1*img_old[i+2][j].r)/16;
				img_new[i][j].g = (1*img_old[i-2][j].g + 4*img_old[i-1][j].g + 6*img_old[i][j].g + 4*img_old[i+1][j].g + 1*img_old[i+2][j].g)/16;
				img_new[i][j].b = (1*img_old[i-2][j].b + 4*img_old[i-1][j].b + 6*img_old[i][j].b + 4*img_old[i+1][j].b + 1*img_old[i+2][j].b)/16;
            }
			for (i=row_number+distance*iteration; i<NR-2; i++){
				img_new[i][j].r = (1*img_old[i-2][j].r + 4*img_old[i-1][j].r + 6*img_old[i][j].r + 4*img_old[i+1][j].r + 1*img_old[i+2][j].r)/16;
				img_new[i][j].g = (1*img_old[i-2][j].g + 4*img_old[i-1][j].g + 6*img_old[i][j].g + 4*img_old[i+1][j].g + 1*img_old[i+2][j].g)/16;
				img_new[i][j].b = (1*img_old[i-2][j].b + 4*img_old[i-1][j].b + 6*img_old[i][j].b + 4*img_old[i+1][j].b + 1*img_old[i+2][j].b)/16;
            }
			i=0;
				img_new[i][j].r = (6*img_old[i][j].r + 4*img_old[i+1][j].r + 1*img_old[i+2][j].r)/11;
				img_new[i][j].g = (6*img_old[i][j].g + 4*img_old[i+1][j].g + 1*img_old[i+2][j].g)/11;
				img_new[i][j].b = (6*img_old[i][j].b + 4*img_old[i+1][j].b + 1*img_old[i+2][j].b)/11;
			i=1;
				img_new[i][j].r = (4*img_old[i-1][j].r + 6*img_old[i][j].r + 4*img_old[i+1][j].r + 1*img_old[i+2][j].r)/15;
				img_new[i][j].g = (4*img_old[i-1][j].g + 6*img_old[i][j].g + 4*img_old[i+1][j].g + 1*img_old[i+2][j].g)/15;
				img_new[i][j].b = (4*img_old[i-1][j].b + 6*img_old[i][j].b + 4*img_old[i+1][j].b + 1*img_old[i+2][j].b)/15;
			i=NR-2;
				img_new[i][j].r = (1*img_old[i-2][j].r + 4*img_old[i-1][j].r + 6*img_old[i][j].r + 4*img_old[i+1][j].r)/15;
				img_new[i][j].g = (1*img_old[i-2][j].g + 4*img_old[i-1][j].g + 6*img_old[i][j].g + 4*img_old[i+1][j].g)/15;
				img_new[i][j].b = (1*img_old[i-2][j].b + 4*img_old[i-1][j].b + 6*img_old[i][j].b + 4*img_old[i+1][j].b)/15;
			i=NR-1;
				img_new[i][j].r = (1*img_old[i-2][j].r + 4*img_old[i-1][j].r + 6*img_old[i][j].r)/11;
				img_new[i][j].g = (1*img_old[i-2][j].g + 4*img_old[i-1][j].g + 6*img_old[i][j].g)/11;
				img_new[i][j].b = (1*img_old[i-2][j].b + 4*img_old[i-1][j].b + 6*img_old[i][j].b)/11;
			
			
        }
        image_copy(img_old, img_new, NC,NR);//copy new -> old
        iteration+=1;
    }


    sprintf(new_file_name, "Result_%d_%d_%s", row_number, distance, ppm_file);
    img_to_ppm_file(img_new, new_file_name, NC, NR);
    free_color_img(img_old);
    free_color_img(img_new);
    show_pgm_file(new_file_name);
}
