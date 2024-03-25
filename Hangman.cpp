#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

vector<string> words = {"HELLO", "WORLD", "PROGRAM", "COMPUTER", "SCIENCE", "ENGINEERING", "HARSH", "DEVELOPER", "CODING", "COLLEGE"};

string chooseWord(const vector<string>& words) {
    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % words.size();
    return words[index];
}

string toUpper(string str) {
    for (char &ch : str) {
        ch = toupper(ch);
    }
    return str;
}

bool contains(const string& word, char guess) {
    return word.find(guess) != string::npos;
}

void display(const string& guessedWord, int trry) {
    string man[] = {
        "  ________\n |        |\n |        O\n |       /|\\\n |       / \\\n_|_", 
        "  ________\n |        |\n |        O\n |       /|\\\n |       / \\\n_|_", 
        "  ________\n |        |\n |        O\n |       /|\\\n |       /\n_|_",  
        "  ________\n |        |\n |        O\n |       /|\\\n |\n_|_",           
        "  ________\n |        |\n |        O\n |       /|\n |\n_|_",             
        "  ________\n |        |\n |        O\n |        |\n |\n_|_",            
        "  ________\n |        |\n |        O\n |\n |\n_|_",                      
        "  ________\n |\n |\n |\n |\n_|_"                                      
    };

    cout << man[trry] << endl;
    cout << "Current word: ";
    for (char ch : guessedWord) {
        cout << ch << " ";
    }
    cout << endl;
}

int main() {
    const int MAX_TRIES = 6;
    string targetWord = chooseWord(words);
    string guessedWord(targetWord.size(), '-');
    int trry = 0;
    char guess;

    cout << "Welcome to Hangman!\n\n";

    while (trry < MAX_TRIES && guessedWord != targetWord) {
        cout << "You have " << (MAX_TRIES - trry) << " tries left.\n";
        display(guessedWord, trry);
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess);

        if (contains(targetWord, guess)) {
            cout << "Correct guess!\n\n";
            for (size_t i = 0; i < targetWord.size(); ++i) {
                if (targetWord[i] == guess) {
                    guessedWord[i] = guess;
                }
            }
        } else {
            cout << "Incorrect guess!\n\n";
            trry++;
        }
    }

    if (guessedWord == targetWord) {
        cout << "Congratulations! You've guessed the word: " << targetWord << endl;
    } else {
        cout << "Sorry, you've run out of tries. The word was: " << targetWord << endl;
    }

    return 0;
}
