## **Course:** CPP101x - Basic C++ Programming

## **Assignment:** 1

## **Assignment Name:** Setting Time for Cars

## **Author:** Phạm Bá Thành

## **Estimated Time:** 3 hours

### **Overview**

In the automotive software system, there are various settings. Time setting is one of the basic settings that must be available on car systems and household appliances. Usually, there are two setting modes: manual setting by hand or automatic time update via GPS. In this assignment, you need to build a program that simulates the time setting function on a car system manually. The program includes the following functions:

- Setting time by hour and minute for the system
- Changing time by time zone
- Changing time format to 12-hour or 24-hour format
- Displaying time after setting

### **How to Complete the Assignment**

1. Create a project named **`CPP101x_Asm1_<YourAccount>`**. You can use devC++, Visual Studio, or any other IDE to code. However, it is recommended to use Visual Studio to complete the assignment.
2. Complete the assignment according to the steps in the guide.
3. Required knowledge to complete the project:
- Input/output data: cin and cout
- Declaring and using basic data types
- Branching statements: switch case, if-else
- Commenting on the logic in your program

## **Resources**

### **How to Calculate Leap Year:**

To check if a year is a leap year, we need to follow one of the two rules:

1. A year is a leap year if it is divisible by 400.
2. A year is a leap year if it is divisible by 4 but not by 100.

## **Guidance on Completing the Project**

### **1. Detailed Functions and Requirements**

### **Question 1: Input Data**

a) The user inputs the day, month, and year.

b) Check if the day, month, and year are valid.

You can check according to the following contents:

- A year has 12 months.
- A month has a maximum of 31 days. Months with 31 days are 1, 3, 5, 7, 8, 10, 12. February has 28 days (if it's a leap year, it has 29 days). The remaining months have 30 days.
- The input year cannot be greater than the current year.
- Day, month, and year must be positive numbers other than 0.
- *If the input time is valid, continue with the program.*
- *If the input time is invalid, display a message and end the program.*

c) Input the day and hour of the system. (*Default input in 24-hour format*).

### **Question 2: Output Data**

Output the information of the day, month, and system time in the following format:

**HH:MM, Day, Month, Year**

*Example: 23g:25p, Ngay 05, Thang Chin, 2022*

### **Question 3: Setting Time in 12-hour/24-hour Format**

a) Ask the user to choose a time format in 12-hour or 24-hour. The user inputs 12 for 12-hour format, 24 for 24-hour format.

b) Output the time information in the correct format.

- *Example 1*: *If 12-hour format*

Display: 11g:25p PM, Ngay 05, Thang Chin, 2022

- *Example 2*: *If 24-hour format:*

Display: 23g:25p, Ngay 05, Thang Chin, 2022

### **2. Time Zone Setting**

World time is divided into time zones from UTC-12:00 to UTC+14:00.

In this assignment, for simplicity, you only need the following time zones:

- UTC-12:00
- UTC-11:00
- UTC-10:00
- UTC-09:00
- UTC-08:00
- UTC-07:00
- UTC-06:00
- UTC-05:00
- UTC-04:00
- UTC-03:00
- UTC-02:00
- UTC-01:00
- UTC-00:00
- UTC+01:00
- UTC+02:00
- UTC+03:00
- UTC+04:00
- UTC+05:00
- UTC+06:00
- UTC+07:00
- UTC+08:00
- UTC+09:00
- UTC+10:00
- UTC+11:00
- UTC+12:00

By default, the input time is in UTC 00:00 time zone (Time zone 0)

a) Ask the user to input the current time zone of the car (input numbers from -12 to 12)

b) Convert the time from time zone 0 to the current time zone

c) Output the time information after converting the time zone

### **3. Code Organization**

Students implement the code step by step and write comments for each part:

```cpp
#include <iostream>
using namespace std;

int main(){
//question 1:
Code

//question 2:
Code

//question 3
Code

         return 0;
}
```

***Note:** You should carefully review the **"Evaluation Criteria"** to ensure that you have completed all the requirements before submitting your assignment.*

## **Guidance on Submitting the Assignment**

**Bookmark this page**

**Guidance on Submitting the Assignment**

- The folder containing the project, assignment, and necessary resource files must be zipped into a single .zip file.
- Name the folder according to the template **CPP101x_Asm1_<YourAccount>** (e.g., [CPP101x_Asm1_thangnvFX00000@funix.edu.vn](mailto:BDP301x_asm1_hatn@fpt.edu.vn)).
- View the guidance and submit the assignment at **Assessment Submission**.

**Evaluation**

Your project will be evaluated by FUNiX mentors based on the rubrics of this project. You need to ensure that you carefully review all the criteria before submitting your assignment. All "Meet Specifications" criteria must be completed. If your submission does not meet the mandatory criteria, you will have to redo the criteria until they are met.

- **Note on grading**

***Mandatory Requirements:***

- All students must complete and submit all listed criteria, and each mandatory criterion must be evaluated as PASS by mentors. If any mandatory criterion FAILS, you must redo and resubmit that criterion until it PASSES.
- When resubmitting, do not submit only the redo criterion; you need to submit the entire project with all completed criteria (***Note: do not regrade the points of advanced criteria***). Resubmit on the LMS system.

### ***Advanced Requirements (if any):***

- You need to add other advanced (supplementary) features to the project.

## **Evaluation Criteria**

### **Basic Functional Requirements**

| **#** | **Criterion** | **Map to LO** | **Specification** | **Weight** | **Points** | **Mandatory** | **Grading type** |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | Input information | CPP101x_o6CPP101x_o8 | Create suitable data type variables to input and store values. | 1 | 01.05 | Yes | Scale (0-5) |
| 2 | Check input time value validity | CPP101x_o8CPP101x_o9CPP101x_o10 | - Check the year to be less than the current year and positive.- Check months in a year- Check the number of days in each month- Check for leap years | 2 | 2.11 | Yes | Scale (0-5) |
| 3 | Output information | CPP101x_o6 | - Output input information (day, month, year, hour, minute) in the correct format | 1 | 01.05 | Yes | Scale (0-5) |
| 4 | Time format conversion | CPP101x_o6CPP101x_o9 | - Can convert time in 12-hour and 24-hour formats | 1 | 01.05 | Yes | Scale (0-5) |

### **Non-Functional Requirements**

| **#** | **Criterion** | **Map to LO** | **Specification** | **Weight** | **Points** | **Mandatory** | **Grading type** |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | README.txt | CPP101x_o1CPP101x_o5 | - Clearly describe which IDE version the application supports- Describe program functions- Clearly state the name and email of the implementer | 0.5 | 0.53 | Yes | Scale (0-5) |
| 2 | Comments | CPP101x_o32 | - Require comments (comment lines) for important variables and code segments. | 0.5 | 0.53 | Yes | Scale (0-5) |
| 3 | Code quality | CPP101x_o32 | Code style must comply with [Google's standard](https://source.android.com/source/code-style.html) on variable naming, function naming, if-else statements, loops, etc.… | 1 | 01.05 | Yes | Scale (0-5) |
| 4 | Code structure | CPP101x_o31 | Require implementation of the program according to the correct structure of a C++ program with function declarations, variable declarations, and clear separation of implementation parts | 1 | 01.05 | Yes |