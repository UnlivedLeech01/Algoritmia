#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int cont=0;
void Divide(vector <int> &v, int q, int i)
{
    if(q==1)
        return;
    q=q/2;
    Divide(v, q, q);
    Divide(v, q, q+1);
    if(v[i]==v[i+1])
        return;
    else if(v[i]!=v[i+1])
    {
        cont++;
        cout<<cont<<" "<<v[i]<<" "<<v[i+1];
    }
    return;
    
} 
void solve()
{
    int n;
    cin>>n;
    vector<int>v(n+1);
    for(auto i=1; i<=n; i++)
        cin>>v[i];
    cont=0;
    Divide(v, n, 0);
    
    return;
}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}