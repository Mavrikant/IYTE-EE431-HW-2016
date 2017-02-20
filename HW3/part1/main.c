// Homework sent by
// Serhat Çillidağ - 200206001
// M. Serdar Karaman - 190206038

/*
To compile type:
gcc -o rgbgauss gauss.c main.c img_pro.c -lm
or just write make if you have UNIX Makefiles
*/

#include "my_header.h"
void usage() {
  printf("Usage: rgbgauss [Rflag 1] [Gflag 2] [Bflag 3] [num. of iter.] [ppm "
         "file] ");
}
int main(int argc, char **argv)

{
  if (argc != 6) {
    usage();
    exit(-1);
  }
  int NR, NC, rflag, gflag, bflag, it;
  char *ppm_file;
  color **img;
  rflag = atoi(argv[1]);
  gflag = atoi(argv[2]);
  bflag = atoi(argv[3]);
  it = atoi(argv[4]);
  ppm_file = argv[5];
  

  /*---------->>> Start image manipulation example */
  img = (color **)ppm_file_to_img(
      ppm_file, &NC,
      &NR); /* read img and its size from file, also allocates memory for img */
  show_pgm_file(ppm_file);
  for (int i = 0; i < it; ++i)
    gaussMask(img, NR, NC, rflag, gflag, bflag);

  img_to_ppm_file(img, "result.ppm", NC, NR); /*  write to file */
  free_color_img(img);                       /* free array */
  show_pgm_file("result.ppm"); /*  show image using an external viewer */
                              /*----------<<< End image manipulation example */
}
