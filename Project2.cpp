#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Global variables shown/referenced by the assembly
int answer;
int choice;
int changechoice;
int newservice;

int num1 = 1;
int num2 = 2;
int num3 = 1;
int num4 = 1;
int num5 = 2;
// SECURITY RISK: hardcoded client names should be in a database or other file, not in code
char name1[] = "Bob Jones";
char name2[] = "Sarah Davis";
char name3[] = "Amy Friendly";
char name4[] = "Johnny Smith";
char name5[] = "Carol Spears";
// SECURITY RISK: very easy to crack password, stored in code in plain text
char username[20];
char password[20] = "123";

// Function prototypes
int CheckUserPermissionAccess();
void DisplayInfo();
void ChangeCustomerChoice();

int main()
{
    cout << "Created by Stef Wright" << endl;
    cout << "Hello! Welcome to our Investment Company\n";

    // Keep asking for login until the password is correct
    // SECURITY RISK: no limit on wrong password in this loop, brute force possible
    // SECURITY FIX: added counter variable to track failed login attempts, when counter reaches a 3 failed tries
    // program prints lockout message ane exits, limits brute force attempts
    // only temp fix since no timer to prevent user from just reloading and trying again
    // storing failed attempts with a time delay to the user account would help make this more secure

    int count = 0;
    const int max_attempts = 3;
    do
    {
        answer = CheckUserPermissionAccess();

        if (answer != 1)
        {
            count += 1;

            if (count >= max_attempts)
            {
                cout << "User reached maximum signin attempts. Account is temporarily blocked, try again later.\n";
                return 1;
            }
            cout << "Invalid Password. Please try again.\n";
            cout << "Attempts remaining: " << 3 - count << endl;
        }

    } while (answer != 1);

    // Main menu
    do
    {
        cout << "\nWhat would you like to do?\n";
        cout << "DISPLAY the client list (enter 1)\n";
        cout << "CHANGE a client's choice (enter 2)\n";
        cout << "Exit the program.. (enter 3)\n";
        // SECURITY RISK: no input validation, infinite loop possible with incorrect input
        // SECURITY FIX: choice is validated and cin is cleared if incorrect input is used. 
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
            continue;
        }

        cout << "You chose " << choice << endl;

        if (choice == 1)
        {
            DisplayInfo();
        }

        else if (choice == 2)
        {
            ChangeCustomerChoice();
        }
        // SECURITY FIX: integer choices not matching menu choices are addressed with message to user
        else if (choice != 3)
        {
            cout << "Please try again with a menu choice (1, 2 or 3).\n";
        }

    } while (choice != 3);

    return 0;
}


int CheckUserPermissionAccess()
{
    // SECURITY RISK: no logging of logins
    // SECURITY RISK: password stored as string and used directly for comparison
    string inputPassword = "";
    int result = 0;
  
    // SECURITY RISK: no input validation, username is not checked against something (username list)
    cout << "Enter your username: ";
    cin >> username;
    // SECURITY RISK: no input validation, password stored and checked without encryption or hashing
    cout << "Enter your password: ";
    cin >> inputPassword;

    result = inputPassword.compare("123");

    if (result == 0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


void ChangeCustomerChoice()
{
    // SECURITY RISK: no user authorization, any user can access this
    // no input validation
    cout << "Enter the number of the client that you wish to change.";
    cin >> changechoice;
    // no input validation, no check to make sure input equals 1 or 2
    cout << "Please enter the client's new service choice "
          "(1 = Brokerage, 2 = Retirement)\n";
    cin >> newservice;

    if (changechoice == 1)
    {
        num1 = newservice;
    }
    else if (changechoice == 2)
    {
        num2 = newservice;
    }
    else if (changechoice == 3)
    {
        num3 = newservice;
    }
    else if (changechoice == 4)
    {
        num4 = newservice;
    }
    else if (changechoice == 5)
    {
        num5 = newservice;
    }
}


void DisplayInfo()
{
    cout << "   Client's Name   Service Selected (1 = Brokerage, 2 = Retirement)" << endl;

    cout << "1. " << name1
         << " selected option " << num1 << endl;

    cout << "2. " << name2
         << " selected option " << num2 << endl;

    cout << "3. " << name3
         << " selected option " << num3 << endl;

    cout << "4. " << name4
         << " selected option " << num4 << endl;

    cout << "5. " << name5
         << " selected option " << num5 << endl;
}
