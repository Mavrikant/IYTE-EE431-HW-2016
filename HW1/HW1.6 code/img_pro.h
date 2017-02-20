
/* If auto-detection doesn't work, choose your operating system. Comment out the rest. */
/* #define _WIN32 */
/* #define _WIN32 */
/* #define __linux */
/* #define __unix */
/* #define __APPLE__ */

#ifdef __linux
#define view "xv -geometry +200+200 " /*  Pick your favorite image viewer for X windows. Yes, I still use xv */

#elif __CYGWIN__
#define view "/cygdrive/c/Program*x86*/IrfanView/i_view32.exe" 
/*  Pick your favorite image viewer for Cygwin on MS-Windows. My favorite is irfanview. Check the above path first. */

#elif __unix
#define view "xli -geometry +200+200 " 
/*  Pick your favorite image viewer for X windows. Yes, I still use xv */

#elif _WIN32
#define view "//c/Program\\ Files/IrfanView/i_view32.exe" 
/*  Pick your favorite image viewer for MS-Windows. My favorite is irfanview. Check the above path first. */

#elif __APPLE__
#define view "open -W -a Toyviewer " 
/* Pick your favorite image viewer for MacOSX. Toyviewer is available in Appstore. -W flag causes a wait state until 
image wiewer is terminated */
#endif

/* Include standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef _WIN32
#include <fcntl.h>
//#include <io.h>
#endif

/* Some useful macros */
/* #define PI     3.1415927 */ /*   should be already defined  */
#define twoPI  6.2831853
#define halfPI 1.5707963
#define max(a,b) (((a)>=(b))?a:b)
#define min(a,b) (((a)<=(b))?a:b)
#define sq(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))          
#define diagonal(a,b) (sqrt((a)*(a)+(b)*(b)))



/* Function definitions */
unsigned char **alloc_img(int ncol,int nrow);
void free_img(unsigned char** img);
void img_to_pgm_file(unsigned char **img, char *file_name,int NC, int NR);
unsigned char **pgm_file_to_img(char *file_name,int *pNC,int *pNR);
void show_pgm_file(char *file_name);
