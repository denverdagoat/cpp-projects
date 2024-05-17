/* Sample C++ code */
#include <iostream>
#include <cstdlib> 
#include <ctime>

const int rock = 1, paper = 2, scissors = 3;
int userWins = 0, computerWins = 0;

int computerChoice(int);
int getUserChoice(int);
void displayComputerNumber(int);
void whoWins(int, int);

using namespace std;
int main() {
    int user_choice, computer_choice, rounds, score;

    cout << "How much rounds do you want to play?" << endl;
    cin >> rounds;

    for (int i = 1; i <= rounds; i++)
    {
        cout << "----------------------------------------------------" << endl; 
        cout << "Round " << i << " :" << endl;
        computer_choice = computerChoice(computer_choice);

        user_choice = getUserChoice(user_choice);

        displayComputerNumber(computer_choice);

        whoWins(computer_choice, user_choice);

        cout << "\nThe score is now\n";
        cout << "User: " << userWins << " to Computer: " << computerWins << endl;
    }
    
    if (computerWins > userWins)
        cout << "\nThe overall winner is the computer!";
    else if (userWins > computerWins)
        cout << "\nThe overall winner is the user!";
    else if (userWins == computerWins)
    {
        do {
            cout << "--------------------------------------------------" << endl;
            cout << "There will be another round since its an overall tie!" << endl;
        computer_choice = computerChoice(computer_choice);

        user_choice = getUserChoice(user_choice);

        displayComputerNumber(computer_choice);

        whoWins(computer_choice, user_choice); 

        cout << "\nThe score is now\n";
        cout << "User: " << userWins << " to Computer: " << computerWins << endl;
            if (computerWins > userWins) {
                cout << "\nThe overall winner is the computer!";
                break; 
            }
            else if (userWins > computerWins) {
                cout << "\nThe overall winner is the user!";
                break;
            }
        }
        while (userWins == computerWins);
    }
    return 0;
}; // end of main function

int computerChoice(int computer_choice) 
{
    unsigned seed = time(0);

    srand(seed);

    return (rand() % (scissors - rock + 1)) + rock;
} //  end of computerChoice function, ensures pure randomness

int getUserChoice(int user_choice) { 

cout << "\nChoose rock, paper, or scissors\n (1) for rock, (2) for paper, (3) scissors" << endl; 
cin >> user_choice;

while ((user_choice < 1) || (user_choice > 3))
    {   cout << "Error. Please enter either 1 (rock), 2 (paper) or 3 (scissors)" << endl;
        cin >> user_choice;}

return user_choice;
} // end of getUserChoice function

void displayComputerNumber(int computer_choice) 
{
    cout << "Computer Choice = ";

    if (computer_choice == 1)
        cout << "Rock" << endl;
    else if (computer_choice == 2)
        cout << "Paper" << endl;
    else if (computer_choice == 3)
        cout << "Scissors" << endl;

} // end of displayComputerNumber function

void whoWins(int computer_choice, int user_choice)
{
    cout << endl;

    if (computer_choice == rock)
    {
        if (user_choice == paper)
        {
            cout << "You win; paper covers rock!\n";
            userWins++;
        }
        else if (user_choice == scissors)
        {
            cout << "Computer wins; rock smashes scissors!\n";
            computerWins++;
        }
        else if (user_choice == rock)
        {
            cout << "Tie; no one wins!\n";
        }
    } 
    else if (computer_choice == paper)
    {
        if (user_choice == rock)
        {
            cout << "Computer wins; paper covers rock!\n";
            computerWins++;
        }
        else if (user_choice == scissors)
        {
            cout << "You win; scissors cuts paper!\n";
            userWins++;
        }
        else if (user_choice == paper)
        {
            cout << "Tie; no one wins!\n";
        }
    }
    else if (computer_choice == scissors)
    {
        if (user_choice == rock)
        {
            cout << "You win; rock smashes scissors!\n";
            userWins++;
        }
        else if (user_choice == paper)
        {
            cout << "Computer wins; scissors cut paper!\n";
            computerWins++;
        }
        else if (user_choice == scissors)
        {
            cout << "Tie; no one wins!\n";
        }
    }
}
