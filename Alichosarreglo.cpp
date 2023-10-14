#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

void Solve()
{
    int n;
    cin>>n;
    vector<int>A(n);
    for(auto &i:A)
        cin>>i;
    int cont=0;
    bool bandera=true;
    while(cont<2 && bandera)
    {
        bandera=false;
        for(auto i=0; i<n; i+=2)
        {
            cout<<A[i]<<endl;
            if(A[i]>A[i+1])
            {
                swap(A[i], A[i+1]);
                cont++; 
                cout<<cont<<endl<<A[i]<<" "<<A[i+1]<<endl;
                bandera=true;
            }
        }
    }
    if(cont>2)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return;
}


int main()
{   
    Solve();
    
    a
}
