#include <iostream>
using namespace std;

class Example
{
public:
    int x;

    // Default constructor
    Example()
    {
        x = 0; // Initialize x to 0
        cout << "Default constructor called, x = " << x << endl;
    }

    // Parameterized constructor
    Example(int val)
    {
        x = val; // Initialize x with the value provided
        cout << "Parameterized constructor called, x = " << x << endl;
    }

    // Copy constructor
    Example(const Example &obj)
    {
        x = obj.x; // Copy the value of x from the passed object
        cout << "Copy constructor called, x = " << x << endl;
    }
};

int main()
{
    Example obj1;        // Default constructor is called
    Example obj2(10);    // Parameterized constructor is called with value 10
    Example obj3 = obj2; // Copy constructor is called with obj2

    return 0;
}