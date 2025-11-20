#include <iostream>
using namespace std;

struct Node {
    Node* prev;

    int data;

    Node* next;
};

// head : store the address of the first node
// tail : store the address of the last node
// next : store the address of the next node
// prev : store the address of the previous node

// point to NULL first so that it doesn't point to any garbage value
Node* head = NULL;
Node* tail = NULL;

// insert at start
void insert_at_head(int val) {
    Node* temp = new Node; // hold address of the new node
    // create the node on the heap (permanent memory until you delete it)
    // Now you have a pointer to its address, so you can connect it to other nodes
    // and it stays alive after the function ends.

    temp->data = val; // assign data to new node
    temp->prev = NULL; // previous of new node will be NULL
    temp->next = NULL; // next of new node will be current head

    if (head == NULL && tail == NULL) {
        head = temp; // head and tail both will point to new node
        tail = temp;
    } else {
        temp->next = head; // link new node's next to current head
        head->prev = temp; // link current head's prev to new node
        head = temp; // update head to new node
    }
}

// insert at end
void insert_at_end(int val) {
    Node* temp = new Node; // new Node --> is to create a node
    // Node* temp is to store the address of that node

    temp->data = val; // assign data to new node
    temp->next = NULL; // next of new node will be NULL
    temp->prev = NULL; // previous of new node will be current tail
    if (head == NULL && tail == NULL) {
        head = temp; // head and tail both will point to new node
        tail = temp;
    } else {
        tail->next = temp; // link current tail's next to new node
        temp->prev = tail; // link new node's prev to current tail
        tail = temp; // update tail to new node
    }
}

// insert at position
void insert_at_position(int v, int pos) {
    Node* temp = new Node;
    temp->data = v;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL && tail == NULL) {
        head = temp;
        tail = temp;
    } else {
        Node* p = head;
        Node* c = head;
        // traverse to the position -- using any loop
        for (int i = 1; i < pos; i++) {
            p = c;
            c = c->next;
        }
        p->next = temp;
        temp->prev = p;
    }

}

void display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}



int main() {
    insert_at_head(10);
    insert_at_head(20);
    insert_at_end(30);
    insert_at_end(40);


    cout << "List after adding nodes: ";
    display();


     insert_at_position(25, 2);
    cout << "List after inserting 25 at position 2: ";
    display();


      return 0;
}

// HOMEWORK
// delete at any position
