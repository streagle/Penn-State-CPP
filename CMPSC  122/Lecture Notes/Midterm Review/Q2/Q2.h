// MyClass.h
#pragma once
#include <string>
#include <iostream>

using namespace std;

class WorkerRecord {
public:
    // Public member functions (methods)
    WorkerRecord();
    WorkerRecord(string name, int level, int years);
    void SetInfo(string name, int level, int years);
    void ShowInformation();
    bool HasLevelHigherThan(WorkerRecord & anotherWorder);



private:
    // Private member variables
    string name;
    int level;
    int years;



};
