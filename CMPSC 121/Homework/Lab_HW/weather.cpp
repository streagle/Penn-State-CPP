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
// Assignment: Hw 11
//
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
// Methods

struct WeatherInfo
{
    double rainfall;
    double highTemp;
    double lowTemp;
};
void displayAverages(WeatherInfo year[], int nQuarter);
void computeMinMax(WeatherInfo year[], int nQuarter, double &highest, double &lowest, int &highQuarter, int &lowQuarter);

void displayAverages(WeatherInfo year[], int nQuarter)
{
    double totalRainfall = 0;
    double totalHighTemp = 0;
    double totalLowTemp = 0;
    for (int i = 0; i < nQuarter; i++)
    {
        totalRainfall += year[i].rainfall;
        totalHighTemp += year[i].highTemp;
        totalLowTemp += year[i].lowTemp;
    }
    double averageQuarterlyRainfall = totalRainfall;
    double averageQuarterlyAverageTemp = (totalHighTemp + totalLowTemp) / 2;
    cout << "Total Rainfall: " << totalRainfall << endl;
    cout << "Average Quarterly Rainfall: " << fixed << setprecision(2) << averageQuarterlyRainfall / 4 << endl;
    cout << "Average Quarterly Average Temperature: " << averageQuarterlyAverageTemp / 4 << endl;
}

void computeMinMax(WeatherInfo year[], int nQuarter, double &highest, double &lowest, int &highQuarter, int &lowQuarter)
{
    highest = year[0].highTemp;
    lowest = year[0].lowTemp;
    highQuarter = 0;
    lowQuarter = 0;
    for (int i = 1; i < nQuarter; i++)
    {
        if (year[i].highTemp > highest)
        {
            highest = year[i].highTemp;
            highQuarter = i;
        }
        if (year[i].lowTemp < lowest)
        {
            lowest = year[i].lowTemp;
            lowQuarter = i;
        }
    }
    cout << "Highest Temperature: " << highest << " in quarter " << highQuarter + 1 << endl;
    cout << "Lowest Temperature: " << lowest << " in quarter " << lowQuarter + 1 << endl;
}

int main()
{
    // Variables
    WeatherInfo year[4];
    double highest;
    double lowest;
    int highQuarter;
    int lowQuarter;

    cout << "Enter the total rainfall, low & high temperatures:";
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Quarter " << i + 1 << ": ";

        cin >> year[i].rainfall >> year[i].lowTemp >> year[i].highTemp;
        if (year[i].rainfall < 0 || year[i].lowTemp < -100 || year[i].highTemp > 140 || year[i].lowTemp > year[i].highTemp)
        {
            do
            {
                cout << "ERROR: Temperature range: -100 through 140" << endl;
                cout << "Low temperature <= high temperature." << endl;
                cout << "Enter the low and high temperatures again: ";
                cin >> year[i].lowTemp >> year[i].highTemp;

            } while (year[i].lowTemp < -100 || year[i].highTemp > 140 || year[i].lowTemp > year[i].highTemp);
        }
    }

    displayAverages(year, 4);
    computeMinMax(year, 4, highest, lowest, highQuarter, lowQuarter);

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   Output                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"weather"
Enter the total rainfall, low & high temperatures:
Quarter 1: 15 40 67
Quarter 2: 40 50 78
Quarter 3: 30 58 80
Quarter 4: 5 -110 85
ERROR: Temperature range: -100 through 140
Low temperature <= high temperature.
Enter the low and high temperatures again: 65 141
ERROR: Temperature range: -100 through 140
Low temperature <= high temperature.
Enter the low and high temperatures again: 140 65
ERROR: Temperature range: -100 through 140
Low temperature <= high temperature.
Enter the low and high temperatures again: 65 85
Total Rainfall: 90
Average Quarterly Rainfall: 22.50
Average Quarterly Average Temperature: 65.38
Highest Temperature: 85.00 in quarter 4
Lowest Temperature: 40.00 in quarter 1
ryanreagle@Ryans-MacBook-Pro-2 output %
*/