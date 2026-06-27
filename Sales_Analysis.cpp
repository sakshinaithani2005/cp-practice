#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, w ;
    cin >> n >>w;
 
 vector<long long > p(n);
 
 

for(int i = 0; i < n; i++) {
    
    cin>>p[i];
    




    
}
int i=0;
long long sum=0;

while(i<w){
    sum+=p[i];
    i++;

}
i=0;
long long ans =sum;
for(int j=w;j<n;j++){
    sum-=p[i];
    sum+=p[j];
    ans =max(ans, sum);
    i++;
}


cout<<(ans*1000)/w;
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