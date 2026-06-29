
/*P4.9 Program to understand the sizeof operator
#include<stdio.h>
int main(void)
{
	int var;
	printf("Size of int=%u\n",sizeof(int));
	printf("Size of float=%u\n",sizeof(float));
	printf("Size of var=%u\n",sizeof(var));
	printf("Size of an integer constant=%u\n",sizeof(45));  
	return 0;
}
///4.11 c
*/
//only need to typecast one variable to get a decimal result, as floating point numbers have
//higher bytes than integer, hence integer is promoted to float
// if you don't typecast c does integer division, throws away the remainder and promotes integer 2 to
//floating point num 2.00000
/*
#include<stdio.h>
int main(void)
{
	int x=5,y=2;
	float p,q;
	p=x/y;		
	printf("p=%f\n",p);
	q=(float)x/y;
	printf("q=%f\n",q);
	return 0;
}
*/

//C compiler automatically recognizes the different datatypes and does conversion on its own
//c2 gets ascii value of character given to it by the integer i1
/*P4.10 Program to understand type conversion in assignment*/
/*
#include<stdio.h>
int main(void)
{
	char c1,c2;
	int i1,i2;
	float f1,f2;
	c1='H';	 
	i1=80.56;		//float converted to int, only 80 assigned to i1  
	f1=12.6;
	c2=i1;		//int converted to char 
	i2=f1;		//float converted to int 
	//Now c2 has the character with ASCII value 80, i2 is assigned value 12  
	printf("c2=%c,  i2=%d\n",c2,i2);
	f2=i1;			//int converted to float
	i2=c1;			//char converted to int 
	//Now i2 contains ASCII value of character 'H' which is 72
	printf("f2=%.2f,  i2=%d\n",f2,i2);
	return 0;
}
*/

//P4.7 Program to understand the use of comma operator

/*
#include<stdio.h>
int main(void)
{
	int a,b,c,sum;
	sum = (a=8,b=7,c=9,a+b+c);	
	printf("Sum=%d\n",sum);
	return 0;
}
*/

//P4.8 Program to interchange the value of two variables using comma operator
/*
#include<stdio.h>
int main(void)
{
 	int a=8,b=7,temp;
	printf("a=%d, b=%d\n",a,b);
	temp=a,a=b,b=temp;
	printf("a=%d, b=%d\n",a,b);
	return 0;
}
*/
//interchanging variables using a 3rd variable


/*P4.6 Program to print the larger of two numbers using conditional operator */
/*
#include<stdio.h>
int main(void)
{
	int a,b,max;
	printf("Enter values for a and b :");	 
	scanf("%d%d",&a,&b);
	//like how we use it for a 2x1 mux in digital design, here true means a will be returned, and false means b will be returned
	max = a>b ? a : b;		//ternary operator
	printf("Larger of %d and %d is %d\n",a,b,max);
	return 0;
}
*/

//#include<stdio.h>
/*P4.12 Program to evaluate some expressions*/

//we have to use the correct order of operations to evaluate the expressions, and then understand the program output
//so the precedence is as follows:parenthesis, mult, div, modulo (from left to right)
//then add , and subtraction
//for bitwise and logical, bitwise not, shift, and, xor, or, then logical and, or
/*
int main(void)
{
	int a,b,c,d,e,f,g,h,k;
	a=8, b=4, c=2, d=1, e=5, f=20;
	printf("%d\t", a+b-(c+d)*3%e+f/9);
	//result is 10 for first
	a=17, b=5, c=6, d=3, e=5;
	printf("%d\t",a%6-b/2+(c*d-5)/e);
	//5
	a=4, b=5, c=6, d=3, e=5, f=10;
	printf("%d\t",a*b-c/d<e+f);
	//0
	a=8, b=5, c=8, d=3, e=65, f=10, g=2, h=5, k=2;
	printf("%d\t",a-b+c/d==e/f-g+h%k);
	//1
	a=8, b=3, c=2, d=3, e=2, f=11;
	printf("%d\n",a-b||(a-b*c)+d&&e-f%3);
	//1
	return 0;
}		

*/

/*
//typecasting to show promotion of b to float datatype even if only one of the addends is a float
//variable, this shows how integer division always produces a whole number value
//E4.11
#include<stdio.h>
int main(void)
{
	float b;
	b = 15/2;
	printf("%f\t",b);
	b = (float)15/2 + (15/2);
	printf("%f\n",b);
	return 0;
}

/*E4.18*/
//If you compile this exact same code but turn on GCC's aggressive optimizations (using the -O3 flag), the compiler m
//ight decide to apply the sticky notes immediately instead of waiting. In that case, it would fetch 110, immediately
// increment a to 111, then fetch 111 for the second operand, and multiply them to get 12210 (110 * 111).
/*
#include<stdio.h>
int main(void)
{
	int a=10;
	a=a++;
	a = a++ * a--;
	printf("%d\n",a);
	printf("%d\n",a);
	printf("%d\n",a++ * a++);
	return 0;
}
		
*/

//comma operator forces the rightmost part of the expression to be added to the
//current value of k , hence k=22 after evaluating the expresssions inside the brackets
/*E4.10*/

/*
#include<stdio.h>
int main(void)
{
	int x,y,z,k=10;
	k+=(x=5, y=x+2, z=x+y);
	printf("x=%d, y=%d, z=%d, k=%d\n",x,y,z,k);
	return 0;
}
*/

//4.16 is just based on understanding of relational and logical operators, a=b (assignment), a==b conditional 
//to check if something is equal or not
//excercise on postfix incr and prefix incr (b increments after assigning value hence we see it update only
//after y is assigned
/*E4.19*/

/*
#include<stdio.h>
int main(void)
{
	int a=2,b=2,x,y;
	x = 4*(++a * 2 + 3);
	y = 4*(b++ * 2 + 3 );
	printf("a=%d, b=%d, x=%d, y=%d\n",a,b,x,y);
	return 0;
}
*/

//E4.9
/*
#include<stdio.h>
int main(void)
{
	int a=15,b=13,c=16,x,y;
	x = a-3%2+c*2/4%2+b/4;
	y = a = b+5-b+9/3;
	printf("x=%d, y=%d\n",x,y);
	return 0;
}
	*/


//understanding relational operators and assignment operators
/*E4.13*/
/*
#include<stdio.h>
int main(void)
{
	int a,b,c,d;
	a=b=c=d=4;
	a*=b+1;
	c+=d*=3;
	printf("a=%d, c=%d\n",a,c);
	return 0;
}
*/

/*E4.12*/
//the ch character gets converted into its ascii value 
/*
#include<stdio.h>
int main(void)
{
	int a=9;
	char ch='A';
	a=a+ch+24;
	printf("%d,%c\t%d,%c\n",ch,ch,a,a);
	return 0;
}
*/

//4.25 very simple program on float datatype and how addres
//4.17, 4.7,4.6,done

//4.4, 4.14, 4.24, 4.20

//4.25
/*E4.25*/
#include<stdio.h>
int main(void)
{
	float m1,m2,m3,m4,m5,per;
	printf("Enter marks : ");
	scanf("%f%f%f%f%f",&m1,&m2,&m3,&m4,&m5);
	per = (m1+m2+m3+m4+m5)/500 * 100;
	printf("Percentage = %f\n",per);
	return 0;
}
