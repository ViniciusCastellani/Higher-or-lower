#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

void display_menu()
{
    cout << "\nGAME HIGHER OR LOWER\n\n";
    cout << "\nCHOOSE A DIFFICULTY\n";
    cout << "A) EASY: NUMBER OF TRIES (5) NUMBER GENERATED BETWEEN 0 AND 10 \n";
    cout << "B) NORMAL: NUMBER OF TRIES (10) NUMBER GENERATED BETWEEN 0 AND 25 \n";
    cout << "C) HARD: NUMBER OF TRIES (5) NUMBER GENERATED BETWEEN 0 AND 50 \n\n";
}

string set_message(char choice)
{
    string message;

    switch (choice)
        {
            case 'A': 
                message = "NUMBER GENERATED BETWEEN 0 AND 10";
                break;
            case 'B':
                message = "NUMBER GENERATED BETWEEN 0 AND 25";
                break;
            case 'C':
                message = "NUMBER GENERATED BETWEEN 0 AND 50";
                break;
        }
    return message;
}

char check_letter(char letter)
{
    bool error = true;

    while (error)
        if (!isalpha(letter))
        {
            cout << "\nYOU DID NOT WRITE A LETTER, PLEASE INSERT A VALID CHARACTER: \n";
            error = true;
            cin >> letter;
            
        }

        else if ((letter == 'a') || (letter == 'b') || (letter == 'c'))
        {
            error = false;
        }

        else
        {
            cout << "\nINVALID OPTION, TRY AGAIN: \n";
            error = true;
            cin >> letter;
        }

    return toupper(letter);
}

char check_answer (char letter)
{
    bool error = true;

    while (error)
        if (!isalpha(letter))
        {
            cout << "\nYOU DID NOT WRITE A LETTER, PLEASE INSERT A VALID CHARACTER: \n";
            error = true;
            cin >> letter;
        }

        else if ((letter == 'y') || (letter == 'n'))
        {
            error = false;
        }

        else
        {
            cout << "\nINVALID OPTION, TRY AGAIN: \n";
            error = true;
            cin >> letter;
        }

    return toupper(letter);
}

int check_number(int guess, char choice)
{
    if (choice == 'A')
    {
        while (guess < 0 || guess >10)
        {
            cout << "\nYOU GUESSED A NUMBER OUT OF THE RANGE OF THE RANDOM NUMBER GENERATED, TRY AGAIN\n";
            cin >> guess;
        }
    }

    else if (choice == 'B')
    {
        while (guess < 0 || guess >25)
        {
            cout << "\nYOU GUESSED A NUMBER OUT OF THE RANGE OF THE RANDOM NUMBER GENERATED, TRY AGAIN\n";
            cin >> guess;
        }
    }

    else if (choice == 'C')
    {
        while (guess < 0 || guess >50)
        {
            cout << "\nYOU GUESSED A NUMBER OUT OF THE RANGE OF THE RANDOM NUMBER GENERATED, TRY AGAIN\n";
            cin >> guess;
        }
    }
    return guess;
}

int main()
{
    char choice;
    bool gameover;
    int tries;
    int random_number;
    int guess;
    char answer;
    string message;

    srand(time(0)); // Seed the random number generator

    do
    {
        Sleep(500);
        system("cls");

        display_menu();
        cin >> choice;
        
        choice = check_letter(choice);
        
        switch (choice)
        {
            case 'A': 
                random_number = rand() % 11;
                tries = 5;
                break;
            case 'B':
                random_number = rand() % 26;
                tries = 10;
                break;
            case 'C':
                random_number = rand() % 51;
                tries = 5;
                break;
        }

        message = set_message(choice);
        
        gameover = false;

        while (tries > 0 && !gameover)
        {
            Sleep(500);
            system("cls");

            cout << "\nNUMBER OF TRIES: " << tries << "  " << message << endl;
            cout << "\nGUESS THE NUMBER: ";
            cin >> guess;

            guess = check_number(guess,choice);

            if (guess > random_number)
            {
                cout << "\nLOWER\n\n";
                tries--;    
                Sleep(500);
                system("cls");
            }
            else if (guess < random_number)
            {
                cout << "\n\nHIGHER\n";
                tries--;    
                Sleep(500);
                system("cls");
            }
            else
            {
                cout << "\nYOU WON\n";
                gameover = true;
            }
        }

        if (tries == 0)
        {
            cout << "\nYOU LOSE\n";
        }
        
        cout << "\nNUMBER OF TRIES: " << tries << " CORRECT NUMBER: " << random_number << endl;
        cout << "\nDO YOU WANT TO PLAY AGAIN? [Y/N]\n";
        cin >> answer;
        answer = check_answer(answer);
        
    } while (answer == 'Y');

    return 0;
}