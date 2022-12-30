#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Counted{

private: //private initializations 
    int id;
    static int count;

public: //public
    Counted() : id(count++){ // constructor (creates objects)
        cout << "This is the constructor! Creation is occurring! The id is " << id << endl; //prints the id of the specific object
    }
    ~Counted(){ // destructor (destroys object)
        cout << "This is the destructor! Deletion is occurring! The id is " << id << endl; //prints the id of the specific object
    }
};

int Counted::count = 0; 

int main(){

    Counted obj1; // five objects result in five things being created and destroyed
    Counted obj2;
    Counted obj3;
    Counted obj4;
    Counted obj5;

    return 0;
}
