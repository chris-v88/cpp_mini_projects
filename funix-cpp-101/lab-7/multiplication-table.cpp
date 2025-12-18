#include <iostream>
using namespace std;

/*
- Khai báo 2 biến kiểu nguyên là i, j; trong đó I sẽ đại diện cho các bảng nhân từ 1 tới 9 (số nhân); còn j đại diện cho các số bị nhận
- Sử dụng vòng lặp for lồng nhau với i bắt đầu từ 1 tới 9, j bắt đầu từ 0 tới 9
- Với mỗi số i, in ra kết quả i nhận với các số từ 0 tới 9
- Lặp lại phép tính sẽ ra được các bảng nhận từ 1 tới 9
*/

int main() {
    cout << "----- MULTIPLICATION TABLE -----" << endl;
    int n = 10;
    for (int i = 1; i <= 10; i++) {
        cout << "----- MULTIPLY BY " << i << " ------" << endl;
        for (int j = 0; j < n; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << "---------------------------" << endl;
    }
}