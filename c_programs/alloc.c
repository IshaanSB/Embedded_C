#include<stdio.h>
#include<stdlib.h>

int main(){

int *ptr,*ptr_2,*ptr_3;



ptr = (int*) malloc(sizeof(int));
ptr_2 = (int*) malloc(sizeof(int));
ptr_3 = (int*) malloc(sizeof(int));

*ptr=4;
*ptr_2=3;

*ptr_3=*ptr+*ptr_2;

printf("ptr3 value : %d\n",*ptr_3);


char *ptr_one,*ptr_two,*ptr_three;



ptr_one = (char*) malloc(sizeof(char));
ptr_two = (char*) malloc(sizeof(char));
ptr_three = (char*) malloc(sizeof(char));

*ptr_one='b';
*ptr_two='c';

*ptr_three=*ptr_one+*ptr_two;

printf("ptr3 value : %d\n",*ptr_three);


}
