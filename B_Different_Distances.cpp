#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 2) {
            cout << "1 2 2 1 2 1 1 2\n";
            continue;
        }

        if (n == 3) {
            cout << "1 2 3 2 3 1 1 2 3 1 2 3\n";
            continue;
        }

        vector<int> shifts = {0, 1, 3, 6};

        bool first = true;

        for (int r = 0; r < 4; r++) {
            for (int i = 0; i < n; i++) {
                if (!first) cout << ' ';
                first = false;

                cout << ((i + shifts[r]) % n) + 1;
            }
        }

        cout << '\n';
    }

    return 0;
}