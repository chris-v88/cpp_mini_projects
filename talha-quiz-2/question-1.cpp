#include <iostream>
#include <limits>

using namespace std;

// n! = n * (n - 1) * (n - 2) * ... * 2 * 1
int calc_factorial(int num) {
    if (num == 1 || num <= 0) {
        return 1;
    };

    int result = 1;
    int i = num;

    do {
        result = result * i;
        i--;
    } while (i > 1);

    return result;
};

int main() {
    int user_input;
    cout << "Enter any value to calculate its Factorial: ";
    cin >> user_input;
    while(cin.fail() || user_input < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again: ";
        cin >> user_input;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int fact_result = calc_factorial(user_input);

    cout << "Factorial of " << user_input << " is: " << fact_result << endl;


    return 0;
}