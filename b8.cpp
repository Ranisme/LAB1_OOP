#include <bits/stdc++.h>

using namespace std;

const int Numday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class SaveMoney {
private:
    string Id;
    string Type;
    string Name;
    string CMND;
    int Day, Month, Year;
    double Money;
public:
    bool IdCheck();
    bool TypeCheck();
    bool NameCheck();
    bool CMNDCheck();
    bool DayCheck();
    bool MoneyCheck();
    void Input();
    void Prin();
    bool Find(string st);
    bool operator < (const SaveMoney& a) const {
        return Money < a.Money;
    }
};

bool SaveMoney :: IdCheck() {
    if (Id.size() > 5)
        return false;
    for (char c : Id) {
        if (!isalnum(c))
            return false;
    }
    return true;
}

bool SaveMoney :: TypeCheck() {
    return (Type.size() <= 10);
}

bool SaveMoney :: NameCheck() {
    if (Name.size() > 30) {
        return false;
    }
    for (char c : Name) {
        if (!isalnum(c) && c != ' ')
            return false;
    }
    return true;
}

bool SaveMoney :: CMNDCheck() {
    if (CMND.size() != 9 && CMND.size() != 12)
        return false;
    for (char c : CMND) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool SaveMoney :: DayCheck() {
    if (Day <= 0 || Month <= 0 || Year <= 0)
        return false;
    if (Month > 12)
        return false;
    if (Day > Numday[Month - 1])
        return false;
    return true;
}

bool SaveMoney :: MoneyCheck() {
    return (Money >= 0);
}


void SaveMoney :: Input() {
    while (true) {
        cout << "Nhap ma so : ";
        getline(cin, Id);
        if (IdCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap loai tiet kiem : ";
        getline(cin, Type);
        if (TypeCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap ten khach hang : ";
        getline(cin, Name);
        if (NameCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap chung minh nhan dan : ";
        getline(cin, CMND);
        if (CMNDCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap ngay _ thang _ nam ";
        cin >> Day >> Month >> Year;
        if (DayCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }

    while (true) {
        cout << "Nhap so tien gui : ";
        cin >> Money;
        if (MoneyCheck())
            break;
        else
            cout << "Khong hop le yeu cau nhap lai \n";
    }
}

void SaveMoney :: Prin() {
    cout << "Khach hang " << Name << ", so chung minh nhan dan " << CMND << ", ma so tiet kiem " << Id << ", loai tiet kiem " << Type << ", gui vao ngay " << Day
    << "/" << Month << "/" << Year << " voi so tien la : " << Money << " d\n";
}

bool SaveMoney :: Find(string st)
{
    return (st == Id || st == CMND);
}

int main() {
    int n;
    cout << "Nhap so luong khach hang : ";
    cin >> n;
    SaveMoney p[n];
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        p[i].Input();
    }

    sort(p + 0, p + 0 + n);
    cout << "Danh sach khach hang sau khi da sap xep theo so tien : \n";
    for (int i = n - 1; i >= 0; i--)
        p[i].Prin();

    cout << "Nhap so chung minh nhan dan hoac ma so tiet kiem ban muon tim kiem :\n";
    string st; cin >> st;
    for (auto cur : p)
        if (cur.Find(st))
        {
            cout << "Day la khach hang ban can tim \n";
            cur.Prin();
            return 0;
        }
    cout << "Khong tim thay khach hang trung khop";
    return 0;
}

