
// Academic Integrity Affidavit:
// I certify that this program code is my work. Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Ryan Reagle>
// Section: <003L>
// Assignment: Lab 03(Bonus)
//
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
double radius, height, volume,newVolume, newHeight, newRadius;
double PI = 3.14159;

//Inputs

cout << "Enter the radius of the dome: ";
cin >> radius;
cout << "Enter the height of the dome: ";
cin >> height;



//Processes

volume = (2.0/3.0 * PI * pow(radius, 3)) + (PI * pow(radius, 2) * height);


//Outputs

cout << "The volume of the dome is: " << volume << endl;

cout << "Adding one to the height and radius..." << endl;
newRadius = radius + 1;
newHeight = height + 1;
newVolume = (2.0/3.0 * PI * pow(newRadius, 3)) + (PI * pow(newRadius, 2) * newHeight);
cout << "The new volume of the dome is: " << newVolume << endl;

cout << "The new dome has " << newVolume - volume << " more volume than the original dome." << endl;





return 0;
}
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"plusone"
Enter the radius of the dome: 3
Enter the height of the dome: 8
The volume of the dome is: 282.743
Adding one to the height and radius...
The new volume of the dome is: 586.43
The new dome has 303.687 more volume than the original dome.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/