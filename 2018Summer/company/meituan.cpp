#include <bits/stdc++.h>
using namespace std;
//Q2 dp 01pack
int main(int argc, char const *argv[])
{
	freopen("in-m", "r", stdin);
	
	ull n;
	ull res = 0;
	cin >> n;
	vector<int> all_score(n, 0), all_time(n, 0), sub_score(n, 0), sub_time(n, 0);
	for (ull i = 0; i < n; i++) {
		cin >> sub_time[i] >> sub_score[i] >> all_time[i] >> all_score[i];
	}
	int dp[200][121] = {0};
	for (int j = 0; j < 121; j++)
		if (j >= sub_time[0] && j < all_time[0])
			dp[0][j] = sub_score[0];
		else if (j >= all_time[0])
			dp[0][j] = all_score[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 121; j++) {
			int max_value = dp[i-1][j];
			if (j - all_time[i] >= 0) {
				int v1 =  dp[i - 1][j - all_time[i]] + all_score[i];
				max_value =  max_value > v1 ? max_value : v1;
			}
			if (j - sub_time[i] >= 0) {
				int v2 = dp[i - 1][j - sub_time[i]] + sub_score[i];
				max_value = max_value > v2 ? max_value : v2;
			}
			dp[i][j] = max_value;
		}
	}

	cout << dp[n-1][120] << endl;
	return 0;
}
// Q1 easy
	// ull n, m;
	// ull res;
	// cin >> n >> m;
	// ull m1 = (n + m) / 3;
	// ull m2 = n > m ? m : n;
	// res = m1 < m2 ? m1 : m2;
	// cout << res << endl;
