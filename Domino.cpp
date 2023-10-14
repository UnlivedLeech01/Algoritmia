#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    for(auto i = 0; i < n; i++)
    {
        if(a[i] == 'U')
            cout << "D";
        if(a[i] == 'D')
            cout << "U";
        if(a[i] == 'L' || a[i] == 'R')
            cout << a[i];
    }
        cout << endl;
    
    
    return;
}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}