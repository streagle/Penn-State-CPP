// driver for project 5
#include <iostream>
using namespace std;

#include "Complex2.h"

int main()
{
    Complex c(7.0, 3.0), d(1.0, -2.0), x, y;

    //   c.print();
    cout << c;
    cout << " + ";
    //  d.print();
    cout << d;
    cout << " = ";
    x = c + d;
    //   x.print();
    cout << x;

    cout << '\n';
    //   c.print();
    cout << c;

    cout << " - ";
    //   d.print();
    cout << d;
    cout << " = ";
    x = c - d;
    //   x.print();
    cout << x;

    cout << '\n';
    //   c.print();
    cout << c;
    cout << " * ";
    //   d.print();
    cout << d;
    cout << " = ";
    x = c * d;
    //   x.print();
    cout << x;

    cout << '\n';
    //   c.print();
    cout << c;
    cout << " / ";
    //   d.print();
    cout << d;
    cout << " = ";
    x = c / d;
    //   x.print();
    cout << x;

    cout << '\n';
    //   c.print();
    cout << c;
    cout << " / ";
    //   d.print();
    cout << y;          // y is (0 + 0i)
    cout << " = ";
    x = c / y;

    //   c.print();
    cout << c;
    cout << " == ";
    //   c.print();
    cout << c;
    cout << ((c == c) ? " is equal " : " is not equal ");
    
    cout << '\n';
    //   c.print();
    cout << c;
    cout << " == ";
    //   d.print();
    cout << d;
    cout << ((c == d) ? " is equal" : " is not equal");
    
    cout << '\n';
    //   c.print();
    cout << c;
    cout << " != ";
    //   c.print();
    cout << c;
    cout << " is " << ((c != c) ? "true" : "false");
    
    cout << '\n';
    //   c.print();
    cout << c;
    cout << " != ";
    //   d.print();
    cout << d;
    cout << " is " << ((c != d) ? "true" : "false");
    cout << "\n\n";


    /* uncomment this line for bonus points version 
    // Optional: 4 Bonus Points
    //   c.print();
    cout << c;
    cout << " + ";
    //   d.print();
    cout << c;
    cout << " / ";
    cout << d;
    cout << " - ";
    cout << d;
    cout << " * ";
    cout << c;
    cout << " = ";
    x = c + c / d - d * c;      // cascading use of operators
    //   x.print();
    cout << x;
    cout << '\n';
    */  // uncomment this line for bonus points version  

    return 0;
}

/* --------------------------------- OUTPUT --------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./complex2
7 + 3i + 1 + -2i = 8 + 1i
7 + 3i - 1 + -2i = 6 + 5i
7 + 3i * 1 + -2i = 13 + -11i
7 + 3i / 1 + -2i = 0.2 + 3.4i
7 + 3i / 0 + 0i = Division by zero is not allowed.
7 + 3i == 7 + 3i is equal 
7 + 3i == 1 + -2i is not equal
7 + 3i != 7 + 3i is false
7 + 3i != 1 + -2i is true

ryanreagle@Ryans-MacBook-Pro-2 output % 
*/


