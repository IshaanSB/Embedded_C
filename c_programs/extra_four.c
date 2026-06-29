/*P5.39 Program to multiply two numbers by russian peasant method*/
#include<stdio.h>
int main(void)
{
	int a,b,x,y,s=0;
	printf("Enter two numbers to be multiplied : ");
	scanf("%d%d",&x,&y);
	a = x;
	b = y;
	while(a>=1)			/*Loop till first number reduces to 1*/ 
	{
		if(a%2!=0)		/*If first number is odd*/
			s=s+b;		/*Add second number to s*/
		a/=2;			/*Divide first number by 2*/	
		b*=2;			/*Multiply second number by 2*/
	}
	printf("%d * %d = %d\n",x,y,s);
	return 0;
}
//effectively using binary representation of the number

//(5.1-pyramids)all of control operators demo programs done. excercises later (focus on reaching pointers, structures, and 
//recursion


//starting from 6.1, 6.13 uses logic of triangles, and herons formula for area

// 6.16 is interesting, static variables have a global lifetime and local scope (only
// the func in which it is declared) can see it
//furthermore each time the function call ahppens, a stack frame is created, then once the function ends
// the stack frame is destroyed and removed hence the a variable value is destroyed and has to be reinitialized once 
// again, the static variable due to it being able to hold values till the program completes its execution
// just updates its value
//reversing the number based (6.17)
//based on powers iof 10 in decimal system and extracting digits by mod 10
// can count only till sqrt of n , as ultimtely factor pairs just come out in reverse after sqrt(n) ^ 2
// to avoid floating point errors use i*i<=n, to safely round to integers
//6.22 exponent prgram constructed using double datatype
//6.21 converts it into a binary number using the clever trick of acuumulating
// the binaru number as 0 s and ones by multiplication by 10 (decimal) 	which you can think of as binary
//in a way, works as a place value shifter
// 6.23 generalized to base 2 and 8
//6.24 permutation and combinations in terms of factorial function

/*P7.5 Program to convert a positive decimal number to Binary, Octal or Hexadecimal */
// converting a number into different bases 2, 8, 16 

#include<stdio.h>
void convert(int, int);
int main(void)
{
	int num;
	printf("Enter a positive decimal number : ");
	scanf("%d",&num);
	convert(num,2);
	printf("\n");
	convert(num,8);
	printf("\n");
	convert(num,16);
	printf("\n");
	return 0;
}/*End of main()*/

void convert(int num,int base)
{
	int rem=num%base;
	
	if(num==0)
		return;
	convert(num/base,base);
	
	if(rem<10)
		printf("%d",rem);	
	else
		printf("%c",rem-10+'A');
}/*End of convert()*/
//7.8 uses comparison between recursive and iterative implementations of the algorithm

//7.12 tail recursion requires a hlper function to esnure
// no corruption happens with the second/additional argument being the accumulator value
//your user doesn't need to understand the internal workings of the function, hence thius
// is necessary , as we can just call the original fucntion directly from this 2nd function
//so the logic in binary search, is start from the middle, change your ending points,
//depending upon whether your items is lesser or larger, this will change
//the direction of iteration(we aren't writing sperate loops, we are
//using the same loop to iterate in a smarter way


/*P7.13 Program to search an element through binary search*/
#include <stdio.h>
#define SIZE 100
int binary_search(int arr[],int item, int low, int high);
int main(void)
{
	int arr[SIZE],i, item, n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter elements of the array(in sorted order) : \n");
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	printf("Enter the item to be searched : ");
	scanf("%d", &item);
	
	i=binary_search(arr,item,0,n-1);
	if(i==-1)
		printf("Not Present\n");
	else
		printf("Present at index %d\n",i);
	return 0;
}/*End of main()*/

int binary_search(int arr[],int item,int low,int up)
{
	int mid;
	if(up < low)
		return -1;	/*not found*/
	mid=(low+up)/2;
	if(item > arr[mid])
		return binary_search(arr,item,mid+1,up);	/*Search in right portion, tail recursive call*/
	else if(item  < arr[mid])
		return binary_search(arr,item,low,mid-1);	/*Search in left portion, tail recursive call*/
	else
		return mid;	/*found*/
}/*End of binary_search()*/
//the logic implemented
// do further optimization using malloc, calloc, pointers
//if you can think about it
//9.2 is about dereferencing pointers in different ways, one thing you can do is,
//pointers will store the addresses of variables, to print these addresses, you would use %p
//now you can pass the address of the pointers themselves to the variables p1,p2
//then the addresses/memory locations of the pointer variables get printed.

//go to extra_five to learn about the next exciting part about c programming. Pointers and structures

