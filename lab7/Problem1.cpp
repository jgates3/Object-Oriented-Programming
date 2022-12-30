#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define size 15 // size of 15
class myClass {

    char arr[size]; // array of char

public:
    myClass(char c = ' ') { memset(arr, c, size); }
    // inline constructor that uses memset() to initialize the array to the constructor argument

    void print(){ // print out all characters in the array
    
        int i = 0;

        while (i < size){ // loops to end of array

            cout << arr[i] << endl; // prints each
            i++;
        }
    }
};

int main(){

    myClass myObj('a'); // object of myClass with requested letter
    myObj.print(); // prints the character
    
    return 0;
}