#include<iostream>
using namespace std;




int main(){
int arr[5]={0,1,2,3,4};

int (&ref)[5]=arr;

ref[2]=20;
ref[3]=30;
ref[4]=40;
ref[1]=10;



for(int i=0;i<5;i++)
cout<<"new arr:"<<ref[i]<<endl;


return 0;
}

