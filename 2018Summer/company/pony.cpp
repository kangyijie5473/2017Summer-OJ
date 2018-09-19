#include <bits/stdc++.h>
using namespace std;
int judge(int i, int j, vector<vector<char>> &graph)
{
	char flag = graph[i][j];
	if (flag == '.')
		return 0;
	int win_flag = false;
	int c = 0;
	if (j < 11) {
		int k = j + 1;
		while (k < 15 && graph[i][k++] == flag)
			c++;
		if (c > 4)
			return -1;
		if (c == 4)
			win_flag = true;
	}
	if (i < 11) {
		int k = i + 1;
		c = 0;
		while (k < 15 && graph[k++][j] == flag)
			c++;
		if (c > 4)
			return -1;
		if (c == 4)
			win_flag = true;
	}
	if (j < 11 && i < 11) {
		int k = i + 1;
		int l = j + 1;
		c = 0;
		while (k < 15 && l < 15 && graph[k++][l++] == flag)
			c++;
		if (c > 4)
			return -1;
		if (c == 4)
			win_flag = true;
	}
	if (j > 3 && i < 11) {
		int k = j - 1;
		int l = i + 1;
		c = 0;
		while(k >= 0 && l < 15 && graph[l++][k--] == flag)
			c++;
		if (c > 4)
			return -1;
		if (c == 4)
			win_flag = true;
	}
	if (win_flag)
		return 1;
	else
		return 0;
}
int main(int argc, char const *argv[])
{
	freopen("in-pony", "r", stdin);
	vector<vector<char>> graph(15, vector<char>(15, 0));
	int white_count = 0;
	int black_count = 0;
	for (int i = 0; i < 15; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 15; j++){
			if (temp[j] == 'B')
				black_count++;
			else if (temp[j] == 'W')
				white_count++;
			graph[i][j] = temp[j];
		}

	}
	bool white_more = false;
	if (white_count > black_count) {
		white_more = true;
		if (white_count - black_count > 1) {
			cout << "invalid board" << endl;
			return 0;
		}
	}else if (black_count - white_count > 1) {
		cout << "invalid board" << endl;
		return 0;
	}
	bool someone_win = false;
	bool white_win = false;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			int ret = judge(i, j, graph);
			if (ret == 1) {
				if (someone_win) {
					cout << "invalid board" << endl;
					return 0;
				}else
					someone_win = true;
				if (graph[i][j] == 'W')
					white_win = true; 
			}else if (ret == -1) {
				cout << "invalid board" << endl;
				return 0;
			}

		}
	}
	if (someone_win) {
		if (white_win)
			cout << "white win" << endl;
		else 
			cout << "black win" << endl;
	} else if (white_count + black_count == 225)
		cout << "draw" << endl;
	else 
		cout << "not finished" << endl;

	return 0;
}