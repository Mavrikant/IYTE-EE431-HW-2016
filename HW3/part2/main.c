// Homework part 2 by:
// Serhat Çillidağ - 200206001
// M. Serdar Karaman - 190206038

/*
To compile type:
gcc -o color_edge main.c edgedetection.c utility.c img_pro.c -lm
or just write make if you have UNIX Makefiles
*/
#include "my_header.h"

void usage() { printf("Usage: [threshold] [saturation] [intensity]"); }
int main(int argc, char **argv) {
  if (argc != 4) {
    usage();
    exit(-1);
  }
  int i, j, NR, NC;
  double mag;
  double max_val = 0;
  double min_val = 255;
  color **img;
  double **magn;
  int threshold = atoi(argv[1]);
  float saturation = atof(argv[2]);
  float intensity = atof(argv[3]);

  img = (color **)ppm_file_to_img(
      "mandrill.ppm", &NC,
      &NR); /* read img and its size from file, also allocates memory for img */
  magn = create_double_array(NR, NC);
  // calculate magnitude of each pixel
  for (i = 0; i < NR; ++i)
    for (j = 1; j < NC; ++j) {
      magn[i][j] = magnitude(img, i, j, NR, NC);
      if (magn[i][j] < threshold)
        magn[i][j] = 0;
      else
        min_val = min(min_val, magn[i][j]);
      max_val = max(max_val, magn[i][j]);
    }

  // add a scale to measure between the hue arc
  float scale = 360 / (max_val);
  unsigned char *rbuf = (unsigned char *)malloc(sizeof(unsigned char));
  unsigned char *gbuf = (unsigned char *)malloc(sizeof(unsigned char));
  unsigned char *bbuf = (unsigned char *)malloc(sizeof(unsigned char));

  for (i = 0; i < NR; ++i)
    for (j = 1; j < NC; ++j) {
      if (!magn[i][j])
        PPM_ASSIGN(img[i][j], 0, 0, 0);
      else {
        hsitorgb(scale * magn[i][j], saturation, intensity, rbuf, gbuf, bbuf);
        PPM_ASSIGN(img[i][j], *rbuf, *gbuf, *bbuf);
      }
    }
  img_to_ppm_file(img, "output.ppm", NC, NR);
  show_pgm_file("output.ppm");
  free(rbuf);
  free(gbuf);
  free(bbuf);
  free_double_array(magn, NR);
  free_color_img(img); /* free arrays */
}
