#include <bits/stdc++.h>

using namespace std;

// Input : n; Output : n!
long long Factorial(int n) {
    long long ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * i;
    return ans;
}

// Input (a, b); Output : a ^ b
long long POW(long long a, long long b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    long long tmp = POW(a, b / 2);
    if (b % 2)
        return tmp * tmp % a;
    else
        return tmp * tmp;
}

// Input : x; Output : sin(x)
double Sin(int x) {
    double ans = 0, n = 0;
    while (true) {
        double cur = POW(-1, n) * POW(x, 2 * n + 1) / Factorial(2 * n + 1);
        ans = ans + cur;
        if (cur < 0.00001)
            break;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << setprecision(5) << fixed;
    cout << sin(n);
    return 0;
}
