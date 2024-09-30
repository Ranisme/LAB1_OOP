#include <bits/stdc++.h>

using namespace std;

const int Numday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Flight {
private:
    string Id;
    int Day, Month, Year;
    int Sec, Hour;
    string From;
    string To;
public:
    bool IdCheck();
    bool TimeCheck();
    bool DayCheck();
    bool PlaceCheck(string Place);
    void Input();
    void Prin();
    bool Find1(string tmp);
    bool Find2(string XuatPhat, int Ngay, int Thang, int Nam);
    bool Find3(string XuatPhat, string KetThuc);

    bool operator < (const Flight& a) const {
        if (Year != a.Year)
            return Year < a.Year;
        if (Month != a.Month)
            return Month < a.Month;
        if (Day != a.Day)
            return Day < a.Day;
        if (Hour != a.Hour)
            return Hour < a.Hour;
        if (Sec != a.Sec)
            return Sec < a.Sec;
        return From < a.From;
    }
};

bool Flight :: IdCheck() {
    if (Id.size() > 5)
        return false;
    for (char c : Id) {
        if (!isalnum(c))
            return false;
    }
    return true;
}

bool Flight :: PlaceCheck(string Place) {
    if (Place.size() > 20) {
        return false;
    }
    for (char c : Place) {
        if (!isalnum(c) && c != ' ')
            return false;
    }
    return true;
}

bool Flight :: DayCheck() {
    if (Day <= 0 || Month <= 0 || Year <= 0)
        return false;
    if (Month > 12)
        return false;
    if (Day > Numday[Month - 1])
        return false;
    return true;
}

bool Flight :: TimeCheck() {
    if (Sec < 0 || Hour < 0)
        return false;
    if (Sec > 59 || Hour > 23)
        return false;
    return true;
}

void Flight :: Input() {
    while (true) {
        cout << "Nhap ma chuyen bay : ";
        getline(cin, Id);
        if (IdCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap ngay bay theo dinh dang ngay _ thang _ nam : ";
        cin >> Day >> Month >> Year;
        if (DayCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap gio bay theo dinh dang gio _ phut : ";
        cin >> Hour >> Sec;
        if (TimeCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    cin.ignore();

    while (true) {
        cout << "Nhap diem cat cach : ";
        getline(cin, From);
        if (PlaceCheck(From))
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap diem ha canh : ";
        getline(cin, To);
        if (PlaceCheck(To))
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }
}

void Flight :: Prin() {
    cout << "Chuyen bay " << Id << " khoi hanh vao luc " << Day << "-" << Month << "-" << Year << " " << Hour << ":" << Sec << " di tu "
    << From << " den " << To << "\n";
}

bool Flight :: Find1(string tmp) {
    return (tmp == Id);
}

bool Flight :: Find2(string XuatPhat, int Ngay, int Thang, int Nam) {
    return ((XuatPhat == From && Ngay == Day) && (Thang == Month && Year == Nam));
}

bool Flight :: Find3(string XuatPhat, string KetThuc) {
    return (XuatPhat == From && KetThuc == To);
}

int main() {

    int n;
    cout << "Nhap so luong chuyen bay : ";
    cin >> n; cin.ignore();
    Flight Plane[n];
    for (int i = 0; i < n; i++) {
        cout << "\n";
        Plane[i].Input();
    }

    cout << '\n';
    cout << "Cac chuyen bay sau khi sap xep theo gio khoi hanh la : \n";
    sort(Plane + 0, Plane + 0 + n);
    for (int i = 0; i < n; i++) {
        Plane[i].Prin();
    }

    cout << "\n";
    cout << "Chon hinh thuc kiem tra : \n";
    cout << "1 Nhap vao ma chuyen bay de kiem tra \n";
    cout << "2 Nhap vao diem xuat phat va ngay bay \n";
    cout << "3 Dem so luong chuyen bay tu diem xuat phat va diem ket thuc \n";
    int type;
    cin >> type;

    if (type == 1) {
        cout << "Moi nhap ma chuyen bay : ";
        string st; bool ok = false;
        cin >> st;

        for (Flight cur : Plane) {
            if (cur.Find1(st))
            {
                ok = true;
                cur.Prin();
            }
        }
        if (!ok)
            cout << "Chuyen bay khong ton tai";
    }

    if (type == 2) {
        string XuatPhat;
        int Ngay, Thang, Nam;
        cout << "Moi nhap diem xuat phat :";
        cin.ignore();
        getline(cin, XuatPhat);
        cout << "Nhap ngay bay theo dinh dang ngay _ thang _ nam : ";
        cin >> Ngay >> Thang >> Nam;

        vector <Flight> ans;
        for (Flight cur : Plane)
            if (cur.Find2(XuatPhat, Ngay, Thang, Nam))
                ans.push_back(cur);
        cout << "Co " << ans.size() << " chuyen bay duoc tim thay, sau day la danh sach : \n";
        for (Flight cur : ans)
            cur.Prin();
    }

    if (type == 3) {
        string XuatPhat, KetThuc;
        cout << "Moi nhap diem xuat phat :";
        cin.ignore();
        getline(cin, XuatPhat);
        cout << "Moi nhap diem den :";
        getline(cin, KetThuc);

        int ans = 0;
        for (Flight cur : Plane)
            if (cur.Find3(XuatPhat, KetThuc))
                ans++;
        cout << "Co " << ans << " chuyen bay khop voi thong tin tim kiem : \n";
    }
    return 0;
}
