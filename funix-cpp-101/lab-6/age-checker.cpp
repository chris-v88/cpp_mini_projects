#include<iostream>
using namespace std;

/*
Lab 6.4: Viết chương trình nhập vào tuổi một người. In ra màn hình:
    Nếu tuổi nhỏ hơn 12 thì in ra là thiếu nhi
    Nếu tuổi lớn hơn hoặc bằng 12 và nhỏ hơn hoặc bằng 50 thì in ra là người trẻ
    Nếu lớn hơn 50 thì in ra là người già
*/

void check_age(int age)
{
    // write conditional statement here
    // output must be all in lower case
    if (age < 12)
    {
        cout << "thiếu nhi" << endl;
    } else if (age >= 12 && age <= 50)
    {
        cout << "người trẻ" << endl;
    } else
    {
        cout << "người già" << endl;
    }
}

int main()
{
    cout << "------- CHECK AGE -------" << endl;
    cout << "Enter an age: ";
    int age;
    cin >> age;
    cout << endl;
    check_age(age);
    return 0;
}