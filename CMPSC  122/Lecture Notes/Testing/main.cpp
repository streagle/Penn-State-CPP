#include <iostream>
#include "Rectangle.cpp"

int main() {
    Rectangle rect(5, 10);

    std::cout << "Area: " << rect.getArea() << std::endl;
    std::cout << "Perimeter: " << rect.getPerimeter() << std::endl;

    return 0;
}
