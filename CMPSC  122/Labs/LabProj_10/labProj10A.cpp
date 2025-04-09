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
// Assignment: LabProj 10
//
// timer.cpp for CMPSC122 lab 
// Measure time in Window  
// Define a Timer object t, use t.start() for beginning of the algorithm, t.stop() for the ending, and t.show() for printing.

#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include "timer.h"
using namespace std;


Timer::Timer()
{
  label = "Process Timer";
  reset();
}


Timer::Timer(const std::string &label)
{
  Timer::label = label;
  reset();
}


Timer::~Timer()
{
	
}


void Timer::reset(void)
{
  tps = CLOCKS_PER_SEC;
  end_time = 0;
  usertime = 0;
  systemtime = 0;
  elapsedtime = 0;
  waittime = 0;
}


void Timer::start(void)
{
    start_time = clock();
}


void Timer::show(void)
{
 cout << "  "
      << label << "\n"
      << "  -------------------------------\n"
      << "  Elapsed Time: "
      << elapsedtime
      << "s" << std::endl;

}


void Timer::stop(void)
{
  end_time = clock();
  elapsedtime = ((double)(end_time -
                start_time )/(double)tps );
  if (elapsedtime < 0.0001)
  {
    elapsedtime = 0.001;
  }

  if ( waittime < 0.00 )
  {
    waittime = 0.00;
  }
}

/* -------------------------------------------------------------------------- */
/*                                  2d Array                                  */
/* -------------------------------------------------------------------------- */

// Function to count paths using dynamic programming
int countPaths(int n, int m)
{
    // Create a 2D table to store results of subproblems
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    // Base case: There's only one way to reach any cell in the first row or first column
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 1;

    // Fill the rest of the table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // The result is stored in dp[n][m]
    return dp[n][m];
}
/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */
/*                                    Main                                    */
/* -------------------------------------------------------------------------- */

int main()
{
  int n, m;
  bool loop = true;
  do{
  do {
    cout << "Enter the number of points to the north (positive integer): ";
    cin >> n;
  } while (n < 0);
  do {
    cout << "Enter the number of points to the east (positive integer): ";
    cin >> m;
  } while (m < 0);
  Timer t;
  t.start();
  cout << "The number of paths from (0,0) to (" << n << "," << m << ") is: " << countPaths(n, m) << endl;
  t.stop();
  t.show();
  cout << "Do you want to try again? (y/n): ";
  char choice;
  cin >> choice;
  if (choice == 'n' || choice == 'N') {
    loop = false;
  }
  else if (choice == 'y' || choice == 'Y') {
    loop = true;
  } 
  else {
    do {
    cout << "Invalid choice, please enter Y or N." << endl;
    cin >> choice;
    }while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
  }
  
  } while (loop == true);
  
  return 0;
}
/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */
/*                                                                                                                                                                                                          
ryanreagle@Ryans-MacBook-Pro-2 output % cd "/Users/ryanreagle/Documents/GitHub/Penn State Comp Sci/Penn-State-CPP/CMPSC  122/Labs/LabProj_10/output"
./"labProj10A"                                                                                                                                                                                                        
ryanreagle@Ryans-MacBook-Pro-2 output % ./"labProj10A"
Enter the number of points to the north (positive integer): 10
Enter the number of points to the east (positive integer): 10
The number of paths from (0,0) to (10,10) is: 184756
  Process Timer
  -------------------------------
  Elapsed Time: 0.000213s
Do you want to try again? (y/n): y
Enter the number of points to the north (positive integer): 16
Enter the number of points to the east (positive integer): 16
The number of paths from (0,0) to (16,16) is: 601080390
  Process Timer
  -------------------------------
  Elapsed Time: 0.000197s
Do you want to try again? (y/n): y
Enter the number of points to the north (positive integer): 5
Enter the number of points to the east (positive integer): 5
The number of paths from (0,0) to (5,5) is: 252
  Process Timer
  -------------------------------
  Elapsed Time: 0.00014s
Do you want to try again? (y/n): 
*/

