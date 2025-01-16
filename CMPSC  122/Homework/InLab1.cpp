#include <iostream>
#include <iomanip>


using namespace std;
//Methods



// makeChange function prototype
void makeChange(int, int &, int &, int &, int &, int &);

void makeChange(int cents, int &dollars, int &quarters, int &dimes, int &nickels, int &pennies)
{
    dollars = cents / 100;
    cents %= 100;
    quarters = cents / 25;
    cents %= 25;
    dimes = cents / 10;
    cents %= 10;
    nickels = cents / 5;
    cents %= 5;
    pennies = cents;
    
}
/************************* Main Program **************************/
int main()
{
int cents, dollars, quarters, dimes, nickels, pennies;
cout << "How much change to make (in cents): ";
cin >> cents;
makeChange(cents, dollars, quarters, dimes, nickels, pennies);
cout << "\nYour change is:" << endl
<< dollars << " dollar(s)" << endl
<< quarters << " quarter(s)" << endl
<< dimes << " dime(s)" << endl
<< nickels << " nickel(s)" << endl
<< pennies << " pennie(s)" << endl;
#ifdef _WIN32 // _WIN32 is used by Visual C++
#if (_MSC_VER <= 1916) // check if it Visual Studio 2017 or earlier
system("pause");
#endif
#endif
return 0;
}
/*************************** End of Main *************************/

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"InLab1"
How much change to make (in cents): 1932

Your change is:
19 dollar(s)
1 quarter(s)
0 dime(s)
1 nickel(s)
2 pennie(s)
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/