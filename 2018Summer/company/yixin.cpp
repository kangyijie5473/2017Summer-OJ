#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll Pow(ll a,ll b)
{
   	ll r = 1, base = a;
   	while (b) {
   		if(b & 1) 
   			r *= base;
    	base *= base;
    	b >>= 1;
  	}
  	return r;
}
// ull Pow(ull n, ull w)
// {
// 	ull res = 1;
// 	for (ull i = 0; i < w; i++)
// 		res *= n;
// 	return res;
// }
int main(int argc, char const *argv[])
{
	ull n, w;
	cin >> n >> w;
	ull sum = Pow(n, w);
	ull sub = Pow(n - 1, w - 1) * n;
	cout << (sum - sub) % 100003 << endl; 
	return 0;
}