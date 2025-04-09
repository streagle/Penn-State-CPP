#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;
//Methods

//generate a random word from a list of words
string generateWord(){
    string words[] = {
    "apple", "banana", "chair", "clock", "dance", "elephant", "flower", 
    "guitar", "house", "island", "jacket", "kitten", "lemon", "mouse", 
    "night", "orange", "pizza", "queen", "robot", "sunset"
    };
    int randomIndex = rand() % words -> size();
    return words[randomIndex];
}

//generate a string of underscores the same length as the word

string generateUnderscores(string word){
    string underscores = "";
    for(size_t i = 0; i < word.length(); i++){
        underscores += "_";
    }
    return underscores;
}

//check if a letter is in the word

bool checkLetter(string word, char letter){
    for(size_t i = 0; i < word.length(); i++){
        if(word[i] == letter){
            return true;
        }
    }
    return false;
}

//replace underscores with the letter

string replaceLetter(string word, string underscores, char letter){
    for(size_t i = 0; i < word.length(); i++){
        if(word[i] == letter){
            underscores[i] = letter;
        }
    }
    return underscores;
}

//check if the word has been guessed

bool checkWord(string word, string underscores){
    if(word == underscores){
        return true;
    }
    return false;
}

//print the hangman

void printHangman(int wrongGuesses){
    switch(wrongGuesses){
        case 0:
            cout << "  ______" << endl;
            cout << " |     |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 1:
            cout << "  ______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 2:
            cout << "  ______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 3:
            cout << "  ______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 4:
            cout << "  ______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 5:
            cout << "  ______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    /" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 6:
            cout << "  ______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    / \\" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
    }
}



int main(){

    //Variables
    string word;
    string underscores;
    char letter;
    int wrongGuesses = 0;
    bool correctGuess;
    bool wordGuessed;

    //Inputs

    srand(time(NULL));
    word = generateWord();
    underscores = generateUnderscores(word);

    //Processes + output

    while(wrongGuesses < 6){
        printHangman(wrongGuesses);
        cout << "Word: " << underscores << endl;
        cout << "Enter a letter: ";
        cin >> letter;
        correctGuess = checkLetter(word, letter);
        if(correctGuess){
            underscores = replaceLetter(word, underscores, letter);
            wordGuessed = checkWord(word, underscores);
            if(wordGuessed){
                cout << "You win!" << endl;
                break;
            }
        } else {
            wrongGuesses++;
        }
    }

    if(wrongGuesses == 6){
        cout << "You lose!" << endl;
    }

return 0;
}