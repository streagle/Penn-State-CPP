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

using namespace std;

// Methods

int *append(int *arrayA, int sizeA, int *arrayB, int sizeB)
{
	int *newArr = new int[sizeA + sizeB];
	for (int i = 0; i < sizeA; i++)
	{
		newArr[i] = arrayA[i];
	}
	for (int i = 0; i < sizeB; i++)
	{
		newArr[i + sizeA] = arrayB[i];
	}
	return newArr;
}

int *merge(int *arrayA, int sizeA, int *arrayB, int sizeB)
{
	int *newArr = new int[sizeA + sizeB];
	int i = 0, j = 0, k = 0;
	while (i < sizeA && j < sizeB)
	{
		if (arrayA[i] < arrayB[j])
		{
			newArr[k] = arrayA[i];
			i++;
		}
		else
		{
			newArr[k] = arrayB[j];
			j++;
		}
		k++;
	}
	while (i < sizeA)
	{
		newArr[k] = arrayA[i];
		i++;
		k++;
	}
	while (j < sizeB)
	{
		newArr[k] = arrayB[j];
		j++;
		k++;
	}
	return newArr;
}

void print(int *array, int size, const char *label)
{
	cout << label << ": ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arrayA[] = {11, 33, 55, 77, 99}; // use other values for more tests
	int arrayB[] = {22, 44, 66, 88};
	print(arrayA, 5, "Sorted array A: ");
	print(arrayB, 4, "Sorted array B: ");
	int *arrayC = append(arrayA, 5, arrayB, 4); // arrayC points to the appended array
	print(arrayC, 9, "Append B to A:  ");
	int *arrayD = merge(arrayA, 5, arrayB, 4);
	print(arrayD, 9, "Merge A to B:   ");
	delete[] arrayC;
	delete[] arrayD;

#ifdef _WIN32		   // _WIN32 is used by Visual C++
#if (_MSC_VER <= 1916) // check if it Visual Studio 2017 or earlier
	system("pause");
#endif
#endif

	return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"InLab3"
Sorted array A: : 11 33 55 77 99 
Sorted array B: : 22 44 66 88 
Append B to A:  : 11 33 55 77 99 22 44 66 88 
Merge A to B:   : 11 22 33 44 55 66 77 88 99 
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/