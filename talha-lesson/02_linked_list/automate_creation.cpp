#include <iostream>
using namespace std;

struct Node
{
    int id;
    string name;
    int age;

    Node *next;
};

Node *createNode(int id, string name, int age)
{
    Node *newNode = NULL;

    newNode = new Node;

    newNode->id = id;
    newNode->name = name;
    newNode->age = age;
    newNode->next = NULL;

    return newNode;
}

// insert at start
void insertAtStart(Node *&head, int id, string name, int age)
{
    Node *newNode = createNode(id, name, age);

    // Node *temp = head;
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
void insertAtEnd(Node *&head, int id, string name, int age)
{
    Node *newNode = createNode(id, name, age);
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
void insertAtPosition(Node *&head, int id, string name, int age, int pos)
{
    Node *newNode = createNode(id, name, age);
    if (head == NULL)
    {
        head = newNode;
    }
    else if (pos == 1)
    {
        newNode->next = head;
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

        cout << "Insert (" << id << " " << name << " " << age << ") at position " << pos << endl;
    }
}

// delete from any specific Location
void deleteFromPosition(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    else if (pos == 1)
    {
        head = head->next;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;
        cout << "Delete (" << deleteNode->id << " " << deleteNode->name << " " << deleteNode->age << ") from position " << pos << endl;
    }
}

// delete node at a specific value
// void deleteFromValue(Node *head, )

// /// MAIN FUNCTION /// //
int main()
{
    Node *head = NULL;

    insertAtStart(head, 5, "Talha", 23);
    insertAtStart(head, 4, "Chris", 23);
    insertAtStart(head, 3, "Ali", 23);
    insertAtStart(head, 2, "Rahul", 23);
    insertAtStart(head, 1, "Abdullah", 23);

    insertAtEnd(head, 10, "Anusha", 24);
    insertAtEnd(head, 11, "Abid", 25);

    insertAtPosition(head, 99, "Zain", 99, 2);
    insertAtPosition(head, 100, "Ayaan", 100, 5);

    cout << "Linked List Data:" << endl
         << endl;

    Node *inital_temp = head;
    while (inital_temp != NULL)
    {
        if (inital_temp->name == "Talha")
        {
        }
        cout << inital_temp->id << endl;
        cout << inital_temp->name << endl;
        cout << inital_temp->age << endl;

        inital_temp = inital_temp->next;

        cout << endl
             << endl;
    }

    // popFromfirst(head);
    // popFromfirst(head);

    deleteFromPosition(head, 3);
    deleteFromPosition(head, 6);

    cout << "------------------------" << endl;
    cout << "Linked List Data After Deletions:" << endl << endl;

    Node *after_temp = head;
    while (after_temp != NULL)
    {
        cout << after_temp->id << endl;
        cout << after_temp->name << endl;
        cout << after_temp->age << endl;

        after_temp = after_temp->next;

        cout << endl
             << endl;
    }
}