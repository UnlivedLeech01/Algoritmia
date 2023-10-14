#include  <bits/stdc++.h>
using namespace std;
#define INF 203163161

int Max(int a,int b,int c)
{
    return a>b ? (a>c?a:c):(b>c?b:c);
    
}
int F(int n, int a, int b, int c, vector<int>& v)
{
    //cout<<v[n]<<"a"<<endl;
    if(n==0) 
        return 0;
    if(n<a && n<b & n<c)
        return -INF;
    if(v[n-1]==-1) 
        v[n-1]=Max(F(n-a, a, b, c, v)+1,F(n-b, a , b, c,v)+1,F(n-c, a, b, c, v)+1);
    //cout<<v[n]<<endl;
    return v[n-1];
}
int main()
{
    int a, b, c, n;
    cin>>n>>a>>b>>c;
    vector<int> v(n,-1);
    cout<<F(n,a,b,c,v)<<endl;

}


