#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<char> win(n + 2, 0); 
    int badInWindow = 0;

    for (int v = n; v >= 1; --v) {
        
        if (v + 1 <= n && cnt[v + 1] > 0 && !win[v + 1]) badInWindow++;
        if (v + k + 1 <= n && cnt[v + k + 1] > 0 && !win[v + k + 1]) badInWindow--;

        if (cnt[v] == 0) continue;

        int remainingSame = cnt[v] - 1; 
        if (badInWindow > 0) {
            win[v] = 1; 
        } else {
            win[v] = (remainingSame % 2 == 1); 
        }
    }

    bool ok = false;
    for (int v = 1; v <= n; ++v) {
        if (cnt[v] > 0 && !win[v]) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}