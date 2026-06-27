#include <bits/stdc++.h>
using namespace std;
void solve() {
    
    int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        sort(p.begin(), p.end());

        // int ans = 0;
        vector<int> ct(n);
        
        set<int> st;
        for(int i = 0; i < n; i++){

    if(n > 1 && p[i] == 1){
        ct[1]++;
        st.insert(p[i]);
        continue;
    }

    if(p[i] == 2){
        if(n > 1) ct[1]++;
        st.insert(2);
        continue;
    }

    int idx;

    if(p[i] % 2 == 0){
        idx = (p[i] / 2) - 1;
    } else {
        idx = (p[i] / 2);
    }

    
    if(idx < 0) idx = 0;
    if(idx >= n) idx = n - 1;

    ct[idx]++;
    st.insert(p[i]);
}
        int sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += ct[i];
        }
        int ans=0;
        for(int i =0;i<n-1;i++){
            
            if(ct[i] == 0){
                ct[i+1] = ct[i+1]  - 1;
                sum--; 
                
            }
            
            if(ct[i]>0){
                sum-=ct[i];
            }
            if(ct[i]<0){
                ct[i+1]=ct[i+1]+ct[i]-1;
                sum--;
            }
            
            if(sum<=0){
                ans=i;
                break;
            }
            ans=i+1;
        }
        if(sum>=0) ans++;
        while(st.find(ans)!=st.end()){
            ans++;
        }
            

        
        

        cout << ans << '\n';

   
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