#include<stdio.h>

int main(){

int gst_arr[4];
float price_arr[4];
char names[4][20];

for(int i=0;i<3;i++){

printf("price_arr[%d]",i);
scanf("%f",&price_arr[i]);


printf("gst_arr[%d]",i);
scanf("%d",&gst_arr[i]);



printf("enter the name:");
scanf("%s",&names[i]);

}





for(int i=0;i<3;i++){

printf("the price of %s is %f and gst is %d",names[i+1],price_arr[i],gst_arr[i]);

}




}
