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



int main(){
//Variables

int numbers[5] = {1, 5, 3, 8, 5};
int position;



//Inputs
cout << "enter the position of the number you want to see: ";
cin >> position;
position = position - 1;

cout << "The number at position " << position + 1 << " is: " << numbers[position] << endl;




//Processes



//Outputs



return 0;
}