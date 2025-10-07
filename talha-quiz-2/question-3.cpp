#include <iostream>

using namespace std;

// reads in a number from user, stores it in a variable named N and calculates the sum of powers using the following formula
// Sum = 1^1 + 2^2 + 3^3 +……+N^N

int n_power_n(int num) {
    int result = 1;
    int i = num;
    while(i > 0) {
        result = result * num;
        i--;
    }
    return result;
}

int sum_of_power(int num) {
    int result = 0;
    int i = num;
    while (i > 0) {
        result = result + n_power_n(i);
        i--;
    }
    return result;
};

int main() {
    cout << "Enter a number: ";
    
    int input;
    cin >> input;
    while(cin.fail() || input < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again: ";
        cin >> input;
    }
    int result = sum_of_power(input);
    cout << "Sum = " << result << endl;

    return 0;
};