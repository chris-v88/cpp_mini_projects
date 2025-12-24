#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

// cargo type
enum LOAI_HANG_HOA {
    NONG_SAN = 0,
    THUY_SAN,
    HANG_TIEU_DUNG
};

struct XE_TAI {
    float quang_duong;
    float tai_trong;
    LOAI_HANG_HOA loai_hang;
    float tieu_hao_nhien_lieu;
    float van_toc_tb;
};

