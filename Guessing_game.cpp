// Creating a guessing game where a user enters a number between 1 - 100 and gets tracks the number of attempts
// Needed to guess the correct number

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
using namespace std;

int main() 
{
    string yourname;

    // String established by user input
    cout << "Enter your name:  ";
    getline (cin >> ws, yourname);

    // Random function
    unsigned seed = time(0);
    srand(seed);

    // Variables used in loop
    int guessing_number;
    int input_counter = 0;
    int user_input;

    // The guessing number can be anything between 1 - 100
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 100;

    // Guessing number statement
    guessing_number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    cout << "Enter your guess (1 - 100): ";

    // Input loop
    while(true)
        {

            if (!(cin >> user_input))
            {
                cout << "Invalid input. Please enter a number/ \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Invalidates characters
                
                continue;
            }

            input_counter++; // Increments number of attempts

            // Input parameters
            if (user_input > MAX_VALUE || user_input < MIN_VALUE)
            {
                cout << "Invalid input. Please enter a number between 1 - 100. \n";
            }
        
            else if (user_input > guessing_number)
            {
                cout << "The number you entered is too high! Try again. \n";
            }
               
            else if (user_input < guessing_number)
            {
                cout << "The number you entered is too low! Try again, \n";
            }
            else 
            {
                cout << yourname << " guessed the correct value! \n";
                cout << yourname << " guessed " << input_counter << " times. \n";

                break; // End loop when user inputs correct value
    
            }
        }

    return 0;
}