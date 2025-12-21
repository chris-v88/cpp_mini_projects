#include<iostream>
using namespace std;

/*
Lab 6.5: Tính số tiền chiết khấu hóa đơn dựa trên hàm có sẵn:
    Đầu vào input: số tiền
    Đầu ra output: In ra số tiền phải trả sau khi được chiết khấu
Biết:
    Nếu số tiền >5000 thì chiết khấu là 20%
    Nếu 2000 <= số tiền <= 5000 thì chiết khấu là 10%
    Nếu số tiền < 2000 thì chiết khấu là 5%
*/

void discount(int amount)
{
    float disAmount;
    // write nested conditions to print discounted amount
    if (amount > 5000)
    {
        cout << "%20" << endl;
    } else if (amount >= 2000 || amount <= 5000)
    {
        cout << "50%" << endl;
    } else
    {
        cout << "5%" << endl;
    }
}

int main()
{
    cout << "------- CHECK DISCOUNT -------" <<endl;
    cout << "Enter the amount: ";
    int amount;
    cin >> amount;
    discount(amount);
}