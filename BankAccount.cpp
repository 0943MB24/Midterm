#include "BankAccount.h"
#include <iostream>
#include <fstream>
using namespace std;

// Default constructor: initializes a blank/inactive account
BankAccount::BankAccount() : accountNumber(0), accountHolder(""), balance(0.0), accountType('C'), isActive(false) {}

// Parameterized constructor: sets up a new active account with initial details
BankAccount::BankAccount(int accNo, const string& name, double initialDeposit, char type)
	: accountNumber(accNo), accountHolder(name), balance(initialDeposit), accountType(type), isActive(true) {
	saveTransactions("Account Created", initialDeposit);
}

// Adds a deposit to the account balance and logs the transaction
void BankAccount::deposit(double amount) {
	balance += amount;
	saveTransactions("Deposit", amount);
	cout << "\nAmount deposited: $" << amount << "\nNew Balance: $" << balance << endl;
}

// Deducts cost from balance if funds are available, logs purchase
void BankAccount::makePurchase(const string& item, double cost) {
	if (cost > balance) {
		cout << "\nInsufficient funds for " << item << endl;

	} else {
		balance -= cost;
		saveTransactions("Purchase - " + item, cost);
		cout << "\nPurchased: " << item << "\nNew Balance: " << balance << endl;
	}
}

// Displays key information about the account
void BankAccount::displayInfo() const {
	cout << "\n-----Account Info-----\n\n" << "Account Holder: " << accountHolder << endl;
	cout << "\nAccount Number: " << accountNumber << "\nAccount Type: " << accountType << endl;
	cout << "\nAccount Status: " << (isActive ? "Active" : "Inactive") << "\nBalance: $" << balance << endl;
}

// Appends a transaction entry to "transactions.txt" for recordkeeping
void BankAccount::saveTransactions(const string& type, double amount) {
	ofstream file("transactions.txt", ios::app);
	if (file.is_open()) {
		file << type << ": $" << amount << endl;
		file.close();
	}
}

// Returns current account balance (read only)
double BankAccount::getBalance() const {
	return balance;
}

// Returns the unique account number for logging in/searching
int BankAccount::getAccountNumber() const {
	return accountNumber;
}
