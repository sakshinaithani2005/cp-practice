#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;


    vector<long long> A(n);
    vector<long long > B(n);
   long long finish = 0;

for(int i = 0; i < n; i++) {
    long long A, B;
    cin >> A >> B;

    long long start = max(finish, A);
    finish = start + B;
}

cout << finish;
    


    

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) solve();
    return 0;
}