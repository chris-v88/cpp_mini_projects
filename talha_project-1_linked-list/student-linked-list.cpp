#include <iostream>

using namespace std;

// Student node
struct Student
{
    int roll_number;
    string name;
    float marks;

    Student *next;
};

Student *head = NULL;
Student *tail = NULL;
int student_count = 0;

// ADD
void add_student(int roll_number, string name, float marks)
{
    Student *newStudent = new Student;

    newStudent->roll_number = roll_number;
    newStudent->name = name;
    newStudent->marks = marks;
    newStudent->next = NULL;

    if (head == NULL && tail == NULL)
    {
        head = newStudent;
        tail = newStudent;
    }
    else
    {
        tail->next = newStudent;
        tail = newStudent;
    }

    student_count++;
};

// DELETE by roll number
void delete_by_roll(int roll_number)
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete" << endl;
        return;
    }

    // if student is first in list
    if (head->roll_number == roll_number)
    {
        Student *temp = head;

        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }

        student_count--;
        cout << "DELETE student (" << temp->roll_number << ", " << temp->name << temp->marks << ")" << endl;
        return;
    }

    // if student is in middle 
    Student *prev = head;
    Student *current = head->next;

    while (current != NULL){
        
        // if found roll number
        if (current->roll_number == roll_number) {
            prev->next = current->next;

            if (current == tail) {
                tail = prev;
            }
            
            student_count--;
            cout << "DELETE student (" << current->roll_number << ", " << current->name << ", " << current->marks << ")" << endl;
            return;
        }

        // if not
        prev = current;
        current = current->next;
    }

    
}

