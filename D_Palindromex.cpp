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
    
    int x;
    cin>>x;
    x=2*x;
    vector<int> arr(x);
    int ans =1;
    int a=0;
    int b=0;
    int flag=0;
    for(int i=0;i<x;i++){
        cin>>arr[i];
        
        if(arr[i]==0 && flag==0) {
            flag=1;
            a=i;
            continue;

        }
        if(arr[i]==0 && flag==1) {
            
            b=i;

        }
        
        
    }
    int i=a-1;
    int j=a+1;
    vector<int> a1(x);
    a1[0]=1;
    while(i>=0 && j<x){
        if(arr[i]==arr[j]) {
            a1[(arr[i])]=1;
            i--;
            j++;

        }
        else break;
    }
    for(int i=0;i<x;i++){
        if(a1[i]==1){
            ans=max(i+1, ans);
        }
        else break ;
    }
    i=b-1;
    j=b+1;
    vector<int> a2;
    a2[0]=1;
    while(i>=0 && j<x){
        if(arr[i]==arr[j]) {
            a2.insert(arr[i]);
            i--;
            j++;

        }
        else break;
    }
    for(int i=0;i<x;i++){
        if(a2.find(i)!=a2.end()){
            ans=max(i+1, ans);
        }
        else break ;
    }
    i=a;
    j=b;
    set<int> a3;
    flag=0;
    while( i>=0 && i<=j && j<x){
        if(arr[i]==arr[j]){
            a3.insert(arr[i]);
            i++;
            j--;

        }
        else {
            flag=1;
            break;
        }
    }
    if(flag==1 && (i>=0 && j<x)) cout<<ans;
    else {
        i=a-1;
        j=b+1;
        while(i>=0 && j<x){
            if(arr[i]==arr[j]){
                a3.insert(arr[i]);
                i--;
                j++;
            }
            else break;
        }
        for(int i=0;i<x;i++){
            if(a3.find(i)!=a3.end()){
                ans=max(i+1, ans);
            }

        }
        cout<<ans;
    } 


    
    
    

   cout<<endl;
    return ;
}


int main() {
   
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}