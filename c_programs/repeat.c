
#include<stdio.h>


int main()
{

int sort_arr[5]={1,3,3,6,7};
int count_arr[5]={};
//by default occurence of any element as one
int count=1;
// a count of 0 in the count_array indicates that element was repeated, and hence it is considered that no element exists in that spot
int temp;
printf("temp is %d\n",temp);
for(int i=0;i<=4;i++){
	for(int j=i+1;j<=5;j++){
	
	if(sort_arr[i]==sort_arr[j]){
	count=count+1;
	count_arr[i]=count;
	temp=j;
	
	}

	else{
	count_arr[i]=count;

	}
	}
//reset count to 1 for the iteration of the next element,

//printf("the value of temp is:%d\n",temp); 
count=1;

//printf("count_arr[%d]:%d\n",i,count_arr[i]);



}



count_arr[temp]=0;
int temp_n=0;
for(int k=0;k<=4;k++){
//printf("count_arr[%d]:%d\n",k,count_arr[k]);

}


}
