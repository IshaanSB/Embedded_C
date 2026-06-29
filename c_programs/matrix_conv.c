#include<stdio.h>
#include<stdlib.h>
int main() {

    int rows=3,cols=3;
    		
    // 1. Initialize the first 3x3 matrix
    int **matr1=(int**) malloc(rows*sizeof(int *));

    // 2. Initialize the second 3x3 matrix
    int **matr2=(int**) malloc(rows*sizeof(int* ));

    // 3. Array to store the result
    int **result=(int**)malloc(rows*sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matr1[i] = (int *)malloc(cols * sizeof(int));
    	matr2[i]=  (int *)malloc(cols * sizeof(int));
	result[i]= (int *)malloc(cols * sizeof(int));
    }	

    //3. input for matrices
    printf("Enter values for Matrix 1 and Matrix 2 side-by-side:\n");

    for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < cols; j++) {
        // Input for Matrix 1
        printf("Matr1 [%d][%d]: ", i, j);
        scanf("%d", &matr1[i][j]);
        
        // Input for Matrix 2
        printf("Matr2 [%d][%d]: ", i, j);
        scanf("%d", &matr2[i][j]);
        
        printf("\n"); // Visual space between elements
    	}
    }
		
	




    // 4. Matrix multiplication logic
    for (int i = 0; i < 3; i++) {           // Iterates over rows of mat1
        for (int j = 0; j < 3; j++) {       // Iterates over columns of mat2
            result[i][j] = 0;               // Initialize the current cell to 0
            
            for (int k = 0; k < 3; k++) {   // Computes the dot product
                result[i][j] += matr1[i][k] * matr2[k][j];
            }
        }
    }



    //. checking loop, and printing array and result
    printf("Matrix1 and 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //printf("matr1[%d][%d]:%d\n",i,j, matr1[i][j]);
    	    //printf("matr2[%d][%d]:%d\n",i,j, matr2[i][j]);
	    printf("matr2[%d][%d]:%d\n",i,j, result[i][j]);		
        }
        printf("\n"); // Move to the next line after printing a row
    }

    return 0;
}
