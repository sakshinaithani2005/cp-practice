#include<bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

bool valid(int x, int y, vector<pair<int,int>>& arr) {

    for(auto &[a,b] : arr) {

        // pair covered
        if(a == x || b == x || a == y || b == y)
            continue;

        return false;
    }

    return true;
}

bool check(int x, vector<pair<int,int>>& arr) {

    int a = -1, b = -1;

    // first pair not containing x
    for(auto &[u,v] : arr) {

        if(u == x || v == x)
            continue;

        a = u;
        b = v;
        break;
    }

    // all pairs already covered by x
    if(a == -1)
        return true;

    return valid(x, a, arr) || valid(x, b, arr);
}

void solve() {

    int m, n;
    cin >> m >> n;

    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    int a = arr[0].first;
    int b = arr[0].second;

    if(check(a, arr) || check(b, arr))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    fast_io;
    solve();
}