#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin >> n >> m;
	ll sum = 0;
	ll flag = -1;
	for(ll i = 1; i <= n; i += m){
		sum += flag * (m * (i + i + m - 1) / 2);
		flag *= -1;
	}
	cout << sum;
	return 0;
}