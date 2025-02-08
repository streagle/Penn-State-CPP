#ifndef RECTANGLE_H // Include guard to prevent multiple inclusions
#define RECTANGLE_H


class Rectangle {
public:
    Rectangle(double width, double height); // Constructor
    double getArea() const;
    double getPerimeter() const;

private:
    double width;
    double height;
};

#endif 
