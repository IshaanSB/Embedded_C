/*E4.22*/

/*
#include<stdio.h>
int main(void)
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("Octal - %o, Hexadecimal - %x\n",n,n);
	return 0;
}
*/
//4.21, 4.20, 4.1 is simple no need to look
//4.3,4.2 simple programs based on logical operators
//4.23, 4.8E, 5.18P also
//5.1-5.1
//taking transpose of a matrix by  interchanging rows and columns in a matrix.
/*P8.13 Tranpose of matrix. */

/*
#include<stdio.h>
#define ROW 3
#define COL 4
int main(void)
{
	int mat1[ROW][COL], mat2[COL][ROW],i,j;
	printf("Enter matrix mat1(%dx%d) row-wise : \n",ROW,COL);
	for(i=0; i<ROW; i++)
		for(j=0; j<COL; j++)
			scanf("%d",&mat1[i][j]);
	
	for(i=0; i<COL; i++)
		for(j=0; j<ROW; j++)
			mat2[i][j]=mat1[j][i];

	printf("Transpose of matrix is:\n");
	for(i=0; i<COL; i++)
	{
		for(j=0; j<ROW; j++)
			printf("%5d",mat2[i][j]);
		printf("\n");
	}
	return 0;
}
*

/*P5.12 Program to find the factorial of any number*/
#include<stdio.h>
int main(void)
{
	int n,num;
	//use unsigned long long for extension, it is gonna give an even bigger range of factorials.
	long fact=1;
	printf("Enter a number : ");
	scanf("%d",&n);
	num=n;
	if(n<0)
		printf("No factorial of negative number\n");
	else
	{
		while(n>1)
		{
			fact*=n;
			n--;
		}
		printf("Factorial of %d=%ld\n",num,fact);
	}
	return 0;
}

/*P5.25 Program to print Armstrong numbers*/
//input number= sum of digits with each digit raised to the power equal to the total number of digits
#include<stdio.h>
int main(void)
{
	int num,n,cube,d,sum;
	printf("Armstrong numbers are :\n");

	for(num=100; num<=999; num++)	/*outer loop to generate numbers*/
	{
		n=num;
		sum=0;
		while(n>0)	/*inner loop to calculate sum of cube of digits*/
		{
			d=n%10;
			n/=10;
			cube=d*d*d;
			sum=sum+cube;
		}/*End of while loop*/
		if(num==sum)	
			printf("%d\n",num);
	}/*End of for loop*/
	return 0;
}


/*P9.1 Program to print address of variables using address operator*/
//helps me understand use of %p, which is used to print the address of the values that are stored in age and salary
#include<stdio.h>
int main(void)
{
	int age=30;
	float salary=1500.50;
	printf("Address of age=%p\n",&age);
	printf("Address of salary=%p\n",&salary);
	return 0;
}


/*P9.2 Dereferencing pointer variables*/
#include<stdio.h>
int main(void)
{
    
	int arr[5]={1,787,3,4,5};
	/*
	for(int i=0;i<5;i++){
	    printf("The values are:%d\n",*(arr+i));
	    
	}
	*/
	
	int* ptr=&arr[0];
	*ptr++; // same as *(ptr=ptr+1) but only that value is 1st assigned then incremented
	
	printf("%d\n",*ptr);
	
	
	
}
/* P5.26 Program to find the sum of digits of a number until the sum is reduced to 1 digit.
   For example -  538769->38->11->2 */
#include<stdio.h>
int main(void)
{
	long num;
	int dig,sum;
	printf("Enter a number : ");
	scanf("%ld",&num);
	printf("%ld->",num);
	do
	{
		sum = 0; 
		while(num!=0) 
		{
			dig=num%10;
			sum+=dig;
			num/=10;
		}
		printf("%d\t",sum);
		num=sum;
	}while(num/10!=0);  /*while num is more than one digit*/	
	return 0;
}
