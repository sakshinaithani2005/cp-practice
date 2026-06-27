#include<bits/stdc++.h>
using namespace std;

#define ll long long

int findParent(int node, vector<int> &parent){

    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node], parent);
}

void unionByRank(int u, int v,
                 vector<int> &parent,
                 vector<int> &rankk){

    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if(pu == pv)
        return;

    if(rankk[pu] < rankk[pv]){

        parent[pu] = pv;
    }
    else if(rankk[pu] > rankk[pv]){

        parent[pv] = pu;
    }
    else{

        parent[pv] = pu;
        rankk[pu]++;
    }
}

void solve(){

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> parent(n);
    vector<int> rankk(n,0);

    // initialize DSU
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    // make unions
    for(int i=0;i<n;i++){

        // k-periodic relation
        if(i + k < n){
            unionByRank(i, i+k, parent, rankk);
        }

        // palindrome relation
        unionByRank(i, n-i-1, parent, rankk);
    }

    // component -> char frequency
    unordered_map<int, unordered_map<char,int>> freq;

    for(int i=0;i<n;i++){

        int p = findParent(i, parent);

        freq[p][s[i]]++;
    }

    ll ans = 0;

    // calculate minimum changes
    for(auto it : freq){

        int total = 0;
        int mx = 0;

        for(auto x : it.second){

            total += x.second;

            mx = max(mx, x.second);
        }

        ans += (total - mx);
    }

    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}