// MyClass.cpp
#include "Dice.h"
#include <iostream>
#include <cstdlib>

// Constructors
Dice::Dice()
{
    sideUp = 1;
}

Dice::Dice(int sideUp)
{
    this->sideUp = sideUp;
}

// getters

int Dice::getSideUp()
{
    return sideUp;
}

// setters

void Dice::setSideUp(int sideUp)
{
    this->sideUp = sideUp;
}

// Roll the dice

void Dice::toss()
{
    sideUp = rand() % 6 + 1;
}

