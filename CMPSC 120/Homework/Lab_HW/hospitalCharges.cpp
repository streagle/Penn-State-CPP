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
// Assignment: Lab 08
//
#include <iostream>
#include <iomanip>


using namespace std;
//Methods

/* -------------------------------------------------------------------------- */
/*                             function prototypes                            */
/* -------------------------------------------------------------------------- */
char getPatientType();
double patientCharges(int days, double roomchrg, double med,double serv); // In-patient
double patientCharges(double med, double serv); // Outpatient
int getDaysInHospital();
double getChargesRate(string chargesItem);

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */
int getDaysInHospital(){
    int days;
    do{
        cout << "Enter the number of days spent in the hospital: ";
        cin >> days;
        if (days < 0){
            cout << "Invalid input, days cannot be less than 0!" << endl;
        }
    }while(days < 0);
    return days;
}

double getChargesRate(string chargesItem){
    double charges;
    do{
        cout << "Enter the " << chargesItem << " charges: ";
        cin >> charges;
        if (charges < 0){
            cout << "Invalid input, charges cannot be less than 0!" << endl;
        }
    }while(charges < 0);
    return charges;
}

char getPatientType(){
    char type;
    do{
        cout << "Enter the type of patient (I for in-patient, O for out-patient): ";
        cin >> type;
        if (type != 'I' && type != 'O' && type != 'i' && type != 'o'){
            cout << "Invalid input, try again!" << endl;
        }
    }while(type != 'I' && type != 'O' && type != 'i' && type != 'o');
    return type;
}

double patientCharges(int days, double roomchrg, double med, double serv){
    return days * roomchrg + med + serv; 
}

double patientCharges(double med, double serv){
    return med + serv;
}


/* -------------------------------------------------------------------------- */
/*                                    main                                    */
/* -------------------------------------------------------------------------- */
int main(){
//Variables
char patientType;
int days;
double roomCharges, medCharges, servCharges, totalCharges;



//Inputs
patientType = getPatientType();
if(patientType == 'I' || patientType == 'i'){
    days = getDaysInHospital();
    roomCharges = getChargesRate("room");
    medCharges = getChargesRate("medication");
    servCharges = getChargesRate("service");
    totalCharges = patientCharges(days, roomCharges, medCharges, servCharges);
}else{
    medCharges = getChargesRate("medication");
    servCharges = getChargesRate("service");
    totalCharges = patientCharges(medCharges, servCharges);
}
cout << endl;
cout << "The total charges are: $" << fixed << setprecision(2) << totalCharges << endl;





//Processes



//Outputs



return 0;
}

/* -------------------------------------------------------------------------- */
/*                              Sample Outoput 1                              */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"hospitalCharges"
Enter the type of patient (I for in-patient, O for out-patient): I
Enter the number of days spent in the hospital: -1
Invalid input, days cannot be less than 0!
Enter the number of days spent in the hospital: 5
Enter the room charges: -10
Invalid input, charges cannot be less than 0!
Enter the room charges: 125
Enter the medication charges: 325.80
Enter the service charges: 150.50

The total charges are: $1101.30
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                               Sample Output 2                              */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"hospitalCharges"
Enter the type of patient (I for in-patient, O for out-patient): O
Enter the medication charges: -25.50
Invalid input, charges cannot be less than 0!
Enter the medication charges: 85.80
Enter the service charges: -100
Invalid input, charges cannot be less than 0!
Enter the service charges: 250.9

The total charges are: $336.70
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/