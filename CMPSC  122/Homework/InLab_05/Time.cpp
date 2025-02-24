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
// Assignment: InLab 05
//
#include "Time.h"
#include <string>

#include <iostream>

using namespace std;

// Set the object�fs data values.
void Time::Set(unsigned hours, unsigned minutes, char am_pm)
{
    if (hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 && (am_pm == 'A' || am_pm == 'P'))
    {
        myHours = hours;
        myMinutes = minutes;
        myAMorPM = am_pm;
    }
    else
        cerr << "*** Can't set these values ***\n";
}

// Display the time represented by the object
void Time::Display()
{
    string minStr = (myMinutes == 0) ? "00" : to_string(myMinutes);
    cout << myHours << ':' << minStr << ' ' << myAMorPM << ".M." << endl;
}

unsigned Time::getHours() {
    return myHours;
}

unsigned Time::getMinutes() {
    return myMinutes;
}

char Time::getAMorPM() {
    return myAMorPM;
}

void Time::Forward(int minutes)
{
    int totalMinutes = myMinutes + minutes;
    myMinutes = totalMinutes % 60;
    int hoursAdded = totalMinutes / 60;
    int nowHours = myHours + hoursAdded;
    int FlipAmPm = ((nowHours / 12) - (myHours / 12)) % 2;

    if (FlipAmPm == 1) {
        if (myAMorPM == 'A') {
            myAMorPM = 'P';
        }
        else {
            myAMorPM = 'A';
        }
    }
    myHours = nowHours % 12;
    if (myHours == 0) {
        myHours = 12;
    }
}

Time::Time() {
    myHours = 12;
    myMinutes = 0;
    myAMorPM = 'A';
}

Time::Time(unsigned hours, unsigned minutes, char am_pm) {
    if (hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 && (am_pm == 'A' || am_pm == 'P'))
    {
        myHours = hours;
        myMinutes = minutes;
        myAMorPM = am_pm;
    }
    else
    {
        cerr << "*** Can't set these values ***\n";
        Time(); // Set to 12:00AM
    }
}

Time Time::operator+(int minutes) {
    Time newTime = *this;
    newTime.Forward(minutes);
    return newTime;
}

Time Time::operator+=(int minutes) {
    Forward(minutes);
    return *this;
}

Time Time::operator=(string time) {
    if (time.length() != 5) {
        cerr << "*** Can't set these values ***\n";
        return *this;
    }
    unsigned hours = stoi(time.substr(0, 2));
    unsigned minutes = stoi(time.substr(2, 2));
    char am_pm = time[4];
    if (hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 && (am_pm == 'A' || am_pm == 'P'))
    {
        myHours = hours;
        myMinutes = minutes;
        myAMorPM = am_pm;
    }
    else
    {
        cerr << "*** Can't set these values ***\n";
    }
    return *this;
}