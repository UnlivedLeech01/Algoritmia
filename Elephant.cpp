#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

void Solve(int x)
{
    int resp=0;
    for(auto i=5; i>0; i--)
    {
        resp+=(x/i);
        x=x%i;
    }
    cout<<resp<<endl;
    return;
}


int main()
{   
    int x;
    cin>>x;
    Solve(x);
    
    return 0;
}
