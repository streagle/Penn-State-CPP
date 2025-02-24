// MyClass.h
#pragma once
#include <string>

class Time
{
public:
    Time();
    Time(unsigned hours, unsigned minutes, char am_pm);
    unsigned getHours();                                    // Return the hour number
    unsigned getMinutes();                                  // Return the minute number
    char getAMorPM();                                       // Return the AM PM value
    void Set(unsigned hours, unsigned minutes, char am_pm); // Set the time
    void Display();                                         // Display the time

    //Overload the operator == to compare two Time objects
    //Time teaTime(5, 30, ‘A’) and Time bedTime(5, 30, ‘P’) are considered not equal
    
    bool operator==(unsigned time) const;
private:
    unsigned myHours, myMinutes;
    char myAMorPM;
};