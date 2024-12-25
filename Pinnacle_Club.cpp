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
    void sortList(); // Placeholder if you want to implement sorting later
    void concatList(list &q1);
    void displayRev(node *t);
    bool reverseDisplay();
};

void list::displayRev(node *t)
{
    if (t == nullptr)
        return;
    displayRev(t->next);
    cout << "\nPRN NO: " << t->prn << " Name: " << t->name;
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

// Main function
int main()
{
    list club1, club2;
    int choice;

    do
    {
        cout << "\n=============== Pinnacle Club Menu ===============";
        cout << "\n1. Create List\n2. Display List\n3. Insert at Beginning\n4. Insert at End\n5. Insert After";
        cout << "\n6. Delete at First\n7. Delete by Value\n8. Delete at End\n9. Compute Total Members";
        cout << "\n10. Reverse Display\n11. Concatenate Lists\n12. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            club1.create();
            break;
        case 2:
            club1.display();
            break;
        case 3:
            club1.insertAtBeginning();
            break;
        case 4:
            club1.insertAtEnd();
            break;
        case 5:
            club1.insertAfter();
            break;
        case 6:
            club1.deleteAtFirst();
            break;
        case 7:
            club1.deleteByValue();
            break;
        case 8:
            club1.deleteAtEnd();
            break;
        case 9:
            cout << "\nTotal Members: " << club1.computeTotal();
            break;
        case 10:
            if (!club1.reverseDisplay())
            {
                cout << "\nList is Empty.";
            }
            break;
        case 11:
            cout << "\nCreating another list to concatenate.";
            club2.create();
            club1.concatList(club2);
            cout << "\nLists concatenated successfully.";
            break;
        case 12:
            cout << "\nExiting program.";
            break;
        default:
            cout << "\nInvalid choice. Try again.";
        }
    } while (choice != 12);

    return 0;
}
