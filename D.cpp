#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m, resp=0;
    cin>>m>>n;
    vector<int> N(n);
    vector<int> M(m);
    for(auto i=0;i<m;i++)
        cin>>M[i];
    for(auto i=0;i<n;i++)
        cin>>N[i];

    for(auto i=0;i<n;i++)
    {
        int x=N[i]-M[0], cont=0;
        for(auto j=0; j<m;j++)
        {
            if(M[j]!=N[i+j]-x)
            {
                i=i+j;
                break;
            }
            cont++;
        }
        if(cont==m)
            resp++;
    }      
    cout<<resp<<endl;  
    return 0;
}