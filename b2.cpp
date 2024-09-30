#include <bits/stdc++.h>

using namespace std;

class Fraction {
private:
    // Numer : tu so
    // Deno : mau so
    int Numer, Deno;
public:
    Fraction(int numer, int deno) {
        Numer = numer;
        Deno = deno;
    }

    void Input() {
        cout << "Nhap tu so va mau so : ";
        cin >> Numer >> Deno;
    }

    void Shorten() {
        int tmp = __gcd(Numer, Deno);
        Numer /= tmp;
        Deno /= tmp;
    }

    // Dinh nghia lai phep so sanh
    // a/b < c/d <=> a * d < b * c
    bool operator < (const Fraction& other) const {
        return (Numer * other.Deno < other.Numer * Deno);
    }

    void Prin() {
        cout << Numer << "/" << Deno;
    }
};

int main() {
    Fraction a(1,1), b(1, 1);
    a.Input(); b.Input();
    if (a < b) {
        b.Prin();
        cout << " la phan so lon hon";
    } else
        if (b < a) {
            a.Prin();
            cout << " la phan so lon hon";
        } else
            cout << "Hai phan so bang nhau";
    return 0;
}
