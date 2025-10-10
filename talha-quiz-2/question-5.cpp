#include <iostream>
#include <string>
#include <limits>

using namespace std;

int sum(int x, int y)
{
    return x + y;
}

int add_up_to(int n)
{
    int i = 1;
    int result = 0;
    while (i <= n)
    {
        result += i;
        i++;
    }
    return result;
}

int main()
{
    cout << "Enter any value of N: ";
    int num;
    cin >> num;
    while (cin.fail() || num < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again: ";
        cin >> num;
    }

    int result = 0;
    cout << "F(" << num << ") = ";
    for (int i = 1; i <= num; i++)
    {
        result += add_up_to(i);
        if (i < num)
            cout << result << " + ";
    }

    cout << " = " << result << endl;

    return 0;
}