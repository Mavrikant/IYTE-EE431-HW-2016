#include "img_pro.h"

unsigned char **alloc_img(int ncol,int nrow)
{
int i;
unsigned char **img;

/* allocate pointers to rows */
img = (unsigned char **) malloc((size_t)((nrow+1)*sizeof(unsigned char*)));
if (!img)
{
  printf("\n\n Cannot allocate memory (1)\n");
  exit(0);
}

/* allocate rows and set pointers to them */
img[0] = (unsigned char *) malloc((size_t)((nrow*ncol+1)*sizeof(unsigned char)));
if (!img[0])
{
  printf("\nCannot allocate memory (21)\n");
  exit(0);
}


for(i=1;i<=nrow;i++)
    img[i]=img[i-1] + ncol;

/* return pointer to array of pointers to rows */
return (img);
}


color **alloc_color_img(int NC,int NR)
{
color **cimg;
cimg=(color **)alloc_img(3*NC,NR);
return (cimg);         
}


void free_img(unsigned char** img)
    {
    free( img[0] );
    free( img );
    }
void free_color_img(color** img)
    {
    free( img[0] );
    free( img );
    }



void show_pgm_file(char *file_name)
{

FILE *xfp;
char command[256]="";
char app[256]="";

strcat(command,view);
sprintf(app," %s",file_name);
/*
 xfp=popen((const char *)strcat(command,app),"w");
 pclose(xfp);
*/

system((const char *)strcat(command,app));

}

void img_to_pgm_file(unsigned char **img, char *file_name,int NC, int NR)
{
int i,j;
FILE *fp;

fp=fopen(file_name,"w");

#ifdef _WIN32
 _setmode( _fileno(fp), _O_BINARY);  /* be sure to write files in binary mode */
#endif

fprintf(fp,"P5\n%d %d\n255\n",NC,NR); 
for(i=0;i<NR;i++) 
  for(j=0;j<NC;j++)
    fputc(img[i][j],fp);  

fclose(fp);

}



unsigned char **pgm_file_to_img(char *file_name,int *pNC,int *pNR)

#define MAXC 80

{

        FILE *fp;
        unsigned char **img;
        char cline[MAXC];
        int i,j,NR,NC;
        int maxgray;
     
        if((fp=fopen(file_name,"r")) == NULL) {
/* open image file */
        printf("\n *** pgm_file_to_img -- can't open file: %s ****",file_name);
        exit(0);                              }

#ifdef _WIN32
 _setmode( _fileno(fp), _O_BINARY);  /* be sure to read files in binary mode */
#endif

    comment_loop0:   /* skip any comments */
       fgets(cline,MAXC,fp);   /* get next line from file */
       if(cline[0]=='#') goto comment_loop0;
       if(cline[0]!='P'||cline[1]!='5')
          {
           printf("\n **** pgm_file_to_img -- not a pgm file: %s ****",file_name);
           exit(0);
          }

    comment_loop1:   /* skip any comments */
        fgets(cline,MAXC,fp);  /* get next line from file */
        if(cline[0]=='#') goto comment_loop1;
        sscanf(cline,"%d %d ",&NC,&NR);  

    comment_loop2:   /* skip any comments */
        fgets(cline,MAXC,fp);  /* get next line from file */
        if(cline[0]=='#') goto comment_loop2;
        sscanf(cline,"%d  ",&maxgray);  /* get maxgray */


/* return size of image  to caller */
        *pNC=NC;
        *pNR=NR;

img=alloc_img(NC,NR);   /* allocate image array */

        for(i=0;i<NR;i++)
         for(j=0;j<NC;j++)
          {
            img[i][j]=fgetc(fp);   /* read image data from file */
          }


fclose(fp);

return(img);

}



void img_to_ppm_file(color **img, char *file_name,int NC, int NR)
{
int i,j;
FILE *fp;

fp=fopen(file_name,"w");

#ifdef MSDOS
 _setmode( _fileno(fp), _O_BINARY);  /* be sure to write files in binary mode */
#endif

fprintf(fp,"P6\n%d %d\n255\n",NC,NR); 
for(i=0;i<NR;i++) 
  for(j=0;j<NC;j++) {
    fputc(img[i][j].r,fp);  
    fputc(img[i][j].g,fp);  
    fputc(img[i][j].b,fp);  
		      }
fclose(fp);

}

color **ppm_file_to_img(char *file_name,int *pNC,int *pNR)

#define MAXC 80

{

        FILE *fp;
        color **img;
        char cline[MAXC];
        int i,j,NR,NC;
        int maxgray;
     
        if((fp=fopen(file_name,"r")) == NULL) {
/* open image file */
        printf("\n *** ppm_file_to_img -- can't open file: %s ****",file_name);
        exit(0);                              }

#ifdef MSDOS
 _setmode( _fileno(fp), _O_BINARY);  /* be sure to read files in binary mode */
#endif

    comment_loop0:   /* skip any comments */
       fgets(cline,MAXC,fp);   /* get next line from file */
       if(cline[0]=='#') goto comment_loop0;
       if(cline[0]!='P'||cline[1]!='6')
          {
           printf("\n **** ppm_file_to_img -- not a ppm file: %s ****",file_name);
           exit(0);
          }

    comment_loop1:   /* skip any comments */
        fgets(cline,MAXC,fp);  /* get next line from file */
        if(cline[0]=='#') goto comment_loop1;
        sscanf(cline,"%d %d ",&NC,&NR);  

    comment_loop2:   /* skip any comments */
        fgets(cline,MAXC,fp);  /* get next line from file */
        if(cline[0]=='#') goto comment_loop2;
        sscanf(cline,"%d  ",&maxgray);  /* get maxgray */


/* return size of image  to caller */
        *pNC=NC;
        *pNR=NR;

img=(color **)alloc_color_img(NC,NR);   /* allocate image array */

        for(i=0;i<NR;i++)
         for(j=0;j<NC;j++)
          {
            img[i][j].r=fgetc(fp);   /* read image data from file */
            img[i][j].g=fgetc(fp);   
            img[i][j].b=fgetc(fp);   
	    
          }


fclose(fp);

return(img);

}






