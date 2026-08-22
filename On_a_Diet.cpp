#include<bits/stdc++.h>
using namespace std;

/**
 * Author: Sakshi (https://github.com/raogaurav17/)
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



void solve() {
    long long  n, m , k  ;
    cin>>n>>m>>k;
    vector<pair<long long , bool>>  p(n);
    for(int i=0; i<n ; i++){
        cin>>p[i].first;
        p[i].second=0;
    }
    long long sum=0;
    for(int i=0; i<m ; i++){
        if(sum+p[i].first<=k) {
            p[i].second=1;
            sum+=p[i].first;
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;

    }
    long long l=0;
    for(int i=m; i<n ; i++){
        if(p[l].second==1) sum-=p[l].first;
        if(sum+p[i].first<=k) {
            p[i].second=1;
            sum+=p[i].first;
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
        l++;

    }


    
    
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