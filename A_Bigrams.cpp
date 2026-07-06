#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;



#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif

// Vector I/O
template<typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }
template<typename T>
void print(const vector<T>& v) { for (auto& x : v) cout << x << " "; cout << endl; }

// Modular Arithmetic
const int MOD = 1e9 + 7;
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    // Logic goes here
    int  k;
    cin>>k ;
    int fl=0;
    int f1=0;
    int f2=0;
    for(int i=0; i<k ; i++){

        int x ; 
        cin>>x;
        if(x>=3) fl=1;
        else if(x>=2 && f1!=1) f1=1;
        else if(x>=2 && f1==1) f2=1;
    }
    if(fl==1 || (f1==1 && f2==1 )) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    
    
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}