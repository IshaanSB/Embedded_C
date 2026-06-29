#include<stdio.h>

int main()
{

int i=2;
int b;
int c=0;

while(i!=0){


printf("enter the value of b to be added");


scanf("%d",&b);



c=b+c;


printf("\n enter the value of c[%d]=%d:",i,c);
printf("enter 1 for continue and 0 for stopping:");
scanf("%d",&i);

}


printf("the value of c is:%d\n",c);


return 0;

}





