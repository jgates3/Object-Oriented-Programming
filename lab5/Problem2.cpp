#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Counted{  

private: //private initializations 
    int id;
    static int count;

public: 
    Counted() : id(count++){ // constructor (creates objects)
        cout << "This is the constructor! Creation is occurring! The id is " << id << endl; //prints the id of the specific object
    }
    ~Counted(){ // destructor (destroys object)
        cout << "This is the destructor! Deletion is occurring! The id is " << id << endl; //prints the id of the specific object
    }
};

int Counted::count = 0;

int main(){

    vector<Counted*> VectorCounter; //creation of vector
    int i = 0;

    while (i < 5){ //goes from 0 to 4 (total should be 5 statements stating they are being created and 5 statements stating they are being destroyed)
        VectorCounter.push_back(new Counted); //fill vector with pointers to new Counted Objects
        i++; //incrementations 
    }

    int size = VectorCounter.size(); //gets the size of the vector 
    int j = size; //j equals size

    while (j >= 0){ //loops until every vector is accessed and deleted 
        delete VectorCounter[j]; //delete all vectors (originally was gonna use pop_back() but couldn't get it to properly work)
        j--; //decrementations 
    }

    return 0;
}
