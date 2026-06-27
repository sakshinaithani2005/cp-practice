#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
int m ;


int heavy[MAXN];
int parent[MAXN];
int depth[MAXN];
int sz[MAXN];
int head[MAXN];
int pos[MAXN];
int nodeat[MAXN];
int flatval[MAXN];
int val[MAXN];

long long seg[4 * MAXN];
int timer_hld =0;

void dfs1(int u, int d, int par, vector<vector<int>> &adj ){
    parent[u]=par;
    sz[u]=1;
    depth[u]=d;
    int maxsz=0;
    heavy[u]=-1;
for(auto v : adj[u]){
    if(v==par) continue;
    dfs1(v, d+1, u, adj);
    sz[u]+=sz[v];
    if(sz[v]>maxsz){
        maxsz=sz[v];
        heavy[u]=v;
    }
}


}
void dfs2(int u , int h, vector<vector<int>> &adj){
    head[u]=h;
    pos[u]=timer_hld;
    flatval[timer_hld]=val[u];
    nodeat[timer_hld]=u;
    timer_hld++;
    
        if(heavy[u]!=-1){
            dfs2(heavy[u], h, adj);
        }
        for(auto v : adj[u]){
            if(v==parent[u] || v==heavy[u] ) continue;
            dfs2(v, v, adj);
    }

    

}

void build(int i , int l , int r ){
    if(l==r){
        seg[i]=flatval[l];
        return ; 
    }
    int m =l+(r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    seg[i]= seg[2*i] + seg[2*i+1];
}
long long  query(int i , int l , int r , int ql, int qr){
    if(l>qr ||  r< ql) return 0;
    if(l>=ql && r<=qr){
        return seg[i];

    }
    int m= l+(r-l)/2;
    return query(2*i, l, m, ql, qr)+ query(2*i+1, m+1, r, ql , qr);
}
void update(int i , int l , int r , int idx, int val ){
    if(l==r){
        seg[i]=val;
        return ;
    }
    int m= l+(r-l)/2;
    if(idx<=m){
        update(2*i, l, m, idx, val);
    }
    else update(2*i+1, m+1, r, idx, val);
    seg[i]= seg[2*i] + seg[2*i+1];
}

long long  path_query(int u ,int v ){
    long long result =0;
    while(head[u]!=head[v]){
        if(depth[head[u]]<depth[head[v]]) swap(u, v);
        result+=query(1, 0, m-1, pos[head[u]], pos[u] );

        u=parent[head[u]];


    }
    if(depth[u]>depth[v]) swap(u, v);
    result+=query(1, 0, m-1,  pos[u], pos[v]);
    return result;
}
void solve() {
    int  nn, q ;
    cin >> nn >>q;
    vector<vector<int>> adj(nn+1);
    for(int i=1; i <=nn;i++){
        int u ;
        cin>>u;
        val[i]=u;
    }
    for(int i=1; i <nn;i++){
        int u ;
        int v ;
        cin>>u>>v;
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    m=nn;

    dfs1(1, 0, 0, adj);
    dfs2(1, 1, adj);
    build(1,0, m-1 );
    for(int i=1; i <=q;i++){
        int u ;
       
        cin>>u;
        if(u==1) {
            int s ;
            cin>>s;
            int x ;
            cin>>x;
            val[s]=x;
            update(1, 0, m-1,pos[s], x );
        }
        else if(u==2){
            int s;
            cin>>s;
            cout<<path_query(1, s)<<endl;
        }
       
        
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