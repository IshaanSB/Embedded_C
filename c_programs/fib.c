#include<stdio.h>
#include<stdlib.h>

//long int fib(int n);
int checkfib(int n, int* cache);

int main(){

int a;
//a = fib(7);
int n;
printf("enter the number of terms");
scanf("%d",&n);

int* cache=(int*)calloc((n+1),sizeof(int));

if(cache==NULL){
printf("Memory production failed");


}


int result;
result=checkfib(n,cache);
printf("result is %d\n",result);

//safely pop off the heap to avoid memory growth or issues
free(cache);

return 0;
}

/*
long int fib(int n){

if(n==0||n==1){
return n;
}


return fib(n-1)+fib(n-2);




}
*/

//cache for capturing the values computed when going in the left branches sub stack frame each time
//this allows to minimize compuations and be far more efficient for larger values of n
//tiem complexity is linear
int checkfib(int n, int* cache){


if(n<=1){

return n;

}


// if it is non-empty, function call  returns a value from the array
if(cache[n]!=0){

return cache[n];

}



cache[n]=checkfib(n-1,cache)+checkfib(n-2,cache);

return cache[n];





}
