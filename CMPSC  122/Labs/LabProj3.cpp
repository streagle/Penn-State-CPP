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

#include "LabProj3.h"

// Implementation of myFind function
int myFind(const char * targetStr, const char * subStr) {
    int count = 0;
    int targetStrLength = strlen(targetStr);
    int subStrLength = strlen(subStr);
    for (int i = 0; i < targetStrLength; i++) {
        if (targetStr[i] == subStr[0]) {
            bool found = true;
            for (int j = 0; j < subStrLength; j++) {
                if (targetStr[i + j] != subStr[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                count++;
            }
        }
    }
    return count;
}

// Implementation of improveFormat function
void improveFormat(char * targetStr) {
    int targetStrLength = strlen(targetStr);
    int j = 0;
    for (int i = 0; i < targetStrLength; i++) {
        if (targetStr[i] == ' ') {
            if (j == 0 || targetStr[j - 1] != ' ') {
                targetStr[j] = targetStr[i];
                j++;
            }
        } else {
            targetStr[j] = targetStr[i];
            j++;
        }
    }
    targetStr[j] = '\0';
}