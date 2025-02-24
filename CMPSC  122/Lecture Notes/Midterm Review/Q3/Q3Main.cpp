#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

#include "Q3.h"

using namespace std;



int main(){
Time teaTime(5, 30, 'A');
if(teaTime == 530) cout << "Same!" <<endl;
// This should print “Same!”, since they both represent 5:30AM
if(teaTime == 1130) cout << "Same!" <<endl;
// This should NOT print anything, since the times are not same
Time bedTime(5, 30, 'P');
if(bedTime == 530) cout << "Same!" <<endl;
// This should NOT print anything, since 5:30PM is NOT 5:30AM

return 0;
}