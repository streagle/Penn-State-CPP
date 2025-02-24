#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

#include "Q2.h"

using namespace std;
//Methods



int main(){
//Variables
WorkerRecord worker1;
WorkerRecord worker2;
WorkerRecord worker3;




//Inputs
worker1.SetInfo("John", 3, 5);
worker2.SetInfo("Jane", 4, 6);




//Outputs
worker1.ShowInformation();
worker2.ShowInformation();
worker3.ShowInformation();

//Comparisons
if(worker1.HasLevelHigherThan(worker2)){
    cout << "John has a higher level than Jane" << endl;
}
else{
    cout << "Jane has a higher level than John" << endl;
}


return 0;
}