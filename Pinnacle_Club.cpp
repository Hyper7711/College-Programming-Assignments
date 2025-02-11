#include <iostream>
#include <string>
using namespace std;

class list;
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
    friend class list; // To access private members of node
};

class list
{
    node *start;

public:
    list()
    {
        start = nullptr;
    }

    // CREATING MEMBER FUNCTIONS
    void create(); // To create and display
    void display();

    void insertatbeg(); // To insert values
    void insertatend();
    void insertafter();

    void deleteatfirst(); // To delete values
    void deleteatend();
    void deletebyvalue();

    void sortlist(); // Later sorting

    int computeTotal(); // To get total
    void concatlist(list &q1);

    void displayrev(node *t); // To display from end
    bool reverseDisplay();
};

void list::create()
{
    int no;
    string nam;
    if (start == nullptr)
    {
        cout << "Enter the PRN Number:";
        cin >> no;
        cout << "Enter Name:";
        cin.ignore();
        getline(cin, nam);
        start = new node(no, nam);
        cout << "\n++++++++++++ LIST CREATED ++++++++++++++";
    }
    else
    {
        cout << "\nLIST IS ALREADY CREATED";
    }
}

void list::display()
{
    node *t = start;
    if (start == nullptr)
    {
        cout << "\nLIST IS EMPTY";
        return;
    }
    cout << "\n++++++++++ LIST ++++++++++\n";
    while (t != nullptr)
    {
        cout << t->prn << " " << t->name << "\n";
        t = t->next;
    }
}

void list::insertatbeg()
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

void list::insertatend()
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
    node *t = start;
    while (t->next != nullptr)
    {
        t = t->next;
    }
    t->next = temp;
    cout << "Inserted " << temp->name << " at the end.";
}

void list::insertafter()
{
    int key, no;
    string nam;
    if (start == nullptr)
    {
        cout << "\nThe list is empty.";
        return;
    }
    cout << "\nInsert the PRN Number after which to insert: ";
    cin >> key;
    cout << "Enter PRN Number: ";
    cin >> no;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, nam);
    node *temp = new node(no, nam);
    node *t = start;
    while (t != nullptr && t->prn != key)
    {
        t = t->next;
    }
    if (t == nullptr)
    {
        cout << "\nPRN Number " << key << " not found.";
        delete temp;
    }
    else
    {
        temp->next = t->next;
        t->next = temp;
        cout << "Inserted " << temp->name << " after PRN " << key << ".";
    }
}

void list::deleteatfirst()
{
    if (start == nullptr)
    {
        cout << "\nList is empty, nothing to delete.";
        return;
    }
    node *temp = start;
    start = start->next;
    cout << "Deleted " << temp->name << " from the beginning.";
    delete temp;
}

void list::deleteatend()
{
    if (start == nullptr)
    {
        cout << "\nList is empty, nothing to delete.";
        return;
    }
    if (start->next == nullptr)
    {
        delete start;
        start = nullptr;
        cout << "\nDeleted last node, list is now empty.";
        return;
    }
    node *t = start;
    while (t->next->next != nullptr)
    {
        t = t->next;
    }
    delete t->next;
    t->next = nullptr;
    cout << "\nDeleted last node.";
}

void list::deletebyvalue()
{
    if (start == nullptr)
    {
        cout << "\nList is empty, nothing to delete.";
        return;
    }
    int key;
    cout << "\nEnter PRN Number to delete: ";
    cin >> key;

    if (start->prn == key)
    {
        deleteatfirst();
        return;
    }

    node *t = start, *prev = nullptr;
    while (t != nullptr && t->prn != key)
    {
        prev = t;
        t = t->next;
    }

    if (t == nullptr)
    {
        cout << "\nPRN Number " << key << " not found.";
    }
    else
    {
        prev->next = t->next;
        delete t;
        cout << "\nDeleted node with PRN " << key << ".";
    }
}

void list::sortlist()
{
    if (start == nullptr || start->next == nullptr)
    {
        cout << "\nlist is too sort to sort.";
        return;
    }
    node *i, *j;
    int tempPrn;
    string tempName;

    for (i = start; i->next != nullptr; i = i->next)
    {
        for (j = i->next; j != nullptr; i != i->next)
        {
            if (i->prn > j->prn)
            {
                tempPrn = i->prn;
                tempName = i->name;
                i->prn = j->prn;
                i->name = j->name;
                j->prn = tempPrn;
                j->name = tempName;
            }
        }
    }
    cout << "\nList sorted successfully.";
}

int list::computeTotal()
{
    int count = 0;
    node *t = start;
    while (t != nullptr)
    {
        count++;
        t = t->next;
    }
    return count;
}

void list::concatlist(list &q1)
{
    if (start == nullptr)
    {
        start = q1.start;
        return;
    }
    node *t = start;
    while (t->next != nullptr)
    {
        t = t->next;
    }
    t->next = q1.start;
    cout << "\nLists concatenated successfully.";
}

void list::displayrev(node *t)
{
    if (t == nullptr)
        return;
    displayrev(t->next);
    cout << t->prn << " " << t->name << "\n";
}

bool list::reverseDisplay()
{
    if (start == nullptr)
    {
        cout << "\nList is empty.";
        return false;
    }
    cout << "\nReversed List:\n";
    displayrev(start);
    return true;
}

int main()
{
    list l1, l2;
    int choice;
    do
    {
        cout << "\n1. Create Loist\n.Display List\n3.Insert at Beginning\n4.Inseert at End\n5. Insert After a PRN\n6.Delete Fisrt\n7. Delete Last\n8. Delete by value\n9.Sort List\n10. Compute Total\n11. Conncatnate List\n12. Reverse Display\n!3. Exit";
        cout << "\n1."
    }
}

cout << "\nEnter your choice: ";
cin >> choice;

switch (choice)
{
case 1:
    l1.create();
    break;
case 2:
    l1.display();
    break;
case 3:
    l1.insertatbeg();
    break;
case 4:
    l1.insertatend();
    break;
case 5:
    l1.insertafter();
    break;
case 6:
    l1.deleteatfirst();
    break;
case 7:
    l1.deleteatend();
    break;
case 8:
    l1.deletebyvalue();
    break;
case 9:
    l1.sortlist();
    break;
case 10:
    cout << "\nTotal Nodes: " << l1.computeTotal();
    break;
case 11:
    cout << "\nCreating another list for concatenation";
    l2.create();
    l2.insertatend();
    l1.concatlist(l2);
    break;
case 12:
    l1.reverseDisplay();
    break;
case 13:
    cout << "\nExiting...";
    break;
default:
    cout << "\nInvalid choice! Try again.";
}
}
while (choice != 13)
    ;
return 0;
}