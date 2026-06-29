/*P9.6 Pointer to pointer*/
#include<stdio.h>
int main(void)
{
	int a=5;
	int *pa;
	int **ppa;
	pa = &a;
	ppa = &pa;
	printf("Address of a=%p\n",&a);
	printf("Value of pa=Address of a=%p\n",pa);
	printf("Value of *pa=Value of a=%d\n",*pa);
	printf("Address of pa=%p\n",&pa);
	printf("Value of ppa=Address of pa=%p\n",ppa);
	printf("Value of *ppa=Value of pa(address of a)=%p\n",*ppa);
	printf("Value of **ppa=Value of a=%d\n",**ppa);
	printf("Address of ppa=%p\n",&ppa);
	return 0;
}

//double pointers; they store the address of the pointer variable, dereferncing them once gives the address of the normal variable, (in other words the
//value at the address of the pointer (pa). Dereferencing one more time gives the value of the variable a itself.

//9.7 , printing elements in the array and figuring out their addresses

/* P9.9 Program to print the value of array elements using pointer and subscript notation */
#include<stdio.h>
int main(void)
{
	int arr[5] = {5,10,15,20,25};
	int i=0;
	for(i=0; i<5; i++)
	{
		printf("Value of arr[%d] = ",i);
		printf("%d\t",arr[i]);
		printf("%d\t",*(arr+i));
		printf("%d\t",*(i+arr));
		printf("%d\n",i[arr]);
		printf("Address of arr[%d] = %p\n",i,&arr[i]);
	}
	return 0;
}
// different ways of handling pointers wrt arrays

/*P9.10 Program to print the value and address of array elements by subscripting a pointer variable*/
#include<stdio.h>
int main(void)
{
	int arr[5]={5,10,15,20,25};
	int i,*p;
	p=arr;		
	for(i=0; i<5; i++)
	{
		printf("Address of arr[%d]= %p %p %p %p\n",i,&arr[i],arr+i,p+i,&p[i]);
		printf("Value of arr[%d]= %d %d %d %d\n",i,arr[i],*(arr+i),*(p+i),p[i]);
	}
	return 0;
}
// & operator and directly calling array name and p, results in calling the address.
//* dereferences and gets the value at an address
//9.11 helps us to understand the difference between int (*ptr)[5] (pointer to an entire int array of 5 elements)
//and int *p or int *ptr[5] (array of pointers)
// ptr=&arr, same as p=arr, both technically give the address of the 1st element in the array as that is the start
//then when the incrementing happens, the pointer to the array get incremented by array size x size of data type
// so it's 20 bytes and not 4 as you would expect
// never write ptr=arr if it is a pointer to an array of integers, not a single integer
//arr decays to &arr[0] which is only the address of an element
//so there is a mismatch between int* and int* [5]

//9.13 and 9.14 teach us about a major plot point in c-programming.
//the difference between pointer to an array of integers and an array of pointers in  a sense
//the concept of pointer to an array is used  in a 2d array because in the 2d array, each row
//consists of a 1d array with the number of elements being equal to the number of columns in the array
//so coming to the caveat, the point is that when you use the following syntax
/(arr+i) and *(arr+i), with the %p format specifier, they both return the same address value of course, in hex
//why? because whhile arr decays to a pointer to each row, the pointer to each row has to hold the address
//of the 1st element anyway, because the starting location of the 1st array /row, is the same as the very 1st\
//element. the only difference is that the offset is not 4 bytes like in a regular int* pointer
//it is actaully sizeof(int[columns]) in the 2d array, and of course you get the point if it is 3d 
//while if you dereference it, *(arr+i), now that means it is saying we want the value at that address for that ith row
//in other words this is the pointer to the 1st element of the array in any ith row. So what does that correspond to?
//THE SAME 1st element, hence it prints the same address as the previous one, but now when you add an integer
//like j, it is now the regular offset of 4 bytes because we are now pointing to addresses of regular integers
//which are 4 bytes not arrays, hence why these are different.

//9.15 is just the extension of the same concepts to a 3d array
//9.16 classic pass by value
//9.17 pass by rference to directly perform the modification
//at the memory locations of the variables in mains stakc frame
//makes it prone to detsruction of stack frame of our oeprator function(function used
//to perfrom modification)
//9.19 a fucntion that returns a pointer datatype, once again, a way of bypassing this ref by value emthod
//output will be an address/i.e. the return value, which of course can be captured by a pointer
//then we can print the addres, or dereference it and get the value at that address
//9.22 perfectly demonstrates how you need to pass by value for a 2d array by using a pointer to
//a pointer to an array
//9.23 is an array of pointers (as the name suggests each element of such an array are just pointers)
//9.24 storing the address of each element of an array in an array of pointers.(better to use pointers to arrays) 
//in a way
//in 9.25 it is far more easier and efficient to understand the use of an array of pointers
//9.27 , error in the code , never try to assign a value something you typecasted as it is 
//only temproary for a single side and line instruction, so
//if you typecast to a float, only typecast the variable or pointer owhatver
//the rest will get promoted accordingly
//9.28 is  just about dynamic memory allocation which you are well aware of
//9.29 is about the realloc function, how it can be used to
//get memory for more integers
//9.30 is all about accessing dynamically allocated memory
//as a 1d array, treating that pointer as an array, as it will allocate memory in a contiguous manner
//continue from 9.31


/*P9.31 Program to dynamically allocate a 2-D array using pointer to an array*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i,j,rows;
	int (*a)[4];
	printf("Enter number of rows : ");
	scanf("%d",&rows);
	a = (int(*)[4])malloc(rows*4*sizeof(int));
	for(i=0; i<rows; i++)
		for(j=0; j<4; j++)
		{
			printf("Enter a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	printf("The matrix is :\n");
	for(i=0; i<rows; i++)
	{
		for(j=0; j<4; j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	free(a);
	return 0;
}

//in this program we are allocating memory for a 2d array in the following way;
//first we are defining a pointer to an array for a certain number of elements, in this case 4
//so now it can point to a 4 element array, then we are using dynamic memory allocation to initialze a 2d array
//with number of 4 eleemnt arrays equal to the number of rows, (typecasted to be a pointer to an array of 4 elements
//in a memory block sense, allocate a block of memory(unbroken) of size rows*4, then by typecasting,
//break this block, into segments of size 4, where the number of segments available are the number of rows
//note that we don't need to specify the rows part, by specificying the size of the segment, we have
//already specified the number of rows bceause total size of the block was already specified as rows*4
//last few programs 9.36,9.37, 9.38

//in 9.35 was the concept of function pointers, was applied.
//(basically a pointer which points to a function, storing the address of the starting of the function
//in the text segment

//9.38 was interesting, as we investigated an array of function pointers, with each element in the array pointing 
//to the starting address of each of the functions in the text segment. So this is really nice
//as if we want to perform certain number of operations say 400, and wanted to display all of them
//or just perofrm 1, either way it is more efficient to use this rather than if else or switch case
//as their time-complexity O(N) scales linearly while this reduces them a constant time-complexity O(1)
//you directly go to their starting address in the text segment

