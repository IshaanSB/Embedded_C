#include<stdio.h>

int main(){

int i=0;
int d=0;
for(i=0;i<=7;i++){
d=i^(i>>1);
printf("The gray coded number is:%d\n",d);
}



}


