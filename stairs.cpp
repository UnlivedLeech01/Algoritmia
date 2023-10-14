#include <bits/stdc++.h>
using namespace std;
    
int solve(int totalsteps, int currentsteps )
{
    if (currentsteps > totalsteps)
        return 0;
    if(currentsteps == totalsteps)
        return 1;
    return solve(totalsteps, currentsteps)+solve(totalsteps, currentsteps*2);
}

int main()
{   
    int n, resp;
    cin>>n;
    resp=solve(n, 1);
    cout<<resp<<endl;

    return 0;
}
