#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

void Solve()
{
    int n;
    cin>>n;
    vector<int>dias(n);
    for(auto &i:dias)
        cin>>i;
    dias.push_back(0);
    int resp=0;
    for(int i=0; i<n; i++)
    {
        int cont=1;
        int j=i+1;
        while(dias[j]>=dias[j-1])
        {
            cont++;
            j++;
        }
        if(resp<cont)
            resp=cont;
    }
    cout<<resp<<endl;
    
    return;
}


int main()
{   
    Solve();
    
    return 0;
}
