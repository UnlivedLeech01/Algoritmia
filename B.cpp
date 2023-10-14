#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int alto=n, ancho=(2*n)-1;
    vector<vector<char>>sol(alto, vector<char>(ancho));
    sol[0][n-1]='*';
    for(auto i=0; i<ancho; i++)
    {
        if(sol[0][i]!='*')
            sol[0][i]='.';
        cout<<sol[0][i];
    }
    cout<<"\n";

    for(auto i=1; i<alto; i++)
    {
        for(auto j=0; j<ancho; j++)
        {
            int cont=0;
            if(i-1>=0 && j-1>=0)
            {
                if(sol[i-1][j-1]=='*')
                    cont++;
            }
            if(i-1>=0 && j+1<ancho)
            {
                if(sol[i-1][j+1]=='*')
                    cont++;
            }
            if(cont==1)
                sol[i][j]='*';
            else
                sol[i][j]='.';
            cout<<sol[i][j];
        }
    cout<<"\n";


        
    }
    return;
}

int main()
{

    solve();
    return 0;
}