#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
// Methods

/* -------------------------------------------------------------------------- */
/*                  checks if the number is divisible by 100                  */
/* -------------------------------------------------------------------------- */
void divisible(int num)
{
	if (num % 100 == 0)
	{
		cout << "The number is divisible by 100" << endl;
	}
	else
	{
		cout << "The number is not divisible by 100" << endl;
	}
}

/* -------------------------------------------------------------------------- */
/*                    prints yeah if true and nope if false                   */
/* -------------------------------------------------------------------------- */
void yeahNope(bool b)
{

	cout << (b ? "yeah" : "nope") << endl;
}

/* -------------------------------------------------------------------------- */
/*                         game of rock paper scissors                        */
/* -------------------------------------------------------------------------- */
void rps(string player1, string player2)
{

	if (player1 == player2)
	{
		cout << "It's a tie!" << endl;
	}
	else if (player1 == "rock")
	{
		if (player2 == "scissors")
		{
			cout << "Player 1 wins!" << endl;
		}
		else if (player2 == "paper")
		{
			cout << "Player 2 wins!" << endl;
		}
	}
	else if (player1 == "scissors")
	{
		if (player2 == "rock")
		{
			cout << "Player 2 wins!" << endl;
		}
		else if (player2 == "paper")
		{
			cout << "Player 1 wins!" << endl;
		}
	}
	else if (player1 == "paper")
	{
		if (player2 == "rock")
		{
			cout << "Player 1 wins!" << endl;
		}
		else if (player2 == "scissors")
		{
			cout << "Player 2 wins!" << endl;
		}
	}
	else
	{
		cout << "Invalid input" << endl;
	}
}

/* -------------------------------------------------------------------------- */
/*    outputs how many times num1 can be halved until it is less than num2    */
/* -------------------------------------------------------------------------- */
void halveCount(int num1, int num2)
{
	int halvedValue = num1;
	int count = 0;
	while (halvedValue > num2)
	{
		halvedValue = halvedValue / 2;
		// cout << halvedValue << endl;
		if (halvedValue < num2)
		{
			break;
		}
		count++;
	}
	cout << "The number of times " << num1 << " can be halved to be less than " << num2 << " is " << count << endl;
}
/* ------------------------------------------------------------------------------------------------ */
/* takes a string in the format of "minutes:seconds" and outputs the length of the video in seconds */
/* ------------------------------------------------------------------------------------------------ */
void videoLengthInSeconds(string time)
{
	int minutes = 0;
	int seconds = 0;
	int colon = time.find(":");
	minutes = stoi(time.substr(0, colon));

	seconds = stoi(time.substr(colon + 1));
	if (seconds > 59)
	{
		cout << "-1" << endl;
	}
	cout << "The video is " << (minutes * 60) + seconds << " seconds long" << endl;
}

/* -------------------------------------------------------------------------- */
/*                takes a string and checks if its a paladrone                */
/* -------------------------------------------------------------------------- */

void isPaladrone(string s)
{
	string string_reversed = s;
	reverse(string_reversed.begin(), string_reversed.end());
	if (s == string_reversed)
	{
		cout << "The string is a paladrone" << endl;
	}
	else
	{
		cout << "The string is not a paladrone" << endl;
	}
}

/* -------------------------------------------------------------------------- */
/*              calculates the mean of the numbers in the vector              */
/* -------------------------------------------------------------------------- */

float mean(array<int, 5> arr)
{
	float sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	return sum / arr.size();
}

/* -------------------------------------------------------------------------- */
/*            takes a snakecase string and converts it to camelcase           */
/* -------------------------------------------------------------------------- */

void toCamelCase(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '_')
		{
			s.erase(i, 1);
			s[i] = toupper(s[i]);
		}
	}
	cout << s << endl;
}

/* -------------------------------------------------------------------------- */
/*            takes a camelcase string and converts it to snakecase           */
/* -------------------------------------------------------------------------- */

void toSnakeCase(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i]))
		{
			s[i] = tolower(s[i]);
			s.insert(i, "_");
		}
	}
	cout << s << endl;
}

/* -------------------------------------------------------------------------- */
/*            takes a password as a string and checks if its valid            */
/* -------------------------------------------------------------------------- */

void passwordValidation(string s)
{
	int upperCount = 0;
	int lowerCount = 0;
	int didgitCount = 0;
	int specialCount = 0;
	for (int i = 0; i < s.size(); i++)
	{

		if (isupper(s[i]))
		{
			upperCount++;
		}
		if (islower(s[i]))
		{
			lowerCount++;
		}
		if (isdigit(s[i]))
		{
			didgitCount++;
		}
		if (ispunct(s[i]))
		{
			specialCount++;
		}
		if (s[i], s[i + 1], s[i + 2] == s[i])
		{
			cout << "Password cannot contain more than 2 repeat characters" << endl;
		}
	}
	if (upperCount < 1)
	{
		cout << "Password must contain at least one uppercase letter" << endl;
	}
	if (lowerCount < 1)
	{
		cout << "Password must contain at least one lowercase letter" << endl;
	}
	if (didgitCount < 1)
	{
		cout << "Password must contain at least one digit" << endl;
	}
	if (specialCount < 1)
	{
		cout << "Password must contain at least one special character" << endl;
	}
	if (s.size() < 6)
	{
		cout << "Password must be at least 6 characters long" << endl;
	}
	if (s.size() > 24)
	{
		cout << "Password must be less than 20 characters long" << endl;
	}

	if (upperCount >= 1 && lowerCount >= 1 && didgitCount >= 1 && specialCount >= 1 && s.size() >= 6 && s.size() <= 24)
	{
		cout << "Password is valid" << endl;
	}
}

/* -------------------------------------------------------------------------- */
/*          Given a string containing an algebraic equation, calculate 		  */
/*			and return the value of x. You'll only be given equations for 	  */
/*			addition and subtraction.										  */
/* -------------------------------------------------------------------------- */

// Dosnt currently work with multiple x's in the equation or multiple numbers on each side, along with multiplication and division

/*
Process for multiplication and division: 
1. Check for * or / in the equation
2. If found, split the equation into two parts, left and right of the operator
3. Check what side X is on
4. Divide the total by the number on the side of the operator if multiplication and multiply if division
5. Return the value of X


*/

/*int evalAlgebra(string s)
{
	int x = 0;

	// Find the position of x
	int pos = s.find('x');
	if (pos == string::npos)
	{
		cout << "No variable x found in the equation." << endl;
		return 0;
	}

	// Remove spaces from the string
	s.erase(remove(s.begin(), s.end(), ' '), s.end());

	// Find the position of '='
	int equalPos = s.find('=');
	// Checks if there is a = in the equation, npos = null position (returns true if the position is not found)
	if (equalPos == string::npos)
	{
		cout << "Invalid equation format." << endl;
		return 0;
	}

	// Split the equation into left and right parts
	string leftPart = s.substr(0, equalPos);
	string rightPart = s.substr(equalPos + 1);

	// Determine the side of x, returns true if x is found at a position on the left side of the equation
	bool xOnLeft = leftPart.find('x') != string::npos;

	// Evaluate the equation(Understood)
	if (xOnLeft)
	{
		// x is on the left side
		int constant = stoi(rightPart); // stores the right side of the equation as the variable constant
		int sign = 1;
		int num = 0;
		for (char c : leftPart)
		{

			if (c == '+')
			{
				constant -= sign * num;
				sign = 1; // indicates the sign is addition (multiplies the num by 1)
				num = 0;
			}
			else if (c == '-')
			{
				constant -= sign * num;
				sign = -1; // indicates the sign is subtraction (multiplies the num by -1)
				num = 0;
			}
			else if (isdigit(c))
			{
				num = num * 10 + (c - '0'); // used to convert the char to a int then multiplies by 10 to shift the number to the left
											// Ex: 123 = (0*10 +(1-0)) -> (1* 10 + (2-0)) -> (12 * 10 + (3-0)) = 123
			}
		}
		x = constant;
	}
	else
	{
		// x is on the right side
		int constant = stoi(leftPart);
		int sign = 1;
		int num = 0;
		for (char c : rightPart)
		{
			if (c == '+')
			{
				constant -= sign * num;
				sign = 1;
				num = 0;
			}
			else if (c == '-')
			{
				constant -= sign * num;
				sign = -1;
				num = 0;
			}
			
			else if (isdigit(c))
			{
				num = num * 10 + (c - '0');
			}
		}
		x = constant;
	}
	return x;
}
	*/

int evalAlgebra(string s){
	
}
/* -------------------------------------------------------------------------- */
/*        given time as a string,return the time in binary as hh:mm:ss 		  */
/* -------------------------------------------------------------------------- */

void timeToBinary(string time)
{
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int colon1 = time.find(":");
	int colon2 = time.find(":", colon1 + 1);
	hours = stoi(time.substr(0, colon1));
	minutes = stoi(time.substr(colon1 + 1, colon2));
	seconds = stoi(time.substr(colon2 + 1));
	cout << "Hours:   " << bitset<8>(hours) << endl;
	cout << "Minutes: " << bitset<8>(minutes) << endl;
	cout << "Seconds: " << bitset<8>(seconds) << endl;
}

/* -------------------------------------------------------------------------- */
/*            checks to see if person1 can donate blood to person 2           */
/* -------------------------------------------------------------------------- */

bool bloodType(string person1, string person2)
{
	if (person1 == "O-")
	{
		return true;
	}
	else if (person1 == "O+")
	{
		if (person2 == "O+" || person2 == "O-")
		{
			return true;
		}
	}
	else if (person1 == "A-")
	{
		if (person2 == "A-" || person2 == "O-")
		{
			return true;
		}
	}
	else if (person1 == "A+")
	{
		if (person2 == "A+" || person2 == "A-" || person2 == "O+" || person2 == "O-")
		{
			return true;
		}
	}
	else if (person1 == "B-")
	{
		if (person2 == "B-" || person2 == "O-")
		{
			return true;
		}
	}
	else if (person1 == "B+")
	{
		if (person2 == "B+" || person2 == "B-" || person2 == "O+" || person2 == "O-")
		{
			return true;
		}
	}
	else if (person1 == "AB-")
	{
		if (person2 == "AB-" || person2 == "A-" || person2 == "B-" || person2 == "O-")
		{
			return true;
		}
	}
	else if (person1 == "AB+")
	{
		if (person2 == "AB+" || person2 == "AB-" || person2 == "A+" || person2 == "A-" || person2 == "B+" || person2 == "B-" || person2 == "O+" || person2 == "O-")
		{
			return true;
		}
	}
}

/* -------------------------------------------------------------------------- */
/*       adds all the even numbers and odds and outputs what is greater       */
/* -------------------------------------------------------------------------- */

void evenOrOdd(int num)
{
	int evenSum = 0;
	int oddSum = 0;
	int count = 0;
	while (num >= 1)
	{
		count = num % 10;
		num = num / 10;
		if (count % 2 == 0)
		{
			evenSum += count;
			count = 0;
		}
		else
		{
			oddSum += count;
			count = 0;
		}
	}
	// cout << "Even sum: " << evenSum << endl;
	// cout << "Odd sum: " << oddSum << endl;
	if (evenSum > oddSum)
	{
		cout << "Even sum is greater" << endl;
	}
	else if (oddSum > evenSum)
	{
		cout << "Odd sum is greater" << endl;
	}
	else
	{
		cout << "Even and odd sum are equal" << endl;
	}
}

/* -------------------------------------------------------------------------- */
/*        calculates the total pay on a day if the pay doubles each day       */
/* -------------------------------------------------------------------------- */

void doublePay(int days)
{
	int pay = 1;
	int totalPay = 0;
	int daysWorked = 0;
	while (daysWorked < days)
	{
		totalPay += pay;
		pay *= 2;
		daysWorked++;
	}
	cout << "The total pay after " << days << " days is " << totalPay << " pennies" << endl;
}

/* ---------------------------------------------------------------------------------- */
/*    prints the reverse of input of numbers then prints it normal in same string     */
/* ---------------------------------------------------------------------------------- */

void reverseAndNot(int num)
{
	string s = to_string(num);
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	cout << reversed << s << endl;
}

/* -------------------------------------------------------------------------- */
/*        calculates  the pecent change between firstNum and secondNum        */
/* -------------------------------------------------------------------------- */

void percentChange(int firstNum, int secondNum)
{

	// take the difference between the two numbers
	double difference = secondNum - firstNum;
	double percentChange = 0;

	// check if negative or positive
	if (difference < 0)
	{
		percentChange = ((difference * -1) / firstNum) * 100;
		cout << "The percent decrease is " << percentChange << "%" << endl;
	}
	else if (difference > 0)
	{
		percentChange = (difference / firstNum) * 100;
		cout << "The percent increase is " << percentChange << "%" << endl;
	}
	else
	{
		cout << "No change" << endl;
	}

	// if negative return the percent decrease

	// if positive return the percent increase

	// if 0 return "no change"

	// return the percent change
}

void helloWorld(string s){
	cout << "Hello World!" << endl;
}

int main()
{
	// Outputs

	// divisible(100);
	// divisible(1);
	// divisible(1000);

	// yeahNope(true);
	// yeahNope(false);

	// rps("rock", "scissors");
	// rps("rock", "paper");

	// halveCount(1324, 98);

	// videoLengthInSeconds("13:56");
	// videoLengthInSeconds("1:60");

	// isPaladrone("racecar");
	// isPaladrone("hello");

	// array <int, 5> arr = {2, 3, 2, 3};
	// cout << mean(arr) << endl;

	// toCamelCase("this_is_test");
	// toSnakeCase("thisIsTest");

	// passwordValidation("Password123!");
	// passwordValidation("password123");
	// passwordValidation("Passsword123");

	//cout << evalAlgebra("1 + x = 3") << endl;
	cout << evalAlgebra("2 - x = 1") << endl;
	cout << evalAlgebra("2 + x = 8") << endl;//? always outputs the final answer, not the value of x if in format of (x + 2 = 8)
	cout << evalAlgebra("2 + 2 = x") << endl;
	
	

	// timeToBinary("10:37:49");

	// cout << bloodType("O-", "O+") << endl;
	// cout << bloodType("O-", "AB+") << endl;
	// cout << bloodType("A-", "O+") << endl;

	// evenOrOdd(1445);
	//  evenOrOdd(1000);
	//  evenOrOdd(4565);

	// doublePay(3);

	// reverseAndNot(1234);

	// percentChange(800, 600);
	// percentChange(100, 950);

	//helloWorld("print");

	return 0;
}
