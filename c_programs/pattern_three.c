
#include<stdio.h>
int main()
{
int spaces=0;
for(int i=1;i<=7;i++){
//printf("   ");
        if(i<=4){
	spaces=4-i;
	for(spaces=4-i;spaces>=1;spaces--){
	printf(" ");
	}
	}
	else{
	spaces=1;
	for(spaces=1;spaces<=i-4;spaces++){
	printf(" ");
	}
	}

	
        
        
        for(int j=1;(i<=4&&j<=i)||(i>=4&&j<=8-i);j++){
        //printf(" ");
        //continue;
        printf("x");
	printf(" ");

        } 
         
printf("\n");     
}
return 0;
}
