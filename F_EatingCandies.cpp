#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/1669/F
void Solve(vector <int> &N)
{
    int l=0, r=N.size()-1, Bob=0, Alice=0, resp=1, final=0;
    Alice=N[0];
    while (l<r)
    {
        while(Bob<=Alice && l<r)
        {
            Bob+=N[r];
            r--;
            resp++;
            cout<<Bob<<" BOB"<<endl;
            if(Bob==Alice)
                final=resp;

        }
        if(Bob==Alice)
            final=resp;
        while(Bob>=Alice && l<r)
        {
            Alice+=N[l];
            l++;
            resp++;
            cout<<Alice<<" Alice"<<endl;
            if(Bob==Alice)
                final=resp;

        }
        if(Bob==Alice)
            final=resp;
    }
    cout<<final<<endl;

    return;
}


int main()
{   
    int t, n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        vector<int>N(n);
        for(auto &i : N)
            cin>>i;
        Solve(N);    
    }
    


    return 0;
}
