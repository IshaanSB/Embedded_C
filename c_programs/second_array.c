#include<stdio.h>

void input(int *array,int size);
int largest(int *array,int size);
int smallest(int *array,int size);



int main(){

int size;
int largest_num=0;

printf("enter the size for the array");
scanf("%d",&size);
int array[size];



input(array,size);


largest_num=smallest(array,size);
printf("the second smallest number is:%d\n",largest_num);

return 0;
}

void input(int *array,int size){

for(int i=0;i<size;i++){

printf("enter the value of arr[%d]:\n",i);
scanf("%d",&array[i]);

}





}




int largest(int *array,int size){
int larger=0;
int second_larger=0;

larger=array[0];
second_larger=array[1];
if(second_larger>larger)
{
int temp=larger;
larger=second_larger;
second_larger=temp;

}// larger=3, second_larger=2

//[3,2,4,1,5], [6,3,4,7,1] larger=6, second_larger=3

//[2,4,3,x,x] second_larger=2, larger=3
for(int i=2;i<size;i++)
{  //4>6
if(array[i]>larger)//4>3 larger=3
{
 second_larger=larger;//second_larger=3
 larger=array[i];//larger=4
 }
 else if(array[i]>second_larger)//4>3
 {
 second_larger=array[i];//second_large=4
 }

}

return second_larger;

}


int smallest(int *array,int size){

int second_smaller=array[1];
int smaller=array[0];

if(second_smaller<smaller){
int temp=second_smaller;
second_smaller=smaller;
smaller=temp;
}


for(int i=2;i<size;i++){
if(array[i]<smaller){
second_smaller=smaller;//put it as the old smaller element
smaller=array[i];
}

else if(array[i]<second_smaller){
second_smaller=array[i];
}

}

return second_smaller;
}
