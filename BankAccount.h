#pragma once // Prevents multiple inclusions of this header file. ALWAYS use this for header files!

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// The BankAccount class models a basic bank account
class BankAccount {
private:
	int accountNumber;
	std::string accountHolder;
	double balance;
	char accountType;
	bool isActive;

public:
	// Default constructor
	BankAccount();
	// Parameterized constructor to initialize a new account with data
	BankAccount(int accNo, const string& name, double initialDeposit, char type);

	// Adds a deposit to the account balance
	void deposit(double amount);

	// Deducts a purchase from the account balance if sufficient funds exist
	void makePurchase(const string& item, double cost);

	// Displays full account details to the console
	void displayInfo() const;

	// Saves a transaction record to a file (In this case, Saves a deposit of $100.00 to file)
	void saveTransactions(const string& type, double amount);

	// Retrieves the account balance
	double getBalance() const;

	// Retrieves the account number for searches
	int getAccountNumber() const;
};