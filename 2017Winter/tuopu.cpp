#include <bits/stdc++.h>
using namespace std;
vector<list<int>> adj;
vector<int> in_degree;
stack<int> st;
void creatGraph()
{
	int n, m, v1, v2;
	cin >> n >> m;
	adj.assign(n, list<int>());
	in_degree.assign(n, 0);
	while(m--){
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		in_degree[v2]++;
	}
	for(int i = 0; i < n; i++)
		if(in_degree[i] == 0)
			st.push(i);
}
void Tsort()
{
	vector<int> v;
	int t;
	while(!st.empty()){
		t = st.top();
		st.pop();
		for(auto i = adj[t].begin(); i != adj[t].end(); i++){
			in_degree[*i]--;
			if(in_degree[*i] == 0)
				st.push(*i);				
		}
		v.push_back(t);
	}
	if(v.size() != in_degree.size()){
		cout << "circle" << endl;
		return;
	}
	for(auto i : v)
		cout << i << ' ';
	cout << endl;
	return;

}
int main(int argc, char const *argv[])
{
	creatGraph();
	Tsort();
	return 0;
}