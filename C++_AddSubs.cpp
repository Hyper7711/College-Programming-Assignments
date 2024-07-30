#include <iostream>
using namespace std;

struct Calculator {
    enum Operation { ADDITION, SUBTRACTION };
    static int count;
    static void incrementCount() { count++; }
};

int Calculator::count = 0;

int add(int a, int b) {
    Calculator::incrementCount();
    return a + b;
}

int subtract(int a, int b) {
    Calculator::incrementCount();
    return a - b;
}

int main() {
    int num1, num2, choice;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cin >> choice;

    int result;
    switch (choice) {
        case 1:
            result = add(num1, num2);
            cout << "Result of addition: " << result << endl;
            break;
        case 2:
            result = subtract(num1, num2);
            cout << "Result of subtraction: " << result << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    cout << "Total operations performed :" << Calculator::count << endl;

    return 0;
}       


