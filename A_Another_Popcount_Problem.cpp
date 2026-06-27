#include <bits/stdc++.h>
using namespace std;

void solve() {
    int  n , k;
    cin >> n>>k ;
    
    int ans =n/3;
    ans*=2;
    if(n%3==2){
        ans+=2;
        
    }
    else if(n%3==1) ans+=1;
    
 
 
 cout<<ans*k<<endl;
return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
     cin >> t;
    while (t--) solve();
    return 0;
}