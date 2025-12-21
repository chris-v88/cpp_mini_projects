#include<iostream>
using namespace std;

/*
Lab 6.6: Viết chương trình nhập vào một số nguyên là tháng trong năm.
In ra tên tháng đó bằng chữ:
Ví dụ:
    Nhập: 8
In ra: Tháng tám
*/
void digit_to_world(int d)
{
    // display digit to word using else if ladder
    if (d == 1)
    {
        cout << "January" << endl;
    }
    else if (d == 2)
    {
        cout << "February" << endl;
    }
    else if (d == 3)
    {
        cout << "March" << endl;
    }
    else if (d == 4)
    {
        cout << "April" << endl;
    }
    else if (d == 5)
    {
        cout << "May" << endl;
    }
    else if (d == 6)
    {
        cout << "June" << endl;
    }
    else if (d == 7)
    {
        cout << "July" << endl;
    }
    else if (d == 8)
    {
        cout << "August" << endl;
    }
    else if (d == 9)
    {
        cout << "September" << endl;
    }
    else if (d == 10)
    {
        cout << "Octocber" << endl;
    }
    else if (d == 11)
    {
        cout << "November" << endl;
    }
    else if (d == 12)
    {
        cout << "December" << endl;
    }
    else
    {
        cout << "Not valid number of month" << endl;
    }
}

int main()
{
    cout << "------- PRINT MONTH -------" << endl;
    cout << "Enter the number of month: ";
    int month;
    cin >> month;
    digit_to_world(month);
    return 0;
}