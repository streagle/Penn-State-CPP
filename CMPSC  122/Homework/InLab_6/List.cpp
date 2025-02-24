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
#include <cstdlib>
#include "List.h"

using namespace std;

void List::insert(ElementType item, int pos)
{
  if (mySize == myCapacity)
    exit(1);
  if (pos < 0 || pos > mySize)
    return;
  // shift array elements right to make room for item
  for (int i = mySize; i > pos; i--)
    myArrayPtr[i] = myArrayPtr[i - 1];
  // insert item at pos and increase list size
  myArrayPtr[pos] = item;
  mySize++; // don't forget this!
}

void List::erase(int pos)
{
  if (pos < 0 || pos >= mySize)
    return;
  // shift array elements left
  for (int i = pos; i < mySize - 1; i++)
    myArrayPtr[i] = myArrayPtr[i + 1];
  mySize--; // don't forget this!
}

List::List(int maxSize)
{
  mySize = 0;
  myCapacity = maxSize;
  myArrayPtr = new ElementType[maxSize];
}

List::~List() { delete[] myArrayPtr; }

List::List(const List &origList)
{
  mySize = origList.mySize;
  myCapacity = origList.myCapacity;
  myArrayPtr = new ElementType[myCapacity];
  for (int i = 0; i < mySize; i++)
    myArrayPtr[i] = origList.myArrayPtr[i];
}

List &List::operator=(const List &origList)
{
  if (this != &origList) // check for list = list
  {
    delete[] myArrayPtr;
    mySize = origList.mySize;
    myCapacity = origList.myCapacity;

    myArrayPtr = new ElementType[myCapacity];
    //--- Copy origList's array into this new array
    for (int i = 0; i < myCapacity; i++)
      myArrayPtr[i] = origList.myArrayPtr[i];
  }
  return *this;
}

bool List::empty() const
{
  return (mySize == 0);
}

unsigned List::size() const
{
  return mySize;
}

ElementType List::get(unsigned pos) const
{
  if (pos >= mySize)
  {
    cerr << "Invalid Index." << endl;
    exit(1);
  }
  return myArrayPtr[pos];
}

void List::display(ostream &out) const
{
  for (int i = 0; i < mySize; i++)
  {
    out << myArrayPtr[i] << " ";
  }
}

int List::getCapacity()
{
  return myCapacity;
}

/* -------------------------------------------------------------------------- */
/*                                New Functions                               */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- List ---------------------------------- */

List::List(ElementType *array, int arraySize, int capacity)
{
  mySize = arraySize;
  myCapacity = capacity;
  myArrayPtr = new ElementType[capacity];
  for (int i = 0; i < arraySize; i++)
  {
    myArrayPtr[i] = array[i];
  }
}

/* ----------------------------- Expand Capacity ---------------------------- */

void List::ExpandCapacity(int sizeToExpand)
{
  if (sizeToExpand <= myCapacity)
  {
    cerr << "Invalid size to expand." << endl;
    exit(1);
  }
  ElementType *temp = new ElementType[sizeToExpand];
  for (int i = 0; i < mySize; i++)
  {
    temp[i] = myArrayPtr[i];
  }
  delete[] myArrayPtr;
  myArrayPtr = temp;
  myCapacity = sizeToExpand;
}

/* ------------------------------- Try Shrink -------------------------------- */

void List::TryShrink()
{
  if (mySize == 0)
  {
    cerr << "Cannot shrink an empty list." << endl;
    exit(1);
  }
  if (mySize < myCapacity)
  {
    ElementType *temp = new ElementType[mySize];
    for (int i = 0; i < mySize; i++)
    {
      temp[i] = myArrayPtr[i];
    }
    delete[] myArrayPtr;
    myArrayPtr = temp;
    myCapacity = mySize;
  }
}
