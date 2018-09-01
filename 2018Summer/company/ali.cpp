#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("in", "r", stdin);
	int sys_nums, depend_nums;
	vector<int> speedtime;
	cin >> sys_nums >> depend_nums;
	vector<int> head_flag = {0, sys_nums+1};
	while (sys_nums--) {
		int temp;
		cin >> temp;
		speedtime.push_back(temp);
	}
	map<int,vector<int>> depends;
	while (depend_nums--) {
		int a,b;
		cin >> a >> b;
		head_flag[b] = 1;
		depends[a].push_back(b);
	}
	int link_nums = 0;
	int max_speedtime = 0;
	for (int i = 1; i <= head_flag.size(); i++) {
		if (head_flag[i] != 0) {
			const vector<int> &p = depends[i];
			for (int j = 0; j < p.size(); j++) {

			}
			link_nums += p.size();
		}
	}

	return 0;
}