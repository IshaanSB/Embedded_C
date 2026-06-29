#include<iostream>
using namespace std;

int add(int* ptr1, int* ptr2);
float add(float* ptr1, float* ptr2);
float add(float* ptr1, int *ptr2);

int main(){
int *ptr1,*ptr2;
float *ptr3, *ptr4;

//ptr=(int*)malloc(sizeof(int));
ptr1=new int;
ptr2=new int;

ptr3=new float;
ptr4=new float;

*ptr1=10;
*ptr2=20;
*ptr3=30.0;
*ptr4=40.0;

int a = add(ptr1,ptr2);
float b = add(ptr3,ptr4);
float c = add(ptr3,ptr2);

cout<<"the add for a:"<<a<<"the add for b:"<<b<<"the add for c:"<<c<<endl;

delete ptr1, ptr2, ptr3, ptr4;



}

int add(int* ptr1, int* ptr2){

int temp;
temp= *ptr1 + *ptr2;

return temp;	
}	

float add(float* ptr1, float* ptr2){
	
float temp;
temp= *ptr1 + *ptr2;	

return temp;	
}

float add(float* ptr1, int *ptr2){
	
float temp;
temp = *ptr1 + *ptr2;

return temp;	
	
}	
	
