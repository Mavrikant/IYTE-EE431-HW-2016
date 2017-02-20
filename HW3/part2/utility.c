#include "my_header.h"

double **create_double_array(int NR, int NC) {
  double **array;
  array = (double **)malloc((NR + 1) * sizeof(double *));
  for (int i = 0; i < NR; i++)
    array[i] = (double *)malloc((NC + 1) * sizeof(double));
  return array;
}
void free_double_array(double **arr, int NR) {
  for (int i = 0; i < NR; ++i)
    free(arr[i]);
  free(arr);
}
void rgbtohsi(unsigned char R, unsigned char G, unsigned char B, float *H,
              float *S, float *I) {
  float r, g, b, num, m, denom;
  r = R / (R + G + B);
  g = G / (R + G + B);
  b = B / (R + G + B);
  m = min(r, min(g, b));
  num = 0.5 * (R - G + R - B);
  denom = sqrt((R - G) * (R - G) + (R - B) * (G - B));
  *H = acos(num / denom);
  *I = (R + G + B) / ((float)(3 * 255));

  if (b > g)
    *H = 2 * PI - (*H);
  *S = 1 - 3 * m;
  // convert back to [0,255]
  *H = (255 / (2 * PI)) * (*H);
  //  *S = ((float)255) * (*S);
  // *I = ((float)255) * (*I);
}

void hsitorgb(float h, float s, float i, unsigned char *r, unsigned char *g,
              unsigned char *b) {
  float x = i * (1 - s);
  if (h < 2 * PI / 3) {
    float y = i * (1 + (s * cos(h)) / (cos(PI / 3 - h)));
    float z = 3 * i - (x + y);
    *b = x;
    *r = y;
    *g = z;
  } else if (h < 4 * PI / 3) {
    float y =
        i * (1 + (s * cos(h - 2 * PI / 3)) / (cos(PI / 3 - (h - 2 * PI / 3))));
    float z = 3 * i - (x + y);
    *r = x;
    *g = y;
    *b = z;
  } else {
    float y =
        i * (1 + (s * cos(h - 4 * PI / 3)) / (cos(PI / 3 - (h - 4 * PI / 3))));
    float z = 3 * i - (x + y);
    *r = z;
    *g = x;
    *b = y;
  }
}