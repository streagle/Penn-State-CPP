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
// Assignment: Lab 03
//

#include <iostream>
#include <iomanip>
#include "myMatrix.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Functions that are already implemented by myself. Do not modify.
///////////////////////////////////////////////////////////////////////////////

void myMatrix::PrintMatrix(ostream &out)
{
	int index = 0;
	for (unsigned i = 0; i < this->height; i++)
	{
		for (unsigned j = 0; j < this->width; j++)
		{
			out << setw(6) << this->myArrayPtr[index];
			index++;
		}
		out << endl;
	}
}

ostream &operator<<(ostream &out, myMatrix &matrix)
{
	matrix.PrintMatrix(out);
	return out;
}

unsigned myMatrix::GetHeight()
{
	return this->height;
}

unsigned myMatrix::GetWidth()
{
	return this->width;
}

void myMatrix::SetEntry(unsigned i, unsigned j, int valueToSet)
{
	this->myArrayPtr[(i * this->width) + j] = valueToSet;
}

///////////////////////////////////////////////////////////////////////////////
// Implement required member functions below
///////////////////////////////////////////////////////////////////////////////

myMatrix::myMatrix()
{

	height = 1;
	width = 1;
	myArrayPtr = new int[1];
	myArrayPtr[0] = 0;
}

myMatrix::myMatrix(unsigned heightVal, unsigned widthVal, int *sourceArray)
{

	height = heightVal;
	width = widthVal;
	myArrayPtr = new int[height * width];
	for (int i = 0; i < height * width; i++)
	{
		myArrayPtr[i] = sourceArray[i];
	}
}

void myMatrix::Concatenate(myMatrix &matrixToConcatenate)
{

	int *tempArray = new int[height * (width + matrixToConcatenate.width)];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			tempArray[i * (width + matrixToConcatenate.width) + j] = myArrayPtr[i * width + j];
		}
		for (int j = 0; j < matrixToConcatenate.width; j++)
		{
			tempArray[i * (width + matrixToConcatenate.width) + width + j] = matrixToConcatenate.myArrayPtr[i * matrixToConcatenate.width + j];
		}
	}
	delete[] myArrayPtr;
	width += matrixToConcatenate.width;
	myArrayPtr = tempArray;
}

///////////////////////////////////////////////////////////////////////////////
// Implement the overloading function for += below
///////////////////////////////////////////////////////////////////////////////

// Code for += overloading

myMatrix &myMatrix::operator+=(const myMatrix &rhs)
{
	if (this->height != rhs.height || this->width != rhs.width)
	{
		cerr << "Error: incompatible matrices for += operation!" << endl;
		return *this;
	}
	for (unsigned i = 0; i < height; ++i)
	{
		for (unsigned j = 0; j < width; ++j)
		{
			this->myArrayPtr[i * width + j] += rhs.myArrayPtr[i * width + j];
		}
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Implement the "big three" below
///////////////////////////////////////////////////////////////////////////////

// Add your "big three" implementation...

myMatrix::myMatrix(const myMatrix &matrixToCopy)
{

	height = matrixToCopy.height;
	width = matrixToCopy.width;
	myArrayPtr = new int[height * width];
	for (int i = 0; i < height * width; i++)
	{
		myArrayPtr[i] = matrixToCopy.myArrayPtr[i];
	}
}

myMatrix &myMatrix::operator=(const myMatrix &matrixToCopy)
{

	if (this == &matrixToCopy)
	{
		return *this;
	}
	delete[] myArrayPtr;
	height = matrixToCopy.height;
	width = matrixToCopy.width;
	myArrayPtr = new int[height * width];
	for (int i = 0; i < height * width; i++)
	{
		myArrayPtr[i] = matrixToCopy.myArrayPtr[i];
	}
	return *this;
}

myMatrix::~myMatrix()
{

	delete[] myArrayPtr;
}

