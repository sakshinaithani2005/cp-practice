#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    long long k;
    cin >> n >> k;

    unordered_map<long long, long long> cnt;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        long long rem = x % k;
        if (rem != 0) {
            cnt[k - rem]++;
        }
    }

    long long ans = 0;

    for (auto it : cnt) {
        long long need = it.first;
        long long freq = it.second;

        ans = max(ans, (freq - 1) * k + need + 1);
    }

    cout << ans << "\n";
}

int main() {
    

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}