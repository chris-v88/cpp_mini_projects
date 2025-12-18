#include <iostream>
using namespace std;

/*
Tính tổng N số tự nhiên
Nhập một số N từ bàn phím (N< 100). In ra màn hình tổng của các số từ 1 tới N.

- Tổng các số từ 1 tới N sẽ là 1 + 2 + 3 + …. + N
- Nhập vào số N từ bàn phím
- Khai báo biến sum có giá trị 0
- Sử dụng vòng for với một biến nguyên i chạy từ 1 tới N
- Gán sum = sum + i
-  Kết thúc vòng lặp for, in ra kết quả của biến sum
*/

void SumOfN(int n)
{
    int sum = 0;
    // write a loop to find sum of n natural number
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "Sum of " << n << " : " << sum << endl;
}

int main()
{
    int n;
    cout << "Enter a number between 1 and 100: ";
    cin >> n;
    while (n >= 100 || n <= 0)
    {
        cout << "Invalid input. Please enter again:";
        cin >> n;
    }
    SumOfN(n);
    return 0;
}