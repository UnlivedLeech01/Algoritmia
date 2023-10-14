#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    
    string n;
    cin>>n;
    if(n.size()>10)
        cout<<n[0]<<n.length()-2<<n[n.size()-1]<<endl;
    else
        cout<<n<<endl;
    
    
    return;
}

int main()
{
    fastio
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}