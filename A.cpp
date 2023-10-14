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
    int h, k, v, s, resp=0;
    int temp;
    cin>>h>>k>>v>>s;
    
    while(h>0)
    {
        v=v+s;
        temp = max(1, (v/10));
        v=v-temp;
        if(v>=k)
            h++;
        if(0<v && v<k)
            h--;
        if(h==0)
            v=0;
        if(v<=0)
        {
            h=0;
            v=0;
        }
        resp+=v;
        if(s>0)
            s--;
            

    }
    cout<<resp<<endl;    
   
    return 0;
}
