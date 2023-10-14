#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

int main()
{   
    int ri, rj;
    vector<vector<int>> Matriz(5, vector<int>(5));
    for (auto i=0; i<5; i++)
    {
        for (auto j=0; j<5; j++)
        {
            cin>>Matriz[i][j];
            if (Matriz[i][j]==1)
            {
                ri=i;
                rj=j;
            }
        }
    }
    int resp1, resp2;
    if(ri<=2)
        resp1=2-ri;
    else
        resp1=ri-2;
    if(rj<=2)
        resp2=2-rj;
    else
        resp2=rj-2;

    cout<<resp1+resp2<<endl;
    
    return 0;
}
