#include <bits/stdc++.h>
using namespace std;
const int Y = 1;
const int N = 2;
const int M = 3;
int main()
{
	freopen("in-4", "r", stdin);
	int n, m, k, c;
	int p,q;
	ios::sync_with_stdio(false);
	scanf("%d%d%d%d", &n, &m, &k, &c);
	int w[7] = {0};
	double weight[7] = {0};
	vector<vector<int>> score(n, vector<int>(m, 0));
	vector<double> final_score(n, 0);
	vector<int> result(n, 0);

	int sum = 0;
	for(int i = 0; i < m; i++){
		scanf("%d", &w[i]);
		sum += w[i];
	}
	for(int i = 0; i < m; i++){
		weight[i] = w[i] * 1.0/sum;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &score[i][j]);
			if(score[i][j] == -1){
				p = i;
				q = j;
			}
		}
	}
	for(int i = 0; i < m; i++){
		if(i == q)
			continue;
		int round_max = 0;
		for(int j = 0; j < n; j++){
			if(round_max < score[j][i])
				round_max = score[j][i];
		}
		for(int j = 0; j < n; j++){
			final_score[j] += score[j][i]*1.0/round_max*weight[i];
		}
	}
	for(int i = 0; i < n; i++)
		printf("%f  \n", final_score[i]);
	// for(int i = 0; i < m; i++)
	// 	printf("%f   \n", weight[i]);	
	return 0;
}