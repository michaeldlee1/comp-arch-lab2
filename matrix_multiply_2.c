// unrolled matrix multiply
#include <stdio.h>
#include <math.h>
#include <time.h>

#define XSIZE 700
#define YSIZE 700
#define MATRIX_SIZE 700

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;
  
  int r;

  clock_t begin, end;

  double time_spent;

  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    }
  }

  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
		z[i][j] = i + j;
    }
  }

  begin = clock();
 
  /* Do matrix multiply */
  // MATRIX_SIZE captures both the row and column dimensions of all matrices
  for (i=0; i < MATRIX_SIZE; i+=2) {
	for (j=0; j < MATRIX_SIZE; j+=2) {
		for(k=0; k < MATRIX_SIZE; k++) {
			if(k == 0){  // then we should set x[i][j] to 0, in  case theres already data stored theere
				x[i][j] = 0;
				x[i+1][j] = 0;
				x[i][j+1] = 0;
				x[i+1][j+1] = 0;
			}
			// calc x[i][j]
			x[i][j] = x[i][j] + y[i][k] * z[k][j];
			// x[i+1][j]
			x[i+1][j] = x[i+1][j] + y[i+1][k] * z[k][j];
			// x[i][j+1]
			x[i][j+1] = x[i][j+1] + y[i][k] * z[k][j+1];
			// x[i+1][j+1]
			x[i+1][j+1] = x[i+1][j+1] + y[i+1][k] * z[k][j+1];
			
		}
	}
  }

  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("Time Spent on MM is:  %lf\n", time_spent);
}
