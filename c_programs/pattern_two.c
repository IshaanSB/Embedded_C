
#include<stdio.h>

int main()
{


for(int i=1;i<=7;i++){
	for(int j=1;(i<=4&&j<=i)||(i>=4&&j<=8-i);j++){
	printf("%d",j);

	} 
printf("\n");     


}





return 0;
}
