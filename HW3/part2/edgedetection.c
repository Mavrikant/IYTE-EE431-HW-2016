#include "my_header.h"

double grad_x(color **img, int x, int y, int NR, int NC, char flag) {
  switch (flag) {
  case ('r'):
    if (x == NC - 1 || x == 0)
      return img[x][y].r;
    return img[x + 1][y].r - img[x - 1][y].r;
    break;
  case ('g'):
    if (x == NC - 1 || x == 0)
      return img[x][y].g;
    return img[x + 1][y].g - img[x - 1][y].g;
    break;
  case ('b'):
    if (x == NC - 1 || x == 0)
      return img[x][y].b;
    return img[x + 1][y].b - img[x - 1][y].b;
    break;
  }
}
double grad_y(color **img, int x, int y, int NR, int NC, char flag) {
  switch (flag) {
  case ('r'):
    if (x == NR - 1 || x == 0)
      return img[x][y].r;
    return img[x][y + 1].r - img[x][y - 1].r;
    break;
  case ('g'):
    if (x == NR - 1 || x == 0)
      return img[x][y].g;
    return img[x][y + 1].g - img[x][y - 1].g;
    break;
  case ('b'):
    if (x == NR - 1 || x == 0)
      return img[x][y].b;
    return img[x][y + 1].b - img[x][y - 1].b;
    break;
  }
}
double gxx(color **img, int x, int y, int NR, int NC) {
  return (sq(grad_x(img, x, y, NR, NC, 'r')) +
          sq(grad_x(img, x, y, NR, NC, 'g')) +
          sq(grad_x(img, x, y, NR, NC, 'b')));
}
double gyy(color **img, int x, int y, int NR, int NC) {
  return (sq(grad_y(img, x, y, NR, NC, 'r')) +
          sq(grad_y(img, x, y, NR, NC, 'g')) +
          sq(grad_y(img, x, y, NR, NC, 'b')));
}

double gxy(color **img, int x, int y, int NR, int NC) {
  return (grad_x(img, x, y, NR, NC, 'r') * grad_y(img, x, y, NR, NC, 'r') +
          grad_x(img, x, y, NR, NC, 'g') * grad_y(img, x, y, NR, NC, 'g') +
          grad_x(img, x, y, NR, NC, 'b') * grad_y(img, x, y, NR, NC, 'b'));
}
double direction(color **img, int x, int y, int NR, int NC) {
  return (0.5 * atan((2 * gxy(img, x, y, NR, NC)) /
                     (gxx(img, x, y, NR, NC) - gyy(img, x, y, NR, NC))));
}
double magnitude(color **img, int x, int y, int NR, int NC) {
  return (sqrt(0.5 * ((gxx(img, x, y, NR, NC) + gyy(img, x, y, NR, NC)) -
                      (gxx(img, x, y, NR, NC) - gyy(img, x, y, NR, NC)) *
                          cos(2 * direction(img, x, y, NR, NC)) +
                      2 * gxy(img, x, y, NR, NC) *
                          sin(2 * direction(img, x, y, NR, NC)))));
}