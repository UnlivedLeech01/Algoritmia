#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);

void Build(vector <pair <ll,ll>> &SegmentTree, int n)
{
    for(int i= n-1 ; i>0; i--)
    {
        SegmentTree[i].first= SegmentTree[i<<1].first + SegmentTree[i<<1|1].first; 
        SegmentTree[i].second= SegmentTree[i<<1].second + SegmentTree[i<<1|1].second + (SegmentTree[i<<1].first * SegmentTree[i<<1|1].first);    
    }
    return;
}

int Query(int n, int l, int r, vector <pair <ll,ll>> &SegmentTree)
{
    pair<ll, ll> respR=make_pair(0,0), respL=make_pair(0,0); 
    for(l += n, r += n; l<r; l>>=1, r>>=1)
    {
        if (l&1)
        {
            respL.second = (respL.second + SegmentTree[l].second + SegmentTree[l].first * respL.first)% mod ;
            respL.first += SegmentTree[l].first;
            l++;
        }
        if (r&1)
        {
            r--;
            respR.second = (respR.second + SegmentTree[r].second + SegmentTree[r].first * respR.first) % mod;
            respR.first += SegmentTree[r].first;
        }
    }

    return (respL.second + respR.second + (respL.first * respR.first))% mod;
}

int main()
{   
    fastio
    int n, q;
    int l, r, resp; 
    cin >> n >> q;
    vector<pair<ll,ll> > SegmentTree(2*n, make_pair(0,0));

    for(auto i=n; i<SegmentTree.size(); i++ )
        cin >> SegmentTree[i].first;
    
    Build(SegmentTree, n);
    
    while(q--)
    {
        cin>> l >> r;
        resp= Query(n, l-1, r, SegmentTree);
        cout << resp <<endl;
    }
    for(auto &i : SegmentTree)
       cout << i.first << " ";
    cout << endl;
    for(auto &i : SegmentTree)
       cout << i.second << " ";  

    return 0;
}
