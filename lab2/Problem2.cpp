#include <iostream>

using namespace std;

class SecondClass; //declaration of second class so that firstclass can have it in memfunction
class FirstClass {
    public: 
        int a = 10; //used as a tracker to where it outputs (helps see the classes'interactions with the pointer of an object)
        int memberFunction(SecondClass *second, int a); //declares memberFunction which takes a pointer of an object in secondclass
};

class SecondClass {
    public:
        int b = 20; //used as a tracker to where it outputs (helps see the classes'interactions with the pointer of an object)
        int memberFunction2(FirstClass *first, int b); //declares memberFunction which takes a pointer of an object in firstclass
};

    int FirstClass::memberFunction(SecondClass *second, int a) { //used to define a function outside a class (compiler looks at firstclass for memberFunction)
    int numoutput = (*second).b; // accesses the members of the class/structure through a pointer (can also be written as second -> b)
        return numoutput;
}
    int SecondClass::memberFunction2(FirstClass *first, int b) { 
    int num2output = (*first).a; //accesses the members of the class/structure through a pointer
        return num2output;
}

int main() {

    FirstClass first; //class objects
    SecondClass second;
    int numoutput;
    int num2output;
    int x;
    int y;
    numoutput= first.memberFunction(&second, x); //accesses class and memberfunction with pointer of an object from another class (instances that call memberfunctions)
    num2output =second.memberFunction2(&first, y);
    cout<<"Firstclass is used and its function memberFunction is used with a paramater of &second: "<< numoutput <<endl;
    cout<<"Secondclass is used and its function memberFunction2 is used with a paramater of &first: "<< num2output <<endl;  

return 0;
}