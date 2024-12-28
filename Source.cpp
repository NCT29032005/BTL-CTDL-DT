#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <locale>
using namespace std;

// Struct nhỏ
struct ThongTinCaNhan {
    long long maNV;
    string hoVaTen;
    string ngaySinh;
    string gioiTinh;
};

struct ThongTinLienHe {
    string diaChi;
    string email;
    string soDT;
};

struct ThongTinGiaDinh {
    string tinhTrangHonNhan;
    int soCon;
    string queQuan;
};

struct ThongTinCongTac {
    string chucDanh;
    string phongBan;
    int soNamKinhNghiem;
};

struct KyNang {
    string kyNangChuyenMon;
    string kyNangMem;
    string ngoaiNgu;
};

struct Luong {
    float luongCB;
    float phuCap;
    float thucLinh;
    int soNgayDiLam;
    int soGioLam;
    int soNgayNghi;
    int soGioNghi;
    int ngayPhepConLai;
    float chamcong[30];
};

// Struct chính
struct NhanVien {
    ThongTinCaNhan thongTinCaNhan;
    ThongTinLienHe thongTinLienHe;
    ThongTinGiaDinh thongTinGiaDinh;
    ThongTinCongTac thongTinCongTac;
    KyNang kyNang;
    Luong luong;
    NhanVien* prev;
    NhanVien* next;
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

<<<<<<< HEAD
=======
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

>>>>>>> 701ada8ab916f0c642c61a6f11145c76409c9616
// Các hàm quản lý thông tin nhân viên
// Cập nhật thông tin cá nhân
void capNhatThongTinCaNhan(NhanVien* nv) {
    if (!nv) {
        cout << "Nhân viên không tồn tại." << endl;
        return;
    }
    cout << "Nhập họ và tên mới: ";
    cin.ignore();
    getline(cin, nv->thongTinCaNhan.hoVaTen);
    cout << "Nhập giới tính mới: ";
    getline(cin, nv->thongTinCaNhan.gioiTinh);
    cout << "Thông tin cá nhân đã được cập nhật." << endl;
}

void capNhatThongTinLienHe(NhanVien* nv) {
    if (!nv) {
        cout << "Nhân viên không tồn tại." << endl;
        return;
    }
    cout << "Nhập địa chỉ mới: ";
    cin.ignore();
    getline(cin, nv->thongTinLienHe.diaChi);
    cout << "Nhập email mới: ";
    getline(cin, nv->thongTinLienHe.email);
    cout << "Nhập số điện thoại mới: ";
    getline(cin, nv->thongTinLienHe.soDT);
    cout << "Thông tin liên hệ đã được cập nhật." << endl;
}

// Cập nhật thông tin gia đình
void capNhatThongTinGiaDinh(NhanVien* nv) {
    if (!nv) {
        cout << "Nhân viên không tồn tại." << endl;
        return;
    }
    cout << "Nhập thông tin gia đình mới: ";
    cin.ignore();
    getline(cin, nv->thongTinGiaDinh.tinhTrangHonNhan);
    cout << "Nhập số con mới: ";
    cin >> nv->thongTinGiaDinh.soCon;
    cin.ignore();
    cout << "Nhập quê quán mới: ";
    getline(cin, nv->thongTinGiaDinh.queQuan);
    cout << "Thông tin gia đình đã được cập nhật." << endl;
}

// Cập nhật thông tin công tác
void capNhatThongTinCongTac(NhanVien* nv) {
    if (!nv) {
        cout << "Nhân viên không tồn tại." << endl;
        return;
    }
    cout << "Nhập chức danh mới: ";
    cin.ignore();
    getline(cin, nv->thongTinCongTac.chucDanh);
    cout << "Nhập phòng ban mới: ";
    getline(cin, nv->thongTinCongTac.phongBan);
    cout << "Nhập số năm kinh nghiệm mới: ";
    cin >> nv->thongTinCongTac.soNamKinhNghiem;
    cin.ignore();
    cout << "Thông tin công tác đã được cập nhật." << endl;
}

// Cập nhật kỹ năng
void capNhatKyNang(NhanVien* nv) {
    if (!nv) {
        cout << "Nhân viên không tồn tại." << endl;
        return;
    }
    cout << "Nhập kỹ năng chuyên môn mới: ";
    cin.ignore();
    getline(cin, nv->kyNang.kyNangChuyenMon);
    cout << "Nhập kỹ năng mềm mới: ";
    getline(cin, nv->kyNang.kyNangMem);
    cout << "Nhập ngoại ngữ mới: ";
    getline(cin, nv->kyNang.ngoaiNgu);
    cout << "Kỹ năng đã được cập nhật." << endl;
}

// Hiển thị thông tin nhân viên
void hienThiThongTinNhanVien(NhanVien* nv) {
    if (!nv) {
        cout << "Nhân viên không tồn tại." << endl;
        return;
    }
    cout << "Mã NV: " << nv->thongTinCaNhan.maNV << ", Họ tên: " << nv->thongTinCaNhan.hoVaTen
        << ", Giới tính: " << nv->thongTinCaNhan.gioiTinh
        << ", Địa chỉ: " << nv->thongTinLienHe.diaChi
        << ", Email: " << nv->thongTinLienHe.email
        << ", Số điện thoại: " << nv->thongTinLienHe.soDT
        << ", Tình trạng hôn nhân: " << nv->thongTinGiaDinh.tinhTrangHonNhan
        << ", Số con: " << nv->thongTinGiaDinh.soCon
        << ", Quê quán: " << nv->thongTinGiaDinh.queQuan
        << ", Chức danh: " << nv->thongTinCongTac.chucDanh
        << ", Phòng ban: " << nv->thongTinCongTac.phongBan
        << ", Số năm kinh nghiệm: " << nv->thongTinCongTac.soNamKinhNghiem
        << ", Kỹ năng chuyên môn: " << nv->kyNang.kyNangChuyenMon
        << ", Kỹ năng mềm: " << nv->kyNang.kyNangMem
        << ", Ngoại ngữ: " << nv->kyNang.ngoaiNgu
        << ", Lương cơ bản: " << nv->luong.luongCB
        << ", Phụ cấp: " << nv->luong.phuCap
        << ", Thực lĩnh: " << nv->luong.thucLinh << endl;
}

// Các hàm quản lý tuyển dụng
void dangTinTuyenDung();
void nhanHoSoTuyenDung();
void phongVan(NhanVien* nv);
void danhGiaTuyenDung(NhanVien* nv);
void quyetDinhTuyenDung(NhanVien* nv);

<<<<<<< HEAD
// Các hàm báo cáo
void baoCaoNhanSu();
void baoCaoLuong();

// Hàm hiển thị bảng chấm công
void hienThiBangChamCong(NhanVien* nv) {
    cout << "Bảng chấm công của nhân viên " << nv->thongTinCaNhan.hoVaTen << ":\n";
    cout << "Số ngày đi làm: " << nv->luong.soNgayDiLam << endl;
    cout << "Số giờ làm: " << nv->luong.soGioLam << endl;
    cout << "Số ngày nghỉ: " << nv->luong.soNgayNghi << endl;
    cout << "Số giờ nghỉ: " << nv->luong.soGioNghi << endl;
    cout << "Chi tiết chấm công (6x6):\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            int idx = i * 6 + j;
            if (idx < 30) {
                cout << fixed << setprecision(1) << nv->luong.chamcong[idx] << " ";
            }
        }
        cout << endl;
    }
}

// Hàm chấm công phương thức 1
void chamCongBangPhuongThuc1(NhanVien* nv) {
    cout << "Chấm công cho nhân viên " << nv->thongTinCaNhan.hoVaTen << ":\n";
    int ngay;
    do {
        cout << "Hôm nay là ngày bao nhiêu (1-30)? ";
        cin >> ngay;
    } while (ngay < 1 || ngay > 30);

    int index = ngay - 1;
    int option;
    do {
        cout << "Hôm nay đi làm không? (0: Không, 1: Half, 2: Cả ngày): ";
        cin >> option;
    } while (option < 0 || option > 2);

    if (option == 0) {
        nv->luong.chamcong[index] = 0;
        nv->luong.soNgayNghi++;
    } else if (option == 1) {
        nv->luong.chamcong[index] = 0.5;
        nv->luong.soNgayDiLam += 0.5;
        nv->luong.soNgayNghi += 0.5;
    } else if (option == 2) {
        nv->luong.chamcong[index] = 1;
        nv->luong.soNgayDiLam++;
    }
}

// Hàm chấm công phương thức 2
void chamCongBangPhuongThuc2(NhanVien* nv) {
    cout << "Chấm công cho nhân viên " << nv->thongTinCaNhan.hoVaTen << ":\n";
    int ngay;
    do {
        cout << "Hôm nay là ngày bao nhiêu (1-30)? ";
        cin >> ngay;
    } while (ngay < 1 || ngay > 30);

    int index = ngay - 1;
    int option;
    do {
        cout << "Hôm nay đi làm không? (0: Không, 1: Half, 2: Cả ngày): ";
        cin >> option;
    } while (option < 0 || option > 2);

    if (option == 0) {
        nv->luong.chamcong[index] = 0;
        nv->luong.soNgayNghi++;
    } else if (option == 1) {
        nv->luong.chamcong[index] = 0.5;
        nv->luong.soNgayDiLam += 0.5;
        nv->luong.soNgayNghi += 0.5;
    } else if (option == 2) {
        nv->luong.chamcong[index] = 1;
        nv->luong.soNgayDiLam++;
    }
}

// Hàm tính giờ làm
void tinhGioLam(NhanVien* nv) {
    nv->luong.soGioLam = nv->luong.soNgayDiLam * 8;
    cout << "Tổng số giờ làm của nhân viên " << nv->thongTinCaNhan.hoVaTen << ": " << nv->luong.soGioLam << " giờ.\n";
}

// Hàm tính giờ nghỉ
void tinhGioNghi(NhanVien* nv) {
    nv->luong.soGioNghi = nv->luong.soNgayNghi * 8;
    cout << "Tổng số giờ nghỉ của nhân viên " << nv->thongTinCaNhan.hoVaTen << ": " << nv->luong.soGioNghi << " giờ.\n";
}

float tinhHeSoTheoChucVu(const string& chucDanh) {
    if (chucDanh == "GIAMDOC") return 3000000;
    else if (chucDanh == "QUANLYCAPCAO") return 1000000;
    else if (chucDanh == "QUANLYCAPTHAP") return 700000;
    else if (chucDanh == "NHANVIEN") return 300000;
    else return 0; // Mặc định
}

float tinhLuongCoBanTheoPhongBan(const string& phongBan) {
    if (phongBan == "Phòng điều hành") return 5000000;
    else if (phongBan == "Phòng kỹ thuật") return 4000000;
    else if (phongBan == "Phòng tài chính") return 3500000;
    else if (phongBan == "Phòng nhân sự") return 3000000;
    else if (phongBan == "Phòng kinh doanh") return 4500000;
    else return 0; // Mặc định
}

float tinhHeSoKinhNghiem(int soNamKinhNghiem) {
    if (soNamKinhNghiem < 3) return 1.0;
    else if (soNamKinhNghiem < 10) return 1.3;
    else if (soNamKinhNghiem < 20) return 1.5;
    else return 2.0;
}

void tinhLuong(NhanVien* nv) {
    float luongCoBan = tinhLuongCoBanTheoPhongBan(nv->thongTinCongTac.phongBan);
    float heSoChucVu = tinhHeSoTheoChucVu(nv->thongTinCongTac.chucDanh);
    float heSoKinhNghiem = tinhHeSoKinhNghiem(nv->thongTinCongTac.soNamKinhNghiem);

    nv->luong.luongCB = luongCoBan;
    float luongNgay = heSoChucVu * nv->luong.soNgayDiLam;
    nv->luong.thucLinh = luongCoBan + luongNgay + (nv->luong.phuCap * heSoKinhNghiem);
}

// Hàm reset bảng chấm công
void resetBangChamCong(NhanVien* nv) {
    cout << "Đặt lại bảng chấm công cho nhân viên " << nv->thongTinCaNhan.hoVaTen << " (1: Có, 0: Không)? ";
    int reset;
    cin >> reset;
    if (reset == 1) {
        nv->luong.soNgayDiLam = 0;
        nv->luong.soNgayNghi = 0;
        nv->luong.soGioLam = 0;
        nv->luong.soGioNghi = 0;
        nv->luong.ngayPhepConLai = 2;
        for (int i = 0; i < 30; i++) {
            nv->luong.chamcong[i] = 0;
        }
        cout << "Đã reset bảng lương.\n";
    }
}

// Hàm tính khấu trừ
void tinhKhauTru(NhanVien* nv) {
    float luongMatDoNghi = nv->luong.soNgayNghi * (nv->luong.luongCB / 30);  // Giả sử mỗi tháng có 30 ngày
    float phatViPham = 0;  // Khởi tạo mức phạt

    // Nhập mức phạt do vi phạm quy định công ty
    cout << "Nhập mức phạt do vi phạm quy định công ty cho nhân viên " << nv->thongTinCaNhan.hoVaTen << " (VND): ";
    cin >> phatViPham;

    // Tính tổng khấu trừ
    float tongKhauTru = luongMatDoNghi + phatViPham;
    nv->luong.thucLinh -= tongKhauTru;

    cout << "Khấu trừ do nghỉ không phép: " << luongMatDoNghi << " VND\n";
    cout << "Khấu trừ do vi phạm quy định công ty: " << phatViPham << " VND\n";
    cout << "Tổng khấu trừ: " << tongKhauTru << " VND\n";
    cout << "Lương thực lĩnh sau khi khấu trừ: " << nv->luong.thucLinh << " VND\n";
}

// Hàm cập nhật lương
void capNhatLuong(NhanVien* nv) {
    float luongCoBan = tinhLuongCoBanTheoPhongBan(nv->thongTinCongTac.phongBan);
    float heSoChucVu = tinhHeSoTheoChucVu(nv->thongTinCongTac.chucDanh);
    float heSoKinhNghiem = tinhHeSoKinhNghiem(nv->thongTinCongTac.soNamKinhNghiem);

    nv->luong.luongCB = luongCoBan;
    float luongNgay = heSoChucVu * nv->luong.soNgayDiLam;
    nv->luong.thucLinh = luongCoBan + luongNgay + (nv->luong.phuCap * heSoKinhNghiem);

    cout << "Lương cơ bản: " << nv->luong.luongCB << " VND\n";
    cout << "Lương theo ngày đi làm: " << luongNgay << " VND\n";
    cout << "Phụ cấp (theo kinh nghiệm): " << nv->luong.phuCap * heSoKinhNghiem << " VND\n";
    cout << "Lương thực lĩnh: " << nv->luong.thucLinh << " VND\n";

    // Cập nhật lại bảng lương sau khi tính khấu trừ
    tinhKhauTru(nv);
}

// Hàm thưởng phạt nhân viên
void thuongPhatNhanVien(NhanVien* nv) {
    int loaiThucThi;
    float giaTriThucThi;

    cout << "Nhân viên " << nv->thongTinCaNhan.hoVaTen << ", chọn loại thưởng/phạt:\n";
    cout << "1. Thưởng\n";
    cout << "2. Phạt\n";
    cout << "Nhập lựa chọn (1/2): ";
    cin >> loaiThucThi;

    if (loaiThucThi == 1) {
        cout << "Nhập giá trị thưởng (VND): ";
        cin >> giaTriThucThi;
        nv->luong.phuCap += giaTriThucThi;
        cout << "Thưởng cho nhân viên " << nv->thongTinCaNhan.hoVaTen << ": " << giaTriThucThi << " VND\n";
    } else if (loaiThucThi == 2) {
        cout << "Nhập giá trị phạt (VND): ";
        cin >> giaTriThucThi;
        nv->luong.phuCap -= giaTriThucThi;
        if (nv->luong.phuCap < 0) nv->luong.phuCap = 0;  // Tránh trường hợp phụ cấp âm
        cout << "Phạt cho nhân viên " << nv->thongTinCaNhan.hoVaTen << ": " << giaTriThucThi << " VND\n";
    }

    // Cập nhật lại lương thực lĩnh sau khi thưởng/phạt
    capNhatLuong(nv);
}

// Hàm xuất bảng lương
void xuatBangLuong(NhanVien* nv) {
    cout << "Bảng lương của nhân viên " << nv->thongTinCaNhan.hoVaTen << ":\n";
    cout << "Lương cơ bản: " << nv->luong.luongCB << " VND\n";
    cout << "Lương theo ngày đi làm: " << (nv->luong.soNgayDiLam * nv->luong.luongCB / 30) << " VND\n";
    cout << "Phụ cấp: " << nv->luong.phuCap << " VND\n";
    cout << "Lương thực lĩnh: " << nv->luong.thucLinh << " VND\n";
}

// Hàm lưu danh sách nhân viên vào file
void luuDanhSachNhanVien(NhanVien* head, const string& tenFile) {
    ofstream file(tenFile);
    if (!file) {
        cout << "Không thể mở file để ghi.\n";
        return;
    }

    NhanVien* current = head;
    while (current != nullptr) {
        file << current->thongTinCaNhan.maNV << ","
            << current->thongTinCaNhan.hoVaTen << ","
            << current->thongTinCaNhan.ngaySinh << ","
            << current->thongTinCaNhan.gioiTinh << ","
            << current->thongTinLienHe.diaChi << ","
            << current->thongTinLienHe.email << ","
            << current->thongTinLienHe.soDT << ","
            << current->thongTinGiaDinh.tinhTrangHonNhan << ","
            << current->thongTinGiaDinh.soCon << ","
            << current->thongTinGiaDinh.queQuan << ","
            << current->thongTinCongTac.chucDanh << ","
            << current->thongTinCongTac.phongBan << ","
            << current->thongTinCongTac.soNamKinhNghiem << ","
            << current->kyNang.kyNangChuyenMon << ","
            << current->kyNang.kyNangMem << ","
            << current->kyNang.ngoaiNgu << ","
            << current->luong.luongCB << ","
            << current->luong.phuCap << ","
            << current->luong.thucLinh << ","
            << current->luong.soNgayDiLam << ","
            << current->luong.soGioLam << ","
            << current->luong.soNgayNghi << ","
            << current->luong.soGioNghi << ","
            << current->luong.ngayPhepConLai;
        for (int i = 0; i < 30; i++) {
            file << "," << current->luong.chamcong[i];
        }
        file << "\n";
        current = current->next;
    }

    file.close();
    cout << "Đã lưu danh sách nhân viên vào file " << tenFile << ".\n";
}

// Hàm tải danh sách nhân viên từ file
void taiDanhSachNhanVien(NhanVien*& head, NhanVien*& tail, const string& tenFile) {
    ifstream file(tenFile);
    if (!file) {
        cout << "Không thể mở file để đọc.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        NhanVien* nvMoi = new NhanVien;
        stringstream ss(line);
        string temp;

        getline(ss, temp, ','); nvMoi->thongTinCaNhan.maNV = stoll(temp);
        getline(ss, nvMoi->thongTinCaNhan.hoVaTen, ',');
        getline(ss, nvMoi->thongTinCaNhan.ngaySinh, ',');
        getline(ss, nvMoi->thongTinCaNhan.gioiTinh, ',');
        getline(ss, nvMoi->thongTinLienHe.diaChi, ',');
        getline(ss, nvMoi->thongTinLienHe.email, ',');
        getline(ss, nvMoi->thongTinLienHe.soDT, ',');
        getline(ss, nvMoi->thongTinGiaDinh.tinhTrangHonNhan, ',');
        getline(ss, temp, ','); nvMoi->thongTinGiaDinh.soCon = stoi(temp);
        getline(ss, nvMoi->thongTinGiaDinh.queQuan, ',');
        getline(ss, nvMoi->thongTinCongTac.chucDanh, ',');
        getline(ss, nvMoi->thongTinCongTac.phongBan, ',');
        getline(ss, temp, ','); nvMoi->thongTinCongTac.soNamKinhNghiem = stoi(temp);
        getline(ss, nvMoi->kyNang.kyNangChuyenMon, ',');
        getline(ss, nvMoi->kyNang.kyNangMem, ',');
        getline(ss, nvMoi->kyNang.ngoaiNgu, ',');
        getline(ss, temp, ','); nvMoi->luong.luongCB = stof(temp);
        getline(ss, temp, ','); nvMoi->luong.phuCap = stof(temp);
        getline(ss, temp, ','); nvMoi->luong.thucLinh = stof(temp);
        getline(ss, temp, ','); nvMoi->luong.soNgayDiLam = stoi(temp);
        getline(ss, temp, ','); nvMoi->luong.soGioLam = stoi(temp);
        getline(ss, temp, ','); nvMoi->luong.soNgayNghi = stoi(temp);
        getline(ss, temp, ','); nvMoi->luong.soGioNghi = stoi(temp);
        getline(ss, temp, ','); nvMoi->luong.ngayPhepConLai = stoi(temp);
        for (int i = 0; i < 30; i++) {
            getline(ss, temp, ','); nvMoi->luong.chamcong[i] = stof(temp);
        }

        nvMoi->prev = nvMoi->next = nullptr;
        themNhanVien(head, tail, nvMoi);
    }

    file.close();
    cout << "Đã tải danh sách nhân viên từ file " << tenFile << ".\n";
}

void hienThiMenu() {
    cout << " _____________________________________________________________________________" << endl;
        cout << "|*****************************************************************************|" << endl;
        cout << "|                              QUAN LY NHAN VIEN                              |" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "|*                                                                           *|" << endl;
        cout << "|              ||\\"<<"\\        //|| ||======  ||\\"<<"\\    || ||       ||              |" << endl;
        cout << "|              || \\"<<"\\      // || ||        || \\"<<"\\   || ||       ||              |" << endl;
        cout << "|              ||  \\"<<"\\    //  || ||======  ||  \\"<<"\\  || ||       ||              |" << endl;
        cout << "|              ||   \\"<<"\\  //   || ||        ||   \\"<<"\\ || ||       ||              |" << endl;
        cout << "|              ||    \\"<<"\\//    || ||======  ||    \\"<<"\\||  \\"<<"\\=====//               |" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|  1.  Thêm Nhân ViênViên                                                     |" << endl;
        cout << "|  2.  Hien thi bảng chấm công                                                |" << endl;
        cout << "|  3.  Tim kiem nhan vien theo maNV                                           |" << endl;
        cout << "|  4.  Tim kiem nhan vien theo CCCD                                           |" << endl;
        cout << "|  5.  Tim kiem nhan vien theo ten                                            |" << endl;
        cout << "|  6.  Reset bảng chấm công                                                   |" << endl;
        cout << "|  7.  Tính lương                                                             |" << endl;
        cout << "|  8.  Tim kiem nhan vien thu nhap cao nhat                                   |" << endl;
        cout << "|  9.  Thưởng phạt nhân viên                                                  |" << endl;
        cout << "|  10. Xuất bảng lương                                                        |" << endl;
        cout << "|  11. Lưu danh sách nhân viên vào file                                       |" << endl;
        cout << "|  12. Tải danh sách nhân viên từ file                                        |" << endl;
        cout << "|  13. Ghi danh sach nhan vien ra file khac                                   |" << endl;
        cout << "|  14. Quay lai menu                                                          |" << endl;
        cout << "|  15. Thoat                                                                  |" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|*___________________________________________________________________________*|" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "|*****************                    ~2TK~                   ****************|" << endl;
        cout << "|*****************************************************************************|" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "Nhap lua chon cua ban [1-15]: ";
}
=======
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
>>>>>>> 701ada8ab916f0c642c61a6f11145c76409c9616

// Hàm main để thử nghiệm
int main() {
    // Thiết lập locale để hiển thị tiếng Việt
    setlocale(LC_ALL, "vi_VN.UTF-8");

    NhanVien* head = khoiTaoDanhSach();
    NhanVien* tail = nullptr;

    int luaChon;
    do {
        hienThiMenu();
        cin >> luaChon;
        cin.ignore(); // Bỏ qua ký tự newline sau khi nhập số

        switch (luaChon) {
            case 1: {
                // Thêm nhân viên
                NhanVien* nvMoi = new NhanVien;
                // Nhập thông tin nhân viên mới
                cout << "Nhập mã nhân viên: ";
                cin >> nvMoi->thongTinCaNhan.maNV;
                cin.ignore();
                cout << "Nhập họ và tên: ";
                getline(cin, nvMoi->thongTinCaNhan.hoVaTen);
                cout << "Nhập ngày sinh: ";
                getline(cin, nvMoi->thongTinCaNhan.ngaySinh);
                cout << "Nhập giới tính: ";
                getline(cin, nvMoi->thongTinCaNhan.gioiTinh);
                cout << "Nhập địa chỉ: ";
                getline(cin, nvMoi->thongTinLienHe.diaChi);
                cout << "Nhập email: ";
                getline(cin, nvMoi->thongTinLienHe.email);
                cout << "Nhập số điện thoại: ";
                getline(cin, nvMoi->thongTinLienHe.soDT);
                cout << "Nhập tình trạng hôn nhân: ";
                getline(cin, nvMoi->thongTinGiaDinh.tinhTrangHonNhan);
                cout << "Nhập số con: ";
                cin >> nvMoi->thongTinGiaDinh.soCon;
                cin.ignore();
                cout << "Nhập quê quán: ";
                getline(cin, nvMoi->thongTinGiaDinh.queQuan);
                cout << "Nhập chức danh: ";
                getline(cin, nvMoi->thongTinCongTac.chucDanh);
                cout << "Nhập phòng ban: ";
                getline(cin, nvMoi->thongTinCongTac.phongBan);
                cout << "Nhập số năm kinh nghiệm: ";
                cin >> nvMoi->thongTinCongTac.soNamKinhNghiem;
                cin.ignore();
                cout << "Nhập kỹ năng chuyên môn: ";
                getline(cin, nvMoi->kyNang.kyNangChuyenMon);
                cout << "Nhập kỹ năng mềm: ";
                getline(cin, nvMoi->kyNang.kyNangMem);
                cout << "Nhập ngoại ngữ: ";
                getline(cin, nvMoi->kyNang.ngoaiNgu);
                nvMoi->luong = {0, 0, 0, 0, 0, 0, 0, 2, {0}};
                nvMoi->prev = nvMoi->next = nullptr;
                themNhanVien(head, tail, nvMoi);
                break;
            }
            case 2: {
                // Hiển thị bảng chấm công
                if (head != nullptr) hienThiBangChamCong(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 3: {
                // Chấm công phương thức 1
                if (head != nullptr) chamCongBangPhuongThuc1(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 4: {
                // Chấm công phương thức 2
                if (head != nullptr) chamCongBangPhuongThuc2(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 5: {
                // Tính giờ làm
                if (head != nullptr) tinhGioLam(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 6: {
                // Tính giờ nghỉ
                if (head != nullptr) tinhGioNghi(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 7: {
                // Tính lương
                if (head != nullptr) tinhLuong(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 8: {
                // Reset bảng chấm công
                if (head != nullptr) resetBangChamCong(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 9: {
                // Thưởng phạt nhân viên
                if (head != nullptr) thuongPhatNhanVien(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 10: {
                // Xuất bảng lương
                if (head != nullptr) xuatBangLuong(head);
                else cout << "Danh sách nhân viên trống.\n";
                break;
            }
            case 11: {
                // Lưu danh sách nhân viên vào file
                luuDanhSachNhanVien(head, "danh_sach_nhan_vien.txt");
                break;
            }
            case 12: {
                // Tải danh sách nhân viên từ file
                taiDanhSachNhanVien(head, tail, "danh_sach_nhan_vien.txt");
                break;
            }
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
                break;
        }
    } while (luaChon != 0);

    return 0;
}