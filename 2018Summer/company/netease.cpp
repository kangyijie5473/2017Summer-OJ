#include <bits/stdc++.h>
using namespace std;
	typedef unsigned long long ull;

ull getSum(int n, int m)
{
	ull up = 1, down = 1;
	int start = n + m;
	int end = n < m ? n : m;
	for (int i = 0; i < end; i++, start--)
		up *= start;
	// cout << "up" << up << endl;
	for (int i = end; i >= 1; i--)
		down *= i;
	// cout << "down" << down << endl;
	// cout << up / down << endl;
	ull sum = up / down;
	return sum;
}
void getResult(ull sum, int k, int na, int nz)
{
	string result;
	while(na + nz > 2) {
		int coutA = sum * na / (na + nz);
		int coutz = sum * nz / (na + nz);
		if (k > coutA){
			result += 'z';
			k -= coutA;
			nz--;
		} else {
			result += 'a';
			na--;
		}
		sum = getSum(na, nz);
	}
	cout << "k" << k << endl;
	if (na == 2){
		result += "aa";
	}else if(nz == 2){
		result += "zz";
	}else if (k == 1){
		result += "az";
	}else if(k == 2){
		result += "za";
	}else 
		result += "aa";
	cout << result << endl;
}
int main(int argc, char const *argv[])
{
	freopen("in-net", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;
	ull sum = getSum(n, m);
	if (k > sum)
		cout << -1 << endl;
	else {
		getResult(sum, k, n, m);
	}
	// ull n , k;
	// cin >> n >> k;
	// vector<int> sleep_flag, score;
	// for (int i = 0; i < n; i++) {
	// 	int temp;
	// 	cin >> temp;
	// 	score.push_back(temp);
	// }
	// for (int i = 0; i < n; i++) {
	// 	int temp;
	// 	cin >> temp;
	// 	sleep_flag.push_back(temp);
	// }
	// ull result = 0;
	// for (int i = 0; i < n; i++) {
	// 	if (sleep_flag[i])
	// 		result += score[i];
	// }
	// //cout << result << endl;
	// int max_awake_score = 0;
	// for (int i = 0; i <= n - k; i++) {
	// 	int awake_score = 0;
	// 	for (int j = 0; j < k; j++) {
	// 		if (sleep_flag[i+j] == 0) {
	// 			awake_score += score[i+j];
	// 		}
	// 	}
	// 	//cout << awake_score << endl;
	// 	if (max_awake_score < awake_score)
	// 		max_awake_score = awake_score;
	// }
	// cout << result + max_awake_score << endl;
	// int a, b, c;
	// cin >> a >> b >> c;
	// int r[6];
	// r[1] = a*b*c;
	// r[2] = a*b+c;
	// r[3] = a+b+c;
	// r[4] = a+b*c;
	// r[5] = (a+b)*c;
	// r[0] = a*(b+c);
	// int max = 0;
	// for (int i = 0; i < 6; i++) {
	// 	if (r[i] > max)
	// 		max = r[i];
	// }
	// cout << max << endl;
	return 0;
}