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
    int f3=0;
    int f1=0;
    int f2=0;
    vector<int> arr(k);
    for(int i=0; i<k ; i++){

        
        cin>>arr[i];
        
    }
    int i=0;
    int x=0;
    int mila=0;
    
        while( i < k && f1==0 ){
            
            if(arr[i]==1){
                x++;
                mila=1;

            } 
            else if(arr[i]==3){
                 x--;
                 mila=1;
            }
            
            else if(arr[i]==2){
                if(x<0 || mila==0){
                    mila=1;
                    x--;
                }
                else if(x>=0 && mila==1 ){
                    f1=1;
                    f2=1;
                    i++;
                    break;
                    
                }
                else if(mila==0){
                    mila=1;
                    x--;
                }
            }
            if(x==0 && mila==1){
                    f1=1;
                  
                    i++;
                    break;
                    
                }
                if(x>=1 && i<k-2 && arr[i+1]==3){
                    x--;
                    i++;
                    if(x==0){
                        i++;
                        f1=1;
                        break;
                    }
                }
                else if(x>=1 && i<k-2 && (arr[i+1]==1 || arr[i+1]==2) ){
                    f1=1;
                    f2=1;
                    i+=2;
                    break;
                    
                }
                
                i++;
            

        }
        if(mila==1 && f1==1 && f2==1 && i<=k-1) cout<<"YES";
        else if(f1==0 && i==k ) cout<<"NO";
        else if(f1==1 && i==k) cout<<"NO";
        else {
            int y=0;
            int mila2=0;
            while(i<k && f2==0){
                if(arr[i]==1 || arr[i]==2){
                    mila2=1;
                    y++;
                } 
                else{
                    y--;
                    mila2=1;

                } 
                if(y>=0  && mila2==1){
                    f2=1;
                    i++;
                    break;
                }
                i++;
                

            }
            if(mila==1 && f1==1 && f2==1 && mila2==1 &&  i<=k-1) cout<<"YES";
            else cout<<"NO";
            

        }

    
    
  
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