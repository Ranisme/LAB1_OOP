#include <bits/stdc++.h>

using namespace std;

// Voi mot thuat toan don gian de hieu la O(n ^ 2)
// Nen chi lam viec voi mang < 10000

class Array {
private:
    int N;
    vector <int> Arr;
public:
    Array(int n, vector <int>&arr) {
        N = n;
        Arr = arr;
    }

    // Input : mang tmp
    // Output : vector vi tri xuat hien cua tmp trong mang cha
    vector <int> Find_In(Array& tmp) {
        vector <int> ans;
        for (int i = 0; i + tmp.N - 1 < N; i++) {
            bool check = true;
            for (int j = 0; j < tmp.N; j++)
                if (tmp.Arr[j] != Arr[i + j]) {
                    check = false;
                    break;
                }
            if (check)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    int n1, n2;
    vector <int> a, b;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++) {
        int cur;
        cin >> cur;
        a.push_back(cur);
    }
    for (int i = 0; i < n2; i++) {
        int cur;
        cin >> cur;
        b.push_back(cur);
    }

    Array A(n1, a); Array B(n2, b);

    vector <int> ans = B.Find_In(A);
    cout << ans.size() << "\n";
    for (auto cur : ans)
        cout << cur << " ";
    return 0;
}
