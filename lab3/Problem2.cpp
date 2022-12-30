#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

class Text {
   public:
    string textfileholder; //holds textfile
    string stored;         //output returned to see text
    Text();                //constructor 
    Text(string textfileholder);  //destructor
    string contents();    //member function
}; 
   Text::Text(){
      stored = "I am the default constructor!"; //default constructor asked to be implemented by question
   }

    Text::Text(string textfileholder){ //other constructor (also accesses Text variables)
      string line;
      fstream file;
      string output;
      file.open(textfileholder, ios::in); //opens the file
      
    if (file.is_open()){
        while(getline(file, line)){
            output = line + "" + output; //gets the text in the file
        }
        stored = output; //stores it to be called later 
        file.close(); //close 
     }
     }
     string Text:: contents(){   //accesses text variables and returns output
         return stored;

     }

int main(){
   Text a ("test.txt"); //inputted text and accesses class
   string x = a.contents(); //call to contents to print output
   cout<<x<<endl; //output

}