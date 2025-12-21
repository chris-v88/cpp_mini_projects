
#include<iostream>
using namespace std;

/*
Lab 7.5: Nhập vào 1 số N, kiểm tra xem số đó có phải là số nguyên tố hay không.
Biết rằng số nguyên tố là số chỉ chia hết cho 1 và chính nó. (Số 1 không phải số nguyên tố)

Gợi ý:
    - Sử dụng vòng lặp chạy từ 1 tới N/2
    - Lần lượt lấy số N thực hiện chia lấy dư (sử dụng toán tử %) cho các giá trị của lặp
    - Nếu kết quả phép chia lấy dư là 0 thì đó không phải là số nguyên tố, kết thúc vòng lặp
    - Nếu chạy hết vòng lặp mà kết quả các phép chia lấy dư vẫn khác 0 thì đó là số nguyên tố
*/

void prime(int n)
{
    if (n <= 1) {
        cout << n << " is not a prime number" << endl;
        return;
    }
    
    bool is_prime = true;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    
    if (is_prime) {
        cout << n << " is a prime number" << endl;
    } else {
        cout << n << " is not a prime number" << endl;
    }
}

int main()
{
    cout << "------- PRIME NUMBER CHECKER -------" << endl;
    cout << "Enter a number: ";
    int num;
    cin >> num;
    prime(num);
    
    return 0;
}
