#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

int n1=5;
float** matrix1=(float**)malloc(sizeof(float*)*n1);
int n2=10;
float** matrix2=(float**)calloc(n2,sizeof(float*));


for(int i=0;i<10;i++){
if(i<5){
matrix1[i] = (float*)malloc(n1 * sizeof(float*));

}
matrix2[i]=(float*)calloc(n2,sizeof(float*));
} 


for (int i = 0; i < n1; i++) {         // Outer loop: iterates through rows
        for (int j = 0; j < n1; j++) {     // Inner loop: iterates through columns
            matrix1[i][j] = 1;        // Assigns a unique value to each element
        }
    }


float ratio_x=(float)(n1)/(n2);
float ratio_y=(float)(n1)/(n2);
float x;
float y;
float dx;
float dy;
int x_ceil,y_ceil,x_floor,y_floor;

//implementation of bilinear interpolation

for (int i = 0; i < n2; i++) {         // Outer loop: iterates through rows
        for (int j = 0; j < n2; j++) {     // Inner loop: iterates through columns
        	x=j*ratio_x;
		y=i*ratio_y;
		dx=x-floor(x);
		dy=y-floor(y);
		//need to modify logic because it is not able to deal with the edges.
		// 1. Establish your safe, clamped pixel anchors
        	x_floor = (int)floor(x);
        	y_floor = (int)floor(y);
        
        	x_ceil  = (x_floor >= n1 - 1) ? x_floor : x_floor + 1;
        	y_ceil  = (y_floor >= n1 - 1) ? y_floor : y_floor + 1;		


		matrix2[i][j]=(1-dx)*(1-dy)*matrix1[y_floor][x_floor]+dx*(1-dy)*matrix1[x_ceil][y_floor]+(1-dx)*dy*matrix1[y_ceil][x_floor]+dx*dy*matrix1[y_ceil][x_ceil];
		           
        }	
    }


printf("Initialized 2D Array:\n");
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            printf("matrix2[%d][%d]:%0.2f ",i,j, matrix2[i][j]);
        }
        printf("\n");
    }




// 1. Free Matrix A (the 5x5 source)
for (int i = 0; i < 5; i++) {
    free(matrix1[i]); // Free each individual row
}
free(matrix1);        // Free the array of row pointers

// 2. Free Matrix B (the 10x10 destination)
for (int i = 0; i < 10; i++) {
    free(matrix2[i]); // Free each individual row
}
free(matrix2);        // Free the array of row pointers




return 0;
}
