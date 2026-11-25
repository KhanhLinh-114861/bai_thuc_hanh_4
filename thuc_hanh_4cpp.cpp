#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;
int nhapSoNguyen(const string& thongBao, int thapNhat, int caoNhat) {
    int giaTri;
    while (true) {
        cout << thongBao;
        cin >> giaTri;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap sai! Vui long nhap so nguyen!\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (giaTri >= thapNhat && giaTri <= caoNhat)
            return giaTri;
        cout << "Gia tri phai tu " << thapNhat
             << " den " << caoNhat << "!\n";
    }
}
char nhapKichThuoc() {
    string chuoi;
    while (true) {
        cout << "Kich thuoc bai (S/M/L): ";
        cin >> chuoi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (chuoi.size() == 1) {
            char kyTu = toupper(chuoi[0]);
            if (kyTu == 'S' || kyTu == 'M' || kyTu == 'L')
                return kyTu;
        }
        cout << "Chi nhap S, M hoac L!\n";
    }
}
string chuanHoaLoaiXe(string chuoi) {
    for (int i = 0; i < (int)chuoi.size(); i++)
        chuoi[i] = tolower(chuoi[i]);

    if (chuoi == "car") return "Car";
    if (chuoi == "motorcycle") return "Motorcycle";
    if (chuoi == "bicycle") return "Bicycle";
    return "";
}
string nhapLoaiXe() {
    string nhapVao, ketQua;
    while (true) {
        cout << "Loai xe (Car/Motorcycle/Bicycle): ";
        cin >> nhapVao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        ketQua = chuanHoaLoaiXe(nhapVao);
        if (ketQua != "")
            return ketQua;

        cout << "Loai xe khong hop le!\n";
    }
}
class Vehicle {
protected:
    int maXe;
    int gioVao;
    int thoiLuongDo;

public:
    Vehicle(int id, int entry, int duration) {
        maXe = id;
        gioVao = entry;
        thoiLuongDo = duration;
    }

    virtual ~Vehicle() {}

    int getMaXe() const { return maXe; }

    virtual double tinhPhiDoXe() const = 0;
    virtual void hienThi() const = 0;
    virtual string getLoaiXe() const = 0;
    virtual Vehicle* saoChep() const = 0;
};
class Car : public Vehicle {
private:
    int soChoNgoi;
public:
    Car(int id, int entry, int duration, int seats)
        : Vehicle(id, entry, duration) {
        soChoNgoi = seats;
    }
    double tinhPhiDoXe() const override {
        double mucGia = 6.0;
        double tongTien = 0;
        bool gioCaoDiem =
            (gioVao >= 6 && gioVao <= 9) ||
            (gioVao >= 15 && gioVao <= 18);

        for (int h = 0; h < thoiLuongDo; h++) {
            if (h < 2) {
                if (gioCaoDiem) tongTien += mucGia * 1.30;
                else tongTien += mucGia * 0.95;
            } else {
                tongTien += mucGia * 0.90;
            }
        }
        return tongTien;
    }

    void hienThi() const override {
        cout << "Ma xe: " << maXe << " | Car"
             << " | Gio vao: " << gioVao << "h"
             << " | Thoi luong: " << thoiLuongDo << "h"
             << " | So cho: " << soChoNgoi
             << " | Phi: $" << fixed << setprecision(2)
             << tinhPhiDoXe() << "\n";
    }

    string getLoaiXe() const override { return "Car"; }

    Vehicle* saoChep() const override {
        return new Car(*this);
    }
};

class Motorcycle : public Vehicle {
private:
    int dungTich;

public:
    Motorcycle(int id, int entry, int duration, int cc)
        : Vehicle(id, entry, duration) {
        dungTich = cc;
    }

    double tinhPhiDoXe() const override {
        double mucGia = 4.0;
        double tongTien = 0;
        bool gioCaoDiem =
            (gioVao >= 6 && gioVao <= 9) ||
            (gioVao >= 15 && gioVao <= 18);

        for (int h = 0; h < thoiLuongDo; h++) {
            if (h < 2) {
                if (gioCaoDiem) tongTien += mucGia * 1.30;
                else tongTien += mucGia * 0.95;
            } else {
                tongTien += mucGia * 0.90;
            }
        }
        return tongTien;
    }

    void hienThi() const override {
        cout << "Ma xe: " << maXe << " | Motorcycle"
             << " | Gio vao: " << gioVao << "h"
             << " | Thoi luong: " << thoiLuongDo << "h"
             << " | Dung tich: " << dungTich << "cc"
             << " | Phi: $" << fixed << setprecision(2)
             << tinhPhiDoXe() << "\n";
    }

    string getLoaiXe() const override { return "Motorcycle"; }

    Vehicle* saoChep() const override {
        return new Motorcycle(*this);
    }
};

class Bicycle : public Vehicle {
private:
    bool xeDien;

public:
    Bicycle(int id, int entry, int duration, bool electric)
        : Vehicle(id, entry, duration) {
        xeDien = electric;
    }

    double tinhPhiDoXe() const override {
        double mucGia = 2.0;
        double tongTien = 0;
        bool gioCaoDiem =
            (gioVao >= 6 && gioVao <= 9) ||
            (gioVao >= 15 && gioVao <= 18);

        for (int h = 0; h < thoiLuongDo; h++) {
            if (h < 2) {
                if (gioCaoDiem) tongTien += mucGia * 1.30;
                else tongTien += mucGia * 0.95;
            } else {
                tongTien += mucGia * 0.90;
            }
        }
        return tongTien;
    }

    void hienThi() const override {
        cout << "Ma xe: " << maXe << " | Bicycle"
             << " | Gio vao: " << gioVao << "h"
             << " | Thoi luong: " << thoiLuongDo << "h"
             << " | Xe dien: " << (xeDien ? "Co" : "Khong")
             << " | Phi: $" << fixed << setprecision(2)
             << tinhPhiDoXe() << "\n";
    }

    string getLoaiXe() const override { return "Bicycle"; }

    Vehicle* saoChep() const override {
        return new Bicycle(*this);
    }
};

class ParkingLot {
private:
    int maBaiDo;
    char kichThuocBai;
    int sucChua;
    int soLuongXeHienTai;
    Vehicle** danhSachXe;

    void thayDoiKichCo(int sucChuaMoi) {
        Vehicle** mangMoi = new Vehicle*[sucChuaMoi];

        for (int i = 0; i < sucChuaMoi; i++)
            mangMoi[i] = nullptr;

        for (int i = 0; i < soLuongXeHienTai; i++)
            mangMoi[i] = danhSachXe[i];

        delete[] danhSachXe;
        danhSachXe = mangMoi;
        sucChua = sucChuaMoi;
    }

public:
    ParkingLot() {
        maBaiDo = 0;
        kichThuocBai = 'S';
        sucChua = 1;
        soLuongXeHienTai = 0;
        danhSachXe = new Vehicle*[sucChua];
        danhSachXe[0] = nullptr;
    }

    ParkingLot(int id, char sz) {
        maBaiDo = id;
        kichThuocBai = sz;
        soLuongXeHienTai = 0;
        sucChua = (sz == 'S') ? 1 : (sz == 'M') ? 2 : 3;
        danhSachXe = new Vehicle*[sucChua];

        for (int i = 0; i < sucChua; i++)
            danhSachXe[i] = nullptr;
    }

    ParkingLot(const ParkingLot& other) {
        maBaiDo = other.maBaiDo;
        kichThuocBai = other.kichThuocBai;
        sucChua = other.sucChua;
        soLuongXeHienTai = other.soLuongXeHienTai;
        danhSachXe = new Vehicle*[sucChua];

        for (int i = 0; i < sucChua; i++)
            danhSachXe[i] = nullptr;

        for (int i = 0; i < soLuongXeHienTai; i++)
            danhSachXe[i] = other.danhSachXe[i]->saoChep();
    }

    ParkingLot& operator=(const ParkingLot& other) {
        if (this == &other)
            return *this;

        for (int i = 0; i < soLuongXeHienTai; i++)
            delete danhSachXe[i];
        delete[] danhSachXe;

        maBaiDo = other.maBaiDo;
        kichThuocBai = other.kichThuocBai;
        sucChua = other.sucChua;
        soLuongXeHienTai = other.soLuongXeHienTai;
        danhSachXe = new Vehicle*[sucChua];

        for (int i = 0; i < sucChua; i++)
            danhSachXe[i] = nullptr;

        for (int i = 0; i < soLuongXeHienTai; i++)
            danhSachXe[i] = other.danhSachXe[i]->saoChep();

        return *this;
    }

    ~ParkingLot() {
        for (int i = 0; i < soLuongXeHienTai; i++)
            delete danhSachXe[i];
        delete[] danhSachXe;
    }

    int getMaBaiDo() const { return maBaiDo; }
    int getSucChua() const { return sucChua; }
    int getSoLuongXeHienTai() const { return soLuongXeHienTai; }

    Vehicle* getXeTaiViTri(int index) const {
        return danhSachXe[index];
    }

    bool laBaiDay() const {
        return soLuongXeHienTai >= sucChua;
    }

    bool themXe(Vehicle* v) {
        if (laBaiDay())
            thayDoiKichCo(sucChua * 2);

        danhSachXe[soLuongXeHienTai] = v;
        soLuongXeHienTai++;
        return true;
    }

    int timViTriXe(int maXeCanTim) const {
        for (int i = 0; i < soLuongXeHienTai; i++) {
            if (danhSachXe[i]->getMaXe() == maXeCanTim)
                return i;
        }
        return -1;
    }

    bool xoaXe(int maXeCanXoa) {
        int viTri = timViTriXe(maXeCanXoa);
        if (viTri == -1)
            return false;

        delete danhSachXe[viTri];

        for (int i = viTri; i < soLuongXeHienTai - 1; i++)
            danhSachXe[i] = danhSachXe[i + 1];

        soLuongXeHienTai--;
        danhSachXe[soLuongXeHienTai] = nullptr;
        return true;
    }

    void hienThiThongTinBai() const {
        cout << "Bai do " << maBaiDo << " [" << kichThuocBai << "] "
             << soLuongXeHienTai << "/" << sucChua << " xe\n";

        for (int i = 0; i < soLuongXeHienTai; i++)
            danhSachXe[i]->hienThi();
    }
};

class SystemInterface {
private:
    static const int MAX_BAI_DO = 10;
    ParkingLot danhSachBaiDo[MAX_BAI_DO];
    int soLuongBaiDoHienTai;

    int timViTriBaiDo(int pID) const {
        for (int i = 0; i < soLuongBaiDoHienTai; i++) {
            if (danhSachBaiDo[i].getMaBaiDo() == pID)
                return i;
        }
        return -1;
    }

    bool kiemTraTonTaiMaBai(int pID) const {
        return timViTriBaiDo(pID) != -1;
    }

    bool kiemTraTonTaiMaXe(int vID) const {
        for (int i = 0; i < soLuongBaiDoHienTai; i++) {
            if (danhSachBaiDo[i].timViTriXe(vID) != -1)
                return true;
        }
        return false;
    }

    int taoMaNgauNhien() {
        return 1000 + rand() % 9000;
    }

public:
    SystemInterface() {
        soLuongBaiDoHienTai = 0;
    }

    void chayMenu() {
        while (true) {
            cout << "\n===== QUAN LY BAI DO XE =====\n";
            cout << "1. Tao bai do xe moi\n";
            cout << "2. Them xe vao bai do\n";
            cout << "3. Xoa mot bai do xe\n";
            cout << "4. Lay xe ra khoi bai do\n";
            cout << "5. Hien thi tat ca bai do xe\n";
            cout << "6. Hien thi xe theo bai cu the\n";
            cout << "7. Liet ke xe theo loai phuong tien\n";
            cout << "8. Tom tat phi do xe trung binh\n";
            cout << "9. Thoat chuong trinh\n";

            int luaChon = nhapSoNguyen("Lua chon cua ban (1-9): ", 1, 9);

            switch (luaChon) {
            case 1: {
                if (soLuongBaiDoHienTai >= MAX_BAI_DO) {
                    cout << "He thong da dat toi da so bai do!\n";
                    break;
                }

                int maBai = nhapSoNguyen("Nhap ma bai: ", 1, 999999);
                char kichThuoc = nhapKichThuoc();

                if (kiemTraTonTaiMaBai(maBai)) {
                    cout << "Ma bai da ton tai, he thong tao ma moi.\n";
                    do {
                        maBai = taoMaNgauNhien();
                    } while (kiemTraTonTaiMaBai(maBai));
                    cout << "Ma bai moi: " << maBai << "\n";
                }

                danhSachBaiDo[soLuongBaiDoHienTai] = ParkingLot(maBai, kichThuoc);
                soLuongBaiDoHienTai++;
                cout << "Tao bai do thanh cong!\n";
                break;
            }

            case 2: {
                if (soLuongBaiDoHienTai == 0) {
                    cout << "Chua co bai do nao!\n";
                    break;
                }

                int maXe = nhapSoNguyen("Nhap ma xe: ", 1, 999999);
                if (kiemTraTonTaiMaXe(maXe)) {
                    cout << "Ma xe da ton tai, he thong tao ma moi.\n";
                    do {
                        maXe = taoMaNgauNhien();
                    } while (kiemTraTonTaiMaXe(maXe));
                    cout << "Ma xe moi: " << maXe << "\n";
                }

                string loaiXe = nhapLoaiXe();
                int gioVao = nhapSoNguyen("Nhap gio vao (0-23): ", 0, 23);
                int thoiLuong = nhapSoNguyen("Nhap thoi luong do (1-23): ", 1, 23);

                Vehicle* v = nullptr;

                if (loaiXe == "Car") {
                    int soCho = nhapSoNguyen("Nhap so cho ngoi: ", 2, 50);
                    v = new Car(maXe, gioVao, thoiLuong, soCho);
                } else if (loaiXe == "Motorcycle") {
                    int cc = nhapSoNguyen("Nhap dung tich xe (cc): ", 50, 2000);
                    v = new Motorcycle(maXe, gioVao, thoiLuong, cc);
                } else {
                    int dien = nhapSoNguyen("Xe dien (1: Co, 0: Khong): ", 0, 1);
                    v = new Bicycle(maXe, gioVao, thoiLuong, dien == 1);
                }
                bool daDatCho = false;
                for (int i = 0; i < soLuongBaiDoHienTai && !daDatCho; i++) {
                    if (!danhSachBaiDo[i].laBaiDay()) {
                        danhSachBaiDo[i].themXe(v);
                        daDatCho = true;
                        cout << "Da them xe vao bai "
                             << danhSachBaiDo[i].getMaBaiDo()
                             << " | Phi: $" << fixed << setprecision(2)
                             << v->tinhPhiDoXe() << "\n";
                    }
                }
                if (!daDatCho) {
                    danhSachBaiDo[0].themXe(v);
                    cout << "Tat ca cac bai da day, da mo rong bai "
                         << danhSachBaiDo[0].getMaBaiDo()
                         << " | Phi: $" << fixed << setprecision(2)
                         << v->tinhPhiDoXe() << "\n";
                }
                break;
            }
            case 3: {
                int maBai = nhapSoNguyen("Nhap ma bai can xoa: ", 1, 999999);
                int idx = timViTriBaiDo(maBai);
                if (idx == -1) {
                    cout << "Khong tim thay bai do!\n";
                    break;
                }
                for (int i = idx; i < soLuongBaiDoHienTai - 1; i++)
                    danhSachBaiDo[i] = danhSachBaiDo[i + 1];

                danhSachBaiDo[soLuongBaiDoHienTai - 1] = ParkingLot();
                soLuongBaiDoHienTai--;
                cout << "Da xoa bai do!\n";
                break;
            }
            case 4: {
                int maXe = nhapSoNguyen("Nhap ma xe can lay ra: ", 1, 999999);
                bool daXoa = false;
                for (int i = 0; i < soLuongBaiDoHienTai && !daXoa; i++)
                    daXoa = danhSachBaiDo[i].xoaXe(maXe);
                if (daXoa) cout << "Da lay xe ra khoi bai!\n";
                else cout << "Khong tim thay xe!\n";
                break;
            }

            case 5: {
                if (soLuongBaiDoHienTai == 0)
                    cout << "Chua co bai do nao!\n";

                for (int i = 0; i < soLuongBaiDoHienTai; i++)
                    danhSachBaiDo[i].hienThiThongTinBai();
                break;
            }
            case 6: {
                int maBai = nhapSoNguyen("Nhap ma bai can xem: ", 1, 999999);
                int idx = timViTriBaiDo(maBai);

                if (idx == -1) cout << "Khong tim thay bai do!\n";
                else danhSachBaiDo[idx].hienThiThongTinBai();
                break;
            }
            case 7: {
                string loaiXe = nhapLoaiXe();
                bool timThay = false;
                for (int i = 0; i < soLuongBaiDoHienTai; i++) {
                    for (int j = 0; j < danhSachBaiDo[i].getSoLuongXeHienTai(); j++) {
                        Vehicle* v = danhSachBaiDo[i].getXeTaiViTri(j);
                        if (v->getLoaiXe() == loaiXe) {
                            cout << "Bai " << danhSachBaiDo[i].getMaBaiDo() << ": ";
                            v->hienThi();
                            timThay = true;
                        }
                    }
                }
                if (!timThay)
                    cout << "Khong co xe thuoc loai nay!\n";
                break;
            }
            case 8: {
                string danhSachLoai[3] = {"Car", "Motorcycle", "Bicycle"};
                cout << "--- TONG KET TOAN HE THONG ---\n";

                for (int t = 0; t < 3; t++) {
                    int dem = 0;
                    double tongTien = 0;
                    for (int i = 0; i < soLuongBaiDoHienTai; i++) {
                        for (int j = 0; j < danhSachBaiDo[i].getSoLuongXeHienTai(); j++) {
                            Vehicle* v = danhSachBaiDo[i].getXeTaiViTri(j);
                            if (v->getLoaiXe() == danhSachLoai[t]) {
                                dem++;
                                tongTien += v->tinhPhiDoXe();
                            }
                        }
                    }
                    cout << danhSachLoai[t] << ": ";
                    if (dem == 0)
                        cout << "Khong co xe\n";
                    else
                        cout << dem << " xe | Trung binh: $"
                             << fixed << setprecision(2) << tongTien / dem << "\n";
                }
                break;
            }
            case 9:
                cout << "Cam on ban da su dung chuong trinh. Tam biet!\n";
                return;
            }
        }
    }
};
int main() {
    srand((unsigned)time(NULL));
    SystemInterface heThong;
    heThong.chayMenu();
    return 0;
}
