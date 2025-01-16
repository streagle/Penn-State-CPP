#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int i = 27;
    double d;
    // cout << "The address of i is: " << &i << endl;
    // cout << "The address of d is: " << &d << endl;
    //?The address of i is denoted by &i
    //?This gives you the "Run time address" of the variable i

    //?Pointer is a variable which contains a memory address of another variable.
    //?(Denoted by * before the variable declaration)
    // Example:

    int *p; //?defines a pointer p that points to a int type variable
    p = &i; //?set p to be the address of i, so p points to i
    // int *p = &i; = alternate definition of p

    //? If you print the value of p it will give you the address of i

    //! Use nullptr if it has no address

    int *iPtr = &i;
    // Now we can refer to the value of i by using *iPtr
    // cout << "The value of i is: " << *iPtr << endl;

    // You can also change the value of i by using *iPtr
    *iPtr = 42;
    // cout << "The value of i is: " << i << endl;

    //? Pointer to a pointer
    int **pp = &iPtr;
    //? pp is a pointer to a pointer to an int
    //? pp points to iPtr
    // All code below points to the same value of i
    /*
    cout << "The value of i is: " << **pp << endl;
    cout << "The address of i is: " << *iPtr << endl;
    cout << "The address of i is: " << i << endl;
    */

    //Request memory durring runtime with new operator
    /*

    int *intPtr;
    intPtr = new int; // allocate space for an intm and set p to the address or
    int *intPtr2 = new int; // alternate definition
    int *ip = new int(42); // allocate space for an int and set it to 42
    can be replaced by ny other types (double, char, etc)
    delete intPtr; //deallocate memory

    you can use pointers as user input
    int *p = new int;
    cout << "Enter a number: ";
    cin >> *p;


    */




   

    return 0;
}