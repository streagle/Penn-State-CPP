#pragma once

class Triangle
{

private:
    double base;

    double height;

public:
    bool setBase(double b);

    bool setHeight(double h);

    double getBase() const;

    double getHeight() const;

    double getArea() const;
};