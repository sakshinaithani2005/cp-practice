#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k ;
    cin >> n >>k;
 
 
for(int i = 0; i < n; i++) {
    long long A;
    cin >> A ;
    
    if(s>=A){
    s+=A;
    continue;
    }
    if(k<(A-s)){
        flag=false ;
        break;
    }
    long long diff =(A-s);
    s+=(diff + A);
    k-=diff;
    ans+=diff;
    
    
}
if(flag)

cout << ans;
else cout<<-1;
    


    

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) solve();
    return 0;
}