#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
 
 
void solve(vector<int> &v, int n){
    int res=(v[0]-v[n-1])*(-1);
    for (auto i=0; i+n-1<v.size(); i++)
    {
        res=min(res, (v[i]-v[i+n-1])*(-1));
    }
    cout<<res<<endl;
    return;
}
 
int main()
{
 
    fastio
    int n, m;
    cin>>n>>m;
    vector<int>M(m);
    for(auto &i: M)
        cin>>i;
    sort(M.begin(), M.end());
    solve(M,n);

    
    return 0;
 
}