// unrolled matrix multiply -- 4x4
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
  // MATRIX_SIZE captures both thee row and column dimensions of all matrices
  for (i=0; i < MATRIX_SIZE; i+=4) {
	for (j=0; j < MATRIX_SIZE; j+=4) {
	//	printf("i = %d    j = %d    i+3 = %d    j+3 = %d\n", i, j, i+3, j+3);
		int r0c0   = x[i][j];
		int r0c1   = x[i][j+1];
		int r0c2   = x[i][j+2];
		int r0c3   = x[i][j+3];

		int r1c0   = x[i+1][j];
		int r1c1   = x[i+1][j+1];
		int r1c2   = x[i+1][j+2];
		int r1c3   = x[i+1][j+3];

		int r2c0   = x[i+2][j];
		int r2c1   = x[i+2][j+1];
		int r2c2   = x[i+2][j+2];
		int r2c3   = x[i+2][j+3];

		int r3c0   = x[i+3][j];
		int r3c1   = x[i+3][j+1];
		int r3c2   = x[i+3][j+2];
		int r3c3   = x[i+3][j+3];

		for(k=0; k < MATRIX_SIZE; k++) {
			if(k == 0){  // then we should set x[i][j] to 0, in  case theres already data stored theere
				r0c0 = 0;	
				r0c1 = 0;	
				r0c2 = 0;	
				r0c3 = 0;

				r1c0 = 0;	
				r1c1 = 0;	
				r1c2 = 0;	
				r1c3 = 0;

				r2c0 = 0;	
				r2c1 = 0;	
				r2c2 = 0;	
				r2c3 = 0;

				r3c0 = 0;	
				r3c1 = 0;	
				r3c2 = 0;	
				r3c3 = 0;
			}
			r0c0 = r0c0 + y[i][k] * z[k][j];
			r0c1 = r0c1 + y[i][k] * z[k][j+1];
			r0c2 = r0c2 + y[i][k] * z[k][j+2];
			r0c3 = r0c3 + y[i][k] * z[k][j+3];				
			
			r1c0 = r1c0 + y[i+1][k] * z[k][j];
			r1c1 = r1c1 + y[i+1][k] * z[k][j+1];
			r1c2 = r1c2 + y[i+1][k] * z[k][j+2];
			r1c3 = r1c3 + y[i+1][k] * z[k][j+3];
	
			r2c0 = r2c0 + y[i+2][k] * z[k][j];
			r2c1 = r2c1 + y[i+2][k] * z[k][j+1];
			r2c2 = r2c2 + y[i+2][k] * z[k][j+2];
			r2c3 = r2c3 + y[i+2][k] * z[k][j+3];
	
			r3c0 = r3c0 + y[i+3][k] * z[k][j];
			r3c1 = r3c1 + y[i+3][k] * z[k][j+1];
			r3c2 = r3c2 + y[i+3][k] * z[k][j+2];
			r3c3 = r3c3 + y[i+3][k] * z[k][j+3];	
		}
		x[i][j]     = r0c0;
		x[i][j+1]   = r0c1;
		x[i][j+2]   = r0c2;
		x[i][j+3]   = r0c3;
		
		x[i+1][j]   = r1c0;
		x[i+1][j+1] = r1c1;
		x[i+1][j+2] = r1c2;
		x[i+1][j+3] = r1c3;	
		
		x[i+2][j]   = r2c0;
		x[i+2][j+1] = r2c1;
		x[i+2][j+2] = r2c2;
		x[i+2][j+3] = r2c3;
		
		x[i+3][j]   = r3c0;
		x[i+3][j+1] = r3c1;
		x[i+3][j+2] = r3c2;
		x[i+3][j+3] = r3c3;
	}
  }

  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("Time Spent on MM is:  %lf\n", time_spent);
}
