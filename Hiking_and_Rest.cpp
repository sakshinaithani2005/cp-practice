#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n ;
    cin >> n ;
 

 vector<long long > pa(n);
 vector<long long > p(n+1);

 int flag=true;
for(int i = 0; i < n; i++) {
    
    cin>>pa[i];

    




    
}

long long ans=0;

p[0]=0;
for(int i=1;i<=n;i++){
    long long t =p[i-1]+pa[i-1];
    if(t<=0) p[i]=0;
    else p[i]=t;
     
    

    
}
long long f=n+3;
for(int i=n;i>=1;i--){
    if(p[i]==0) break;
    if(pa[i-1]<0){
        if(p[i-1]/2+pa[i-1]<=0){
            p[i]=0;
            f=i+1;
        }
    }

}

for(int i=f;i<=n;i++){
    long long t =p[i-1]+pa[i-1];
    if(t<=0) p[i]=0;
    else p[i]=t;
     
    

    
}
if(f==n+3){
    cout<<p[n]/2;
}
else {
    cout<<p[n];
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