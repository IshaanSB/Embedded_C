#include<iostream>
using namespace std;

class ishaan{

public:
int age;
float height;

void get(float h,int a){

age=a;
height=h;

}

void display(){

cout<<"height=,"<<height<<"age="<<age<<endl;


}


};




int main(){


ishaan i1,i2;

i1.get(180.8,20);
i2.get(100.8,10);

i1.display();
i2.display();

return 0;
}
