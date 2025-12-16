#include <iostream>

using namespace std;

// Student node
struct Student
{
    int roll_number;
    string name;
    double marks;

    Student* next;
};

Student* head = NULL;
Student* tail = NULL;
int student_count = 0;

// ADD
void add_student(int roll_number, string name, double marks)
{
    Student* newStudent = new Student;

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

    cout << "ADD student (" << newStudent->roll_number << ", " << newStudent->name << ", " << newStudent->marks << ")";
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
        Student* temp = head;

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
    Student* prev = head;
    Student* current = head->next;

    while (current != NULL)
    {

        // if found roll number
        if (current->roll_number == roll_number)
        {
            prev->next = current->next;

            if (current == tail)
            {
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
};

// DISPLAY
void display_all()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    cout << endl << "========== STUDENT LIST ==========" << endl;
    cout << "Total # Students: " << student_count << endl;
    cout << "----------------------------------" << endl << endl;

    Student* temp = head;
    while (temp != NULL)
    {
        cout << "Roll #: " << temp->roll_number << endl;
        cout << "  Name: " << temp->name << endl;
        cout << "  Marks: " << temp->marks << endl
            << endl;
        temp = temp->next;
    }
};

// search student by roll number
Student* search_by_roll(int roll_number)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    Student* temp = head;
    while (temp != NULL)
    {
        if (temp->roll_number == roll_number)
        {
            cout << "Found Student with Roll #: " << temp->roll_number << endl;
            cout << "  Name: " << temp->name << endl;
            cout << "  Mark: " << temp->marks << endl
                << endl;

            return temp;
        }
        temp = temp->next;
    }

    cout << "Cannot find Student with Roll # " << roll_number << endl;
    return NULL;
}

// update student detail
void update_student_name(int roll_number, string new_name)
{
    Student* temp = search_by_roll(roll_number);
    // cout << temp->roll_number;
    if (temp == NULL)
    {
        return;
    }
    else
    {
        temp->name = new_name;
    }
}

// update student mark
void update_student_mark(int roll_number, double new_mark)
{
    Student* temp = search_by_roll(roll_number);
    if (temp == NULL) {
        return;
    }
    else {
        temp->marks = new_mark;
    }
}

// calculate Class Statistics of 
// Average marks
double average()
{
    if (head == NULL)
    {
        cout << "LIst is empty" << endl;
    }

    Student* temp = head;
    double total = 0;
    while (temp != NULL)
    {
        total += temp->marks;
        temp = temp->next;
    }

    double average = total / student_count;
    return average;
}

// Highest marks
Student* highest_marks()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    Student* temp = head;
    Student* highest = head;
    while (temp != NULL)
    {
        if (temp->marks > highest->marks)
        {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

// Lowest marks
Student* lowest_marks()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    Student* temp = head;
    Student* lowest = head;
    while (temp != NULL)
    {
        if (temp->marks < lowest->marks)
        {
            lowest = temp;
        }
        temp = temp->next;
    }
    return lowest;
}

// Count of student above/below 50%
int count_above_50()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    Student* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->marks > 50.0)
        {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

int count_below_50()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    Student* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->marks < 50.0)
        {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

// Program to get student details from user and perform operations
void perform_add_student_operation()
{
    string student_name = "";
    cout << endl << "------------- ADD STUDENT --------------";
    cout << "\nType 'exit' for 'Student Name' to stop adding students" << endl;
    int roll_number = 0;
    if (head == NULL)
    {
        cout << "Currently, there is no students in the system." << endl;
        roll_number = 0;
    }
    else
    {
        roll_number = tail->roll_number + 1;
    }

    while (student_name != "exit" || student_name != "EXIT")
    {
        double marks;
        cout << endl << "Enter Student Info" << endl;
        cout << "  Student Name: ";
        cin >> student_name;
        if (student_name == "exit" || student_name == "EXIT")
        {
            break;
        }

        cout << "  Marks: ";
        cin >> marks;
        add_student(roll_number, student_name, marks);
        cout << endl << endl;
        roll_number++;
        student_count++;
    }
}

int main()
{
    // add student
    // add_student(101, "Talha", 92.5);
    // add_student(102, "Chris", 78.5);
    // add_student(103, "Ali", 85.5);
    // add_student(104, "Rahul", 50.0);
    // add_student(105, "Sandeep", 49.5);
    // add_student(106, "Anusha", 82.0);
    // add_student(107, "Veda", 95.5);
    // add_student(108, "Vivek", 41.8);

    // delete
    // delete_by_roll(101); // head
    // delete_by_roll(103); // middle
    // delete_by_roll(106); // tail
    // display_all();

    // search by roll
    // search_by_roll(103);

    // update student name
    // update_student_name(102, "Vidya");
    // display_all();

    // update student mark`
    // update_student_mark(105, 90.0);
    // display_all();

    cout << "========== STUDENT MANAGEMENT SYSTEM ==========" << endl;
    cout << "What would you like to do?" << endl;
    string user_input = "";
    cout << "Options: ADD, DELETE, SEARCH, UPDATE_NAME, UPDATE_MARK" << endl;

    cout << "Enter your choice: ";
    cin >> user_input;

    if (user_input == "ADD" || user_input == "add")
    {
        perform_add_student_operation();
    }
    else if (user_input == "DELETE" || user_input == "delete")
    {
        int roll_number;
        cout << "Enter Roll Number to DELETE: ";
        cin >> roll_number;
        delete_by_roll(roll_number);
    }
    else if (user_input == "SEARCH" || user_input == "search")
    {
        int roll_number;
        cout << "Enter Roll Number to SEARCH: ";
        cin >> roll_number;
        search_by_roll(roll_number);
    }
    else if (user_input == "UPDATE_NAME" || user_input == "update_name")
    {
        int roll_number;
        string new_name;
        cout << "Enter Roll Number to UPDATE NAME: ";
        cin >> roll_number;
        cout << "Enter New Name: ";
        cin >> new_name;
        update_student_name(roll_number, new_name);
    }
    else if (user_input == "UPDATE_MARK" || user_input == "update_mark")
    {
        int roll_number;
        double new_mark;
        cout << "Enter Roll Number to UPDATE MARK: ";
        cin >> roll_number;
        cout << "Enter New Mark: ";
        cin >> new_mark;
        update_student_mark(roll_number, new_mark);
    }
    else if (user_input == "EXIT" || user_input == "exit")
    {
        cout << "Exiting Student Management System" << endl;
    }
    else
    {
        cout << "Invalid Option. Exiting Student Management System" << endl;
    }

    if (student_count == 0)
    {
        cout << "No students to display report." << endl;
        return 0;
    }
    else {
        display_all();

        cout << "============= REPORT =============" << endl;
        cout << "Total # Students: " << student_count << endl;

        cout << "Average: " << average() << endl << endl;

        Student* top_student = highest_marks();
        cout << "Student with highest marks: " << top_student->name << " -- marks: " << top_student->marks << endl;

        Student* lowest_student = lowest_marks();
        cout << "Student with lowest marks: " << lowest_student->name << " -- marks: " << lowest_student->marks << endl << endl;

        int number_above_50 = count_above_50();
        cout << "Number of students above 50%: " << number_above_50 << endl;

        int number_below_50 = count_below_50();
        cout << "Number of students below 50%: " << number_below_50 << endl;

        cout << "----------------------------------\n";

        return 0;
    }
}