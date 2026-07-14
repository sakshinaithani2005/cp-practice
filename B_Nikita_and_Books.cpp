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
    vector<long long > a(k+1);

    long long  ans =0;
  
    for(int i=1; i<=k;i++){
        cin>>a[i];
    }
   
    int  flag=0;
    for(int i=1;i<k;i++){
        if(a[i]==i) continue;
        if(a[i]>i){
            ans=(a[i]-i);
            a[i+1]+=ans;
        }
        else if(a[i]<i){
            flag=1;
            break;
        }
    }
    if(flag==1  ||  (k!=1 && a[k]<k)){
        cout<<"NO"<<endl;
        return ;

    } 
    cout<<"YES";
     
    
  
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