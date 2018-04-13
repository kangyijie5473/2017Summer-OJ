#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h;
	cin  >> h;
	for(int i = 1; i <= h; i++){
		for(int j = h-i; j>0; j--)
			cout << '.';
		if(h-i == 0)
			for(int j = 0; j < 2*h-1; j++)
				cout << '*';
		else{
			cout << '*';
			if(i != 1){
				for(int j = (i-1)*2-1; j > 0; j--)
					cout << '.';
				cout << '*';				
			}

		}
		cout << endl;


	}
	return 0;
		
}