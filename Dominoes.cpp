#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n ;
    cin >> n ;
 
 vector<long long > p(n);
 
 

for(int i = 0; i < n; i++) {
    
    cin>>p[i];
    




    
}
int x=1;
for(int i=0;i<n;i++){
    if(i==0) cout<<0<< " ";
    else {
        if(p[i-1]>p[i]){
            cout<<i<<" ";
        }
        else {
            cout<<0<<" ";
            
        }
    }
}
return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) solve();
    return 0;
}