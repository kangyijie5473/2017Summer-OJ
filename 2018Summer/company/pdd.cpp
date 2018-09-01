#include <bits/stdc++.h>
using namespace std;
int N, L;

bool func(vector<string> &table, vector<set<char>> &s, int index, string str)
{
	bool flag = true;
	if (index == L - 1) {
		for (auto i : s[index]) {
			str += i;
			for (int j = 0; j < N; j++)
				if (str == table[j]){
					flag = false;
					break;
				}
			if (flag) {
				cout << str << endl;
				return true;
			}else 
				str.pop_back();
		}
		return false;
	}else {
		for (auto i : s[index]) {
			str += i;
			if (func(table, s, index+1, str) == false)
				str.pop_back();
			else
				return true;
		}
		return false;
	}

}
int main(int argc, char const *argv[])
{
	freopen("pdd-in", "r", stdin);
	cin >> N >> L;
	vector<string> table(N, string());
	for (int i = 0; i < N; i++)
		cin >> table[i];
	// for (int i = 0; i < N; i++)
	// 	cout << table[i] << endl;
	vector<set<char>> s(L, set<char>());
	for (int i = 0; i < L; i++)
		for (int j = 0; j < N; j++)
			s[i].insert(table[j][i]);
	string str;
	bool flag = false;
	for (auto i : s[0]){
		str += i;
		if (func(table, s, 1, str) == false)
			str.pop_back();
		else{
			flag = true;
			break;
		}
	}
	if (flag == false)
		cout << "-" << endl;
	// for (int i = 0; i < L; i++) {
	// 	cout << "set:" << i << endl;
	// 	for (auto l : s[i])
	// 		cout << l << ' ';
	// 	cout << endl;
	// }
	return 0;
}
// int main(int argc, char const *argv[])
// {
// 	freopen("pdd-in", "r", stdin);
// 	int n,m;
// 	cin >> n >> m;
// 	vector<vector<char>> table(n, vector<char>(m, 0));
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++)
// 			cin >> table[i][j];
// 	}
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++)
// 			cout <<  table[i][j] << ' ';
// 		cout << endl;
// 	}
// 	for (int i = 0; i < m; i++) {
// 		int index = n - 1;
// 		while (index >= 0 && table[index][i] != 'x')
// 			index--;
// 		if (index < 0){
// 			for (int j = 0; j < n; j++)
// 				table[j][i] = '.';
// 			continue;
// 		}else
// 			for (int j = index + 1; j < n; j++)
// 				table[j][i] = '.';
// 		int pre_index = index -1;
// 		while (pre_index >= 0){
// 			int c = 0;
// 			while (pre_index >= 0 && table[pre_index][i] != 'x'){
// 				if (table[pre_index][i] == 'o')
// 					c++;
// 				pre_index--;
// 			}
// 			int j = index - 1;
// 			for (int k = 0; k < c; k++,j--)
// 				table[j][i] = 'o';
// 			for (; j > pre_index; j--)
// 				table[j][i] = '.';
// 			index = pre_index;
// 			pre_index = index - 1;

// 		}

// 	}
// 	//cout << "------------------" << endl;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++)
// 			cout <<  table[i][j] << ' ';
// 		cout << endl;
// 	}
// 	return 0;
// }


// typedef long long ull;
// typedef long long ll;
// ull normal_attack, buff_attack;
// ull max_round = INT_MAX;
// void getMinRound(ll max_hp, ll hp, bool buff, ull round)
// {
// 	round++;
// 	if (buff) {
// 		if (hp - buff_attack <= 0){
// 			if (round < max_round)
// 				max_round = round;
// 			else
// 				;
// 			return ;
// 		} else
// 			getMinRound(max_hp, hp - buff_attack, false, round);
// 	}
// 	else {
// 		if (hp - normal_attack <= 0){
// 			if (round < max_round)
// 				max_round = round;
// 			else
// 				;
// 			return ;			
// 		}
// 		else
// 			getMinRound(max_hp, hp - normal_attack, false, round);
// 		getMinRound(max_hp, hp, true, round);

// 	}


// }
// int main(int argc, char const *argv[])
// {
// 	freopen("pdd-in", "r", stdin);
// 	ll hp;
// 	cin >> hp >> normal_attack >> buff_attack ;
// 	getMinRound(hp, hp, true, 1);
// 	getMinRound(hp, hp - normal_attack, false, 1);
// 	cout << max_round << endl;
// 	return 0;
// }