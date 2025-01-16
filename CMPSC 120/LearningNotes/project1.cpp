#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

using namespace std;
//Methods
//a function that checks if the entered number is a valid number and not a letter or string
int checkNum(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    //cin.fail() checks if the input is a letter or string and num <= 0 checks if the input is a negative number
    while (cin.fail() || num <= 0){ 
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "The number is not valid" << endl;
        cout << "Enter a number: ";
        cin >> num;
    }
    return num;
}


int main(){

checkNum();

return 0;
}