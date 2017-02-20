/* Applies Gaussian filter to image
 * Modifies the original image
 * Takes column and row numbers as inputs
 */
#include "my_header.h"
void gaussMask(color **img, int NR, int NC, int rflag,
               int gflag, int bflag)
{
    for (int i = 1; i < NR - 1; ++i)
        for (int j = 1; j < NC - 1; ++j)
        {
            if (rflag)
            {
                img[i][j].r = (img[i - 1][j - 1].r + img[i - 1][j].r * 2 + img[i - 1][j + 1].r + img[i][j - 1].r * 2 + img[i][j].r * 4 + img[i][j + 1].r * 2 + img[i + 1][j - 1].r + img[i + 1][j].r * 2 + img[i + 1][j + 1].r) / 16;
            }
            if (gflag)
            {
                img[i][j].g = (img[i - 1][j - 1].g + img[i - 1][j].g * 2 + img[i - 1][j + 1].g + img[i][j - 1].g * 2 + img[i][j].g * 4 + img[i][j + 1].g * 2 + img[i + 1][j - 1].g + img[i + 1][j].g * 2 + img[i + 1][j + 1].g) / 16;
            }
            if (bflag)
            {
                img[i][j].b = (img[i - 1][j - 1].b + img[i - 1][j].b * 2 + img[i - 1][j + 1].b + img[i][j - 1].b * 2 + img[i][j].b * 4 + img[i][j + 1].b * 2 + img[i + 1][j - 1].b + img[i + 1][j].b * 2 + img[i + 1][j + 1].b) / 16;
            }
        }
}