#include<stdio.h>

int main()
{


int given=0;
int result=1;


printf("enter any number:");
scanf("%d",&given);

while(given){



result=result*given;
given--;

}

printf("result is %d:\n",result);






}
