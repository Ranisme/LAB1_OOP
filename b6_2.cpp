#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string Name;
    double Math, Lir, Eng, Avg;
public:

    // Kiem tra xem co chua cac ki tu khong phai chu cai hay khong
    bool NameCheck(string&Tmp) {
        if (Tmp == "")
            return false;
        for (char cur : Tmp) {
            if (cur == ' ')
                continue;
            if (!('a' <= cur && cur <= 'z') && !('A' <= cur && cur <= 'Z'))
                return false;
        }
        return true;
    }

    // Kiem tra diem hop le
    bool CheckPoint(double val) {
        if (val < 0  || 10 < val)
            return false;
        return true;
    }

    void GetPoint(double&val) {
        while (true) {
            cin >> val;
            if (CheckPoint(val))
                break;
            else
                cout << "Khong hop le yeu cau nhap lai \n";
        }
    }

    void GetAvg() {
        Avg = (Math * 2 + Lir + Eng) / 4;
    }

    // ham phan loai hoc sinh
    void Type() {
        cout << setprecision(2) << fixed;
        cout << "Hoc sinh : " << Name << " diem trung binh " << Avg << " xep loai : ";
        if (Avg < 5)
            cout << "Yeu";
        else
            if (Avg < 6.5)
                cout << "Trung Binh";
            else
                if (Avg < 8)
                    cout << "Kha";
                else
                    if (Avg < 9)
                        cout << "Gioi";
                    else
                        cout << "Xuat sac";
        cout << "\n";
    }

    // ham tra ve hoc sinh co diem trung binh cao hon
    static Student BetterAvg(Student a, Student b) {
        if (a.Avg >= b.Avg)
            return a;
        else
            return b;
    }

    // ham so sanh dua tren diem toan
    bool operator < (const Student& a) const {
        return (Math < a.Math);
    }

    bool SameMath(Student a) {
        return (Math == a.Math);
    }

    // xuat ra hoc sinh co diem trung binh cao nhat
    void TheBest() {
        cout << "Hoc sinh co diem cao nhat la : " << Name << "\n";
    }

    bool Ok(string tmp) {
        string cur = Name;
        for (char&c : cur)
            c = toupper(c);
        for (char&c : tmp)
            c = toupper(c);
        if (cur.find(tmp) != -1)
            return true;
        else
            return false;
    }

    void Prin() {
        cout << Name << " diem trung binh : " << Avg << "; diem toan : " << Math << '\n';
    }


    void Input() {
        while (true) {
            cout << "Nhap ten hoc sinh : ";
            getline(cin, Name);
            if (NameCheck(Name))
                break;
            else
                cout << "Khong hop le yeu cau nhap lai \n";
        }
        cout << "Nhap diem toan : ";
        GetPoint(Math);
        cout << "Nhap diem van : ";
        GetPoint(Lir);
        cout << "Nhap diem ngoai ngu : ";
        GetPoint(Eng);
        cin.ignore();
        GetAvg();
    }
};

int main() {
    int n = 3;
    Student a[n];
    for (int i = 0; i < n; i++)
        a[i].Input();

    for (int i = 0; i < n; i++)
        a[i].Type();

    Student Best = a[0];
    for (int i = 0; i < n; i++)
        Best = Student::BetterAvg(Best, a[i]);
    Best.TheBest();

    cout << "Danh sach hoc sinh co diem toan thap :" << "\n";
    sort(a + 0, a + 0 + n);
    for (int i = 0; i < n; i++)
        if (a[i].SameMath(a[0]))
            a[i].Prin();

    string s;
    cout << "Hoc sinh ban muon tim kiem la : ";
    getline(cin, s);
    cout << "Ket qua tim kiem : ";
    for (int i = 0; i < n; i++)
        if (a[i].Ok(s))
            a[i].Prin();
    return 0;
}
