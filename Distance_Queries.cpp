#include <bits/stdc++.h>
using namespace std;
void   binary_lifting(vector<vector<int>> &up, vector<int> &parent){
    for(int i=1;i<parent.size();i++){
        up[i][0]=parent[i];

    }
    int LOG=ceil(log2(parent.size()-1)) +1;
    for(int j=1; j<LOG; j++){
        for(int node =1; node <parent.size(); node++){
            if(up[node][j-1]==-1) continue;
            up[node][j]= up[up[node][j-1]][j-1];
        }

    }


}
int kth_ancestor(int k , vector<vector<int>> &up, int node){
    int i=0;
    while(k && node !=-1){
        if(k & 1) {
            node = up[node][i];

        }
        i++;
        k=k>>1;

    }
    return node;
}
int lca(int n1, int n2, vector<vector<int>> &up, int LOG){
    if(n1==n2) return n1;
    for(int j= LOG-1; j>=0; j--){
        if(up[n1][j]==-1 || up[n2][j]==-1) continue;
        if(up[n1][j]!=up[n2][j]){
            n1=up[n1][j];
            n2=up[n2][j];
        }
    }
    return  up[n1][0];
}
void dfs(int node , vector<vector<int>> &adj, vector<int > &d, vector<int> &parent, int par){
    parent[node]=par;
    for(auto child : adj[node]){
        if(child==par) continue;
        d[child]=1+d[node];
        dfs(child, adj, d, parent, node);
    }
}
void solve() {
    int  n, q ;
    cin >> n >>q;
    vector<int> a(n+1);
    vector<int> d(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0; i <n-1;i++){
        int u ;
        int v ;
        cin>>u>>v;
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    a[1]=-1;
    dfs(1, adj, d, a, -1);
    
    int LOG=ceil(log2(n) )+1;
    vector<vector<int>> up(n+1, vector<int> (LOG, -1));
    binary_lifting(up, a);

    for(int i=0;i<q;i++){
        int s;
        int e;
        cin>>s>>e;
        int ans =0;
        if(d[s]!=d[e]){
            if(d[s]>d[e]){
                ans+=(d[s]-d[e]);
                s=kth_ancestor(d[s]-d[e], up, s);
                
            }
            else{
                ans+=(d[e]-d[s]);
                e=kth_ancestor(d[e]-d[s], up, e);

            }
        }
        if(s==e){
            cout<<ans<<endl;
            continue;
        }
        int l_c_a =lca(s, e, up, LOG);
        ans+=(d[s]-d[l_c_a]);
        ans+=(d[e]-d[l_c_a]); 
        cout<<ans<<endl;
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