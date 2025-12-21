#include <iostream>
using namespace std;

/**
 * Lab 6.2: Xác định số âm hay số dương:
 */

void sign(int n)
{
    //write conditional statement here to print "positive" or "negative"
    if (n < 0) {
        cout << "NEGATIVE" << endl;;
    }
    else if (n > 0) {
        cout << "POSITIVE" << endl;;
    }
    else {
        cout << "ZERO" << endl;
    }
}

int main()
{
    cout << "------- INTERGER SIGN CHECK -------" << endl;
    cout << "Enter a number, the program will determine if it is positive or negative: " << endl;
    int num;
    cin >> num;
    sign(num);
    return 0;
}
