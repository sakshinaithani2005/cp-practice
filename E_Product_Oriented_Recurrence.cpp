#include<bits/stdc++.h>
using namespace std;

/**
 * Author: sakshi (https://github.com/raogaurav17/)
 */


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
int rootn;
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
struct q{
    int indx, l , r, ans ;
} ;

int f(int n, int c , int f1, int f2, int f3){
    if(n==1) return f1;
    if(n==2) return f2 ;
    if(n==3 ) return f3 ;
    return pow(c, ((2*n)-6)) * f(n-1, c, f1, f2, f3)*f(n-2, c, f1, f2, f3)*f(n-3, c, f1, f2,f3);
}
void solve() {
    
    int   n, f1, f2, f3, c;
    cin>>n>>f1>>f2>>f3>>c;
    
    cout<<f(n,c, f1, f2, f3)<<endl;

   
    return ;
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}