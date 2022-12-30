#include <iostream>
using namespace std;
string n; //user input variable
int mapper; //store a value in this variable for switch (essentially marks user input for a specific case)
int main(){
    
    while(true){ //infinite loop
        cout <<"Ice cream flavor list: Vanilla, Chocolate, Strawberry, Mint, Pistachio, Neapolitan, Mango, Sherbet, Coffee, Ube and Cheesecake.\n";
        cout<<"Enter a ice cream flavor from the list above!(Type stop or exit to end): ";
        cin>>n; //user input
        if (n == "stop" || n == "exit"){ //type stop or exit to kill program
            break;
}
        if (n == "Vanilla" || n == "vanilla"){ //identifies user input
            mapper = 1; //stores for switch

}
        else if (n == "Chocolate"|| n == "chocolate"){
                mapper = 2;

}
        else if (n == "Strawberry"|| n == "strawberry"){
                mapper = 3;

}

        else if (n == "Mint"|| n == "mint"){
                mapper = 4;

}
        else if (n == "Pistachio"|| n == "pistachio"){
                mapper = 5;

}
        else if (n == "Neapolitan"|| n == "neapolitan"){
                mapper = 6;

}
        else if (n == "Mango"|| n == "mango"){
                mapper = 7;

}
        else if (n == "Sherbet"|| n == "sherbet"){
                mapper = 8;

}
        else if (n == "Coffee"|| n == "coffee"){
                mapper = 9;

}
        else if (n == "Ube"|| n == "ube"){
                mapper = 10;

}
        else if (n == "Cheesecake"|| n == "cheesecake"){
                mapper = 11;

}
        else{   //for any value/word that isnt in the list
                mapper = 0;
}
    switch(mapper){ //goes to a certain case depending on what the mapper value is
        case 1: 
            cout<<"\nThe ice cream flavor you inputted was Vanilla and is the color white. \n";  
            cout<<"\n"; //visibility 
            break; //stops program
        case 2:
            cout<<"\nThe ice cream flavor you inputted was Chocolate and is the color brown.\n";  
            cout<<"\n";
            break;
        case 3:
            cout<<"\nThe ice cream flavor you inputted was Strawberry and is the color pink \n"; 
            cout<<"\n"; 
            break;
        case 4:
            cout<<"\nThe ice cream flavor you inputted was Mint and is the color green \n"; 
            cout<<"\n";
            break;
        case 5:
            cout<<"\nThe ice cream flavor you inputted was Pistachio and is the color green \n";   
            cout<<"\n";
            break;
        case 6:
            cout<<"\nThe ice cream flavor you inputted was Neapolitan and is the color pink, brown and white. \n";
            cout<<"\n";
            break;
        case 7:
            cout<<"\nThe ice cream flavor you inputted was Mango and is the color yellow \n"; 
            cout<<"\n";
            break;
        case 8:
            cout<<"\nThe ice cream flavor you inputted was Sherbet and is multi colored \n";  
            cout<<"\n";
            break;   
        case 9:
            cout<<"\nThe ice cream flavor you inputted was Coffee and is the color brown  \n";
            cout<<"\n";
            break;
        case 10:
            cout<<"The ice cream flavor you inputted was Ube and is the color purple \n"; 
            cout<<"\n";
            break;
        case 11:
            cout<<"\nThe ice cream flavor you inputted was Cheesecake and is the color white \n";  
            cout<<"\n";
            break;  
        default: //any input that isn't listed
            cout<<"Wrong input. Please input a flavor on the list \n";
            cout<<"\n";
            break;
}




}
}