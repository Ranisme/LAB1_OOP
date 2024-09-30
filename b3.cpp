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
        int tmp = __gcd(abs(Numer), abs(Deno));
        Numer /= tmp;
        Deno /= tmp;
    }

    // Dinh nghia lai phep so sanh
    // a/b < c/d <=> a * d < b * c
    bool operator < (const Fraction& other) const {
        return (Numer * other.Deno < other.Numer * Deno);
    }

    Fraction operator + (const Fraction& other) const {
        return Fraction(Numer * other.Deno + other.Numer * Deno, Deno * other.Deno);
    }

    Fraction operator - (const Fraction& other) const {
        return Fraction(Numer * other.Deno - other.Numer * Deno, Deno * other.Deno);
    }

    Fraction operator * (const Fraction& other) const {
        return Fraction(Numer * other.Numer, Deno * other.Deno);
    }

    Fraction operator / (const Fraction& other) const {
        return Fraction(Numer * other.Deno, Deno * other.Numer);
    }

    void Prin() {
        cout << Numer << "/" << Deno << "\n";
    }
};

int main() {
    Fraction a(1,1), b(1, 1);
    a.Input(); b.Input();
    Fraction Plus = a + b;
    Fraction Minus = a - b;
    Fraction Times = a * b;
    Fraction Div = a / b;
    cout << " + : "; Plus.Shorten(); Plus.Prin();
    cout << " - : "; Minus.Shorten(); Minus.Prin();
    cout << " * : "; Times.Shorten(); Times.Prin();
    cout << " / : "; Div.Shorten(); Div.Prin();
    return 0;
}
