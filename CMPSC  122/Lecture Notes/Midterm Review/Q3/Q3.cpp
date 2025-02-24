// MyClass.cpp
#include "Q3.h"
#include <iostream>

Time::Time()
{
    myHours = 0;
    myMinutes = 0;
    myAMorPM = 'A';
}

Time::Time(unsigned hours, unsigned minutes, char am_pm)
{
    myHours = hours;
    myMinutes = minutes;
    myAMorPM = am_pm;
}

unsigned Time::getHours()
{
    return myHours;
}

unsigned Time::getMinutes()
{
    return myMinutes;
}

char Time::getAMorPM()
{
    return myAMorPM;
}

void Time::Set(unsigned hours, unsigned minutes, char am_pm)
{
    myHours = hours;
    myMinutes = minutes;
    myAMorPM = am_pm;
}

void Time::Display()
{
    std::cout << myHours << ":" << myMinutes << " " << myAMorPM << "M" << std::endl;
}

bool Time::operator==(unsigned time) const
{
    unsigned hours = time / 100;
    unsigned minutes = time % 100;
    if (myAMorPM == 'P')
    {
        hours += 12;
        //Written By Ben
    }
    return myHours == hours && myMinutes == minutes;
}


