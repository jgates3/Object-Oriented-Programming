#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include <iostream>

class myClass{ //myclass creation
public:
    class MyException { //nested class
         const char *myString; //private
    public:
        MyException(const char *str) {
            myString = str; 
            }; //takens in a single char as its argument
    
    void printException() { //prints out exception
        cout<<myString<<endl;
    }
    };
    
    void myFun(){ 
        throw MyException ("Throw successful."); //throws the exception
        }
};


int main(){
    myClass myobj; //create an object of myclass
    
    try { //try block 
        cout << "Try Successful" <<endl;
        myobj.myFun();
    }
    catch (myClass::MyException accessor){ //catch cause that handles the exception by printing out the description string
        cout << "Catch Successful" <<endl;
        accessor.printException();

    }
   
    return 0;
}