#include<iostream>
using namespace std;

/*
Lab 7.6: Nhập vào 1 số N, in ra số đảo ngược của số đó

Gợi ý:
    - Yêu cầu người dùng nhập vào 1 số nguyên N là số chữ số của số cần đảo ngược
    - Yêu cầu người dùng nhập vào số A cần đảo ngược
    - Kiểm tra xem người dùng có nhập số có đúng N chữ số hay không? Ví dụ N = 3 thì số cần nhập phải nằm trong khoảng 100 < A < 999
    - Tạo 1 biến tạm có tên tmp
    - Lấy từng chữ số ở hàng đơn vị và in ra bằng cách chia số đó cho 10 và lấy phần dư

Ví dụ:
    + Số cần đảo ngược là 123
    + Lấy 123 chia 10 và lấy phần dư là 3, in ra số 3
    + Lưu lại kết quả của phép chia lấy phần nguyên của 123 cho 10 là 12
    + Thực hiện chia 12 cho 10 và lấy phần dư là 2, in ra số 2
    + Lưu lại kết quả của phép chia lấy phần nguyên của 12 cho 10 là 1
    + Thực hiện chia lấy dư của 1 cho 10 được số 1, in ra 1
    + Lấy 1 chia lấy phần nguyên cho 10 được 0. Kết thúc
*/

void reverse(int n)
{
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    cout << res << endl;
}

int main()
{
    cout << "------- NUMBER REVERSER -------" << endl;
    cout << "Enter a number: ";
    int num;
    cin >> num;
    reverse(num);
    
    return 0;
}