#include "Triangle.h"
#include <iostream>

using namespace std;

bool Triangle::setBase(double b)
{
    if (b > 0)
    {
        base = b;
        return true;
    }
    else
    {
        return false;
    }
}

bool Triangle::setHeight(double h)
{
    if (h > 0)
    {
        height = h;
        return true;
    }
    else
    {
        return false;
    }
}

double Triangle::getBase() const
{
    return base;
}

double Triangle::getHeight() const
{
    return height;
}

double Triangle::getArea() const
{
    return 0.5 * base * height;
}
