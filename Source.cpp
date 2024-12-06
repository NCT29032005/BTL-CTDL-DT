#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Định nghĩa cấu trúc nhân viên (danh sách liên kết móc nối)
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
    // Các thông tin khác có thể thêm vào
    NhanVien* next;  // Con trỏ đến nhân viên tiếp theo (móc nối)
};

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

// Các hàm quản lý đào tạo
void quanLyKhoaHoc();
void dangKyDaoTao(NhanVien* nv);
void danhGiaKhoaHoc(NhanVien* nv);

// Các hàm đánh giá hiệu suất
void lapKeHoachDanhGia(NhanVien* nv);
void thuThapKetQuaDanhGia(NhanVien* nv);
void hienThiKetQuaDanhGia(NhanVien* nv);

// Các hàm quản lý tài sản
void quanLyTaiSan();
void phanPhatTaiSan(NhanVien* nv);
void theoDoiTaiSan(NhanVien* nv);

// Các hàm báo cáo
void baoCaoNhanSu();
void baoCaoLuong();
void baoCaoDaoTao();
void baoCaoHieuSuat();
void baoCaoTaiSan();

// Các hàm quản lý văn bản
void quanLyHopDong(NhanVien* nv);
void quanLyQuyetDinhKhenThuong(NhanVien* nv);
void quanLyVVanBanNhanSu();

// Các tính năng khác
void quanLySuKien();
void tinhToanThongKeNhanSu();
void phanQuyenTruyCap();
void baoMatDuLieu();

// Các chức năng nâng cao
void quanLyPhucLoi(NhanVien* nv);
void lapKeHoachPhatTrienNgheNghiep(NhanVien* nv);
void quanLyQuanHeLaoDong(NhanVien* nv);
void quanLySucKhoe(NhanVien* nv);
void xayDungCongDongNhanVien();
void phanTichDuLieuNhanSu();

// Hàm khởi tạo danh sách liên kết móc nối (circular linked list)
NhanVien* khoiTaoDanhSach() {
    return nullptr;  // Danh sách ban đầu trống
}

// Hàm thêm nhân viên vào danh sách móc nối
void themNhanVien(NhanVien*& tail, NhanVien* nvMoi) {
    if (tail == nullptr) {
        nvMoi->next = nvMoi;  // Nếu danh sách trống, nhân viên tự trỏ lại chính nó
        tail = nvMoi;
    } else {
        nvMoi->next = tail->next;  // Nút mới trỏ về đầu danh sách
        tail->next = nvMoi;  // Nút cuối trỏ về nút mới
        tail = nvMoi;  // Cập nhật tail là nút mới
    }
}

// Hàm hiển thị danh sách nhân viên trong danh sách móc nối
void hienThiDanhSach(NhanVien* tail) {
    if (tail == nullptr) {
        cout << "Danh sách trống." << endl;
        return;
    }

    NhanVien* temp = tail->next;  // Bắt đầu từ đầu danh sách
    do {
        cout << "MaNV: " << temp->maNV << ", HoTen: " << temp->hoVaTen << ", LuongCB: " << temp->luongCB << ", PhuCap: " << temp->phuCap << ", ThucLinh: " << temp->thucLinh << endl;
        temp = temp->next;
    } while (temp != tail->next);  // Lặp lại từ đầu nếu đã đi đến cuối danh sách
}

// Hàm main để thử nghiệm
int main() {
    NhanVien* tail = khoiTaoDanhSach();  // Khởi tạo danh sách rỗng

    // Tạo nhân viên mẫu
    NhanVien* nv1 = new NhanVien{1, "Nguyen Van A", "Ha Noi", "Nam", "a@gmail.com", "0123456789", 10000, 2000, 12000, "Giám đốc", nullptr};
    themNhanVien(tail, nv1);

    NhanVien* nv2 = new NhanVien{2, "Tran Thi B", "Ho Chi Minh", "Nu", "b@gmail.com", "0987654321", 8000, 1500, 9500, "Trưởng phòng", nullptr};
    themNhanVien(tail, nv2);

    // Hiển thị danh sách nhân viên
    hienThiDanhSach(tail);

    return 0;
}
