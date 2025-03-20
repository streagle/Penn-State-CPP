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

//Functions

//Function to solve algebraic equations such as 2+3 = x and 2 + x = 5

double evalAlgebra(string equation){
    //check if the equation is valid
    if(equation.find('=') == string::npos){
        cout << "Invalid equation" << endl;
        return 0;
    }
    //find the position of the equal sign
    int pos = equation.find('=');
    //find the position of the operator
    int opPos = equation.find_first_of("+-*/");
    //find the position of the variable
    int varPos = equation.find_first_of("abcdefghijklmnopqrstuvwxyz");
    //find the position of the first number
    int numPos = equation.find_first_of("1234567890");
    //find the position of the second number
    int numPos2 = equation.find_first_of("1234567890", numPos+1);
    //find the operator
    char op = equation[opPos];
    //find the variable
    char var = equation[varPos];
    //find the first number
    double num1 = stod(equation.substr(numPos, varPos - numPos));
    //find the second number
    double num2 = stod(equation.substr(numPos2, pos - numPos2));
    //find the result
    double result = 0;
    switch(op){
        case '+':
            if(varPos < pos){
                result = num2 - num1;
            }else{
                result = num1 + num2;
            }
            break;
        case '-':
            if(varPos < pos){
                result = num2 + num1;
            }else{
                result = num1 - num2;
            }
            break;
        case '*':
            if(varPos < pos){
                result = num2 / num1;
            }else{
                result = num1 * num2;
            }
            break;
        case '/':
            if(varPos < pos){
                result = num2 * num1;
            }else{
                result = num1 / num2;
            }
            break;
    }
    return result;

}


//Methods



int main(){

    cout << evalAlgebra("2 + x = 5") << endl;
    cout << evalAlgebra("2 + 3 = x") << endl;
    cout << evalAlgebra("2 * x = 10") << endl;



return 0;
}