#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull Pow(int power, ull a)
{
	ull sum = 1;
	for(ull i = 1; i <= a; i++){
		ull old = sum;
		sum *= power;
		if(old > sum)
			return ULLONG_MAX;
	}
	return sum;
}
int main()
{

	ull n ;
	cin >> n;
	ull s = n/3;
	int table[] = {0,1,2,2,4,6,9,12,18};
	// if(n < 0){
	// 	cout << INT_MAX ;
	// 	return 0;
	// }
	if(n < 9){
		cout << table[n];
		return 0;
	}
	if(n%3 == 0)
		cout << Pow(3,s);
	if(n%3 == 1){
		ull temp = Pow(3,s-1)
		ull t = Pow(3,s-1) * 4;
		if(t < temp)
			cout << ULLONG_MAX;
		else
			cout << t;
	}
	if(n%3 == 2){
		ull temp = Pow(3,s)
		ull t = Pow(3,s) * 2;
		if(t < temp)
			cout << ULLONG_MAX;
		else
			cout << t;

	}
	return 0;
}