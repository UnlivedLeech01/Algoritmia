#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

void Solve()
{
    int n, resp=1; cin>>n;
    int bit;cin>>bit;
    for(auto i=1; i<n; i++)
    {
        int temp=bit;
        cin>>bit;
        if(temp!=bit)
            resp++;
    }    
    cout<<resp<<endl;
    return;
}


int main()
{   

    Solve();
    
    return 0;

}
