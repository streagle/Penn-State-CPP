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
// Assignment: Lab 06
//
#include <iostream>


using namespace std;

typedef int ElementType; // Now "ElementType" is "int"
                         // can change int to double,char,...
class List
{
public:
  List(int maxSize = 1024); // constructor

  List(ElementType *array, int arraySize, int capacity);
  void ExpandCapacity(int sizeToExpand);
  void TryShrink();

  // Big Three:
  ~List();                           // Destructor
  List(const List &orig);            // Copy Constructor
  List &operator=(const List &orig); // Assignment operator

  unsigned size() const;
  bool empty() const;                     // check if empty
  void insert(ElementType item, int pos); // insertion
  void erase(int pos);                    // deletion
  void display(ostream &out) const;       // display every item
  ElementType get(unsigned pos) const;
  int getCapacity();

private:
  int mySize; // current # of items in list
  int myCapacity;
  ElementType *myArrayPtr; // pointer to dynamic array
};
