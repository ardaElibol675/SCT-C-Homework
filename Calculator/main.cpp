#include <iostream>
#include <string>
#include "Calculator.cpp"
using namespace std;

Calculator generate(); // generate a calculator
Calculator generate5(); // generator for square

int main() {

    while(true) {

        string operation;

        cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
        cout << right << setw(25) << "CALCULATOR" << endl;
        cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;

        cout << left << setw(23) << "1. Adddition" << "2. Substraction\n"
             << left << setw(23) << "3. Multiplication" << "4. Division\n"
             << left << setw(23) << "5. Square" << "6. Exponentiation\n"
             << left << setw(23) << "7. Modulus" <<  "8. Exit\n";
        cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
        cout << left << setw(23) << "Enter Your Operation: ";
        cin >> operation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case the user provides extra input

        try {

            if (operation == "8") {
                cout << "Program Terminated" << endl;
                break;
            } else if (operation == "1") {
                generate().addition();
            } else if (operation == "2") {
                generate().subtraction();
            } else if (operation == "3") {
                generate().multiplication();
            } else if (operation == "4") {
                generate().division();
            } else if (operation == "5") {
                generate5().square();
            } else if (operation == "6") {
                generate().exponentiation();
            } else if (operation == "7") {
                generate().modulus();
            } else {
                cout << "Invalid Operation Input!\n";
            }

        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
        } catch (const logic_error&e) {
            cerr << e.what() << endl;
        }

    }
    
    return 0;
}

Calculator generate() {
    float x, y;
    cout << left << setw(23) << "Enter Your Numbers: ";       
    if (!(cin >> x >> y)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Invalid Input! Inputs Must Be Numbers");
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case the user provides extra input
    Calculator calculator(x, y);
    return calculator;
}

Calculator generate5() {
    float x;
    cout << left << setw(23) << "Enter Your Number: ";
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove the error-causing input from buffer
        throw runtime_error("Invalid Input! Input Must Be A Number");
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case the user provides extra input
    Calculator Calculator(x);
    return Calculator;
}
