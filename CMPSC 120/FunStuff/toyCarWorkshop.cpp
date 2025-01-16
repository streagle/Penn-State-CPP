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
int wheels, body,figures,numberOfCars;




//Inputs

//get the user input on the total of wheels, bodies, and figures
cout << "Welcome to the toy car workshop!" << endl;
cout << "Enter the number of total wheels: ";
cin >> wheels;
cout << "Enter the number of total bodies: ";
cin >> body;
cout << "Enter the number of total figures: ";
cin >> figures;



//Processes

//calculate the total number of cars  that can be made from each
numberOfCars = min(wheels/4, min(body, figures/2));


//find the minimum number of cars that can be made



cout << "The total number of cars that can be made is: " << numberOfCars << endl;



//Outputs



return 0;
}