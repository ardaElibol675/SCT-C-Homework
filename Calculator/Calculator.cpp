#include <iostream>
#include <math.h>
#include <iomanip>
#include "Calculator.h"
using namespace std;

void Calculator::addition() {
    cout << left << setw(23) << "Result: " << n1+n2 << endl;
}

void Calculator::subtraction() {
    cout << left << setw(23) << "Result: " << n1-n2 << endl;
}

void Calculator::multiplication() {
    cout << left << setw(23) << "Result: " << n1*n2 << endl;
}

void Calculator::division() {
    if (n2 == 0) // check whether the denominator is zero
        throw logic_error("Invalid Input! Denominator Can't Be Zero");
    cout << left << setw(23) << "Result: " << n1/n2 << endl;
}

void Calculator::square() {
    cout << left << setw(23) << "Result: " << n1*n1 << endl;
}

void Calculator::exponentiation() {
    cout << left << setw(23) << "Result: " << pow(n1, n2) << endl;
}

void Calculator::modulus() {
    if (n2 == 0) // check whether the divider is zero
        throw logic_error("Invalid Input! Divider Can't Be Zero");
    else if (!(int{n1}==n1) || !(int{n2}==n2)) // check whether numbers are floating
        throw logic_error("Invalid Input! Inputs Must Be Integer");
    cout << left << setw(23) << "Result: " << int{n1}%int{n2} << endl;
}
