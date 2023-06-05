#include <bits/stdc++.h>
#define ll long long
// ll power(int x, int n, int m)
// {
// 	if(n==0)	return 1;
// 	if(n==1)	return x;
	
// 	ll temp = power(x,n/2,m);
// 	if(n%2==0)	return (temp*temp)%m;
// 	else		return (x*(temp*temp))%m;
// }

int modularExponentiation(int x, int n, int m) {
	if(m==1 || x==0)	return 0;
	// return power(x%m,n,m);

	ll ans=1, y=x%m;
	while(n>0)
	{
		if(n%2 != 0)	ans = (ans*y)%m;
		y = (y*y)%m;
		n = n/2;
	}
	return ans;
}