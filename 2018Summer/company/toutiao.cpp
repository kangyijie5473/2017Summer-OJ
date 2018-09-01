#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("in-toutiao", "r", stdin);
	int t;
	cin >> t;
	cout << t << endl;
	while (t--) {
		int n;
		set<string> str;
		cin >> n;
		while(n--) {
			string s;
			cin >> s;
			str.insert(s);
		}
		cout << "-----in---" << t <<endl;
		for(auto i = str.begin(); i != str.end(); i++) {
			string s = *i;
			str.erase(s);
			bool flag = false;
			for (int i = 0; i < s.size() - 1; i++) {
				string sa;
				for(int j = i+1; j < s.size(); j++)
					sa.push_back(s[j]);
				for(int j = 0; j < i+1; j++) 
					sa.push_back(s[j]);

				string sb;
				for(int j = i; j >= 0; j--)
					sb.push_back(s[j]);
				for(int j = s.size()-1; j > i; j--)
					sb.push_back(s[j]);
				cout << "sa:" << sa << "  sb: " << sb <<endl; 
				if (str.find(sa) != str.end() || str.find(sb) != str.end()) {
					cout << "yeah" << endl;
					flag = true;
					break;
				}

			}
			if (flag == false) {
				reverse(s.begin(), s.end());
				if (str.find(s) == str.end()) {
					cout << "sad" << endl;
				}				
			}
			str.insert(s);
		}
 	}

	return 0;
}
// int pre[10000] = {0};
// int find(int x)
// {
// 	int t = x;
// 	if (pre[t] == 0)
// 		return t;
// 	while (pre[t] != t) {
// 		if (pre[t] == 0)
// 			return t;
// 		t = pre[t];
// 	}
// 	return t;
// }
// bool Union(int x, int y)
// {
// 	int xx = find(x);
// 	int yy = find(y);
// 	//cout << "x " << x << "y" << y << "xx" << xx << "yy" << yy <<endl;
// 	if (xx != yy && xx != 0) {
// 		pre[xx] = yy;
// 		return false;		
// 	} else {
// 		return true;
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	//freopen("in-toutiao", "r", stdin);
// 	int n;
// 	cin >> n;
// 	vector<int> temp;
// 	vector<vector<int>> people;
// 	for (int i = 0; i < n+1; i++)
// 		people.push_back(temp);
// 	for (int i = 1; i <= n; i++) {
// 		int t = -1;
// 		while(1) {
// 			cin >> t;
// 			if (t == 0)
// 				break;
// 			people[i].push_back(t);
// 		}
// 	}
// 	for (int i = 1; i <= n; i++) {
// 		for(auto j : people[i]) {
// 			Union(i, j);
// 			//cout <<  << "rr" << endl;
// 		}
// 	}

// 	vector<int> count(n+1, 0);
// 	for (int i = 1; i <= n; i++) {
// 		//cout << find(i) << endl;
// 		count[find(i)]++;
// 	}
// 	int res = 0;
// 	for (int i = 1; i<=n; i++) {
// 		if (count[i])
// 			res++;
// 	}
// 	cout << res << endl;
// 	return 0;
// }
