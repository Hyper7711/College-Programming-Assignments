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

    void create();
    void display();

    void insertatbeg();
    void insertatend();
    void insertafter();

    void deleteatfirst();
    void deleteatend();
    void deleteatend();

    void sortlist(); // later sorting

    int computeTotal();
    void concatlist(list & q1);

    void displayrev(node * t);
    bool reverseDisplay();
};
