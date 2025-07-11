#include <iostream>
#include "BankSystem.h" // Include the header for the BankSystem class

using namespace std;

// Entry point of the program
int main() {
	// Create an instance of the banking system
	BankSystem system;

	// Start the main banking system loop (login and menu)
	system.run();

	return 0; // Exits the program
	}