#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(int argc, char const *argv[])
{
	/* code */
	freopen("g3-in", "r", stdin);
	ull T;
	cin >> T;
	for(int k = 0; k < T; k++) {
		ull N, K;
		cin >> N >> K;
		vector<ull> Ai;
		for (int i = 0; i < N; i++) {
			ull temp;
			cin >> temp;
			Ai.push_back(temp);
		}
		sort(Ai.begin(), Ai.end());
		// for (auto i : Ai)
		// 	cout << "Ai" << i << endl;
		ull res = 0;
		ull index = 0;
		ull day = 0;
		while(index != N) {

			for(int j = 0; j < K && index != N; index++) {
				//cout << "j:" << j << "index:" << index << "Ai:"<< Ai[index] << "day:" << day << endl;
				if (Ai[index] > day)
					j++,res++;
			}
			day++;
		}
		cout << "Case #" << k+1 << ": " << res << endl;
	}
	return 0;
}