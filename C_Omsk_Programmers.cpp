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


void solve() {
    int a, b, x;
    cin >> a>> b>>x;
    int ans=0;
    while(a!=b){
        if((abs(a/x -b/x)< abs(a-b)) && (abs(a/x -b/x)<abs(a/x-b)) && (abs(a/x -b/x)<abs(a-b/x)) ){
            a=a/x;
            b=b/x;
            ans++;
            continue;
        }
        if(a>b){
            if(abs(a-b)>abs(a/x-b)){
                a=a/x;
            }
            else{
                b++;

            }
        }
        else{
            if(abs(a-b)>abs(b/x-a)){
                b=b/x;
            }
            else{
                a++;

            }
            

        }

        ans++;
    }
    cout<<ans;

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