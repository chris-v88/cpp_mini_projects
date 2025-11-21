#include <iostream>
using namespace std;

struct Node
{
    int id;
    string name;
    int age;

    Node *next;
};

Node *createNode(int val, string n, int a)
{
    Node *newNode = NULL;

    newNode = new Node;

    newNode->id = val;
    newNode->name = n;
    newNode->age = a;
    newNode->next = NULL;

    return newNode;
}

// insert at start
void insertAtStart(Node *&head, int val, string n, int a)
{
    Node *newNode = createNode(val, n, a);

    Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// insert at end
void insertAtEnd(Node *&head, int val, string n, int a)
{
    Node *newNode = createNode(val, n, a);
    if (head == NULL)
    {
        head = newNode;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// pop from start
void popFromfirst(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    //    cout<<head->id<<endl;
    //    cout<<head->name<<endl;
    //    cout<<head->age<<endl;
    head = head->next;
}

// /// HOMEWORK /// //
// insert at any specific Location
void insertAtPosition(Node *&head, int val, string n, int a, int pos)
{
    Node *newNode = createNode(val, n, a);
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *nextNode = temp->next;
        temp->next = newNode;
        newNode->next = nextNode;
    }
}

// delete from any specific Location
void deleteFromPosition(Node *&head, int pos)
{
}

// delete node at a specific value

// /// MAIN FUNCTION /// //
int main()
{
    Node *head = NULL;

    insertAtStart(head, 5, "Talha", 23);
    insertAtStart(head, 4, "Chris", 23);
    insertAtStart(head, 3, "Ali", 23);
    insertAtStart(head, 2, "Rahul", 23);
    insertAtStart(head, 1, "Abdullah", 23);

    insertAtEnd(head, 10, "Chris", 24);
    insertAtEnd(head, 11, "Ali", 25);

    popFromfirst(head);
    popFromfirst(head);

    Node *temp = head;
    while (temp != NULL)
    {

        if (temp->name == "Talha")
        {
        }
        cout << temp->id << endl;
        cout << temp->name << endl;
        cout << temp->age << endl;

        temp = temp->next;

        cout << endl
             << endl
             << endl
             << endl;
    }
}