#include <iostream>
#include <string>

using namespace std;

// Function prototypes
float add(float num1, float num2); // Function to add two numbers
float subtract(float num1, float num2); // Function to subtract two numbers
float multiply(float num1, float num2); // Function to multiply two numbers
float divide(float num1, float num2); // Function to divide two numbers

// Main function to perform calculations based on user input
int main() {
    // Display menu for user selection
    cout << "Select operation:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;

    // Take input from the user for the selected operation
    cout << "Enter choice (1/2/3/4): ";
    char choice;
    cin >> choice;

    // Check if the choice is valid
    if (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
        cout << "Invalid input" << endl;
        return 0;
    }

    // Input two numbers for the operation
    float num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Perform the selected operation based on user's choice
    switch (choice) {
    case '1':
        cout << "Result: " << add(num1, num2) << endl;
        break;
    case '2':
        cout << "Result: " << subtract(num1, num2) << endl;
        break;
    case '3':
        cout << "Result: " << multiply(num1, num2) << endl;
        break;
    case '4':
        cout << "Result: " << divide(num1, num2) << endl;
        break;
    }

    return 0;
}

// Function to add two numbers
float add(float num1, float num2) {
    return num1 + num2;
}

// Function to subtract two numbers
float subtract(float num1, float num2) {
    return num1 - num2;
}

// Function to multiply two numbers
float multiply(float num1, float num2) {
    return num1 * num2;
}

// Function to divide two numbers
float divide(float num1, float num2) {
    // Ensure no division by zero
    if (num2 == 0) {
        cout << "Error! Division by zero is not allowed." << endl;
        return 0;
    }
    return num1 / num2;
}
