//E 3.1 to 
// P2.1 Program to find out the size and limits of data types
/*

// 2s complement representation of sizes and max values and why format specifier is so important to give correct 
//values for these different numbers
#include<stdio.h>
#include<limits.h>
#include<float.h>
int main(void)
{
	printf("sizeof(char) = %u\n",sizeof(char));
	printf("sizeof(short) = %u\n",sizeof(short));
	printf("sizeof(int) = %u\n",sizeof(int));
	printf("sizeof(long) = %u\n",sizeof(long));
	printf("sizeof(float) = %u\n",sizeof(float));
	printf("sizeof(double) = %u\n",sizeof(double));
	printf("sizeof(long double) = %u\n",sizeof(long double));

	printf("SCHAR_MIN = %d\n",SCHAR_MIN);
	printf("SCHAR_MAX = %d\n",SCHAR_MAX);
	printf("UCHAR_MAX = %d\n",UCHAR_MAX);
	
	printf("SHRT_MIN = %d\n",SHRT_MIN);
	printf("SHRT_MAX = %d\n",SHRT_MAX);
	printf("USHRT_MAX = %u\n",USHRT_MAX);
		
	printf("INT_MIN = %d\n",INT_MIN);
	printf("INT_MAX = %d\n",INT_MAX);
	printf("UINT_MAX = %u\n",UINT_MAX);
	
	printf("LONG_MIN = %ld\n",LONG_MIN);
    printf("LONG_MAX = %ld\n",LONG_MAX);
    printf("ULONG_MAX = %lu\n",ULONG_MAX);
    
	printf("FLT_MIN = %e\n",FLT_MIN);
	printf("FLT_MAX = %e\n",FLT_MAX);

	printf("DBL_MIN = %e\n",DBL_MIN);
	printf("DBL_MAX = %e\n",DBL_MAX);

	printf("LDBL_MIN = %Le\n",LDBL_MIN);
	printf("LDBL_MAX = %Le\n",LDBL_MAX);

	Number of digits of precision
	printf("FLT_DIG = %d\n",FLT_DIG);
	printf("DBL_DIG = %d\n",DBL_DIG);
	printf("LDBL_DIG = %d\n",LDBL_DIG);
	return 0;
}
/*

//character and string modification
/*
E3.2
#include<stdio.h>
int main(void)
{
	printf("Indiankabakc\b \n");  							
	printf("New\rhi\n");
	return 0;
}
*/

/*
//integer overflow
#include<stdio.h>
//max value of different data types and numbers
#include<limits.h>
int main(void)
{
	//perfect! we are now in place for the demonstartion of the important concept of signed overflow, which occurs
// as this number is far too large to be represented in 2s complement format in the signed integer so, instead compiler
// takes 4 billion to be a negative number by the look of the msb, so it instead gives the 2s complement representation
// of whatever bits can be represented,resulting in wrong result	
//solution: long int , if you want to support negative numbers, unsigned int if you want to support only positive num
//-bers


	int a=4000000000;
	unsigned int b=4000000000;
	printf("a=%ld, b=%u\n",a,b);
	printf("%d, %u\n",INT_MAX,UINT_MAX);
	return 0;
}


/* 


//%d specifier for a character stored in a type 'char' variable results in the printing of its ascii value
/*E3.5*/
/*
#include<stdio.h>
int main(void)
{
	char ch;
	printf("Enter a character : ");
	scanf("%c",&ch);
	printf("%c\n",ch);
	return 0;
}
*/
//integer value of 98, represents some character according to  the ascii table, the conversion is known as default ar
//-gument promotion
/*E3.8*/
/*
#include<stdio.h>
int main(void)
{
	int a=98;
	char ch='c';
	printf("%c,%d\n",a,ch);
	return 0;
}
*/

//for the float extra decimal places .000003 was added even though it wasn't present in the original number
//%f-->all decimal places,%.2f-->2 decimal places, %.3f-->3 decimal places.
/*E3.6*/
/*
#include<stdio.h>
int main(void)
{
	float b=123.1265;
	printf("%f\t",b);
	printf("%.2f\t",b);
	printf("%.3f\n",b);
	return 0;
}
*/
/*
//E3.9
#include<stdio.h>
int main(void)
{
	float a1,b1,a2,b2,a3,b3;
	a1=2;
	b1=6.8;
	a2=4.2;
	b2=3.57;
	a3=9.82;
	b3=85.673;
	printf("%3.1f,%4.2f\n",a1,b1);
	printf("%5.1f,%6.2f\n",a2,b2);
	printf("%7.1f,%8.2f\n",a3,b3);
	return 0;
}
*/


//prefix incr/decr change the value first then the printing of the updated value of x is done
//note:the update happens within the one line statement itself
//with postfix, the printing of the current value of x would happen, then the change, and
//finally, when we write a printf statement on the next line, we would see the updated value


/*
#include<stdio.h>
int main(void)
{
	int x=8;
	printf("x=%d\t",x);
	printf("x=%d\t",++x);	//Prefix increment
	printf("x=%d\t",x);
	printf("x=%d\t",--x);	/Prefix decrement
	printf("x=%d\n",x);
	return 0;
}
*/



//the postfix inc4/decr, as aforementioned, the change happens after the execution of the print statement with 
//the current x value, then after it gets incr/decr , then the new value is printed in the next line/next  printf 
//statement
/*
#include<stdio.h>
int main(void)
{
	int x=8;
	printf("x=%d\t",x);
	printf("x=%d\t",x++);	//postfix increment
	printf("x=%d\t",x);
	printf("x=%d\t",x--);	//postfix decrement
	printf("x=%d\n",x);
	return 0;
}

*/
//understood P4.2.c
/*
#include<stdio.h>
int main(void)
{
	float a=12.4,b=3.8;
	printf("Sum=%.2f\n",a+b);
	printf("Difference=%.2f\n",a-b);
	printf("Product=%.2f\n",a*b);
	printf("a/b=%.2f\n",a/b);
	return 0;
}
*/


