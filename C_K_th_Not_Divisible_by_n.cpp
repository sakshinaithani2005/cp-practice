#include <bits/stdc++.h>
using namespace std;

void solve() {
    int  n , k;
    cin >> n>>k ;
 
 long long  current=k;
 if(current%n==0) current++;
 long long diff= current-current/n;
 while(k-diff>0){
    current+=(k-diff);
    if(current%n==0) current++;
    diff= current-current/n;
 }
 cout<<current<<endl;
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