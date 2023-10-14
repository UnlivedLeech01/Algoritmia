#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

void Solve()
{
    int n, cont=0; cin>>n;
    vector<int>v(n);
    for(auto &i: v)
    {
        cin>>i;
        if(i%2==1)
            cont++;
    }
    if(cont%2==1)
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return;
}


int main()
{   
    int t;cin>>t;
    while(t--)
        Solve();
    
    return 0;

}
