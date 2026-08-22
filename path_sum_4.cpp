#include<bits/stdc++.h>
using namespace std ;

pair<int, int>  v(int i , int j , vector <vector<int >> vec, int &sum){
    if(i>=5 || j>8) return {0, 0};
    if(vec[i][j]==-1) return {0, 0};
    auto  l = v(i+1, j*2-1 , vec, sum);
    auto  r = v(i+1, j*2, vec, sum);
    bool hasLeft =
        (i+1 < 5 && j*2-1 <= 8 && vec[i+1][j*2-1] != -1);

    bool hasRight =
        (i+1 < 5 && j*2 <= 8 && vec[i+1][j*2] != -1);

    if (!hasLeft && !hasRight)
        return {vec[i][j], 1};
    return {l.first+r.first+ ((l.second) + (r.second) )*vec[i][j],  l.second+r.second +1 };
}
int main(){
    int n ; 
    cin>>n;
    vector<int > inpt(n);
    for(int i=0; i<n ; i++) cin>>inpt[i] ;

    vector<vector<int> >vec(5, vector<int> (9, -1));
    for(int i=0;i<n ;i++){
        vec[inpt[i]/100][(inpt[i]/10-10*(inpt[i]/100)) ] = inpt[i]%10;
        
        
    }
    int sum=0;
    int k=v(1, 1, vec, sum).first;
    cout<<k;
    return 0;
    
    
    
    

}
