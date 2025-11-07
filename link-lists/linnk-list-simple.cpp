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
};

void insertAtStart(Node* &head, int val, string n, int a)
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
};

void insertAtEnd(Node* &head, int val, string n, int a)
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
};

void popFromFirst(Node* &head) 
{
    if (head == NULL) 
    {
        cout<<"List is empty";
    }
}
