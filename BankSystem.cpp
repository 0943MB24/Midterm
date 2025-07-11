#include "BankSystem.h"
#include <iostream>
using namespace std;

// Constructor initializes the system and sets up dummy accounts
BankSystem::BankSystem() : accountCount(3) {
    createDummyAccounts();
}

// Populates the system with the predefined sample accounts
void BankSystem::createDummyAccounts() {
    accounts[0] = BankAccount(1001, "Alice", 300.0, 'S');
    accounts[1] = BankAccount(1002, "Bob", 450.0, 'C');
    accounts[2] = BankAccount(1003, "Carol", 600.0, 'S');
}

// Binary search algorithm to locate an account by its account number
int BankSystem::binarySearch(int targetID) {
    int low = 0, high = accountCount - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (accounts[mid].getAccountNumber() == targetID)
            return mid;
        else if (accounts[mid].getAccountNumber() < targetID)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Main user interface loop for logging in and managing an account
void BankSystem::run() {
    int id;
    cout << "Welcome to the CIS25 Online Banking System.\n\nPlease Enter your Account Number to Log In: ";
    cin >> id;

    // Uses the Binary Search Algorithm to attempt to find the entered account number
    int index = binarySearch(id);
    if (index == -1) {
        cout << "\nAccount not found. Please Refer to the README file for Further Help. Exiting.\n";
        return;
    }

    // Pointer to the logged-in account for further operations
    BankAccount* user = &accounts[index];
    char menuSelect;

    // Menu loop to perform actions on the account
    do {
        cout << "\n(D)eposit\n(P)urchase\n(I)nfo\n(E)xit\n\n";
        cin >> menuSelect;
        menuSelect = toupper(menuSelect);

        switch (menuSelect) {
        case 'D':
            user->deposit(100.00); // Hardcoded deposit
            break;
        case 'P':
            user->makePurchase("Coffee", 7.95); // Hardcoded purchase
            break;
        case 'I':
            user->displayInfo();
            break;
        case 'E':
            cout << "\nThank You for Banking with CIS25. Signing out..\n";
            break;
        default:
            cout << "\nInvalid Option. Try Again.\n";
        }
    } while (menuSelect != 'E'); // Exit loop when user selects 'E'
}