#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

void solve() {
    int x ;
    cin>>x;

   int ans ;
   if(x==67) ans=67;
   else if(x<=0) ans =0;
   else ans=x+1;
    cout<<ans<<endl;
}

int main() {
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}