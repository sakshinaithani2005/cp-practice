#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, w ;
    cin >> n >>w;
 
 vector<long long > p(n);
 vector<long long > pa(100000000, 0);

 

for(int i = 0; i < n; i++) {
    
    cin>>p[i];
    




    
}
int i=0;
int j=1;
while(i<n){
    if(pa[j]+p[i]<=w){
        pa[j]+=(p[i]+1);
        i++;

    }
    else{
        j++;
    }
    

}


cout<<j;
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