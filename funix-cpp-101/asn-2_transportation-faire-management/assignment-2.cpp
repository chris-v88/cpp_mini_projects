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
};
struct XE_TAXI 
{
    float quang_duong;          // distance(km)
    float thoi_gian_cho;        // waiting time (minute)
    float tieu_hao_nhien_lieu;  // fuel
    float van_toc_tb;           // avg speed
    string diem_di;             // starting point
    string diem_den;            // destination
};