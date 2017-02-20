// Homework sent by
// Serhat Çillidağ - 200206001
// M. Serdar Karaman - 190206038

/*
To compile type:
gcc -o tilt_shiftB main.c img_pro.c -lm
or just write make if you have UNIX Makefiles
*/

#include "my_header.h"


void usage()
{
    printf("Usage: ./tilt_shiftB [center i] [center j] [distance d] [.pgm file]");
}

void image_copy(color **img_old, color **img_new, int NC, int NR)
{
    for (int i=0; i<NR; i++)
        for (int j=0; j<NC; j++)
            img_old[i][j] = img_new[i][j];

}

int main(int argc, char **argv)
{

    if (argc != 5)
    {
        usage();
        exit(-1);
    }

    int NR, NC, center_i, center_j, distance, iteration;
    char *ppm_file;
    char new_file_name [64];
    color **img_old;
    color **img_new;
    center_i = atoi(argv[1]);
    center_j = atoi(argv[2]);
    distance = atoi(argv[3]);
    ppm_file = argv[4];

    img_old = (color **)ppm_file_to_img(ppm_file, &NC, &NR);
    img_new = (color **)ppm_file_to_img(ppm_file, &NC, &NR);

    iteration=1;
    while(distance*iteration < sqrt(pow(NR,2)+pow(NR,2)) ){
        for (int i=2; i<NR-2; i++){
            for (int j=2; j<NC-2; j++){
                if(sqrt(pow(center_i-i,2)+pow(center_j-j,2))>distance*iteration){
                    img_new[i][j].r = (1*img_old[i-2][j].r + 4*img_old[i-1][j].r + 6*img_old[i][j].r + 4*img_old[i+1][j].r + 1*img_old[i+2][j].r)/16;
                    img_new[i][j].g = (1*img_old[i-2][j].g + 4*img_old[i-1][j].g + 6*img_old[i][j].g + 4*img_old[i+1][j].g + 1*img_old[i+2][j].g)/16;
                    img_new[i][j].b = (1*img_old[i-2][j].b + 4*img_old[i-1][j].b + 6*img_old[i][j].b + 4*img_old[i+1][j].b + 1*img_old[i+2][j].b)/16;
                }
            }
        }
        image_copy(img_old, img_new, NC,NR);//copy new -> old
        iteration+=1;
    }

    iteration=1;
    while(distance*iteration < sqrt(pow(NR,2)+pow(NR,2)) ){
        for (int i=2; i<NR-2; i++){
            for (int j=2; j<NC-2; j++){
                if(sqrt(pow(center_i-i,2)+pow(center_j-j,2))>distance*iteration){
                    img_new[i][j].r = (1*img_old[i][j-2].r + 4*img_old[i][j-1].r + 6*img_old[i][j].r + 4*img_old[i][j+1].r + 1*img_old[i][j+2].r)/16;
                    img_new[i][j].g = (1*img_old[i][j-2].g + 4*img_old[i][j-1].g + 6*img_old[i][j].g + 4*img_old[i][j+1].g + 1*img_old[i][j+2].g)/16;
                    img_new[i][j].b = (1*img_old[i][j-2].b + 4*img_old[i][j-1].b + 6*img_old[i][j].b + 4*img_old[i][j+1].b + 1*img_old[i][j+2].b)/16;
                }
            }
        }
        image_copy(img_old, img_new, NC,NR);//copy new -> old
        iteration+=1;
    }

    sprintf(new_file_name, "Result_%d_%d_%d_%s", center_i, center_j, distance, ppm_file);
    img_to_ppm_file(img_new, new_file_name, NC, NR);
    free_color_img(img_old);
    free_color_img(img_new);
    show_pgm_file(new_file_name);
}
