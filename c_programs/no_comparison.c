#include<stdio.h>

int main()
{

int a=20;
int b=30;
int c=0;
int d=0;
int e=0;
printf("\n");
for(int i=31;i>=0;i--){
//bit setting logic
c=(b>>i)&1;
d=(a>>i)&1;
//xor gate is a comparator
e=c^d;
//printf("\n");
if(e){
//printf("%d",e);
printf("The numbers are not equal");
e=1;
break;
}




}

//if the last bit is still not set after all 32 iterations over the 32 bit binary number, then it means the numbers must be equal
if(!e){
printf("the numbers are equal\n");
}


printf("\n");





}
