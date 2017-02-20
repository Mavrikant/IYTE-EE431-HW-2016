#include "img_pro.h"
#include <math.h>
double grad_x(color **img, int x, int y, int NR, int NC, char flag);
double grad_y(color **img, int x, int y, int NR, int NC, char flag);
double gxx(color **img, int x, int y, int NR, int NC);
double gyy(color **img, int x, int y, int NR, int NC);
double gxy(color **img, int x, int y, int NR, int NC);
double direction(color **img, int x, int y, int NR, int NC);
double magnitude(color **img, int x, int y, int NR, int NC);
double **create_double_array(int NR, int NC);
void free_double_array(double **arr, int NR);
void rgbtohsi(unsigned char r, unsigned char g, unsigned char b, float *h,
              float *s, float *i);
void hsitorgb(float h, float s, float i, unsigned char *r, unsigned char *g,
              unsigned char *b);
