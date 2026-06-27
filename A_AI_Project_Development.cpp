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


void solve() {
    
    int n , x, y, z;
    cin>>n>>x>>y>>z;
    int ans =0;
    int a= x+y;
    if(n%a!=0){
        ans =n/a;
        ans++;
    }
    else ans =n/a;
    // with ai ;
    int t=z*x;
     int f = n-t;
     if(f<=0) ans =min(ans, z);
     else {
        int r = x + y*10;
        int u = f/r;
        if(f%r==0) ans =min(ans , z+u );
        else {
            ans =min(ans ,z+u+1 );
        }
     }
     cout<<ans;

    cout<<endl;

   
    return ;
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