#include <bits/stdc++.h>
using namespace std;
#define INF 5e12 + 1
/* int Solve()
{

    return ;
} */


int main()
{   
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<int> >Adj(n+1, vector<int>(n+1,0));
    while(m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if(Adj[a][b]==0)
            Adj[a][b]=c;
        else
            Adj[a][b]=min (c, Adj[a][b]);
        Adj[b][a]=Adj[a][b];
    }

    vector<vector<long long> > dist(n+1,vector<long long>(n+1,0));

    for (int i=1; i <= n; i++)
    {
        for (int j=1; j <= n; j++)
        {
            if (i == j) 
                dist[i][j] = 0;
            else if (Adj[i][j])
                dist[i][j]=Adj[i][j];
            else 
                dist[i][j] = INF;
        }
    }
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++)
                dist[i][j]= min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    
    }

    while(q--)
    {
        int i, f;
        cin>>i>>f;
        if(dist[i][f] == INF)
            cout<<"-1"<<endl;
        else
            cout<<dist[i][f]<<endl;
    }
/* for (int i=1; i <= n; i++)
    {
        for (int j=1; j <= n; j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    } */
    return 0;
}
