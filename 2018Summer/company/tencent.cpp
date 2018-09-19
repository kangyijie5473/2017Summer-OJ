#include <bits/stdc++.h>
using namespace std;
int n, m;

void dfs(int src, int pos, vector<int> &vis, vector<vector<int>> &graph) //
{
	if (vis[pos])
		return;
	if (graph[src][pos])              
		vis[pos] = 1;                  
	for (int i = 1; i <= n; i++)
		if (graph[pos][i])            
			dfs(pos, i, vis, graph);  
}
int main(int argc, char const *argv[])
{
	//freopen("in-tencent", "r", stdin);
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	vector<int> dst_count(n + 1, 0);
	vector<int> src_count(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		vector<int> vis(n + 1, 0);
		dfs(i, i, vis, graph);            
		for (int j = 1; j <= n; j++)
			if (vis[j]){                  
				src_count[i]++;
				dst_count[j]++;
			}
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (dst_count[i] > src_count[i]){
			c++;
		}
	}
	cout << c << endl;
	return 0;
}
// int main(int argc, char const *argv[])
// {
// 	int a, b, c;
// 	cin >> a >> b >> c;

// 	return 0;
// }