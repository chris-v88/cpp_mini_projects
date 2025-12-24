#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

// cargo type
enum LOAI_HANG_HOA
{
    NONG_SAN = 0,
    THUY_SAN,
    HANG_TIEU_DUNG
};

struct XE_TAI
{
    float quang_duong;          // distance (km)
    float tai_trong;            // weight (kg)
    LOAI_HANG_HOA loai_hang;    // cargo type
    float tieu_hao_nhien_lieu;  // fuel
    float van_toc_tb;           // avg speed (km/h)

    // hàm nhập thông tin cho xe
    void set_info()
    {
        cout << "Nhap quang duong (km): ";
        cin >> quang_duong;

        cout << "\nNhap tai trong (kg): ";
        cin >> tai_trong;

        cout << "Nhap loai hang hoa (0: Nong san, 1: Thuy san, 2: Hang tieu dung): ";
        int loai;
        cin >> loai;
        loai_hang = static_cast<LOAI_HANG_HOA>(loai);

        cout << "Nhap tieu hao nhien lieu (lit/100km): ";
        cin >> tieu_hao_nhien_lieu;

        cout << "Nhap van toc trung binh (km/h): ";
        cin >> van_toc_tb;
    }

    // tính giá cước vận tải cho xe biết rằng giá cước cho mỗi 1 km
    float get_freight_cost()
    {
        float freight_price = 0.0;
        // Nếu xe vận chuyển hải sản hoặc đồ tươi sống thì chi phí bảo quản lạnh cao
        // do đó giá cước là 3000 đồng/1kg
        if (loai_hang == THUY_SAN)
        {
            freight_price = 3000.0;
        }

        // Nếu xe vận chuyển nông sản
        // thì giá cước là 500 đồng/1kg
        else if (loai_hang == NONG_SAN)
        {
            freight_price = 500.0;
        }
        
        // Nếu xe vận chuyển hàng tiêu dùng
        //thì giá cước là 1000 đồng/1kg
        else if (loai_hang == HANG_TIEU_DUNG)
        {
            freight_price = 1000.0;
        }

        return tai_trong * freight_price;
    }
};

struct XE_BUYT
{
    int so_ghe;                 // number of seats
    float quang_duong;          // distance (km)
    float thoi_gian_chay;       // time per trip (minutes)
    float tieu_hao_nhien_lieu;  // fueld
    float van_toc_tb;           // avg speed(km/h)
    int khach_ngan;             // # passengers for <3km
    int khach_tb;               // # passengers for 3-10km
    int khach_dai;              // # passengers for >10km

    void set_info() 
    {
        cout << "Nhap so ghe: ";
        cin >> so_ghe;

        cout << "Nhap quang duong (km): ";
        cin >> quang_duong;

        cout << "Nhap thoi gian chay moi chuyen (phut): ";
        cin >> thoi_gian_chay;

        cout << "Nhap tieu hao nhien lieu (lit/100km): ";
        cin >> tieu_hao_nhien_lieu;

        cout << "Nhap van toc trung binh (km/h): ";
        cin >> van_toc_tb;

        cout << "Nhap so khach duong ngan (<3km): ";
        cin >> khach_ngan;

        cout << "Nhap so khach duong trung binh (3-10km): ";
        cin >> khach_tb;

        cout << "Nhap so khach duong dai (>10km): ";
        cin >> khach_dai;
    };
};

struct XE_TAXI
{
    float quang_duong;          // distance(km)
    float thoi_gian_cho;        // waiting time (minute)
    float tieu_hao_nhien_lieu;  // fuel
    float van_toc_tb;           // avg speed
    string diem_di;             // starting point
    string diem_den;            // destination

    void set_info()
    {
        cout << "Nhap quang duong (km): ";
        cin >> quang_duong;

        cout << "Nhap thoi gian cho (phut): ";
        cin >> thoi_gian_cho;

        cout << "Nhap tieu hao nhien lieu (lit/100km): ";
        cin >> tieu_hao_nhien_lieu;

        cout << "Nhap van toc trung binh (km/h): ";
        cin >> van_toc_tb;

        cout << "Nhap diem di: ";
        cin >> diem_di;

        cout << "Nhap diem den: ";
        cin >> diem_den;
    }
};