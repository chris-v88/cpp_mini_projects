#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "Nhap a: ";
    cin >> a;

    cout << "Nhap b: ";
    cin >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    cout << "Gia tri cua ptrA: " << *ptrA << endl;
    cout << "Dia chi ma ptrA tro toi: " << ptrA << endl;

    cout << "Gia tri cua ptrB: " << *ptrB << endl;
    cout << "Dia chi ma ptrB tro toi: " << ptrB << endl;

    return 0;
}