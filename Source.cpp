#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    long long maNV;
    string hoVaTen;
    string diaChi;
    string gioiTinh;
    string email;
    string soDT;
    float luongCB;
    float phuCap;
    float thucLinh;
    string chucDanh;
    NhanVien* prev; // Con trỏ đến nhân viên trước
    NhanVien* next; // Con trỏ đến nhân viên tiếp theo
};

// Hàm khởi tạo danh sách liên kết đôi
NhanVien* khoiTaoDanhSach() {
    return nullptr; // Danh sách ban đầu trống
}

// Hàm thêm nhân viên vào cuối danh sách liên kết đôi
void themNhanVien(NhanVien*& head, NhanVien*& tail, NhanVien* nvMoi) {
    if (head == nullptr) { // Nếu danh sách trống
        head = tail = nvMoi;
        nvMoi->prev = nvMoi->next = nullptr;
    } else {
        tail->next = nvMoi;
        nvMoi->prev = tail;
        nvMoi->next = nullptr;
        tail = nvMoi;
    }
}

// Hàm hiển thị danh sách nhân viên theo chiều xuôi
void hienThiDanhSach(NhanVien* head) {
    if (head == nullptr) {
        cout << "Danh sách trống." << endl;
        return;
    }

    NhanVien* temp = head;
    while (temp != nullptr) {
        cout << "MaNV: " << temp->maNV << ", HoTen: " << temp->hoVaTen << ", LuongCB: " << temp->luongCB
            << ", PhuCap: " << temp->phuCap << ", ThucLinh: " << temp->thucLinh << endl;
        temp = temp->next;
    }
}

// Hàm hiển thị danh sách nhân viên theo chiều ngược
void hienThiDanhSachNguoc(NhanVien* tail) {
    if (tail == nullptr) {
        cout << "Danh sách trống." << endl;
        return;
    }

    NhanVien* temp = tail;
    while (temp != nullptr) {
        cout << "MaNV: " << temp->maNV << ", HoTen: " << temp->hoVaTen << ", LuongCB: " << temp->luongCB
            << ", PhuCap: " << temp->phuCap << ", ThucLinh: " << temp->thucLinh << endl;
        temp = temp->prev;
    }
}

// Các hàm quản lý thông tin nhân viên
void capNhatThongTinCaNhan(NhanVien* nv);
void capNhatThongTinLienHe(NhanVien* nv);
void capNhatThongTinGiaDinh(NhanVien* nv);
void capNhatThongTinCongTac(NhanVien* nv);
void capNhatKyNang(NhanVien* nv);
void hienThiThongTinNhanVien(NhanVien* nv);

// Các hàm quản lý tuyển dụng
void dangTinTuyenDung();
void nhanHoSoTuyenDung();
void phongVan(NhanVien* nv);
void danhGiaTuyenDung(NhanVien* nv);
void quyetDinhTuyenDung(NhanVien* nv);

// Các hàm quản lý chấm công
void chamCongBangPhuongThuc1(NhanVien* nv);
void chamCongBangPhuongThuc2(NhanVien* nv);
void tinhGioLam(NhanVien* nv);
void tinhGioNghi(NhanVien* nv);
void hienThiBangChamCong(NhanVien* nv);

// Các hàm quản lý lương
void tinhLuong(NhanVien* nv);
void tinhKhauTru(NhanVien* nv);
void xuatBangLuong(NhanVien* nv);
void capNhatLuong(NhanVien* nv);
void thuongNhanVien(NhanVien* nv);


// Các hàm báo cáo
void baoCaoNhanSu();
void baoCaoLuong();

// Hàm main để thử nghiệm
int main() {
    NhanVien* head = khoiTaoDanhSach(); // Khởi tạo danh sách rỗng
    NhanVien* tail = nullptr;

    // Tạo nhân viên mẫu
    NhanVien* nv1 = new NhanVien{1, "Nguyen Van A", "Ha Noi", "Nam", "a@gmail.com", "0123456789", 10000, 2000, 12000, "Giám đốc", nullptr, nullptr};
    themNhanVien(head, tail, nv1);

    NhanVien* nv2 = new NhanVien{2, "Tran Thi B", "Ho Chi Minh", "Nu", "b@gmail.com", "0987654321", 8000, 1500, 9500, "Trưởng phòng", nullptr, nullptr};
    themNhanVien(head, tail, nv2);

    // Hiển thị danh sách nhân viên theo chiều xuôi
    cout << "Danh sách nhân viên (xuôi):" << endl;
    hienThiDanhSach(head);

    // Hiển thị danh sách nhân viên theo chiều ngược
    cout << "\nDanh sách nhân viên (ngược):" << endl;
    hienThiDanhSachNguoc(tail);

    return 0;
}
