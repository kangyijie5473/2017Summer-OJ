#include <bits/stdc++.h>
using namespace std;
int n1,n2,n3,n4;
int m1,m2,m3,m4;

int f(int v, int m, int i, int j, int k, int l)
{
	int sum = i*m1 + j*m2 + k*m3 + l*m4;
	return v + m*(sum%10);
}
int main()
{
	int dp[31][31][31][31] = {0};
	cin >> n1 >> n2 >> n3 >> n4 >> m1 >> m2 >> m3 >> m4;
	int a,b,c,d;
	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= n2; j++){
			for(int k = 0; k <= n3; k++){
				for(int l = 0; l <= n4; l++){
					if(i-1>=0)
						a = f(dp[i-1][j][k][l],m1,i-1,j,k,l);
					else
						a = dp[0][j][k][l];

					if(j-1>=0)
						b = f(dp[i][j-1][k][l],m2,i,j-1,k,l);
					else
						b = dp[i][0][k][l];

					if(k-1>=0)
						c = f(dp[i][j][k-1][l],m3,i,j,k-1,l);
					else
						c = dp[i][j][0][l];											
					if(l-1>=0)
						d = f(dp[i][j][k][l-1],m4,i,j,k,l-1);
					else
						d = dp[i][j][k][0];
					dp[i][j][k][l] = max(max(a,b),max(c,d));
					//cout << dp[i][j][k][l] << endl;
				}
			}
		}
	}
	cout << dp[n1][n2][n3][n4] << endl;
	return 0;
}