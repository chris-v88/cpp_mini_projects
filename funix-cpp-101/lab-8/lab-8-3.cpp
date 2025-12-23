#include <iostream>
using namespace std;

int main()
{
    int* p1 = new int;
    int* p2 = new int;

    cout << "Nhap gia tri cho p1: ";
    cin >> *p1;
    cout << "Nhap gia tri cho p2: ";
    cin >> *p2;

    if (*p1 > *p2) {
        cout << "So lon nhat la: " << *p1 << endl;
    } else {
        cout << "So lon nhat la: " << *p2 << endl;
    }

    delete p1;
    delete p2;

    return 0;
}