#include<iostream>
using namespace std;
// Namespace declaration
namespace Autobot {

    // Variable
    int count = 5;

    // Function
    void displayCount() {
        cout << "Count = " << count << endl;
    }

    // Class
    class Demo {
    public:
        void show() {
            cout << "Inside Demo class of MyNamespace" << endl;
        }
    };
}

int main(){
Autobot::displayCount();
cout<<"Variable count:"<<Autobot::count<<endl;
Autobot::Demo obj;
obj.show();


return 0;
}
