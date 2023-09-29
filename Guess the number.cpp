#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    cout << endl << "Welcome to the Guess the Number game..." << endl;
    cout << "Guess the number between 1-100." << endl;
    cout << "You will have limited choices." << endl;

    while (true) {
        int difficulty;
        cout << "\nEnter the difficulty level of the game:" << endl;
        cout << "1 for easy level" << endl;
        cout << "2 for medium level" << endl;
        cout << "3 for hard level" << endl;
        cout << "0 to end the game" << endl;

        cin >> difficulty;

        if (difficulty == 0) {
            return 0; // Exit the program
        } else if (difficulty < 1 || difficulty > 3) {
            cout << "Wrong value entered. Please enter a correct value." << endl;
            continue; // Go back to the beginning of the loop
        }

        srand(time(0));
        int randomnumber = 1 + (rand() % 100);
        int pchoice;
        int maxTurns;

        if (difficulty == 1) {
            maxTurns = 10;
            cout << "You have 10 choices." << endl;
        } else if (difficulty == 2) {
            maxTurns = 6;
            cout << "You have 6 choices." << endl;
        } else if (difficulty == 3) {
            maxTurns = 3;
            cout << "You have 3 choices." << endl;
        }

        for (int turns = 1; turns <= maxTurns; turns++) {
            cout << "Enter a number between 1 to 100: ";
            cin >> pchoice;

            if (pchoice == randomnumber) {
                cout << "Well played! You won. " << pchoice << " is the number." << endl;
                break;
            } else {
                cout << "No, not the right number." << endl;
                if (pchoice > randomnumber) {
                    cout << "The entered number is greater than the random number." << endl;
                } else {
                    cout << "The entered number is smaller than the random number." << endl;
                }
                cout << maxTurns - turns << " choices are left now." << endl;
            }

            if (turns == maxTurns) {
                cout << "Sorry, you lost the game." << endl;
                cout << "The random number was " << randomnumber << endl;
            }
        }
    }

    return 0;
}
