#include <bits/stdc++.h>
using namespace std;

/**
 * Author: sakshi (https://github.com/raogaurav17/)
 */

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif

// Vector I/O
template <typename T>
void read(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}
template <typename T>
void print(const vector<T> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

// Modular Arithmetic
const int MOD = 1e9 + 7;
int rootn;
ll power(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n == 1 || n <= m || a[0] > b[0] || a[n - 1] < b[m - 1])
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<int> pre(m, 0);
        int k = 0;
        int i = 0;
        while(i < n && k < m){
            if(a[i] < b[k]){
                pre[k]++;
                i++;
            }
            else{
                k++;
                if (k == m) break;
                pre[k] = pre[k - 1];
            }
        }
        stack<int> st;
        int j = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                
                st.push(a[i]);
            }
            else if (j < m && a[i] > b[j])
            { 
               if(pre[j]-j==0) break;
                st.pop();
                j++;
            }
            else if (j < m && a[i] < b[j])
            {
                
                st.push(a[i]);
            }
            else if (j == m)
            {
                break;
            }
        }
        if (j == m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return;
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}