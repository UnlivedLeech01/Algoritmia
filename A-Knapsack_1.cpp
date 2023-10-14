#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

void Solve(int x)
{

}


int main()
{   
    int n, w, resp=0;
    cin>>n>>w;
    vector<vector<p2i>> dp(n, vector<p2i>(n, make_pair(0,0)));
    vector<p2i> elementos(n);
    for(auto &i: elementos)
        cin>>i.first>>i.second;
    for(auto i=0; i<n; i++)
    {
        for(auto j=0; j<n; j++)
        {
            if(dp[i][j].first>=w)
                break;
            else
            {
                dp[i][j].second+=elementos[j].second;
                dp[i][j].first+=elementos[j].first;
                if(dp[i][j].second>=resp)
                {
                    resp=dp[i][j].second;
                }
            }
        }
    }
    cout << resp << endl;
    return 0;
}
