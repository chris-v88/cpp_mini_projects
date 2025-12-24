# Môn học: CPP101x - Lập trình C++ Cơ bản 

# Tổng quan dự án - Bài tập số: 2

**Tên bài tập: Quản lý cước vận tải**

**Tác giả:** Phạm Bá Thành

**Thời gian làm bài dự kiến:** 3 giờ 20 phút

### Tổng quan bài tập

Trong một doanh nghiệp vận tải nhiều sản phẩm xe khác nhau như xe taxi, xe buyt, xe tải. Doanh nghiệp cần quản lý và tính giá cước, chi phí vận hành xe cho cả 3 loại xe trên. Bạn cần tạo 1 chương trình mô phỏng hoạt động quản lý vận tải của doanh nghiệp này.

* Cài đặt các thông tin cơ bản cho từng loại xe
* Tính giá cước taxi
* Tính giá cước cho các vé xe buýt
* Tính giá cước taxi cho mỗi chuyến xe
* Thực hiện tính chi phí vận hành cho mỗi loại xe

### Làm thế nào để hoàn thành bài asm?

Tạo project có tên `CPP101x_Asm2_<YourAccount>`. Có thể dùng devC++ hoặc Visual studio hoặc IDE bất kỳ để thao tác code. Tuy nhiên khuyến khích các bạn sử dụng Visual Studio để thực hiện bài tập.

Thực hiện bài tập theo các bước trong phần hướng dẫn.

Kiến thức cần có để hoàn thành dự án:
* Nhập xuất dữ liệu: cin và cout
* Khai báo và sử dụng các kiểu dữ liệu cơ bản
* Các lệnh rẽ nhánh: switch case, if else
* Cách comment cho các logic trong chương trình của mình
* Sử dụng vòng lặp while, do-while, for
* Khai báo và sử dụng hàm
* Khai báo và sử dụng kiểu dữ liệu Struct

---
---

# Hướng dẫn hoàn thành dự án

### 1. Chức năng và yêu cầu chi tiết

**1.1. Yêu cầu cơ bản**

a) Tạo các `Struct` lưu trữ thông tin cho từng loại xe

Tạo `Struct XE_TAI` với các thuộc tính sau:
* Quãng đường (km)
* Tải trọng (kg)
* Loại hàng hóa 
* Mức tiêu hao nhiên liệu (số lít xăng cho mỗi 100 km)
* Vân tốc trung bình (km/h)

Trong đó loại hàng hóa được quy định bởi 1 Enum:
```cpp
enum LOAI_HANG_HOA
{
        NONG_SAN = 0,
        THUY_SAN,
        HANG_TIEU_DUNG,
}
```

Tạo struct XE_BUYT với các thuộc tính sau:
* số ghế
* quãng đường (km)
* thời gian chạy mỗi chuyến (phút)
* Mức tiêu hao nhiên liệu (số lít xăng cho mỗi 100 km)
* Vân tốc trung bình (km/h)
* Số lượng khách đi quãng đường ngắn ( dưới 3km)
* Số lượng khách đi quãng đường trung bình (từ 3km tới 10 km)
* Số lượng khách đi quãng đường dài (trên 10km)

Tạo struct XE_TAXI với các thuộc tính sau:

* Quãng đường (km)
* Thời gian chờ (phút)
* Mức tiêu hao nhiên liệu (số lít xăng cho mỗi 100 km)
* Vân tốc trung bình (km/h)
* Điểm đến
        Điểm đi

b) Thực hiện chức năng cho từng loại xe

1) Xe buýt
* Viết hàm nhập thông tin cho xe buýt.
* Viết hàm tính số tiền vé thu được sau mỗi chuyến xe, biết rằng:
  * Nếu quãng đường dưới 3km giá vé là 3000 đồng.
  * Nếu quãng đường từ 3km tới dưới 10km thì giá vé là 7000 đồng.
  * Nếu quãng đường lớn hơn 10km thì giá vé là 9000 đồng.
    * Viết hàm tính thời gian trung bình xe chạy giữa 2 trạm. Biết mỗi trạm cách nhau 1km

2) Xe Tải

* Viết hàm nhập thông tin cho xe
* Thực hiện tính giá cước vận tải cho xe biết rằng giá cước cho mỗi 1 km như sau:
  * Nếu xe vận chuyển hải sản hoặc đồ tươi sống thì chi phí bảo quản lạnh cao, do đó giá cước là 3000 đồng/1kg
  * Nếu xe vận chuyển nông sản thì giá cước là 500 đồng/1kg
  * Nếu xe vận chuyển hàng tiêu dùng thì giá cước là 1000 đồng/1kg

3) Xe Taxi

* Viết hàm nhập thông tin cho xe
* Thực hiện tính giá cước mỗi chuyến xe biết:
  * Nếu thời gian chờ trên 5ph thì tính thêm phí 5000 đồng. Từ phút thứ 10 là 3000 đồng / 1 phút 
  * Nếu quãng đường dưới 5km thì cước là 20.000 đồng/1 km 
  * Nếu quãng đường từ 5 tới 10km thì cước là 15.000 đồng / 1km
  * Nếu quãng đường trên 10km thì cước là 13.000 đồng/1km

4) Thực hiện tính chi phí nhiên liệu và doanh thu

* Viết hàm tính chi phí nhiên liệu cho mỗi loại xe trong quãng đường mà xe đó chạy. 
* Giả sử: xe tải và xe buýt chạy dầu với giá 20.000/lit, xe taxi chạy xăng với giá 23.000/lit
* Tính doanh thu mỗi chuyến xe sau khi đã trừ chi phí nhiên liệu.

5) Nhập và xuất thông tin 

Tạo menu nhập thông tin như sau (MH-1):
```
============ Quan ly xe =========
        Xe buyt
        Xe tai
        Xe taXi
        Thoat chuong trinh
```
**Nếu chọn 1,2,3:** thì tiếp tục hiện menu như sau (MH-2):

```
   ============= Quan ly xe ========

   1. Nhap thong tin 

   2. Xuat thong tin

   3. Tro ve menu truoc  
```  

**Nếu chọn 1:** tiến hành nhập thông tin cho loại xe tương ứng

**Nếu chọn 2:**

* Xe buýt: Xuất thông tin: quãng đường đi, số lượng hành khách cho từng lộ trình, số tiền vé thu được, chi phí nhiên liệu, doanh thu, thời gian chạy trung bình giữa 2 trạm.
* Xe tải: Xuất thông tin quãng đường, loại hàng hóa,  tiền cước vận tải, chi phí nhiên liệu, doanh thu
* Taxi: Xuất thông tin quãng đường đi, điểm đến, điểm đi, giá cước, chi phí nhiên liệu và doanh thu.

**Nếu chọn 3:** chương trình sẽ hiển thị màn hình chọn loại xe (Menu màn hình MH-1)

6) Yêu cầu khác

* Thực hiện chú thích cho các biến, hàm và các đoạn code quan trọng.
* Từ các menu có thể đến và lùi về thì màn hình terminal cần clear và hiển thị nội dung liên quan đến menu đó. Không giới hạn số chuyển đổi giữa các menu. Để clear màn hình cũ bạn sử dụng lệnh system("cls").
* Có thể tạm dừng chương trình để tiến hành nhập dữ liệu hoặc xem kết quả bằng lệnh system("pause").

--- 

**1.2. Các yêu cầu nâng cao**

Kiểm tra các dữ liệu nhập vào là số hay chữ tại tất cả các vị trí yêu cầu nhập dữ liệu từ bàn phím. Ví dụ: Menu lựa chọn, các giá trị cài đặt

---

### 3. Tổ chức code

Sinh viên thực hiện code theo từng bước và thực hiện viết chú thích cho từng phần theo tổ chức code như sau:

```
//include các thư viện
//code của bạn

#include <iostream>

//Khai báo các biến, hàm, struct
//code của bạn


//Khai báo thân hàm
//code của bạn

int main(){

//code của bạn

}
```

Lưu ý: Bạn nên kiểm tra kĩ mục "Tiêu chí đánh giá" để đảm bảo đã hoàn thành đủ các yêu cầu trước khi nộp bài. 

---
---

# Hướng dẫn nộp bài

        Thư mục chứa project bài làm và các file tài nguyên cần thiết phải được nén thành 1 file dạng .zip
        Đặt tên folder theo mẫu CPP101x_Asm2_<YourAccount> (E.g. CPP101x_asm2_thangnvFX00000@funix.edu.vn) 
        Xem hướng dẫn và nộp bài tại mục Assessment Submission

## Đánh giá

Project của bạn sẽ được đánh giá và phỏng vấn (review) bởi mentor FUNiX dựa trên rubrics của project này. Bạn cần đảm bảo tự review cẩn thận xem đã đáp ứng tất cả các tiêu chí chưa trước khi nộp bài. Tất cả các tiêu chí “Đáp ứng các đặc tả” phải được hoàn thành. Trường hợp bài nộp của bạn chưa đáp ứng các tiêu chí bắt buộc thì sẽ phải làm lại cho đến khi đáp ứng. 

### * Lưu ý về việc chấm bài

Yêu cầu bắt buộc:

* Các bạn sinh viên phải làm và nộp đủ các tiêu chí đã được liệt kê, mỗi tiêu chí bắt buộc phải được mentor đánh giá là PASS. Nếu có bất kỳ tiêu chí bắt buộc nào FAIL thì bạn phải làm và nộp lại tiêu chí đó cho đến khi PASS. 
* Khi nộp lại bài không nộp riêng tiêu chí làm lại mà bạn cần nộp cả project trong đó có các tiêu chí đã làm lại (Lưu ý: không chấm lại điểm của tiêu chí nâng cao). Bài nộp lại trên hệ thống LMS.

Yêu cầu nâng cao (nếu có):

* Các bạn cần đưa thêm những tính năng nâng cao (bổ sung) khác cho bài project.
