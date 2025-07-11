#pragma once
#include "BankAccount.h"

// The BankSystem class manages some of the BankAccount objects,
// which enables logging in by account number, accessing accounts, and performing banking operations.
class BankSystem {
private:
    BankAccount accounts[3];  // Array of bank accounts (size is fixed to 3)
    int accountCount; // Total number of active accounts in the system

public:
    BankSystem(); // Constructor to initialize system and populate accounts
    void createDummyAccounts(); // Creates pre-defined accounts for demonstration
    int binarySearch(int targetID); // Searches for an account by account number
    void run(); // Runs the main interface loop (login and user menu)
};