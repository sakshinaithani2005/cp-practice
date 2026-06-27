#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k ;
    cin >> n >>k;
 
 vector<long long > p(n);
 vector<long long > pa(n);
 vector<long long > pb(n);
 int flag=true;
for(int i = 0; i < n; i++) {
    
    cin>>pa[i];
    




    
}
for(int i = 0; i < n; i++) {
    
    cin>>pb[i];
    




    
}
long long ans=0;

for(int i=0;i<n;i++){
     if(i!=0){
        p[i]+=p[i-1];
        
    }
    int need = pb[i]-pa[i]- p[i];
    if(need<0){
        cout<<-1;
        return ;
    }
    if(i<=(n-k)){
        p[i]+=need;
        ans+=need;

    }
    if(i+k<n){
        p[i+k]-=need;
    }
    if(i>(n-k) && need>0){
        cout<<-1;
        return ;
    }

   
    
    

    
}
cout<<ans;
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