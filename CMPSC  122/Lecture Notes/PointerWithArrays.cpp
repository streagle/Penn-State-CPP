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

int main()
{

    // The name of array can be used as the address of the first element in that array
    int a[100];
    int *arrayPtr = a; //? arrayPtr points to the first element of a
    int *ptr2 = arrayPtr + 1; //? ptr2 points to the second element of a

    return 0;
}