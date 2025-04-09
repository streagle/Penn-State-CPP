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
// Assignment: Lab 10
//

// timer.h for CMPSC122 lab 
// Measure time in Window  
// Define a Timer object t, use t.start() for beginning of the algorithm, t.stop() for the ending, and t.show() for printing.

#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class Timer
{
  public:
    
    Timer();
    Timer(const std::string &label);
    ~Timer();
    void start(void);
    void stop(void);
    void show(void);
    //getter for elapsedtime
    double getElapsedTime() const { return elapsedtime; }
 
  private:
    void reset(void);
    string label;
    long tps;
    clock_t start_time, end_time;
    double usertime,
		   systemtime,
		   elapsedtime,
		   waittime;
};

#endif

