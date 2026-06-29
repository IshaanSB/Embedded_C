#include<stdio.h>

int main()
{


int given=0;
int result=1;
int store_num=0;

printf("enter any number:");
scanf("%d",&given);

while(given){

store_num=given%10;

result=store_num*result;
given=given/10;

}

printf("result is %d:\n",result);






}
