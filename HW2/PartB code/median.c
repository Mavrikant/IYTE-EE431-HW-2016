// HW2
// Serdar Karaman 190206038
// Serhat Çillidağ 200206001

#include "img_pro.h"
#include "my_header.h"

int compare(const void *a, const void *b) {
  return (*(unsigned char *)a - *(unsigned char *)b);
}

// applies median filter to image
// does not modify outer values outside the filter
void medianMask(unsigned char **img, int i, int j, int size) {
  int rows = 0, elements = 0, cols = 0;
  unsigned char array[size * size];
  int limit = (size - 1) / 2; // to calculate limit addresses

  // add the numbers inside filter to array
  for (rows = i - limit; rows <= (i + limit); ++rows)
    for (cols = j - limit; cols <= (j + limit); ++cols, ++elements)
      array[elements] = img[rows][cols];

  // apply quicksort algorithm from stdlib to find median
  qsort(array, size * size, sizeof(unsigned char), compare);

  // change the img pointer to median value
  img[i][j] = *(array + ((size * size - 1) / 2));
}
int main(int argc, char **argv) {
  unsigned char **img, **img2;
  char *pgm_file;
  int i, j, c, NC2, NR2, count, size, limit;
  if (argc != 4) {
    printf("\n Usage: median [filter strength] [times] [.pgm file]  \n");
    exit(-1);
  }

  pgm_file = argv[3];
  size = atoi(argv[1]);
  count = atoi(argv[2]);
  img = pgm_file_to_img(pgm_file, &NC2, &NR2);
  show_pgm_file(pgm_file);
  limit = (size - 1) / 2;
  for (c = 0; c < count; ++c) {
    for (i = limit; i <= NR2 - limit; ++i)
      for (j = limit; j <= NC2 - limit; ++j)
        medianMask(img, i, j, size);
  }

  img_to_pgm_file(img, "test2.pgm", NC2, NR2);
  show_pgm_file("test2.pgm");

  free_img(img);
  return (0);
}
