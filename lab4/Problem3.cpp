#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

class Subject{       // base class Subject
public: // three functions below
    virtual void f(){
        cout << "Class Subject and Function f() is called here!" << endl;
    }
    virtual void g(){
        cout << "Class Subject and Function g() is called here!" << endl;
    }
    virtual void h(){
        cout << "Class Subject and Function h() is called here!" << endl;
    }
};
class Implementation1: public Subject { //derived class of implementation1 (inheritance at works)
public:
    void f(){
        cout<<"Class Implementation1 and Function f() is called here!"<<endl;
    }
    void g(){
        cout<<"Class Implementation1 and Function g() is called here!"<<endl;
    }
    void h(){
        cout<<"Class Implementation1 and Function h() is called here!"<<endl;
    }

};
class Implementation2: public Subject { //derived class of implementation2 (inheritance at works)
public:
    void f(){
        cout<<"Class Implementation2 and Function f() is called here!"<<endl;
    }
    void g(){
        cout<<"Class Implementation2 and Function g() is called here!"<<endl;
    }
    void h(){
        cout<<"Class Implementation2 and Function h() is called here!"<<endl;
    }

};
class Proxy: public Subject{ //derived class of proxy and base class of subject
private:
    Subject* SubPoint; //has a pointer to a subject
public:

    void f(){
        SubPoint -> f(); //accesses function/members
    }
     void g(){
        SubPoint -> g(); //accesses function/members 
    }
    void h(){
        SubPoint -> h(); //accesses function/members 
    }
    Proxy (Subject* t): Subject(), SubPoint(t){} //essential code for implementation switches (t is temp)

    Subject*rewrite(Subject* pointer1){
        SubPoint = pointer1; //rewrites and makes pointer 1 equal subpoint
        return SubPoint; //return subpoint 
    
    }

};
int main(){
    Implementation1 x; //two different implementations that is used by proxy
    Implementation2 y;
    Subject* output; //initialize z
    Proxy prox(&x); 
    //calls to functions that call implementation 1 and print implementation 1 print statements 
    prox.f();
    prox.g();
    prox.h();
    output = prox.rewrite(&y); //changes implementation into implementation 2
    //calls to functions that call implementation 2 and print implementation 2 print statements 
    prox.f();
    prox.g();
    prox.h();

return 0;
}