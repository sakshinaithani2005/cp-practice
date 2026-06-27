#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n == 1) {
        cout << 1 << " " << 1 << "\n";
        cout << -a[1] << "\n";

        cout << 1 << " " << 1 << "\n";
        cout << 0 << "\n";

        cout << 1 << " " << 1 << "\n";
        cout << 0 << "\n";
        return 0;
    }

   
    cout << 1 << " " << n - 1 << "\n";
    for (int i = 1; i < n; i++) {
        long long rem = ((a[i] % n) + n) % n;
        long long add = rem * (n - 1);
        cout << add << " ";
        a[i] += add;
    }
    cout << "\n";


    cout << n << " " << n << "\n";
    cout << -a[n] << "\n";
    a[n] = 0;


    cout << 1 << " " << n << "\n";
    for (int i = 1; i < n; i++) {
        cout << -a[i] << " ";
    }
    cout << 0 << "\n";

    return 0;
}