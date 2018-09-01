#include <bits/stdc++.h>
using namespace std;
int func(const vector<int> &v1, const vector<int> &v2)
{
	int p = 0, q = 0;
	int mid = ceil((v1.size() + v2.size() - 2) / 2.0);
	cout << mid << "mid" << endl;
	if (mid == 1)
		return v1.size() == 1 ? v2[1] : v1[1];
	bool flag = false;
	while(p + q != mid) {
		if (v1.size() - 1 == p){
			q++;
			flag = false;

			continue;
		} else if(v2.size() - 1 == q){
			p++;
			flag = true;

			continue;
		}

		if (v1[p + 1] > v2[q + 1]){
			q++;
			flag = false;
		} else{
			p++;
			flag = true;
		}
	}
	if (flag)
		return v1[p];
	else
		return v2[q];
}
int main(int argc, char const *argv[])
{
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> v1(n1 + 1, 0),v2(n2 + 1, 0);
	for (int i = 1; i <= n1; i++)
		cin >> v1[i];
	for (int i = 1; i <= n2; i++)
		cin >> v2[i];



	cout << func(v1, v2) << endl;
	return 0;
}