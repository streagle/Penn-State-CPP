// MyClass.cpp
#include "Q2.h"
#include <iostream>

using namespace std;

// Public member functions (methods)
WorkerRecord::WorkerRecord(){
    name = "Void Worker";
    level = 0;
    years = 0;
}

WorkerRecord::WorkerRecord(string name, int level, int years){
    this->name = name;
    this->level = level;
    this->years = years;
}


void WorkerRecord::SetInfo(string name, int level, int years){
    this->name = name;
    this->level = level;
    this->years = years;
}

void WorkerRecord::ShowInformation(){
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Years: " << years << endl;
}


bool WorkerRecord::HasLevelHigherThan(WorkerRecord & anotherWorder){
    return level > anotherWorder.level;
}




