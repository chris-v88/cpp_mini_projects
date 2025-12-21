#include<iostream>
using namespace std;

/*
Lab 7.4: Nhập một số N từ bàn phím. In ra các ước số của số N

Gợi ý:
    - Sử dụng vòng lặp với 1 giá trị i chạy từ 1 tới N/2
    - Lần lượt chia N cho i
    - Nếu N chia hết cho i thì in số đó ra màn hình
*/

void factors(int n)
{
    // print all factors of a number n
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() 
{
    cout << "------- FINDING FACTOR OF A NUMBER -------" << endl;
    cout << "Enter a number: ";
    int num;
    cin >> num;
    factors(num);
    
    return 0;
}
