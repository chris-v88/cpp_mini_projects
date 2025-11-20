#include <iostream>
using namespace std;

struct Node{
    int id;
    string name;
    int age;

    Node* next;
};


int main(){
    Node *p = NULL;
    Node *q = NULL;

    p = new Node;
    q = new Node;

    p -> id = 1;
    p -> name = "Chris";
    p -> age = 20;

    p -> next = q;

    q -> id = 2;
    q -> name = "Talha";
    q -> age = 23;
    q -> next = NULL;

    Node* temp = p;
    while (temp != NULL)
    {
        cout<<temp->id<<endl;
        cout<<temp->name<<endl;
        cout<<temp->age<<endl;

        temp = temp->next;

        cout<<endl<<endl<<endl<<endl;
    }
    
    return 0;
}