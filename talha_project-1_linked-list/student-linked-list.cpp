#include <iostream>

using namespace std;

// Student node
struct Student {
    int roll_number;
    string name;
    float marks;

    Student *next;
};

Student *head = NULL;
Student *tail = NULL;
int student_count = 0;

// ADD
void add_student(int roll_number, string name, float marks) {
    
}