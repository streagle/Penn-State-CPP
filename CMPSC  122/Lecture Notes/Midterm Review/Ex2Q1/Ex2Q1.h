
#include <iostream>
#include <list>
using namespace std;

typedef int ElementType;
class List {
public:
List(int maxSize = 1024);
~List();
List(const List & orig);
List & operator= (const List & orig);
unsigned size() const;
bool empty() const;
void insert(ElementType item, int pos);
void erase(int pos);
void display(ostream & out) const;
ElementType get(unsigned pos) const;
int getCapacity();

void CutList(int cutSize) {
    // Remove the first 'cutSize' elements from the list
    for (int i = 0; i < cutSize; i++) {
        list.pop_front();
    }
    
    int remainingSize = list.size();
    
    int newSize = remainingSize * 2;
    
    ElementType* newArray = new ElementType[newSize];

    for (int i = 0; i < remainingSize; i++) {
        newArray[i] = list.front();
        list.pop_front();
    }
    
    myArrayPtr = newArray;
    mySize = remainingSize;  // Correctly set to the number of elements transferred
    myCapacity = newSize;    // Set to 2x the remaining size
}


private:
int mySize;
int myCapacity;
ElementType * myArrayPtr;
list<ElementType> list;
};