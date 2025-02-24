#include <iostream>
#include <cstring>

using namespace std;
//Methods
void InsertToBlank(char * strToModify, const char * wordToInsert);

// Insert word between blanks in a string
void InsertToBlank(char * strToModify, const char * wordToInsert){
    char * currentPos = strToModify; // Pointer to traverse the string
    
    while(*currentPos != '\0'){ // Loop until the end of the string
        if(*currentPos == ' '){ // Check for a blank space
            char * endPos = currentPos + strlen(currentPos); // Pointer to the end of the string
            // Shift characters to the right to make space for the word
            while(endPos >= currentPos) {
                *(endPos + strlen(wordToInsert) + 1) = *endPos;
                endPos--;
            }
            *currentPos++ = ' '; // Move past the blank space
            // Insert the word
            while(*wordToInsert) {
                *currentPos++ = *wordToInsert++;
            }
        }
        currentPos++; // Move to the next character
    }
}



int main(){
    char str[] = "Hello World!";
    char word[] = "Funny";

    InsertToBlank(str, word);
    cout << str << endl;

   
return 0;
}