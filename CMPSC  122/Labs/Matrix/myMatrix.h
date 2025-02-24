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

#pragma once

#include <iostream>

using namespace std;

class myMatrix {
public:
	///////////////////////////////////////////////////////////////////////////
	// Member functions you need to implement:
	///////////////////////////////////////////////////////////////////////////

	// 1. The default constructor. 
	// Initialize the matrix to a 1x1 matrix with entry 0
	
	myMatrix();

	// 2. The Second constructor. 
    // Initialize the matrix of given height and width with elements from a given array

	myMatrix(unsigned heightVal, unsigned WidthVal, int * sourceArray);
	
	// 3. Concatenate function.
	// Concatenates a matrix of the same height to the right of the caller matrix

	void Concatenate(myMatrix & matrixToConcatenate);

	// 4. Overloading of the += operator. Suggest using internal method.

	// !! ADD declaration line for the overloading function yourself !!

	myMatrix& operator+=(const myMatrix & rhs);


	// 5,6,7: The "big three"

	// !! ADD declaration lines for the "big three" functions yourself !!

	//5.
	myMatrix(const myMatrix & matrixToCopy);

	//6.
	myMatrix& operator=(const myMatrix & matrixToCopy);

	//7.
	~myMatrix();

	

	///////////////////////////////////////////////////////////////////////////
	// Member functions I have already implemented. Do not touch.
	///////////////////////////////////////////////////////////////////////////

	unsigned GetHeight();
	unsigned GetWidth();
	void PrintMatrix(ostream & out);
	void SetEntry(unsigned i, unsigned j, int valueToSet);

private:
	unsigned height;
	unsigned width;
	int* myArrayPtr;
};

// Overloading the << operator for easy output
ostream& operator<<(ostream& out, myMatrix& matrix);