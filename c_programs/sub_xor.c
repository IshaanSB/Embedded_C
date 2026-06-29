#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

int n;
printf("enter the size for the array:");
scanf("%d",&n);

int total_sub_arr=n*(n+1)/2;

int *arr=malloc(n*sizeof(int));


for(int i=0;i<n;i++){
printf("enter arr[%d]:",i);
scanf("%d",&arr[i]);
}

int **sub_arr=malloc(total_sub_arr*sizeof(int *));
int *sub_sizes=malloc(total_sub_arr*sizeof(int));
int sub_count=0;
int *results=malloc(total_sub_arr*sizeof(int));

for(int sub_size=n;sub_size>=1;sub_size--){
	for(int start_index=0;start_index<=n-sub_size;start_index++){
	// Allocate an exact, contiguous chunk of memory for this sub-array
            sub_arr[sub_count] = malloc(sub_size * sizeof(int));
            sub_sizes[sub_count] = sub_size;



	// Copy the contiguous block of data from the main array
            memcpy(sub_arr[sub_count], &arr[start_index], sub_size * sizeof(int));
            
            sub_count++; // Move to the next slot in our master pointer array
	}


}


//printf("\n--- All %d Contiguous Sub-arrays ---\n", total_sub_arrays);
    for (int i = 0; i < total_sub_arr; i++) {
        //printf("Sub-array %2d (Size %d): [ ", i + 1, sub_sizes[i]);
        for (int j = 0; j < sub_sizes[i]; j++) {
            results[i]=sub_arr[i][0];
	    results[i]=results[i]^sub_arr[i][j];
	
            printf("sub_arrays[%d][%d]:%d\n",i,j,sub_arr[i][j]);            		
        }
     //printf("results[%d]:%d\n",i,results[i]);   
    }
int temp=0;
int index=0;
for (int i = 0; i < total_sub_arr; i++) {

	if(results[i]>temp){
	temp=results[i];//keep replacing till you find the maximum xor value
	index=i;
}        

}

printf("The sub_arr[%d] has the max xor value of %d\n",index,temp);







for (int i = 0; i < total_sub_arr; i++) {
        free(sub_arr[i]); // Free each individual contiguous sub-array
    }
    free(sub_arr);        // Free the master pointer table
    free(sub_sizes);         // Free the size tracking array
    free(arr);        // Free the original array
    free (results);
    

return 0;
}
