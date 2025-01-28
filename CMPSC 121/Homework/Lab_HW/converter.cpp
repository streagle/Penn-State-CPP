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
// Assignment: Lab 09
//

#include <iostream>
#include <iomanip>


using namespace std;
//Methods
void getTemperature(double temp[], int size){
    for(int i = 0; i < size; i++){
        do {
            cout << "Enter celcius temperature " << i + 1 << ": ";
            cin >> temp[i];
            if(temp[i] < -273.15){
                cout << "Temperature cannot be below absolute zero (-273.15 C)." << endl;
            }
        } while(temp[i] < -273.15);
    }
}

void convertTemperature(double c_temp[], double f_temp[], int size)
{
    for(int i = 0; i < size; i++){
        f_temp[i] = c_temp[i] * 9 / 5 + 32;
    }
}



int main(){
//Variables
const int size = 4;



//Inputs


double c_temp[size];
double f_temp[size];

getTemperature(c_temp, size);
convertTemperature(c_temp, f_temp, size);

for(int i = 0; i < size; i++){
    cout << "The temperature in Celsius is " << c_temp[i] << " and the temperature in Fahrenheit is " << f_temp[i] << endl;
}
return 0;
}

/* -------------------------------------------------------------------------- */
/*                                 Test Cases                                 */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % cd "/Users/ryanreagle/Documents/GitHub/Penn State Comp Sci/psuCPP/Homework/Lab_HW/outp
ut"
./"converter"                                                                                                                 
ryanreagle@Ryans-MacBook-Pro-2 output % ./"converter"
Enter celcius temperature 1: -274
Temperature cannot be below absolute zero (-273.15 C).
Enter celcius temperature 1: -31
Enter celcius temperature 2: 0
Enter celcius temperature 3: 13.25
Enter celcius temperature 4: 100
The temperature in Celsius is -31 and the temperature in Fahrenheit is -23.8
The temperature in Celsius is 0 and the temperature in Fahrenheit is 32
The temperature in Celsius is 13.25 and the temperature in Fahrenheit is 55.85
The temperature in Celsius is 100 and the temperature in Fahrenheit is 212
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/