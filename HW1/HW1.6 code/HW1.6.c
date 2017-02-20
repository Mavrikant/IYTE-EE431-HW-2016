#include "img_pro.h"
#include "my_header.h"

int main(int argc, char * * argv){
  unsigned char * * img;
  char * pgm_file, * new_pgm_file;
  int i, j, NR, NC, number;

  if (argc != 4) {
    printf("\n Usage: HW1 [OLD Image file (*.pgm)] [NEW Image file (*.pgm)] [Value]\n");
    printf("\n E.g.   HW1 cathedral.pgm new.pgm 15 \n");
    exit(-1);
  }

  pgm_file = argv[1];
  new_pgm_file = argv[2];
  number = atoi(argv[3]);
  img = pgm_file_to_img(pgm_file, &NC, &NR);

	for (i = 0; i < NR; i++) {
		for (j = 0; j < NC; j++) {
			if (img[i][j] + number > 255){
				img[i][j] = 255;
			}
			else if (img[i][j] + number < 0){
				img[i][j] = 0;
			}
			else{
				img[i][j] += number;
			}
		}
	}

  img_to_pgm_file(img, new_pgm_file, NC, NR);
  free_img(img);
  show_pgm_file(new_pgm_file); 

  return (1);
}