#include <iostream>
#include <string>
using namespace std;

class list;

class node
{
    int prn;
    string name;
    node *next;

public:
    node(int x, string nm)
    {
        prn = x;
        next = nullptr;
        name = nm;
    }
    friend class list;
};

class list
{
    node *start;

public:
    list()
    {
        start = nullptr;
    }

    void create();
    void display();
    void insertAtBeginning();
    void insertAtEnd();
    void insertAfter();
    void deleteAtFirst();
    void deleteByValue();
    void deleteAtEnd();
    int computeTotal();
    void sortList();
    void concatList(list &q1);
    void displayRev(node *t);
    bool reverseDisplay();
};

// Recursive function to display list in reverse order
void list::displayRev(node *t)
{
    if (t == nullptr)
        return;
    displayRev(t->next);
    cout << "\nPRN NO:" << t->prn << " Name: " << t->name;
}

void list::create()
{
    int no;
    string nam;
    if (start == nullptr)
    {
        cout << "Enter PRN number: ";
        cin >> no;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, nam);
        start = new node(no, nam);
        cout << "\n=============== List Created ===============";
    }
    else
    {
        cout << "\nList is already created.";
    }
}

void list::display()
{
    node *t = start;
    if (start == nullptr)
    {
        cout << "\nList is Empty";
        return;
    }
    cout << "\n=============== List: ===============\n";
    while (t != nullptr)
    {
        cout << t->prn << " " << t->name << " \n";
        t = t->next;
    }
}

void list::insertAtBeginning()
{
    int no;
    string nam;
    if (start == nullptr)
    {
        create();
        return;
    }
    cout << "\nEnter PRN Number: ";
    cin >> no;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, nam);
    node *temp = new node(no, nam);
    temp->next = start;
    start = temp;
    cout << "Inserted " << temp->name << " at the beginning.";
}

void list::insertAtEnd()
{
    int no;
    string nam;
    if (start == nullptr)
    {
        create();
        return;
    }
    cout << "\nEnter PRN Number: ";
    cin >> no;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, nam);
    node *t = start;
    while (t->next != nullptr)
        t = t->next;
    t->next = new node(no, nam);
}

void list::insertAfter()
{
    int prev_no;
    cout << "\nEnter PRN No. after which you want to insert: ";
    cin >> prev_no;
    node *t = start;
    string nam;
    int no;
    while (t != nullptr)
    {
        if (t->prn == prev_no)
        {
            cout << "\nEnter PRN Number: ";
            cin >> no;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, nam);
            node *p = new node(no, nam);
            p->next = t->next;
            t->next = p;
            return;
        }
        t = t->next;
    }
    cout << "\n"
         << prev_no << " is not in the list.";
}

void list::deleteAtFirst()
{
    if (start == nullptr)
    {
        cout << "\nClub is Empty.";
        return;
    }
    node *t = start;
    start = start->next;
    delete t;
    cout << "\nPresident deleted.";
}

void list::deleteByValue()
{
    int no;
    cout << "\nEnter PRN No. of member to be deleted: ";
    cin >> no;
    node *t = start, *prev = nullptr;

    while (t != nullptr && t->prn != no)
    {
        prev = t;
        t = t->next;
    }

    if (t == nullptr)
    {
        cout << "\nMember not found.";
        return;
    }

    if (prev == nullptr)
    {
        // First node
        start = t->next;
    }
    else
    {
        prev->next = t->next;
    }

    delete t;
    cout << "\nMember with PRN No: " << no << " is deleted.";
}

void list::deleteAtEnd()
{
    if (start == nullptr)
    {
        cout << "\nClub is Empty.";
        return;
    }
    if (start->next == nullptr)
    {
        delete start;
        start = nullptr;
        cout << "\nSecretary Deleted.";
        return;
    }
    node *t = start, *prev = nullptr;
    while (t->next != nullptr)
    {
        prev = t;
        t = t->next;
    }
    prev->next = nullptr;
    delete t;
    cout << "\nSecretary Deleted.";
}

int list::computeTotal()
{
    node *t = start;
    int count = 0;
    while (t != nullptr)
    {
        count++;
        t = t->next;
    }
    return count;
}

void list::concatList(list &q1)
{
    if (start == nullptr)
    {
        start = q1.start;
    }
    else
    {
        node *t = start;
        while (t->next != nullptr)
        {
            t = t->next;
        }
        t->next = q1.start;
    }
    q1.start = nullptr;
}

bool list::reverseDisplay()
{
    if (start == nullptr)
        return false;
    displayRev(start);
    return true;
}

// Main function remains the same
