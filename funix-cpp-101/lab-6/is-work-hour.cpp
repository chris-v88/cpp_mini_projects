#include<iostream>
using namespace std;

/*
Lab 6.3: Cho người dùng nhập vào 1 số. Xác định xem đó có phải giờ làm việc hay không?
Biết rằng giờ làm việc là từ 

9h sáng tới 16h chiều. (Từ 12h trưa tới 13h là giờ nghỉ trưa):
*/

void is_working(int hour)
{
    //write condition here to print "working" or "leisure"
    if (hour < 9 || (hour >= 12 && hour <= 13) || hour > 16)
        cout << "leisure";

    cout << "working";
} 

int main()
{
    cout << "------- CHECK WORK HOUR -------" << endl;
    cout << "Enter the time (in hour) : ";
    int hour = 0;
    cin >> hour;
    cout << endl;
    is_working(hour);
}