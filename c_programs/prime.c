#include<stdio.h>
int main(){
//value of number of divisors
int count=0;

for(int i=2;i<=40;i++){
	for(int j=1;j<=i;j++){
        if(i%j==0){
	count=count+1;
	}
        else{
        //skips to the next iteration/j value
        continue;
        }
	}
//prime number only has 1 and itself as a divisor
if(count==2){
printf("num is:%d\n",i);
}
//count is not resetting after incrementing, so we reset it each time we are checking a new number
count=0;


}

}



