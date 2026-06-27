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


void solve() {
    
    int n , m;
    cin>>n>>m;
    vector<int> arr(n+1);
    for(int i=0;i<n;i++) cin>>arr[i];
    q qu[m];
    vector<int> an(m);
    for(int i=0;i<m;i++){
        qu[i].indx=i;
        cin>>qu[i].l;
        cin>>qu[i].r;



        
    }
    rootn=sqrtl(n);
    sort(qu, qu+m, [](q &x, q &y){
        if(x.l/rootn== y.l/rootn) {
            return x.r<y.r;
        }
        return x.l/rootn <  y.l/rootn;
    });
    
    
    int cl=0;
    int cr=-1;
    int l;
    int r;
    unordered_map<int, int > mp ;
    long long ans =0;
    for(int i=0;i<m;i++){
        l=qu[i].l;
        r=qu[i].r;
        l--;
        r--;

         while(r>cr){
            cr++;
            mp[arr[cr]]++;
            if(arr[cr] && mp[arr[cr]]==arr[cr]) ans++;
            if(arr[cr] && mp[arr[cr]]==arr[cr]+1) ans--;
            
        }
        while(l>cl){
           

            mp[arr[cl]]--;
            if(arr[cl] && mp[arr[cl]]==arr[cl]) ans++;
            if(arr[cl] && mp[arr[cl]]==arr[cl]-1) ans--;

            cl++;
            
            
        }
        while(l<cl){
            cl--;
            mp[arr[cl]]++;
            if(arr[cl] && mp[arr[cl]]==arr[cl]) ans++;
            if(arr[cl] && mp[arr[cl]]==arr[cl]+1) ans--;


        }
       
        while(r<cr){
           
            mp[arr[cr]]--;
            if(arr[cr] && mp[arr[cr]]==arr[cr]) ans++;
            if(arr[cr] && mp[arr[cr]]==arr[cr]-1) ans--;
            cr--;
        }

        an[qu[i].indx]=ans;
    }

    for(auto &i: an){
        cout << i << '\n';
    }
   
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