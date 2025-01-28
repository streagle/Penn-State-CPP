#include <iostream>
#include <iomanip>
#include <string>


using namespace std;
//Methods

string getInfo();

string getInfo(){
    string name;
    cout << "Enter your first and last name: ";
    getline(cin, name);
    return name;
}


int main(){
//Variables
string name;

name = getInfo();

cout << "Your Name: " << name << endl;
    



return 0;
}