#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

int data;
struct Node* next;


} Node;

void iterate(Node* object){

//iterate till end of the linked list
while(object!=NULL){

object=object->next;//iteration logic update address with the next node
printf("the data is %d and the address of the object is %p",object->data,object->next);

}



}


int main(){

//not rying to store data, just want to store the address of the first node
//these are the actual nodes with memory and stuff basically
//defining the nodes, why pointers?
//to store the address of each next block of memory, naming them like this for easily understanding what they are
//anyway that is a standard of 8 bytes for all pointers
//just some random memory location
//size of the drefrenced thing is 12 bytes for our case
Node* head=NULL;                    
Node* one=NULL;
Node* two=NULL;
Node* three_last=NULL;
one=(Node*)malloc(sizeof(Node)); 
two=(Node*)malloc(sizeof(Node)); 
three_last=(Node*)malloc(sizeof(Node));
//head pointer contains address for the first node
head=one;
one->next=two;
two->next=three_last;
three_last->next=NULL;
//last next pointer doesn't point to any node indicating the end of the linked list

one->data=1;
two->data=2;
three_last->data=3;


iterate(one);

return 0;
}
