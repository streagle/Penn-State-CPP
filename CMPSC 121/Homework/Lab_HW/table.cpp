#include <iostream>
#include <iomanip>



using namespace std;
//Methods



int main(){
//Variables
int row;
int column;



//Inputs
cout << "Lets build a multiplication table!" << endl;
cout << "Enter the number of rows (1-12 inclusive): ";
cin >> row;
while (row < 1 || row > 12){
    cout << "Invalid input. Please enter a number between 1 and 12: ";
    cin >> row;
}
cout << "Enter the number of columns (1-12 inclusive): ";
cin >> column;
while (column < 1 || column > 12){
    cout << "Invalid input. Please enter a number between 1 and 12: ";
    cin >> column;
}
cout << endl;




//Processes



//output the colum and row headers
cout << setw(4) << " ";
for (int i = 1; i <= column; i++){
    cout << setw(4) << i;
}
cout << endl;

//output the table
for (int i = 1; i <= row; i++){
    cout << setw(4) << i;
    
    for (int j = 1; j <= column; j++){
        cout << setw(4) << i * j;
    }
    cout << endl;
}









return 0;
}

/* -------------------------------------------------------------------------- */
/*                              EXAMPLE OUTPUT 1                              */
/* -------------------------------------------------------------------------- */

/* 
ryanreagle@Ryans-MacBook-Pro-2 output % ./"table"
Lets build a multiplication table!
Enter the number of rows (1-12 inclusive): -10
Invalid input. Please enter a number between 1 and 12: 4
Enter the number of columns (1-12 inclusive): 16
Invalid input. Please enter a number between 1 and 12: 5

       1   2   3   4   5
   1   1   2   3   4   5
   2   2   4   6   8  10
   3   3   6   9  12  15
   4   4   8  12  16  20

ryanreagle@Ryans-MacBook-Pro-2 output % 
*/