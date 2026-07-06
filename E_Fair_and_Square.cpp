// C++ solution for Problem E
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> adj;
vector<ll> sub;    // subtree sizes
vector<int> a;
vector<int> parent_node;

void dfs(int u, int p) {
    parent_node[u] = p;
    sub[u] = 1;
    for(int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
}

bool isSquare(int x) {
    int r = floor(sqrt(x));
    return 1LL*r*r == x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        cin >> n;
        a.assign(n+1, 0);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        adj.assign(n+1, {});
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        sub.assign(n+1, 0);
        parent_node.assign(n+1, 0);

        // Root the tree at node 1 (arbitrary)
        dfs(1, 0);

        ll total = 0;
        // Precompute combination (n-1 choose 2)
        ll choose2 = (n-1LL)*(n-2LL)/2;  
        ll T = n-1LL; // sum of branch sizes for any center = n-1

        // For each potential center c
        for(int c=1; c<=n; c++){
            if (!isSquare(a[c])) continue;

            // count_1: triples including c
            ll count1 = choose2;

            // Compute S2 and S3 over branches at c
            ll S2 = 0, S3 = 0;
            for(int v: adj[c]) {
                ll s;
                if (v == parent_node[c]) {
                    // branch is outside c's subtree
                    s = n - sub[c];
                } else {
                    // branch is subtree of child v
                    s = sub[v];
                }
                S2 += s*s;
                S3 += s*s*s;
            }
            // count_2: triples from three distinct branches
            // formula: (T^3 - 3*T*S2 + 2*S3) / 6
            ll count2 = 0;
            if (adj[c].size() >= 3) {
                // If fewer than 3 neighbors, count2 stays 0
                count2 = (T*T*T - 3LL*T*S2 + 2LL*S3) / 6LL;
            }
            total += count1 + count2;
        }
        cout << total << "\n";
    }
    return 0;
}
