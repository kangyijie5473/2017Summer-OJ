#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int t;
	cin >> t;
	while(t--){
		ull n;
		cin >> n;
		if(n%2 != 0){
			cout << "No" << endl;
			continue;
		}
		ull p = 2;

		while(n >= p){
			if(n % p == 0 && (n/p)%2 == 1){
				cout << (n/p) << " " << p << endl;
				break;
			}else
				p *= 2;
		}


	}

}

	
