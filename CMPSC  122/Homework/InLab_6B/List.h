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
// Assignment: Lab 07
//
#include <iostream>

using namespace std;

typedef int ElementType;

const int DEFAULT_CAP = 1024;

class List {
public:
    List(int maxSize = 1024);  //constructor

    //Big Three:
    ~List(); // Destructor
    List(const List& orig); // Copy Constructor
    List& operator= (const List& orig); // Assignment operator

    // Array Convertion Constructor - From Lab 6. Implemented.
    List(ElementType* arr, int arrSize, int Capacity);

    // Member functions you need to implement for Lab 7
    List(List& orig, int lowIndex, int highIndex); // Sublist constructor
    void Append(List& listToAppend); // append function

    unsigned size() const;
    bool empty() const; //check if empty
    void insert(ElementType item, int pos); //insertion
    void erase(int pos);	//deletion
    void display(ostream& out) const; //display every item
    ElementType get(unsigned pos) const;
    int getCapacity();
private:
    int mySize;       // current # of items in list     
    int myCapacity;
    ElementType* myArrayPtr; //pointer to dynamic array
};

/* --------------------------------- OUTPUT --------------------------------- */
/*
list1 created from array: 
6 3 5 1 8 4 7 12 54 37 68 

list2 created from array: 
1 5 15 23 3 0 8 

list3 created from list1, from index [2]-[8]: 
5 1 8 4 7 12 54 

list4 created from list2, from index [0]-[6]: 
1 5 15 23 3 0 8 

list5 created from list2, from index [3]-[3]: 
23 

Append list2 to list1. Result: 
6 3 5 1 8 4 7 12 54 37 68 1 5 15 23 3 0 8 

Append another List, list3, to list1. Result: 
6 3 5 1 8 4 7 12 54 37 68 1 5 15 23 3 0 8 5 1 8 4 7 12 54 

The current capacity of list1 is 42
*/
