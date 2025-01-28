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
// Assignment: Lab 02
//
#include <iostream>
using namespace std;

void find_best_strategy(const double prices[], int n, double &max_profit, int &buy_day, int &sell_day)
{
    // Initialize max_profit to a very small value to ensure any profit found will be larger
    max_profit = -1000;
    buy_day = 0;
    sell_day = 0;

    // Iterate through each possible buy day
    for (int i = 0; i < n; ++i)
    {
        // Iterate through each possible sell day, ensuring it's at least 3 days after the buy day
        for (int j = i + 3; j < n; ++j)
        {
            
            double profit = (1000 / prices[i]) * prices[j] - 1000;

            
            if (profit > max_profit)
            {
                max_profit = profit;
                buy_day = i + 1;  
                sell_day = j + 1; 
            }
        }
    }
}

int main()
{
    cout << "Please type the 12-day price history of the stock:" << endl;
    vector<double> prices(12);

   
    for (int i = 0; i < 12; ++i)
    {
        cin >> prices[i];
    }

    
    double max_profit;
    int buy_day, sell_day;

    
    find_best_strategy(prices.data(), 12, max_profit, buy_day, sell_day);

   
    if (max_profit >= 0)
    {
        cout << "Max Profit: " << max_profit << ".\n";
        cout << "Best Strategy: buy on day " << buy_day << ", sell on day " << sell_day << ".\n";
    }
    else//Not needed in problem but mkes it easier to read
    {
        cout << "Max Loss: " << -max_profit << ".\n";
        cout << "Best Strategy to minimize loss: buy on day " << buy_day << ", sell on day " << sell_day << ".\n";
    }

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                               POSITIVE PROFIT                              */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"LabProj2"
Please type the 12-day price history of the stock:
50 200 100 30 20 25 40 10 5 35 45 20
Max Profit: 3500.
Best Strategy: buy on day 8, sell on day 11.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                 ZERO PROFIT                                */
/* -------------------------------------------------------------------------- */
/*
Please type the 12-day price history of the stock:
50 100 50 40 40 40 40 40 40 40 40 40
Max Profit: 0.
Best Strategy: buy on day 4, sell on day 7.
*/

/* -------------------------------------------------------------------------- */
/*                               NEGATIVE PROFIT                              */
/* -------------------------------------------------------------------------- */
/*
Please type the 12-day price history of the stock:
150 140 130 120 110 100 90 80 60 50 20 10
Max Loss: 200.
Best Strategy to minimize loss: buy on day 1, sell on day 4.
*/