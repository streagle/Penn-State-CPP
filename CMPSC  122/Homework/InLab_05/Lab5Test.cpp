#include <iostream>
#include <string>

#include "Time.h"

using namespace std;

void ShowNowTime(Time& timept, string objectName) {
	cout << "Time object " << objectName << " is now ";
	timept.Display();
	cout << endl;
}

int main()
{
	Time nowTime;
	nowTime.Set(11, 30, 'P');
	ShowNowTime(nowTime, "nowTime");
	cout << "Forward 20 Minutes." << endl;
	//nowTime.Forward(20);
	nowTime += 20;
	ShowNowTime(nowTime, "nowTime");
	cout << "Forward 20 Minutes." << endl;
	//nowTime.Forward(20);
	nowTime += 20;
	ShowNowTime(nowTime, "nowTime");
	cout << "Forward 500 Minutes." << endl;
	//nowTime.Forward(500);
	nowTime += 500;
	ShowNowTime(nowTime, "nowTime");
	cout << "Forward 330 Minutes." << endl;
	//nowTime.Forward(330);
	nowTime += 330;
	ShowNowTime(nowTime, "nowTime");

	cout << "Create a testTime object, which forwards nowTime by 30 Minutes. (Testing the + operator.)" << endl;
	Time testTime = nowTime + 30;
	ShowNowTime(testTime, "testTime");

	ShowNowTime(nowTime, "nowTime");
	cout << "nowTime should NOT be changed from the + operator." << endl;

	cout << endl;

	cout << "Assigning string \"0840A\" to nowTime." << endl;
	nowTime = "0840A";
	ShowNowTime(nowTime, "nowTime");

	cout << "Assigning string \"1200P\" to nowTime." << endl;
	nowTime = "1200P";
	ShowNowTime(nowTime, "nowTime");
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./InLab_05
Time object nowTime is now 11:30 P.M.

Forward 20 Minutes.
Time object nowTime is now 11:50 P.M.

Forward 20 Minutes.
Time object nowTime is now 12:10 A.M.

Forward 500 Minutes.
Time object nowTime is now 8:30 A.M.

Forward 330 Minutes.
Time object nowTime is now 2:00 P.M.

Create a testTime object, which forwards nowTime by 30 Minutes. (Testing the + operator.)
Time object testTime is now 2:30 P.M.

Time object nowTime is now 2:00 P.M.

nowTime should NOT be changed from the + operator.

Assigning string "0840A" to nowTime.
Time object nowTime is now 8:40 A.M.

Assigning string "1200P" to nowTime.
Time object nowTime is now 12:00 P.M.

ryanreagle@Ryans-MacBook-Pro-2 output % 
*/
