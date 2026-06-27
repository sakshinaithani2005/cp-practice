#include <bits/stdc++.h>
using namespace std;

int main() {
 
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string row1, row2;
        cin >> row1 >> row2;
        int ans=0;
        vector<int> visited(n, 0);
        for(int i=0;i<n;i++){
            if(row1[i]==row2[i]){
                ans++;
                visited[i]=1;
            } 
            if(i!=0){
                if((row1[i]==row1[i-1]  )  || (row2[i]==row2[i-1])){
                    if(visited[i-1]==0 && visited[i]==0) {
                        visited[i]=1;
                        visited[i-1]=1;
                    
                    if(row1[i]==row1[i-1]  ) ans++;
                    if(row2[i]==row2[i-1]) ans++;
                    }

                }
            }

            
        }
      
        
        
        
        cout << n-ans << "\n";
    }
    return 0;
}