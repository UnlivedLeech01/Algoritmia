#include <bits/stdc++.h>
using namespace std;
#define INF 5e12 + 1
/* int Solve()
{

    return ;
} */


int main()
{   
    int w, h;
    cin>>w>>h;
    while(w!=0 && h!=0)
    {
        string s;
        int n=h, m=w, q;
        cin>>n>>m>>q;
        int inicioh, finalh, iniciow, finalw;
        vector<vector<int> >Adj(h+1, vector<int>(w+1,0));
        while(n--)
        {
            cin>>s;
            m=w;
            while(m--)
            {
                int a, b, c;
                char c2;
                cin>>a>>b>>c;
                if(Adj[h-n][w-m]==0){
                    if(s[m]=='S'||s[m]=='D')
                        {
                            Adj[h-n][w-m]=0;
                            iniciof=
                        }
                    else
                    {
                        c2=s[m];
                        c=c2 - '0';
                        Adj[h-n][w-m]=c;
                    }
                }
                else
                {
                    c2=s[m];
                    c=c2 - '0';
                    Adj[h-n][w-m]=min (c, Adj[h-n][w-m]);
                }
                Adj[w-m][h-n]=Adj[h-n][w-m];
            }
        }

        vector<vector<long long> > dist(h+1,vector<long long>(w+1,0));

        for (int i=1; i <= h; i++)
        {
            for (int j=1; j <= w; j++)
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
            for (int i=1; i<=h; i++){
                for (int j=1; j<=w; j++)
                    dist[i][j]= min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        
        }
        int i=
            cin>>i>>f;
            if(dist[i][f] == INF)
                cout<<"-1"<<endl;
            else
                cout<<dist[i][f]<<endl;
/* for (int i=1; i <= n; i++)
    {
        for (int j=1; j <= n; j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    } */
    }
    return 0;
}
