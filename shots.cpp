#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, k, ml, l, r, g, x, y, resBebidas, resLimones, resSalsa, aux;
	cin>> n>> k>> ml>> l>> r>> g>> x>> y;
	
	resBebidas=k*ml/x;
	resLimones=l*r;
	resSalsa=g/y;

	if(resBebidas > resLimones)
		aux = resLimones;
	else 
		aux = resBebidas;
		
	if (aux > resSalsa)
		aux = resSalsa;
	
	cout<<aux/n<<endl;
	
	
	return 0;
}