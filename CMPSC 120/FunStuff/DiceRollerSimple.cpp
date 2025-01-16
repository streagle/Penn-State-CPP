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

int dice_sides = 6;
int num_rolled;
int num_rolls;
int total_rolled = 0;
char keep_rolling = 'y';
char reset_total;
//Inputs

//Processes
srand((unsigned int)time(NULL));


//Outputs

while (keep_rolling == 'y' || keep_rolling == 'Y')
{
    cout << "How many times would you like to roll the dice? ";
    cin >> num_rolls;
    cout << "How many sides does the dice have? ";
    cin >> dice_sides;
    for (int i = 0; i < num_rolls; i++)
    {
        num_rolled = rand() % dice_sides + 1;
        cout << "You rolled a " << num_rolled << endl;
        total_rolled += num_rolled;
    }
    cout << "You rolled a total of " << total_rolled << endl;
    cout << "Would you like to roll again? (y or n) ";
    cin >> keep_rolling;
    if (keep_rolling == 'y' || keep_rolling == 'Y')
    {
        cout << "Would you like to reset the total? (y or n) ";
        cin >> reset_total;
        if (reset_total == 'y' || reset_total == 'Y')
        {
            total_rolled = 0;
        }
    }
}




return 0;
}