// de bai khong de cap nen xin phep khong lam nam nhuan
// de nghi khong nhap so nam la 1
#include <bits/stdc++.h>

using namespace std;

const int Numday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class ToDay {
private:
    int Day, Month, Year;
public:
    ToDay(int day, int month, int year) {
        Day = day;
        Month = month;
        Year = year;
    }

    void InputData() {
        cout << "Nhap vao ngay : ";
        cin >> Day;
        cout << "Nhap vao thang : ";
        cin >> Month;
        cout << "Nhap vao nam : ";
        cin >> Year;
    }

    static ToDay NextDay(ToDay other) {
        other.Day++;
        if (other.Day > Numday[other.Month - 1]) {
            other.Day = 1;
            other.Month++;
            if (other.Month == 13) {
                other.Month = 1;
                other.Year++;
            }
        }
        return other;
    }

    static ToDay LastDay(ToDay other) {
        other.Day--;
        if (other.Day <= 0) {
            other.Month--;
            if (other.Month <= 0) {
                other.Month = 12;
                other.Year--;
            }
            other.Day = Numday[other.Month - 1];
        }
        return other;
    }

    int CountDay() {
        int ans = 0;
        for (int i = 0; i < Month - 1; i++) {
            ans = ans + Numday[i];
        }
        ans = ans + Day;
        return ans;
    }

    void Prin() {
        cout << Day << "/" << Month << "/" << Year << "\n";
    }
};

int main() {
    ToDay CurDay(0, 0, 0);
    CurDay.InputData();

    ToDay a = ToDay::NextDay(CurDay);
    a.Prin();

    ToDay b = ToDay::LastDay(CurDay);
    b.Prin();

    int Cnt = CurDay.CountDay();
    cout << Cnt;

    return 0;
}
