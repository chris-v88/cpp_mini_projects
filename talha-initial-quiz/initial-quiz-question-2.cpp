#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    char user_input;

    cout << "Enter a character, anything from number to letter (upper/lower case) :" << endl;
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
        if ((user_input - '0') % 2 == 0) {
            cout << "This is a EVEN NUMBER" << endl;
        } else {
            cout << "This is a ODD NUMBER" << endl;
        }
    } else if (user_input >= 'a' && user_input <= 'z') {
        cout << "This is a LOWER-CASE LETTER" << endl;
    } else if (user_input >= 'A' && user_input <= 'Z') {
        cout << "This is a UPPER-CASE LETTER" << endl;
    } else {
        cout << "This is a SPECIAL CHARACTER" << endl;
    }

    return 0;
}
