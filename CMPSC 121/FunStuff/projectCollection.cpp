#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

//this project will allow two numbers to be  inputed by a user and then check if  the numbers are equal to or add to the sum of 20

using namespace std;
//Methods

bool checkSum(int num1, int num2, int x){
    if(num1 + num2 == x){
        return true;
    } // end of main function
    return false;
}

bool checkEqual(int num1, int num2, int x){
    if(num1 == x || num2 == x){
        return true;
    }
    return false;
}



    





int main(){
//Variables

int num1;
int num2;
int x;
double test = 1.6;
for (int i = 1; i <= 10; i++){
    cout << i;
}
cout << endl;
cout << floor(test) << endl;
cout << ceil(test) << endl;






//Inputs
/*
cout<< "Enter the number you want to check for: ";
cin >> x;
cout << "Enter the first number: ";
cin >> num1;
cout << "Enter the second number: ";
cin >> num2;




//Processes


//Outputs
if(checkEqual(num1, num2, x)){
    cout << "At least one of the numbers is equal to 20" << endl;
}
else if(checkSum(num1, num2, x)){
    cout << "The sum of the numbers is equal to " << x << endl;
}
else{
    cout << "The numbers are not equal to 20 or add to " << x << endl;
}
*/

// evenOrOdd([1,2,3]); // This line is invalid and has been commented out

return 0;
}

