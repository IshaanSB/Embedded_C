#include<stdio.h>


int factorial(int n);


int factorial(int n){

int result=1;




while(n){



result=result*n;
n--;

}


return result;


}



int main(){
/*
int a=1;
int b;
b=factorial(a);
printf("b is:%d",b);
*/
int c=0;
int coeff=1;



//printf("\n");
for(int i=0;i<=3;i++){
	printf("\n");

//spaces loop depends on the value of the row, depending upon that the triangle row appropriately shifts

	for(int spaces=3-i;spaces>=0;spaces--){
	printf(" ");		
	}

	for(int j=0;j<=i;j++){
	
	coeff=factorial(i)/(factorial(j)*factorial(i-j));
	//printf("\n");
	printf("%d",coeff);
	printf(" ");
	}



}
printf("\n");
return 0;

}
