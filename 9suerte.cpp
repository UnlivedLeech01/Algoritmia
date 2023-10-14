#include <bits/stdc++.h>
using namespace std;

int main()
{   
    string cadena;
    int i, n, result;
    vector<int>numeros(10);
    for(i=0;i<10;i++)
        numeros[i]=0;
    cin >> cadena;   
    stringstream ss(cadena);
    cout<<cadena;

    while(ss>>n)
        numeros[n]++;
    
    /*for(i=0; i<numeros.size();i++)
        result=numeros[i]+result;*/

    if(result%9==0 || result==0)
        cout << "Yes";
    else 
        cout << "No";

    return 0;
}
