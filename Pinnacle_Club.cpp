#include <iostream>
#include <string>
using namespace std;

class List;

class node
{
    int prn; // attributes
    string name;
    node *next;

public:
    node(int p, string nm)
    {
        prn = p; // constructors
        next = nullptr;
        name = nm;
    }
    friend class list; // TO access private mem of node
};

class list;
{
    node *start;

public:
    list() :
    {
        start = nullptr;
    }

    // CREATING MEMBER FUNCTIONS

    void create(); // TO create and display
    void display();

    void insertatbeg(); // To insert values
    void insertatend();
    void insertafter();

    void deleteatfirst(); // To delete values
    void deleteatend();
    void deleteatend();

    void sortlist(); // later sorting

    int computeTotal(); // To get total
    void concatlist(list & q1);

    void displayrev(node * t); // To display from end-st
    bool reverseDisplay();
};
