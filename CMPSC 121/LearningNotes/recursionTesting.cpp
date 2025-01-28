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
int nSum(int n);
int fib(int n);
void pArray(int* arr, int n);



//adds each number together Ex: If n = 5, it returns 15 (5+4+3+2+1)
int nSum(int n)
{
    // base condition to terminate the recursion when N = 0
    if (n == 0) {
        return 0;
    }

    // recursive case / recursive call
    int res = n + nSum(n - 1);

    return res;
}


//Fibonacci sequence
int fib(int n)
{
    // Stop condition
    if (n == 0)
        return 0;
    // Stop condition
    if (n == 1 || n == 2)
        return 1;
    // Recursion function
    else
        return (fib(n - 1) + fib(n - 2));
}

// recursive function to print array
void pArray(int* arr, int n)
{
    // base condition
    if (n == 0) {
        return;
    }
    // recursive call
    cout << arr[n - 1] << ' ';
    pArray(arr, n - 1);  
}

int main(){
//Variables

int n = 0;
int arr[] = { 1, 2, 3, 4, 5 };


cout << "Enter a number: ";
cin >> n;
//Sum by recursion
cout << "The sum of the first " << n << " numbers is: " << nSum(n) << endl;

//Fibonacci sequence by recursion
cout << "Fibonacci series of 5 numbers is: ";
    // for loop to print the fibonacci series.
    for (int i = 1; i <= n; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;


// recursive function to print array reversed
pArray(arr, 5);


//Inputs



//Processes



//Outputs



return 0;
}