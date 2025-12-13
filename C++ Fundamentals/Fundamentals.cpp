#include <iostream>
#include <vector>
#include <limits>
#include <cstdint>
#include <string>
#include <memory>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
    
    // My Variables
    auto integer = 15;
    const float floating = 0.515;
    constexpr double dFloating = 0.15151515;
    char letter = 'a';
    int a = letter; //the value is the ASCII code of 'a'
    bool yes = true;
    bool no = false;

    // Display of My Variables
    cout << "\nMy Variables" << endl << setfill('-') << setw(45) << "" << endl << setfill(' ');
    cout << left << setw(8) << "int: " << left << setw(17) << integer << "[Size: " << sizeof(int) << "]" << endl;
    cout << left << setw(8) << "float: " << left << setw(17) << floating << "[Size: " << sizeof(float) << "]" << endl;
    cout << left << setw(8) << "double: " << left << setw(17) << dFloating << "[Size: " << sizeof(double) << "]" << endl;
    cout << left << setw(8) << "char: " << left << setw(17) << letter << "[Size: " << sizeof(char) << "]" << endl;
    cout << left << setw(8) << "bool: " << left << setw(17) << yes << "[Size: " << sizeof(bool) << "]" << endl;
    cout << setfill('-') << setw(45) << "" << endl << setfill(' ');

    // Display of Variable Limits
    cout << endl << "Variable Limits" << endl << setfill('-') << setw(45) << "" << endl << setfill(' ');
    cout << left << setw(25) << "int: " << numeric_limits<int>::min() << ", " << numeric_limits<int>::max() << endl;
    cout << left << setw(25) << "float: " << numeric_limits<float>::min() << ", " << numeric_limits<float>::max() << endl;
    cout << left << setw(25) << "double: " << numeric_limits<double>::min() << ", " << numeric_limits<double>::max() << endl;
    cout << left << setw(25) << "char: " << numeric_limits<char>::min() << ", " << numeric_limits<char>::max() << endl;
    cout << left << setw(25) << "bool: " << numeric_limits<bool>::min() << ", " << numeric_limits<bool>::max() << endl;
    cout << setfill('-') << setw(45) << "" << endl << setfill(' ');

    // Display of Behavior Differences
    cout << endl << "Behaviors" << endl << setfill('-') << setw(45) << "" << endl << setfill(' ');
    cout << left << setw(25) << "08 bit int" << "[" << numeric_limits<int8_t>::min() << ", " << numeric_limits<int8_t>::max() << "]" << endl;
    cout << left << setw(25) << "16 bit int" << "[" << numeric_limits<int16_t>::min() << ", " << numeric_limits<int16_t>::max() << "]" << endl;
    cout << left << setw(25) << "32 bit int" << "[" << numeric_limits<int32_t>::min() << ", " << numeric_limits<int32_t>::max() << "]" << endl;
    cout << left << setw(25) << "Unsigned Plain int" << "[" << numeric_limits<u_int32_t>::min() << ", " << numeric_limits<u_int32_t>::max() << "]" << endl;
    
    cout << fixed << setprecision(2) << endl << left << setw(30) << "float and double with precision 2: " << endl << left << setw(25) << floating << dFloating << endl;
    cout << fixed << setprecision(5) << endl << left << setw(30) <<"float and double with precision 5: " << endl << left << setw(25) << floating << dFloating << endl;
    cout << endl << "bool: " << yes << " // Prints 1 for true value." << endl;
    cout << endl << "bool: " << no << " // Prints 0 for false value." << endl;
    cout << endl << "char: " << letter << " // char for the ASCII: " << a << endl;
    cout << setfill('-') << setw(45) << "" << endl << setfill(' ');

    // Pointers and Dynamic Memory Allocation
    cout << endl << "Pointers and Dynamic Memory Allocation" << endl << setfill('-') << setw(45) << "" << endl << setfill(' ');
    int x;
    cout << left << setw(25) << "Enter an integer:";
    cin >> x;
    int* ptr = &x;
    cout << left << setw(25) << "x:" << x << endl
         << left << setw(25) << "Size of x: " << sizeof(int) << endl
         << left << setw(25) << "Adress of x:" << &x << endl
         << left << setw(25) << "Size of the adress: " << sizeof(int*) << endl
         << left << setw(25) << "x by pointer:" << *ptr << endl
         << left << setw(25) << "Adress of x by pointer:" << ptr << endl;
    
    int* myArray = new int[x]; // allocating a memory with size x
    vector<int> myVector; // vector without any initializer or size
    
    for (int i=0; i < x; i++) { // fill the array
        myArray[i] = i+1;
    }
    
    cout << left << setw(25) << "Elements of the array: ";
    for (int i=0; i < x; i++) { // print and copy the elemnts of the array
        cout << myArray[i] << " ";
        myVector.push_back(myArray[i]);
    }
    delete[] myArray; // this array won't be used again
    cout << endl;
    
    myVector.pop_back(); // pop the last element of the vector
    cout << left << setw(25) << "Elements of the vector: ";
    for (const auto& i: myVector) { // print the elements of the vector
        cout << i << " ";
    }
    cout << endl;
    
    *ptr = 10; // modify the variable via the pointer
    cout << left << setw(25) << "New x:" << x << endl;
    cout << setfill('-') << setw(45) << "" << endl << setfill(' ');

    // List, Stack and Queue
    cout << endl << "List, Stack and Queue" << endl << setfill('-') << setw(45) << "" << endl << setfill(' ');
    list<int> lst{1, 5, 3};
    lst.push_front(6); // new list {6, 1, 5, 3}
    auto first = lst.begin(); // .begin() returns the pointer of first element, type of 'first' is list iterator
    cout << left << setw(25) << "First of the list:" << *first << endl;
    first++; // iterator points to 1
    lst.pop_front();
    cout << left << setw(25) << "New First of the list:" << *lst.begin() << endl;
    cout << left << setw(25) << "First: " << lst.front() << endl; // .front() returns the value of first element
    first++; // iterator points to 5
    cout << left << setw(25) << "Second: " << *first << endl;
    
    stack<int> s;
    for (int i = 1; i <= 5; i++) // fill the stack
        s.push(i);
    cout << endl << left << setw(25) << "Top of the stack:" << s.top() << endl;
    s.pop(); // remove the top element (LIFO)
    cout << left << setw(25) << "New Top of the stack:" << s.top() << endl;

    queue<int> q;
    for (int i = 1; i <= 5; i++) // fill the queue
        q.push(i);
    cout << endl << left << setw(25) << "Front of the queue:" << q.front() << endl;
    cout << left << setw(25) << "Back of the queue:" << q.back() << endl;
    q.pop(); // remove the front element (FIFO)
    cout << left << setw(25) << "New Front of the queue:" << q.front() << endl;
    cout << setfill('-') << setw(45) << "" << endl << setfill(' ') << endl;

    return 0;
}
