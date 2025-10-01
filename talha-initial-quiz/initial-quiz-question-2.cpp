#include <iostream>
#include <string>
using namespace std;

int main() {
    char user_input;

    cout << "Enter 1 a character, anything form number to letter (upper/lower case) :" << endl;
    cin >> user_input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        cin >> user_input;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "You entered : " << user_input << endl;

    if (user_input >= '0' && user_input <= '9') {
        if (user_input % 2 == 0) {
            cout << "This is an EVEN NUMBER" << endl;
        } else {
            cout << "This is an ODD NUMBER" << endl;
        }
    } else if (user_input >= 'a' && user_input <= 'z') {
        cout << "This is an LOWER-CASE LETTER" << endl;
    } else if (user_input >= 'A' && user_input <= 'Z') {
        cout << "This is an UPPER-CASE LETTER" << endl;
    } else {
        cout << "This is an SPECIAL CHARACTER" << endl;
    }

    return 0;
}