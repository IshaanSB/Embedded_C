#include<iostream>
using namespace std;


int swap(int a,int b);
int swap_ptr(int *a,int *b);
int swap_ref(int &a, int &b);

int main(){
int a=1,b=2,c=3,d=4,e=5,f=6;
int *ptr;
ptr=&a;
int *&i=ptr;

*i=10;

swap(a,b);
cout<<"swap a,b"<<a<<" "<<b<<endl;
swap_ptr(&c,&d);
cout<<"swap c,d"<<c<<" "<<d<<endl;
swap_ref(e,f);
cout<<"swap e,f"<<e<<" "<<f<<endl;

return 0;
}

int swap(int a,int b){

int temp;

temp=a;
a=b;
b=temp;

return 0;
}

int swap_ptr(int *a,int *b){

int temp;

temp=*a;
*a=*b;
*b=temp;

return 0;
}

int swap_ref(int &a,int &b){

int temp;

temp=a;
a=b;

return 0;
}
