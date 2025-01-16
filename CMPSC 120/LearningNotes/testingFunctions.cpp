#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;
//Methods
void checks(){
    char x = '2';
    if (isalnum(x)){
        cout << "The character is alphanumeric." << endl;
    }
    else{
        cout << "The character is not alphanumeric." << endl;
    }
    if (isalpha(x)){
        cout << "The character is alphabetic." << endl;
    }
    else{
        cout << "The character is not alphabetic." << endl;
    }
    if (isdigit(x)){
        cout << "The character is a digit." << endl;
    }
    else{
        cout << "The character is not a digit." << endl;
    }
}



int main(){
//Variables


//Inputs



//Processes




//Outputs
checks();



return 0;
}