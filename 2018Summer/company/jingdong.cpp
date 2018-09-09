#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
bool bfs(int s, int n, vector<int> &color, vector<vector<int>> &graph) {  
    queue<int> q;  
    q.push(s);  
    color[s] = 1;  
    while(!q.empty()) {  
        int from = q.front();  
        q.pop();  
        for(int i = 1; i <= n; i++) {  
            if(graph[from][i] && color[i] == -1) {  
                q.push(i);  
                color[i] = !color[from];
            }  
            if(graph[from][i] && color[from] == color[i])
                return false;  
        }  
    }  
    return true;       
}
int main(int argc, char const *argv[])
{
	freopen("in-jd", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		int n, m, a, b;
		cin >> n >> m;
		vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
		vector<int> color(n + 1, -1);
		while(m--) {
			cin >> a >> b;
			graph[b][a] = graph[a][b] = 1;
 
		}
		bool flag = false;  
	    for(int i = 1; i <= n; i++)  
	        if(color[i] == -1 && !bfs(i, n, color, graph)) {
	            flag = true;  
	            break;    
	        }  
	    if(flag)  
	        cout << "No" <<endl;      
	    else  
	        cout << "Yes" <<endl; 

	}
	return 0;
}
 
  


// int main(int argc, char const *argv[])
// {
// 	 freopen("in-jd", "r", stdin);
// 	int n;
// 	cin >> n;
// 	ull count = 0;
// 	vector<int> va(n, 0), vb(n, 0), vc(n, 0);
// 	for (int i = 0 ; i < n; i++)
// 		cin >> va[i] >> vb[i] >> vc[i];
// 	// for (int i = 0; i < n; i++)
// 	// 	cout << va[i] << vb[i] << vc[i] << endl;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			// cout << 'i' << i << va[i] << ' ' << vb[i] << vc[i] << endl; 
// 			// cout << 'j' << j << va[j] << ' ' << vb[j] << vc[j] << endl;
// 			if (j == i)
// 				continue;
// 			if (va[j] > va[i] && vb[j] > vb[i] && vc[j] > vc[i]){
// 				count++;
// 				break;
// 			}
// 		}
// 	}
// 	cout << count << endl;
// 	return 0;
// }