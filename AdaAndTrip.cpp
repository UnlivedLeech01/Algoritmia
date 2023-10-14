#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX
int cities;

int Dijkstra(int i, int f, int n, vector <vector<p2i>> &Adlist)
{
    vector <int> dist(n+1, INF);
    dist[i]=0;

    priority_queue<p2i, vector<p2i>, greater<p2i> >Q;
    Q.push({0,i});

    while(!Q.empty())
    {
        int cost=Q.top().first;
        int nod=Q.top().second;
        Q.pop();

        for(p2i &edge:Adlist[nod])
        {
            int nnode=edge.first;
            int val=edge.second;

            if(dist[nnode]>cost+val)
            {
                dist[nnode]=cost+val;
                Q.push({dist[nnode], nnode});
            }
        }
    }

    return dist[f];
}


int main()
{   
    int q, n, m, a, b;
    cin>>q;
    while (q--)
    {
        cin>> n >> m >> a >> b;
        vector <vector<p2i>> Adjlist(n+1);
        while(m--)
        {
            int x, y, c;
            cin>> x >> y >> c;
            Adjlist[x].push_back({y, c});
            Adjlist[y].push_back({x, c});
        }

        int cost=Dijkstra(a, b, n, Adjlist);

        if(cost==INF)
            cout<<"NONE"<<endl;
        else
            cout<<cost<<cities<<endl; 
    }
    
    return 0;
}
