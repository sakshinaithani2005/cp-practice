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
int find(int u , vector<int> &parent){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u], parent);
}
void unio(int u , int v, vector<int> &rank, vector<int> &parent ){
    int up=find(u, parent);
    int vp=find(v, parent);
    if(up==vp) return ;
    if(rank[up]>rank[vp]){
        parent[vp]=up;
       
    }
    else if(rank[vp]>rank[up]){
        parent[up]=vp;
       
    }
    else {
        parent[up]=vp;
        rank[up]++;
    }
}

void solve() {
    // Logic goes here
    int  k, x, y;
    cin>>k>>x>>y ;
    vector<long long > a(k+1);
vector<int> parent(k+1);
for(int i=1; i<=k;i++) parent[i]=i;
vector<int>rank(k+1, 0);




    
  
    for(int i=1; i<=k;i++){
        cin>>a[i];
        

    }
    for(int i=1; i<=k;i++){
        if (i - x >= 1) unio(i, i - x, rank, parent);
        if (i + x <= k) unio(i, i + x, rank, parent);

        if (i - y >= 1) unio(i, i - y, rank, parent);
        if (i + y <= k) unio(i, i + y, rank, parent);
        
    }
    int flag=0;
    for(int i=1; i<=k;i++){
       
        if(find(a[i], parent)!=find(i, parent)){
            flag=1;
            break;
        }

    }
    if(flag==1) cout<<"NO";
    else cout<<"YES";
   
    
   
     
    
  
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