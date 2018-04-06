#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull getNum(int n, int k)
{
	ull a = 1;
	ull b = 1;
	for(int i = n, j = 0; j < k; j++,i--)
		a *= i;
	for(int i = k; i >= 1; i--)
		b *= i;
	return a/b;
}
int main()
{

	freopen("s", "r", stdin);

	int k, a,x,b,y;
	ull sum = 0;
	cin >> k >> a >> x >> b >> y;
	if(k % a == 0){
		int t = k/a;
		sum += getNum(x,t);
	}
	if(k % b == 0){
		int t = k/b;
		sum += getNum(y,t);
	}
	if(k%(a+b) == 0){
		int t = k/(a+b);
		sum += (getNum(x,t)*getNum(y,t));
	}
	int i, j;
	for(i = 1; (i*a) <= k; i++){
		for(j = 1; (j*b + i*a) <= k; j++){
			if((j*b + i*a) == k && i != j)
				sum += (getNum(x,i)*getNum(y,j));

		}
	}
	cout << sum%1000000007;

	return 0;
}