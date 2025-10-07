#include <iostream>
#include <limits>

using namespace std;

// takes an integer input from user in the variable named ‘num’
// calculates the sum of all integers from 1 to ‘num’ and displays this sum on screen

int sum_to_n(int num){
    int result = 0;
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        for (int i = num; i >= 1; i--) {
            result += i;
        }
        return result;
    }
}

int main() {
    cout << "Enter any value: ";
    
    int num;
    cin >> num;
    while(cin.fail() || num < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again: ";
        cin >> num;
    }

    int result = sum_to_n(num);
    cout << "Sum of integers from 1 to " << num << " is: " << result << endl;
}