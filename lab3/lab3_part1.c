#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define N 1024 
//#define N 512 
#define N 256 
//define matrices
float A[N][N]; 
float B[N][N];
float C[N][N];

int main()
{
	//use srand() for random initialization
	srand((unsigned)time(NULL)); 
	//randomly initialize matrices
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			A[i][j] = rand()/(float)RAND_MAX;
			B[i][j] = rand()/(float)RAND_MAX;
		}
	}
	
	clock_t startTime = clock(); 

	float bTranspose[N][N]; 
	//optimization
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			bTranspose[j][i] = B[i][j]; 
		}
	}	

	//matrix multiplication
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			C[i][j] = 0;
			for(int k=0; k<N; k++){
				// C[i][j] += A[i][k] * B[k][j]; 
				C[i][j] += A[i][k] * bTranspose[j][k]; 
			}
		}
	}
	
	//end clocl
	clock_t endTime = clock(); 
	//calculate runtime
	float runntime = (float)(endTime - startTime)/CLOCKS_PER_SEC; 
	printf("Runtime: %.4f seconds\n", runntime); 
	return 0;
}
