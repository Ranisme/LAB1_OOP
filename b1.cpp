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

    void Prin() {
        cout << Numer << "/" << Deno;
    }
};

int main() {
    Fraction a(1,1);
    a.Input();
    a.Shorten();
    a.Prin();
    return 0;
}
