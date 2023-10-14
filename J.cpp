#include <bits/stdc++.h>
using namespace std;
using p2i=pair<int, int>;
#define INF INT_MAX

int Solve()
{
    

    return 0 ;
}


int main()
{   
    int ds, ys;
    int dm, ym;
    int temp, cont=0;
    cin>>ds>>ys>>dm>>ym;

    dm=(-1)*dm;
    int iniciodm=dm;
    ds=(-1)*ds;
    temp=min(ys, ym);
    if(ys==0 || ym==0){
        cout<<"5000"<<endl;
        return 0;
        }

    while(ds!=dm || dm>=5000 || ds>=5000)
    {
        while(ds<dm)
        {    
            ds+=ys;
        }   
        while(dm<ds) 
        {
            cont++;
            dm+=ym;
        }
    cout<<ds<<" "<<dm<<endl;
    }
    int resp=iniciodm+(cont*ym);

    if(dm>=5000 || ds>=5000)
        cout<<"5000"<<endl;
    if(dm==0)
        cout<<"5000"<<endl;
    else 
        cout<<dm<<endl;

    return 0;
}
